#include <BitcoinExchange.hpp>

using ErrorHandler = std::function<void(const std::string &)>;

BitcoinExchange::BitcoinExchange() {
}

BitcoinExchange::~BitcoinExchange() {
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& src) {
	*this = src;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& src) {
    if (this != &src) {
        this->_DB = src._DB;
    }
    return *this;
}

ErrorHandler handler = [](const std::string &err) {
	std::cout << "Error: " << err << std::endl;
};

static bool isLeapYear(int year) {
	return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
}

static bool validDate(const std::string& date, ErrorHandler onError = nullptr) {
	if (date.size() == 0) {
		if (onError) {
			handler("missing date");
		}
		return false;
	}
    struct tm tm{};
    if (!strptime(date.c_str(), "%Y-%m-%d", &tm)) {
        return false;
    }
	int daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	int year  = tm.tm_year + 1900;
    int month = tm.tm_mon + 1;
    int day   = tm.tm_mday;

	if (isLeapYear(year)) {
		daysInMonth[1] = 29;
	}

	if (day > daysInMonth[month - 1]) {
		return false;
	}
    return true;
}

static bool validValue(const std::string& value, ErrorHandler onError = nullptr) {
	if (value.size() == 0) {
		if (onError) {
			handler("missing value");
		}
		return false;
	}
    if (value[0] == '-') {
		if (onError) {
			handler("not a positive number");
		}
        return false;
    }

	float f;
    try {
        size_t pos;
        f = std::stof(value, &pos);
        if (pos != value.size()) {
			if (onError) {
				handler("invalid input");
			}
            return false;
        }
    }
    catch (std::invalid_argument) {
		if (onError) {
			handler("invalid input");
		}
        return false;
    }
    catch (std::out_of_range) {
		if (onError) {
			handler("too large a number");
		}
        return false;
    }
    if (f > static_cast<float>(INT_MAX)) {
		if (onError) {
			handler("too large a number");
		}
		return false;
    }
    return true;
}

static bool validFormat(std::string &line, ErrorHandler onError = nullptr) {
	if (line.size() == 0) {
		if (onError) {
			handler("empty line");
		}
		return false;
	}
	size_t pos = line.find("|");
	if (pos == std::string::npos) {
		if (onError) {
			handler("missing '|'");
		}
		return false;
	}
	return true;
}

static void trimWhiteSpaces(std::string &str) {
    str.erase(0, str.find_first_not_of(" \t"));
    str.erase(str.find_last_not_of(" \t") + 1);
}

void BitcoinExchange::convertValue(const std::string& date, const std::string &value) {
	auto it = _DB.upper_bound(date);
	if (it == _DB.begin()) {
		std::cout << "Error: no data available to convert" << std::endl;
	}
	it--;
	float rate = it->second;
	float inputValue = std::stof(value);
	float result = rate * inputValue;
	std::cout << date << " => " << value << " = " << result << std::endl;
}

void BitcoinExchange::convertInput(const std::string& filename) {
    std::ifstream file(filename.c_str());
    if (!file.is_open()) {
        throw std::runtime_error("Error: could not open file.");
    }
	int i = 2;

    std::string line;
    std::getline(file, line); //skip header date | value
    while (std::getline(file, line)) {
        std::stringstream   ss(line);
        std::string         date;
        std::string         value;
		if (!validFormat(line, handler)) {
			continue;
		}
        if (std::getline(ss, date, '|')) {
			trimWhiteSpaces(date);
            if (!validDate(date, handler)) {
				std::cout << "Error: invalid input => " << date << std::endl;
                continue;
            }
			if (std::getline(ss, value)) {
				trimWhiteSpaces(value);
				if (!validValue(value, handler)) {
					continue;
				}
			}
			else {
				std::cout << "Error: missing value" << std::endl;
				continue;
			}
			convertValue(date, value);
        }
		i++;
    }
    file.close();
}

void    BitcoinExchange::parseData(const std::string& filename) {
    std::ifstream   file(filename.c_str());

    if (!file.is_open()) {
        throw std::runtime_error("Error: could not open file");
    }

    std::string line;
    while (std::getline(file, line)) {
        std::stringstream   ss(line);
        std::string         date;
        std::string         valueStr;

        if (std::getline(ss, date, ',')) {
			trimWhiteSpaces(date);
			if (!validDate(date)) {
				continue;
			}
			if (std::getline(ss, valueStr)) {
				if (!validValue(valueStr)) {
					continue;
				}
				try {
					size_t pos;
					float value = std::stof(valueStr, &pos);
					if (pos != valueStr.size()) {
						continue;
					}
					_DB[date] = value;
				}
				catch (const std::exception &e) {
					continue;
				}
			}
        }
    }
	if (_DB.empty()) {
		file.close();
		throw std::runtime_error("Error: database is empty");
	}
    file.close();
}
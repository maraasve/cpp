#include <BitcoinExchange.hpp>

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

#include <iomanip>
void    BitcoinExchange::parseData(const std::string& filename) {
    std::ifstream   file(filename.c_str());

    if (!file.is_open()) {
        throw std::runtime_error("Error: could not open file.");
    }

    std::string line;
    while (std::getline(file, line)) {
        std::stringstream   ss(line);
        std::string         date;
        std::string         valueStr;

        if (std::getline(ss, date, ',') && std::getline(ss, valueStr)) {

            try {
                float value = std::stof(valueStr);
                _DB[date] = value;
            }
            catch (std::exception) {}
        }
    }
    file.close();
}

static bool validateDate(const std::string& date) {
    struct tm tm{};
    if (!strptime(date.c_str(), "%Y-%m-%d", &tm)) {
        return false;
    }
    return true;
}

static bool validateValue(const std::string& value) {
    float f;
    if (value[0] == '-') {
        std::cout << "Error: not a positive number." << std::endl;
        return false;
    }
    try {
        size_t pos;
        f = std::stof(value, &pos);
        if (pos != value.size()) {
            return false;
        }
    }
    catch (std::invalid_argument) {
        std::cout << "Error: invalid input." << std::endl;
        return false;
    }
    catch (std::out_of_range) {
        std::cout << "Error: too large a number." << std::endl;
        return false;
    }
    if (f > INT_MAX) {
        std::cout << "Error: too large a number." << std::endl;
    }
    return true;
}

static void trimWhiteSpaces(std::string &str) {
    str.erase(0, str.find_first_not_of(" \t"));
    str.erase(str.find_last_not_of(" \t") + 1);
}

void BitcoinExchange::convertInput(const std::string& filename) {
    std::ifstream file(filename.c_str());
    if (!file.is_open()) {
        throw std::runtime_error("Error: could not open file.");
    }

    std::string line;
    std::getline(file, line); //skip header date | value
    while (std::getline(file, line)) {
        std::stringstream   ss(line);
        std::string         date;
        std::string         valueStr;
        if (std::getline(ss, date, '|')) {
            trimWhiteSpaces(date);
            std::cout << date << std::endl;
            if (!validateDate(date)) {
                std::cout << "Error: invalid input => " << date << std::endl;
                continue;
            }
        }
        if (std::getline(ss, valueStr)) {
            trimWhiteSpaces(date);
            if (!validateValue(valueStr)) {
                continue;
            }
        }
    }
    file.close();
}
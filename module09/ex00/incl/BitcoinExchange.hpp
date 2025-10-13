#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <map>
# include <fstream>
# include <sstream>
# include <climits>
// # include <ctime>
# include <functional>

class BitcoinExchange {
	private:
		std::map<std::string, float>	_DB;

	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& src);
		BitcoinExchange& operator=(const BitcoinExchange& src);
		~BitcoinExchange();

		void	parseData(const std::string& filename);
		void	convertInput(const std::string& filename);
		void	convertValue(const std::string& date, const std::string& value);

};

#endif

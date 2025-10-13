#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <map>
# include <fstream>
# include <sstream>
# include <limits>
# include <ctime>

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

};

#endif

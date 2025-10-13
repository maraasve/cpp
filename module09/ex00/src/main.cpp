#include <BitcoinExchange.hpp>

int main(int argc, char *argv[]) {
	if (argc == 1) {
		std::cerr << "Error: could not open file." << std::endl;
		return 1;
	}
	BitcoinExchange btc;
	try {
		btc.parseData("data.csv");
	}
	catch (std::exception) {}
	try {
		btc.convertInput(argv[1]);
	}
	catch (std::exception) {}
}
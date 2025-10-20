#include <PmergeMe.hpp>

int main(int argc, char *argv[]) {
	if (argc == 1) {
		std::cout << "Nothing to sort" << std::endl;
		return 0;
	}
	try {
		PmergeMe P(argc, argv);
		std::cout << "Before: "; P.printDeq();
	}
	catch (const std::exception &e) {
		return 1;
	}
}
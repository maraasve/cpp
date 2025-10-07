#include <Array.hpp>
#include <limits>

int main(void) {
	Array<int> a(5);
	std::cout << BLUE << "Array size = " << RESET << a.size() << std::endl;

	// TEST 1: [] operator
	std::cout	<< BOLDMAGENTA << "\nTEST 1: [] operator\n" << RESET 
				<< BLUE << "Array on index:" << RESET <<std::endl;
	for (unsigned int i = 0; i < a.size(); i++) {
		a[i] = i;
		std::cout << BLUE << "[" << i << "]: " << RESET << a[i] << std::endl;
	}
	std::cout << "\nPress Enter to continue..." << std::endl;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');


	// TEST 2: out of bounds index
	try {
		std::cout	<< BOLDMAGENTA << "\n\nTEST 2: out of bounds index\n" << RESET 
					<< BLUE <<"Array on index 10:" << RESET << std::endl;
		std::cout << a[10] << std::endl;
	} catch (const std::exception &e) {
		std::cerr << RED << "Error: " << e.what() << RESET << std::endl;
	}

	try {
		std::cout << BLUE << "\nArray on index -1:" << RESET << std::endl;
		std::cout << a[-1] << std::endl;
	} catch (const std::exception &e) {
		std::cerr << RED << "Error: " << e.what() << RESET << std::endl;
	}
	std::cout << "\nPress Enter to continue..." << std::endl;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');


	// TEST 3: copy constructor
	{
		std::cout << BOLDMAGENTA << "\n\nTEST 3: copy constructor" << RESET <<std::endl;

		Array<int> b(a);

		std::cout << BLUE << "Array b (copy of a) on index:" << RESET <<std::endl;
		for (unsigned int i = 0; i < b.size(); i++) {
			std::cout << BLUE << "[" << i << "]: " << RESET << b[i] << std::endl;
		}
	}
	std::cout << "\nPress Enter to continue..." << std::endl;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');


	// TEST 4: default constructor
	{
		std::cout << BOLDMAGENTA << "\n\nTEST 4: default constructor" << RESET << std::endl;
		Array<int> b;
		std::cout << BLUE << "Array b is an empty array with size: " << b.size() << RESET <<std::endl;
		
		try {
			std::cout << BLUE << "\nArray b on index 0:" << RESET << std::endl;
			std::cout << b[0] << std::endl;
		} catch (const std::exception &e) {
			std::cerr << RED << "Error: " << e.what() << RESET << std::endl;
		}

		std::cout << "\nPress Enter to continue..." << std::endl;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		// TEST 5: assignment operator
		std::cout << BOLDMAGENTA << "\n\nTEST 5: assignment operator" << RESET <<std::endl;
		b = a;
		std::cout << BLUE <<"Array b (after assignment from a) on index:" << RESET <<std::endl;
		for (unsigned int i = 0; i < b.size(); i++) {
			std::cout << BLUE << "[" << i << "]: " << RESET << b[i] << std::endl;
		}
	}
}
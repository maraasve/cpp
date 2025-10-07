#include <easyfind.hpp>
#include <iostream>
#include <vector>
#include <list>

int main(void) {
	std::vector<int> vec = {1, 2, 3, 4, 5};
	std::list<int> lst = {10, 20, 30, 40, 50};

	auto it_vec = easyfind(vec, 3);
	if (it_vec != vec.end()) {
		std::cout << "Found in vector: " << *it_vec << std::endl;
	}
	else {
		std::cout << "Value not found in vector." << std::endl;
	}

	auto it_lst = easyfind(lst, 0);
	if (it_lst != lst.end()) {
		std::cout << "Found in list: " << *it_lst << std::endl;
	}
	else {
		std::cout << "Value not found in list." << std::endl;
	}
}
#include <iter.hpp>

#include <iostream>
#include <colors.hpp>

template <typename T>
void print(const T &x) {
	std::cout << x << std::endl;
}

template <typename T>
void increment(T &x) {
	x += 1;
}

int main() {
    int int_arr[] = {1, 2, 3, 4, 5};
	std::string str_arr[] = {"hello", "world", "!"};
	char char_arr[] = {'a', 'b', 'c', 'd', 'e'};

	std::cout << BOLDBLUE << "INTEGERS" << RESET << std::endl;
	iter(int_arr, 5, print<int>);
	std::cout << BOLDBLUE << "\nSTRINGS" << RESET << std::endl;
	iter(str_arr, 3, print<std::string>);
	std::cout << BOLDBLUE << "\nCHARS" << RESET << std::endl;
	iter(char_arr, 5, print<char>);

	std::cout << BOLDMAGENTA << "\nINTEGERS AFTER INCREMENTING" << RESET << std::endl;
	iter(int_arr, 5, increment<int>);
	iter(int_arr, 5, print<int>);
	std::cout << BOLDMAGENTA << "\nCHARS AFTER INCREMENTING" << RESET << std::endl;
	iter(char_arr, 5, increment<char>);
	iter(char_arr, 5, print<char>);
}
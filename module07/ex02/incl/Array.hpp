#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <colors.hpp>
# include <stdexcept>

template <typename T>
class Array {
	private:
		T				*_array;
		unsigned int	_size;
public:
	Array() {
		_array = NULL;
		_size = 0;
		std::cout << GREEN << "Array default constructor called" << RESET <<std::endl;
	}

	Array(unsigned int size) : _size(size) {
		_array = new T[_size];
		std::cout << GREEN << "Array constructor called" << RESET << std::endl;
	}

	Array(const Array &src) {
		_size = src._size;
		_array = new T[_size];
		for (unsigned int i = 0; i < _size; i++) {
			_array[i] = src._array[i];
		}
		std::cout << GREEN << "Array copy constructor called" << RESET << std::endl;
	}

	~Array() {
		delete[] _array;
		std::cout << RED << "Array destructor called" << RESET << std::endl;
	}

	Array &operator=(const Array &src) {
		if (this != &src) {
			delete[] _array;
			_size = src._size;
			_array = new T[_size];
			for (unsigned int i = 0; i < _size; i++) {
				_array[i] = src._array[i];
			}
		}
		std::cout << GREEN << "Array assignment operator called" << RESET << std::endl;
		return *this;
	}

	T &operator[](unsigned int index) {
		if (index >= _size) {
			throw std::out_of_range("Index out of range");
		}
		return _array[index];
	}

	unsigned int size() const {
		return _size;
	}
	
};
#endif
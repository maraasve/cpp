#ifndef DATA_HPP
# define DATA_HPP

# include <iostream>

class Data {
	private:
		size_t _num1;
		size_t _num2;

	public:
		Data() = delete;
		Data(size_t num1, size_t num2);
		Data(const Data& src);
		Data& operator=(const Data& src);
		~Data();

		size_t getNum1() const;
		size_t getNum2() const;
};

#endif

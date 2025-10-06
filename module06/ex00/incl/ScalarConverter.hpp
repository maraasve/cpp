#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <limits>
# include <climits>

class ScalarConverter {
	public:
		ScalarConverter() = delete;
		ScalarConverter(const ScalarConverter& src) = delete;
		ScalarConverter& operator=(const ScalarConverter& src) = delete;
		~ScalarConverter() = delete;
		
		static void convert(const std::string& literal);
};

#endif

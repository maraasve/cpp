#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <climits>

class Span {
	private:
		unsigned int		_N;
		std::vector<int>	_vec;

	public:
		Span() = delete;
		Span(unsigned int N);
		Span(const Span& src);
		Span& operator=(const Span& src);
		~Span();

		void		addNumber(int number);
		void		addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);
		long int	shortestSpan() const;
		long int	longestSpan() const;

		class NoSpan : public std::exception {
			public:
				virtual const char* what() const throw();
		};
};

#endif
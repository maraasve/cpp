#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>
# include <sstream>

class RPN {
	private:
		std::stack<float>	_stack;
		float				_finalResult;

	public:
		RPN() = delete;
		RPN(const std::string& input);
		RPN(const RPN& src);
		RPN& operator=(const RPN& src);
		~RPN();

		void	readInput(const std::string& input);
		void	pushOperand(const std::string& token);
		void	applyOperator(const std::string& token);
		void	checkResult();

		float	getFinalResult() const;
};

#endif

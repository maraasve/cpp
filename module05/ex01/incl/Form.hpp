#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <Bureaucrat.hpp>

class Form 
{
	private:
		const std::string	_name;
		bool				_isSigned;
		const size_t		_signGrade;
		const size_t		_execGrade;

	public:
		Form();
		Form(std::string const &name, size_t const signGrade, size_t const execGrade);
		Form(const Form &src);
		Form&	operator=(const Form &src);
		~Form();

		//exceptions
		class GradeTooHighException : public std::exception {
			public:
				const char *what() const noexcept override;
		};

		class GradeTooLowException : public std::exception {
			public:
				const char *what() const noexcept override;
		};

		//getters
		size_t				getSignGrade()	const;
		size_t				getExecGrade()	const;
		const std::string&	getName()		const;
		bool				getIsSigned()	const;
		void				beSigned(const Bureaucrat &b);
};

std::ostream& operator << (std::ostream& o, const Form& src);

#endif

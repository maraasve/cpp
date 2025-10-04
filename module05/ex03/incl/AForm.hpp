#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <Bureaucrat.hpp>
# include <stdexcept>

class AForm 
{
	private:
		const std::string	_name;
		bool				_isSigned;
		const size_t		_signGrade;
		const size_t		_execGrade;

	protected:
		AForm();
		AForm(std::string const &name, size_t const signGrade, size_t const execGrade);
		AForm(const AForm &src);
		AForm& operator=(const AForm &src);
		
		public:
		//exceptions
		class GradeTooHighException : public std::exception {
			public:
			const char *what() const noexcept override;
		};
		
		class GradeTooLowException : public std::exception {
			public:
			const char *what() const noexcept override;
		};

		class UnsignedFormException : public std::exception {
			public:
				const char *what() const noexcept override;
			};
			
			//getters
			size_t				getSignGrade()	const;
			size_t				getExecGrade()	const;
			const std::string&	getName()		const;
			bool				getIsSigned()	const;
			
		virtual ~AForm();
		//methods
		void				beSigned(const Bureaucrat& b);
		virtual void		execute(const Bureaucrat& executor) const;
		virtual void		formAction() const = 0;
};

std::ostream& operator << (std::ostream& o, const AForm& src);

#endif

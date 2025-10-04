#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>

class Form;

class Bureaucrat {
	private:
		const std::string	_name;
		size_t				_grade;

	public:
		//constructors and decontructors
		Bureaucrat();
		Bureaucrat(size_t grade);
		Bureaucrat(const std::string& name, size_t grade);
		Bureaucrat(const Bureaucrat& src);
		Bureaucrat& operator = (const Bureaucrat& src);
		~Bureaucrat();
		

		//exceptions
		class GradeTooHighException : public std::exception {
			public:
				const char *what() const noexcept override;
		};

		class GradeTooLowException : public std::exception {
			public:
				const char *what() const noexcept override;
		};
		
		size_t				getGrade() const;
		const std::string	&getName() const;
		void				incrementGrade();
		void				decrementGrade();
		void				signForm(Form &f);
};

std::ostream& operator << (std::ostream& o, const Bureaucrat& src);

#endif
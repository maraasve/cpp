#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <ShrubberyCreationForm.hpp>
# include <RobotomyRequestForm.hpp>
# include <PresidentialPardonForm.hpp>

class Intern {
	public:
		Intern();
		Intern(const Intern& src);
		Intern& operator=(const Intern& src);
		~Intern();

		AForm*	makeForm(const std::string& formName, const std::string& target) const;
		AForm*	pardonForm(const std::string &target) const;
		AForm*	robotomyForm(const std::string &target) const;
		AForm*	shrubberyForm(const std::string &target) const;
};

#endif

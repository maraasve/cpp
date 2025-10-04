#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include <fstream>
# include <AForm.hpp>

class ShrubberyCreationForm : public AForm {
	private:
		const std::string	_target;
		ShrubberyCreationForm();

	protected:
		void	formAction() const override;

	public:
		ShrubberyCreationForm(const std::string& target);
		ShrubberyCreationForm(const ShrubberyCreationForm& src);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& src);
		~ShrubberyCreationForm();

		const std::string&	getTarget() const;
};

#endif

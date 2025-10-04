#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <AForm.hpp>

class PresidentialPardonForm : public AForm {
	private:
		const std::string _target;
		PresidentialPardonForm();

	protected:
		void formAction() const;

	public:
		PresidentialPardonForm(const std::string& target);
		PresidentialPardonForm(const PresidentialPardonForm& src);
		PresidentialPardonForm& operator=(const PresidentialPardonForm& src);
		~PresidentialPardonForm();

		const std::string getTarget() const;
};

#endif

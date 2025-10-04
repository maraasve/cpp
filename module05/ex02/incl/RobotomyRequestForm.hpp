#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <AForm.hpp>
# include <math.h>

class RobotomyRequestForm : public AForm {
	private:
		const std::string _target;
		RobotomyRequestForm();

	protected:
		void formAction() const override;

	public:
		RobotomyRequestForm(const std::string& target);
		RobotomyRequestForm(const RobotomyRequestForm& src);
		RobotomyRequestForm& operator=(const RobotomyRequestForm& src);
		~RobotomyRequestForm();

		const std::string getTarget() const;
};

#endif

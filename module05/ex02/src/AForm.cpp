#include <AForm.hpp>

AForm::AForm(): _name("Anonymous"), _isSigned(false), _signGrade(150), _execGrade(150) {
	std::cout << "Default constructor called" << std::endl;
}

AForm::AForm(std::string const& name, size_t signGrade, size_t execGrade): _name(name), _isSigned(false), _signGrade(signGrade), _execGrade(execGrade) {
	if (_signGrade < 1 || _execGrade < 1) {
		throw GradeTooHighException();
	}
	if (_signGrade > 150 || _execGrade > 150) {
		throw GradeTooLowException();
	}
	std::cout << "AForm " << _name << " created with signgrade: " << _signGrade << " and execGrade " << _execGrade << std::endl;
}

AForm::~AForm() {
	std::cout << "Destructor called" << std::endl;
}

AForm::AForm(const AForm &src): _name(src.getName()), _isSigned(src.getIsSigned()), _signGrade(src.getSignGrade()), _execGrade(src.getExecGrade()){
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

AForm& AForm::operator=(const AForm &src) {
	if (this != &src) {
		_isSigned = src.getIsSigned();
	}
	return *this;
}

//getters
const std::string& AForm::getName() const {
	return _name;
}

bool AForm::getIsSigned() const {
	return _isSigned;
}

size_t AForm::getExecGrade() const {
	return _execGrade;
}

size_t AForm::getSignGrade() const {
	return _signGrade;
}

// methods
void AForm::beSigned(const Bureaucrat& b) {
	if (b.getGrade() > _signGrade) {
		throw GradeTooLowException();
	}
	_isSigned = true;
}

void AForm::execute(const Bureaucrat& executor) const{
	if (!_isSigned) {
		throw UnsignedFormException();
	}
	if(executor.getGrade() > _execGrade) {
		throw GradeTooLowException();
	}
	formAction();
}

// exceptions
const char* AForm::GradeTooHighException::what() const noexcept {
	return "Grade too high...";
} 

const char* AForm::GradeTooLowException::what() const noexcept {
	return "Grade too low...";
}

const char* AForm::UnsignedFormException::what() const noexcept {
	return "Form unsigned...";
}

// insertion operator overload
std::ostream& operator << (std::ostream& o, const AForm &src) {
	o << src.getName() << " AForm, signed: " << src.getIsSigned() << ", sign grade: " << src.getSignGrade() << ", exec grade: " << src.getExecGrade();
	return o;
}

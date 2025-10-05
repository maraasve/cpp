#include <Form.hpp>

Form::Form(): _name("Form"), _isSigned(false), _signGrade(150), _execGrade(150) {
	std::cout << "Form " << _name << " created with signgrade: " << _signGrade << " and execGrade " << _execGrade << std::endl;
}

Form::Form(std::string const& name, size_t signGrade, size_t execGrade): _name(name), _isSigned(false), _signGrade(signGrade), _execGrade(execGrade) {
	if (_signGrade < 1 || _execGrade < 1) {
		throw GradeTooHighException();
	}
	if (_signGrade > 150 || _execGrade > 150) {
		throw GradeTooLowException();
	}
	std::cout << "Form " << _name << " created with signgrade: " << _signGrade << " and execGrade " << _execGrade << std::endl;
}

Form::~Form() {
	std::cout << "Destructor called" << std::endl;
}

Form::Form(const Form &src): _name(src.getName()), _isSigned(src.getIsSigned()), _signGrade(src.getSignGrade()), _execGrade(src.getExecGrade()){
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Form& Form::operator=(const Form &src) {
	if (this != &src) {
		_isSigned = src.getIsSigned();
	}
	return *this;
}

// methods
const std::string& Form::getName() const {
	return _name;
}

bool Form::getIsSigned() const {
	return _isSigned;
}

size_t Form::getExecGrade() const {
	return _execGrade;
}

size_t Form::getSignGrade() const {
	return _signGrade;
}

void Form::beSigned(const Bureaucrat& b) {
	if (b.getGrade() > _signGrade) {
		throw GradeTooLowException();
	}
	_isSigned = true;
}

// exceptions
const char* Form::GradeTooHighException::what() const noexcept {
	return "Grade too high...";
} 

const char* Form::GradeTooLowException::what() const noexcept {
	return "Grade too low...";
}

// insertion operator overload
std::ostream& operator << (std::ostream& o, const Form &src) {
	o << src.getName() << " form, signed: " << src.getIsSigned() << ", sign grade: " << src.getSignGrade() << ", exec grade: " << src.getExecGrade();
	return o;
}

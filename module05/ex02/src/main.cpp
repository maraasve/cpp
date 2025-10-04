#include <ShrubberyCreationForm.hpp>

int main(void) {
	ShrubberyCreationForm testForm("test");
	Bureaucrat b(5);

	testForm.beSigned(b);
	testForm.execute(b);
}
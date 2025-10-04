#include <ShrubberyCreationForm.hpp>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137){
    std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("ShrubberyCreationForm", 145, 137), _target(target) {
    std::cout << "ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
   std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src) {
    std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& src) {
    std::cout << "Copy assignemt operator called" << std::endl;
    if (this != &src) {
        AForm::operator=(src);
    }
    return *this;
}

const std::string&   ShrubberyCreationForm::getTarget() const {
    return _target;
}

void ShrubberyCreationForm::formAction() const{
    std::ofstream ofs(_target  + "_shrubbery");
    if (!ofs) {
        throw std::runtime_error("Failed to create file...");
    }
    ofs << "               ,%%%%%%%," << std::endl;
    ofs << "       ,,,.   ,%%%%%%/%%,  .#######." << std::endl;
    ofs << "    ,&&&&%&&%,%%maraasve%%,####\\##/##" << std::endl;
    ofs << "   ,%&\\%&&%&&%,%%%\\/%%%/%%##\\#####/##'" << std::endl;
    ofs << "   %&&%&%&/%&&%%%\\%%/ /%%#####\\#####'" << std::endl;
    ofs << "   %&&%/ %&&&&&%%\\ V /%%' `##\\# `/##'" << std::endl;
    ofs << "   `&%\\ ` /%&'   |.|         |'|#'" << std::endl;
    ofs << "       |o|        | |         | |" << std::endl;
    ofs << "       |.|        | |         | |" << std::endl;
    ofs << "    \\\\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_" << std::endl;
    ofs.close();
}
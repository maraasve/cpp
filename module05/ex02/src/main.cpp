#include <ShrubberyCreationForm.hpp>
#include <PresidentialPardonForm.hpp>
#include <RobotomyRequestForm.hpp>
#include <colors.hpp>

int main() {

    /* ------------------ TEST 1 ------------------ */

	std::cout << GREEN << "---------- TEST 1 ----------- \n" << RESET << std::endl;
    std::cout << "Shrubbery Form, signable and executable" << std::endl;

    try {
        Bureaucrat bur("John", 10);
        ShrubberyCreationForm form("Home");
        form.beSigned(bur);
        form.execute(bur);
    } catch (std::exception &e) {
        std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
    }
    std::cout << "\n -------------------------- \n\n";
	std::cout << "\nPress Enter to continue...";
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');


    /* ------------------ TEST 2 ------------------ */

	std::cout << GREEN << "---------- TEST 2 ----------- \n" << RESET << std::endl;
    std::cout << "Should throw an exception -> Shrubbery Form, signable but not executable" << std::endl;

    try {
        Bureaucrat bur("John", 140);
        ShrubberyCreationForm form("Home");
        form.beSigned(bur);
        form.execute(bur);
    } catch (std::exception &e) {
        std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
    }
    std::cout << "\n -------------------------- \n\n";
	std::cout << "\nPress Enter to continue...";
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');


    /* ------------------ TEST 3 ------------------ */

	std::cout << GREEN << "---------- TEST 3 ----------- \n" << RESET << std::endl;
    std::cout << "Robotomy Form, signable and executable" << std::endl;
    try {
        Bureaucrat bur("John", 40);
        RobotomyRequestForm form("Chicken");
        form.beSigned(bur);
        form.execute(bur);
    } catch (std::exception &e) {
        std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
    }
    std::cout << "\n -------------------------- \n\n";
	std::cout << "\nPress Enter to continue...";
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');


    /* ------------------ TEST 4 ------------------ */

	std::cout << GREEN << "---------- TEST 4 ----------- \n" << RESET << std::endl;
    std::cout << "Should throw an exception -> Robotomy Form, signable but not executable" << std::endl;

    try {
        Bureaucrat bur("John", 50);
        RobotomyRequestForm form("Chicken");
        form.beSigned(bur);
        form.execute(bur);
    } catch (std::exception &e) {
        std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
    }
    std::cout << "\n -------------------------- \n\n";
	std::cout << "\nPress Enter to continue...";
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');


    /* ------------------ TEST 5 ------------------ */

	std::cout << GREEN << "---------- TEST 5 ----------- \n" << RESET << std::endl;
    std::cout << "Presidential Pardon Form, signable and executable" << std::endl;

    try {
        Bureaucrat bur("John", 4);
        PresidentialPardonForm form("Marvin");
        form.beSigned(bur);
        form.execute(bur);
    } catch (std::exception &e) {
        std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
    }
    std::cout << "\n -------------------------- \n\n";
	std::cout << "\nPress Enter to continue...";
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');


    /* ------------------ TEST 6 ------------------ */

	std::cout << GREEN << "---------- TEST 6 ----------- \n" << RESET << std::endl;
    std::cout << "Should throw an exception - > Presidential Pardon Form, signable but not executable" << std::endl;
   
    try {
        Bureaucrat bur("John", 20);
        PresidentialPardonForm form("Marvin");
        form.beSigned(bur);
        form.execute(bur);
    } catch (std::exception &e) {
        std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
    }
    std::cout << "\n -------------------------- \n\n";
	std::cout << "\nPress Enter to continue...";
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');


    /* ------------------ TEST 7 ------------------ */

	std::cout << GREEN << "---------- TEST 7 ----------- \n" << RESET << std::endl;
    std::cout << "Shrubbery Form, signable and executable" << std::endl;

    try {
        Bureaucrat bur("John", 10);
        ShrubberyCreationForm form("Home");
        form.beSigned(bur);
        form.execute(bur);
    } catch (std::exception &e) {
        std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
    }
    std::cout << "\n -------------------------- \n\n";
	std::cout << "\nPress Enter to continue...";
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');


    /* ------------------ TEST 8 ------------------ */

	std::cout << GREEN << "---------- TEST 8 ----------- \n" << RESET << std::endl;
    std::cout << "Should throw an exception -> Shrubbery Form, signable but not executable" << std::endl;

    try {
        Bureaucrat bur("John", 140);
        ShrubberyCreationForm form("Home");
        form.beSigned(bur);
        form.execute(bur);
    } catch (std::exception &e) {
        std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
    }
    std::cout << "\n -------------------------- \n\n";
	std::cout << "\nPress Enter to continue...";
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');


    /* ------------------ TEST 9 ------------------ */

	std::cout << GREEN << "---------- TEST 9 ----------- \n" << RESET << std::endl;
    std::cout << "Should throw an exception -> Robotomy Form, signable but not executable"
              << std::endl;
    try {
        Bureaucrat bur("John", 50);
        RobotomyRequestForm form("Chicken");
        form.beSigned(bur);
        form.execute(bur);
    } catch (std::exception &e) {
        std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
    }
    std::cout << "\n -------------------------- \n\n";
	std::cout << "\nPress Enter to continue...";
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');


    /* ------------------ TEST 10 ------------------ */

	std::cout << GREEN << "---------- TEST 10 ----------- \n" << RESET << std::endl;
    std::cout << "Should throw an exception -> Presidential Pardon Form, signable but not executable" << std::endl;

    try {
        Bureaucrat bur("John", 20);
        PresidentialPardonForm form("Marvin");
        form.beSigned(bur);
        form.execute(bur);
    } catch (std::exception &e) {
        std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
    }
    std::cout << std::endl;

    return 0;
}
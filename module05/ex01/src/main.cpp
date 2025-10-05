#include <Form.hpp>
#include <colors.hpp>

int main(void)
{
	/* ------------------ TEST 1 ------------------ */

	std::cout << GREEN << "---------- TEST 1 ----------- \n" << RESET << std::endl;
	std::cout << "Should throw an exception -> grade is too high" << std::endl;
	{
		try
		{
			Form form("A1", 0, 5);
			std::cout << form << std::endl;
		}
		catch(std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
		
	}

	std::cout << "\n -------------------------- \n\n";
	std::cout << "\nPress Enter to continue...";
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');


	/* ------------------ TEST 2 ------------------ */

	std::cout << GREEN << "\n\n---------- TEST 2 ----------- \n\n" << RESET << std::endl;
	std::cout << "Creates a form and signs it without exceptions\n" << std::endl;
	{
		try
		{
			Bureaucrat bob("Bob", 15);
			Form form("A2", 20, 45);
			std::cout << bob << std::endl;
			std::cout << form << std::endl;
			bob.signForm(form);
			std::cout << form << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	
	std::cout << "\n -------------------------- \n\n";
	std::cout << "\nPress Enter to continue...";
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');


	/* ------------------ TEST 3 ------------------ */

	std::cout << GREEN << "\n\n---------- TEST 3 ----------- \n\n" << RESET << std::endl;
	std::cout << "Tries to sign form, but grade is too low\n" << std::endl;
	{
		try
		{
			Bureaucrat bella("Bella", 35);
			Form form2("A3", 20, 45);
			std::cout << bella << std::endl;
			std::cout << form2 << std::endl;
			form2.beSigned(bella);
			std::cout << form2 << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	return (0);
}
#include <Bureaucrat.hpp>
#include <colors.hpp>

int main(void)
{
	/* ------------------ TEST 1 ------------------ */

	std::cout << GREEN << "---------- TEST 1 ----------- \n" << RESET << std::endl;
	std::cout << "Should throw an exception -> grade is too high" << std::endl;
	{
		try
		{
			Bureaucrat bob("Bob", 0);
			std::cout << bob << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << "\n -------------------------- \n\n";
	std::cout << "\nPress Enter to continue...";
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	

	/* ------------------ TEST 2 ------------------ */

	std::cout << GREEN << "\n\n---------- TEST 2 ----------- \n\n" << RESET << std::endl;
	std::cout << "Should throw an exception -> grade is too low\n" << std::endl;
	{
		try
		{
			Bureaucrat jim("Jim", 151);
			std::cout << jim << std::endl;
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
	std::cout << "Should throw an exception after incrementGrade -> grade is too high\n" << std::endl;
	{	
		try 
		{
			Bureaucrat hank("Hank", 3);
			std::cout << hank << std::endl;
			hank.incrementGrade(); //grade 2
			std::cout << hank << std::endl;
			hank.incrementGrade(); //grade 1
			std::cout << hank << std::endl;
			hank.incrementGrade(); //grade 0 -> exception
			std::cout << hank << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	std::cout << "\n -------------------------- \n\n";
	std::cout << "\nPress Enter to continue...";
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');


	/* ------------------ TEST 4 ------------------ */

	std::cout << GREEN << "\n\n---------- TEST 4 ----------- \n\n" << RESET << std::endl;
	std::cout << "Should throw an exception after decrementGrade -> grade is too low\n" << std::endl;
	{	
		try
		{
			Bureaucrat bella("Bella", 149);
			std::cout << bella << std::endl;
			bella.decrementGrade(); // 150
			std::cout << bella << std::endl;
			bella.decrementGrade(); // 151 -> exception
			std::cout << bella << std::endl;
			bella.decrementGrade();
			std::cout << bella << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	return (0);
}
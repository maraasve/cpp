#include "Bureaucrat.hpp"

int main(void)
{
	/* Throw exception when calling constructor with grade too high */
	{
		try
		{
			Bureaucrat mike("Mike", 0);
			std::cout << mike << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	std::cout << "\n --------------------- \n\n";

	/* Throw exception when calling constructor with grade too low */
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

	std::cout << "\n --------------------- \n\n";
	
	/* Throw exeception when calling incrementGrade() */
	{	
		try 
		{
			Bureaucrat dur("Dur", 3);
			std::cout << dur << std::endl;
			dur.incrementGrade(); //grade 2
			std::cout << dur << std::endl;
			dur.incrementGrade(); //grade 1
			std::cout << dur << std::endl;
			dur.incrementGrade(); //grade 0 -> exception
			std::cout << dur << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	std::cout << "\n --------------------- \n\n";

	/* Throw exeception when calling derementGrade */
	{	
		try
		{
			Bureaucrat alan("Alan", 149);
			std::cout << alan << std::endl;
			alan.decrementGrade(); // 150
			std::cout << alan << std::endl;
			alan.decrementGrade(); // 151 -> exception
			std::cout << alan << std::endl;
			alan.decrementGrade();
			std::cout << alan << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	return (0);
}
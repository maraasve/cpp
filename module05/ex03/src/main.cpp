#include <Intern.hpp>
#include <colors.hpp>

int main() {

    {
        Intern someRandomIntern;
        AForm *rrf;
        rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        if (rrf) {
            Bureaucrat bur("John", 2);
            rrf->beSigned(bur);
            rrf->execute(bur);
            delete rrf;
        }
    }

    /* ------------------------------------ */

    std::cout << "------------------------------------------" << std::endl;

    /* ------------------------------------ */

    {
        Intern someRandomIntern;
        AForm *rrf;
        rrf = someRandomIntern.makeForm("pardon request", "Bender");
        if (rrf) {
            Bureaucrat bur("John", 2);
            rrf->beSigned(bur);
            rrf->execute(bur);
            delete rrf;
        }
    }

    /* ------------------------------------ */

    std::cout << "------------------------------------------" << std::endl;

    /* ------------------------------------ */

    {
        Intern someRandomIntern;
        AForm *rrf;
        rrf = someRandomIntern.makeForm("shrubbery request", "Bender");
        if (rrf) {
            Bureaucrat bur("John", 2);
            rrf->beSigned(bur);
            rrf->execute(bur);
            delete rrf;
        }
    }

    /* ------------------------------------ */

    std::cout << "------------------------------------------" << std::endl;

    /* ------------------------------------ */

    {
        Intern someRandomIntern;
        AForm *rrf;
        rrf = someRandomIntern.makeForm("another request", "Bender");
        if (rrf) {
            Bureaucrat bur("John", 2);
            rrf->beSigned(bur);
            rrf->execute(bur);
            delete rrf;
        }
    }

    return 0;
}
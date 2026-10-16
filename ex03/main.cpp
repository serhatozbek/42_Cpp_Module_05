#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include <iostream>

int main()
{
    std::cout << "=== Intern form factory ===" << std::endl;

    Intern someRandomIntern;
    
    AForm* form1;
    AForm* form2;
    AForm* form3;
    AForm* form4;

    form1 = someRandomIntern.makeForm("shrubbery creation", "Bender");
    form2 = someRandomIntern.makeForm("robotomy request", "Bender");
    form3 = someRandomIntern.makeForm("presidential pardon", "Bender");
    form4 = someRandomIntern.makeForm("coffee making", "Bender");

    Bureaucrat boss("The Boss", 1);

    if (form1)
    {
        boss.signForm(*form1);
        boss.executeForm(*form1);
    }
    if (form2)
    {
        boss.signForm(*form2);
        boss.executeForm(*form2);
    }
    if (form3)
    {
        boss.signForm(*form3);
        boss.executeForm(*form3);
    }
    if (!form4)
    {
        std::cout << "The unknown form name was rejected by the intern." << std::endl;
    }


    delete form1;
    delete form2;
    delete form3;
    delete form4;

    return 0;
}
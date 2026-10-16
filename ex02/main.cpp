#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>

int main()
{

    srand(time(NULL));

    Bureaucrat boss("The Boss", 1);
    Bureaucrat midGuy("Mid Manager", 50);
    Bureaucrat intern("Intern", 150);

    std::cout << boss << std::endl;
    std::cout << midGuy << std::endl;
    std::cout << intern << std::endl;

    std::cout << "\n--------------------------------------------------------" << std::endl;
    std::cout << "                 FORMS CREATED                 " << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;

    ShrubberyCreationForm shrub("home");
    RobotomyRequestForm robo("Bender");
    PresidentialPardonForm pardon("Ford Prefect");

    std::cout << "\n=== 1. An unsigned form cannot be executed ===" << std::endl;
    try {
        boss.executeForm(shrub);
    } catch (std::exception &e) {
        std::cout << "Expected exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== 2. Shrubbery creation form ===" << std::endl;
    try {
        intern.signForm(shrub);
        midGuy.signForm(shrub);
    } catch (std::exception &e) {
        std::cout << "Expected exception: " << e.what() << std::endl;
    }
    try {
        std::cout << "The intern cannot execute the form because the execution grade is too low." << std::endl;
        intern.executeForm(shrub);
    } catch (std::exception &e) {
        std::cout << "Expected exception: " << e.what() << std::endl;
    }
    try {
        midGuy.executeForm(shrub);
    } catch (std::exception &e) {
        std::cerr << "Unexpected exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== 3. Robotomy request form (50% success chance) ===" << std::endl;
    try {
        midGuy.signForm(robo);
        boss.executeForm(robo);
        boss.executeForm(robo);
        boss.executeForm(robo);
    } catch (std::exception &e) {
        std::cerr << "Unexpected exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== 4. Presidential pardon form ===" << std::endl;
    try {
        midGuy.signForm(pardon);
    } catch (std::exception &e) {
        std::cout << "Expected exception: " << e.what() << std::endl;
    }
    try {
        boss.signForm(pardon);
        boss.executeForm(pardon);
    } catch (std::exception &e) {
        std::cerr << "Unexpected exception: " << e.what() << std::endl;
    }

    std::cout << "\n--------------------------------------------------------" << std::endl;
    std::cout << "                    TESTS FINISHED                    " << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;

    return 0;
}
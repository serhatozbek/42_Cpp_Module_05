#include "Intern.hpp"

Intern::Intern() {
    std::cout << "Intern default constructor called." << std::endl;
}
Intern::Intern(const Intern& other) {
    std::cout << "Intern copy constructor called." << std::endl;
    (void)other;
}
Intern& Intern::operator=(const Intern& other) {
    std::cout << "Intern copy assignment operator called." << std::endl;
    (void)other;
    return *this;
}
Intern::~Intern() {
}

AForm* Intern::makeForm(std::string formName, std::string target) {
    std::string formNames[] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };

    AForm* newForm = NULL;
    int index = -1;
    for (int i = 0; i < 3; i++) {
        if (formNames[i] == formName) {
            index = i;
            break;
        }
    }

    switch (index) {
        case 0:
            newForm = new ShrubberyCreationForm(target);
            break;
        case 1:
            newForm = new RobotomyRequestForm(target);
            break;
        case 2:
            newForm = new PresidentialPardonForm(target);
            break;
        default:
            std::cerr << "Intern couldn't create form: '" << formName << "' does not exist!" << std::endl;
            return NULL;
    }

    std::cout << "Intern creates " << newForm->getName() << std::endl;
    return newForm;
}
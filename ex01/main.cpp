#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main()
{
    std::cout << "=== Form creation and signing ===" << std::endl;
    try {
        Form taxForm("Tax form", 50, 25);
        std::cout << "Created: " << taxForm << std::endl;
    } 
    catch (const std::exception &exception) {
        std::cerr << "Unexpected exception: " << exception.what() << std::endl;
    }

    std::cout << "\n=== Form constructor validation ===" << std::endl;
    try {
        Form invalidSignGrade("Invalid sign grade", 0, 50);
        (void)invalidSignGrade;
    } 
    catch (const std::exception &exception) {
        std::cout << "Sign grade 0 rejected: " << exception.what() << std::endl;
    }

    try {
        Form invalidExecuteGrade("Invalid execute grade", 50, 151);
        (void)invalidExecuteGrade;
    } 
    catch (const std::exception &exception) {
        std::cout << "Execute grade 151 rejected: " << exception.what() << std::endl;
    }

    std::cout << "\n=== Signing permissions ===" << std::endl;
    try {
        Bureaucrat intern("Intern", 100);
        Form confidentialForm("Confidential form", 50, 20);

        std::cout << "Before the signing attempt: " << confidentialForm << std::endl;
        intern.signForm(confidentialForm);
        std::cout << "After the signing attempt: " << confidentialForm << std::endl;
    } 
    catch (const std::exception &exception) {
        std::cerr << "Unexpected exception: " << exception.what() << std::endl;
    }

    std::cout << "\n=== Successful signing ===" << std::endl;
    try {
        Bureaucrat manager("Manager", 10);
        Form leaveRequest("Leave request", 50, 20);

        std::cout << "Before the signing attempt: " << leaveRequest << std::endl;
        manager.signForm(leaveRequest);
        std::cout << "After the signing attempt: " << leaveRequest << std::endl;
    } 
    catch (const std::exception &exception) {
        std::cerr << "Unexpected exception: " << exception.what() << std::endl;
    }

    return 0;
}
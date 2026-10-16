#include "Bureaucrat.hpp"

int main()
{
    std::cout << "=== Bureaucrat: grade management ===" << std::endl;

    try
    {
        Bureaucrat employee("Alice", 75);
        std::cout << "Initial state: " << employee << std::endl;
        employee.incrementGrade();
        std::cout << "After promotion: " << employee << std::endl;
        employee.decrementGrade();
        std::cout << "After demotion: " << employee << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Unexpected exception: " << e.what() << std::endl;
    }

    
    try
    {
        Bureaucrat invalidHigh("Invalid high grade", 0);
        (void)invalidHigh;
    }
    catch(const std::exception& e)
    {
        std::cout << "Grade 0 rejected: " << e.what() << std::endl;
    }

    try
    {
        Bureaucrat invalidLow("Invalid low grade", 151);
        (void)invalidLow;
    }
    catch(const std::exception& e)
    {
        std::cout << "Grade 151 rejected: " << e.what() << std::endl;
    }

    try {
        Bureaucrat highest("Highest-ranked bureaucrat", 1);
        std::cout << highest << std::endl;
        highest.incrementGrade();
    } 
    catch (std::exception &e) {
        std::cout << "Promotion above grade 1 rejected: " << e.what() << std::endl;
    }


    try {
        Bureaucrat lowest("Lowest-ranked bureaucrat", 150);
        std::cout << lowest << std::endl;
        lowest.decrementGrade();
    } 
    catch (std::exception &e) {
        std::cout << "Demotion below grade 150 rejected: " << e.what() << std::endl;
    }

    return 0;
    
}
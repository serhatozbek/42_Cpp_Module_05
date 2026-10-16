#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>

#include <exception>
class Bureaucrat;

class Form
{
private:
    const std::string _name;
    bool _signed;
    const int _signedGrade;
    const int _execGrade;

public:
    Form();
    Form(const std::string& name, int signedGrade, int execGrade);
    Form(const Form& other);
    Form& operator=(const Form& other);
    ~Form();

    std::string getName() const;
    bool getSigned() const;
    int getExecGrade() const;
    int getSignedGrade() const;

    void beSigned(const Bureaucrat& bureaucrat);

    class GradeTooLowException : public std::exception {
        public:
            virtual const char* what() const throw();
    };

    class GradeTooHighException : public std::exception {
        public:
            virtual const char* what() const throw();
    };
};
std::ostream& operator<<(std::ostream& os, const Form& form);

#endif
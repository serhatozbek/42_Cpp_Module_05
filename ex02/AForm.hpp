#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <iostream>
#include <exception>
class Bureaucrat;
class AForm
{
private:
    const std::string _name;
    bool _signed;
    const int _signedGrade;
    const int _execGrade;

public:
    AForm();
    AForm(const std::string& name, int signedGrade, int execGrade);
    AForm(const AForm& other);
    AForm& operator=(const AForm& other);
    virtual ~AForm();

    std::string getName() const;
    bool getSigned() const;
    int getExecGrade() const;
    int getSignedGrade() const;

    void beSigned(const Bureaucrat& bureucrat);
    void execute(Bureaucrat const & executor) const;
    class GradeTooLowException : public std::exception {
        public:
            virtual const char* what() const throw();
    };

    class GradeTooHighException : public std::exception {
        public:
            virtual const char* what() const throw();
    };

    class FormNotSignedException : public std::exception{
        public:
            virtual const char* what() const throw();
    };

    protected:
    virtual void executeAction() const = 0;
};

#endif
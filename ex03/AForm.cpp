#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(): _name("default"), _signed(false), _signedGrade(150), _execGrade(150) {}

AForm::AForm(const std::string& name, int signedGrade, int execGrade) 
    : _name(name), _signed(false), _signedGrade(signedGrade), _execGrade(execGrade) {
    if (signedGrade < 1 || execGrade < 1)
        throw AForm::GradeTooHighException();
    if (signedGrade > 150 || execGrade > 150)
        throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm& other) 
    : _name(other._name), _signed(other._signed), _signedGrade(other._signedGrade), _execGrade(other._execGrade) {}

AForm& AForm::operator=(const AForm& other) {
    if (this != &other) {
        this->_signed = other._signed;
    }
    return *this;
}

AForm::~AForm() {
}

std::string AForm::getName() const {
    return this->_name;
}

bool AForm::getSigned() const {
    return this->_signed;
}

int AForm::getExecGrade() const {
    return this->_execGrade;
}

int AForm::getSignedGrade() const {
    return this->_signedGrade;
}

void AForm::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() > _signedGrade)
        throw AForm::GradeTooLowException();

    _signed = true;
}

const char* AForm::GradeTooHighException::what() const throw() {
    return "Grade is too high!";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "Grade is too low!";
}

const char* AForm::FormNotSignedException::what() const throw() {
    return "Form is not signed!";
}

void AForm::execute(Bureaucrat const & executor) const {
    if (!this->getSigned())
        throw AForm::FormNotSignedException();

    if (executor.getGrade() > this->getExecGrade())
        throw AForm::GradeTooLowException();
        
    this->executeAction();
}
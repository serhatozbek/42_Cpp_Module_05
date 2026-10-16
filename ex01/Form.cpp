#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(): _name("default"), _signed(false), _signedGrade(150), _execGrade(150) {}

Form::Form(const std::string& name, int signedGrade, int execGrade) : _name(name), _signed(false), _signedGrade(signedGrade), _execGrade(execGrade) {
    if(_signedGrade > 150 || _execGrade > 150)
        throw Form::GradeTooLowException();
    else if(_signedGrade < 1 || _execGrade < 1)
        throw Form::GradeTooHighException();
}

Form::Form(const Form& other) : _name(other._name), _signed(other._signed), _signedGrade(other._signedGrade), _execGrade(other._execGrade) {
}

Form& Form::operator=(const Form& other) {
    if (this != &other) {
        this->_signed = other._signed;
    }
    return *this;
}

Form::~Form(){};

void Form::beSigned(const Bureaucrat& bureaucrat){
    if (bureaucrat.getGrade() > _signedGrade)
        throw Form::GradeTooLowException();
    _signed = true;
}

std::string Form::getName() const{
    return _name;
}

bool Form::getSigned() const{
    return _signed;
}

int Form::getExecGrade() const{
    return _execGrade;
}
int Form::getSignedGrade() const {
    return _signedGrade;
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Grade is too low!";
}

const char* Form::GradeTooHighException::what() const throw() {
    return "Grade is too high!";
}
std::ostream& operator<<(std::ostream& os, const Form& form)
{
    os << "Form name: " << form.getName() << "\n"
    << "Signed status: " << (form.getSigned() ? "YES" : "NO") << "\n"
    << "Grade to sign: " << form.getSignedGrade() << "\n"
    << "Grade to execute: " << form.getExecGrade();
    return os;
 }
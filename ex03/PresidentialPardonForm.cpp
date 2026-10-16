#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), _target("default"){
  std::cout << "PresidentialPardonForm default constructor called."<< std::endl;
} 
PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm",25,5),_target(target){
    std::cout << "PresidentialPardonForm constructor called. Target: " << _target << std::endl; 
}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) :  AForm(other), _target(other._target){
    std::cout << "PresidentialPardonForm copy constructor called." << std::endl;
} 
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
    if(this != &other){
        AForm::operator=(other);
        this->_target = other._target;
    }
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm(){}

void PresidentialPardonForm::executeAction() const{
    std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
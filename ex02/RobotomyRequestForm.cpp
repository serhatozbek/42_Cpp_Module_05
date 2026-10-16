#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("default"){
  std::cout << "RobotomyRequestForm default constructor called."<< std::endl;
}
RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm",72,45),_target(target){
    std::cout << "RobotomyRequestForm constructor called. Target: " << _target << std::endl; 
}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) :  AForm(other), _target(other._target){
    std::cout << "RobotomyRequestForm copy constructor called." << std::endl;
} 
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
    if(this != &other){
        AForm::operator=(other);
        this->_target = other._target;
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm(){}

void RobotomyRequestForm::executeAction() const{
    std::cout << "* Bzzzzzzzt! Vrrrrrrrrr! * (Drilling noises)" << std::endl;
    
    if (rand() % 2 == 0) {
        std::cout << this->_target << " has been robotomized successfully!" << std::endl;
    } else {
        std::cout << "Robotomy failed on " << this->_target << "!" << std::endl;
    }
}
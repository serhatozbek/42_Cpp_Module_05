#ifndef PresidentialPARDONFORM_HPP
#define PresidentialPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {

    private:
        std::string _target;
    protected:
        void executeAction() const;    
    public:
        PresidentialPardonForm();
        PresidentialPardonForm(std::string target);
        PresidentialPardonForm(const PresidentialPardonForm& other);
        PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
        ~PresidentialPardonForm();
};
#endif
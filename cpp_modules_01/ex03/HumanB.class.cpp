#include "HumanB.class.hpp"
#include "Weapon.class.hpp"

HumanB::HumanB(std::string name) : _name(name){
}

HumanB::~HumanB(void){
}

void	HumanB::attack(void) const{
	std::cout << this->_name << " attacks with his " << this->_weapon->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon &set){
	this->_weapon = &set;
}

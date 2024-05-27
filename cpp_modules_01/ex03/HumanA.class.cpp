#include "HumanA.class.hpp"
#include "Weapon.class.hpp"

HumanA::HumanA(std::string name, Weapon &set) : _name(name), _weapon(set){
}

HumanA::~HumanA(void){
}

void	HumanA::attack(void) const{
	std::cout << this->_name << " attacks with his " << this->_weapon.getType() << std::endl;
}

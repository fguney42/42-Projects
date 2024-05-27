#include "zombie.class.hpp"

Zombie::Zombie(void){
	
	return;
}

Zombie::~Zombie(void){
	
	return;
}

void	Zombie::announce(void){
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName(std::string name){
	this->_name = name;
}

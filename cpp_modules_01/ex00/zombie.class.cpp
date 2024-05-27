#include "zombie.class.hpp"

Zombie::Zombie(std::string init_name){
	std::cout << "Create a zombie" << std::endl;
	this->_name = init_name;
	return;
}

Zombie::~Zombie(void){
	std::cout << "kill " << this->_name << " the zombie!" << std::endl;
	return;
}

void	Zombie::announce(void){
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

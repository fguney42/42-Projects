#include "zombie.class.hpp"
#include <iostream>
#include <string>

Zombie*	newZombie(std::string name);
void	randomChump(std::string name);
	
int		main(void)
{
	Zombie	*zombie;

	zombie = newZombie("Heap");
	zombie->announce();
	delete zombie;
	randomChump("Stack");
	return (0);
}

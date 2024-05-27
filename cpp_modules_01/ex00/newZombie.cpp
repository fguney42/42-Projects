#include "zombie.class.hpp"

Zombie*	newZombie(std::string name){
	Zombie	*zombie;

	zombie = new Zombie(name);
	return (zombie);
}
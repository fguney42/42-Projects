#ifndef HUMANB_CLASS_HPP
# define HUMANB_CLASS_HPP
# include <iostream>
# include "Weapon.class.hpp"

class HumanB
{
public:

	HumanB(std::string name);
	~HumanB(void);

	void			attack(void) const;
	void			setWeapon(Weapon &set);
	
private:

	std::string		_name;
	Weapon			*_weapon;

};

#endif

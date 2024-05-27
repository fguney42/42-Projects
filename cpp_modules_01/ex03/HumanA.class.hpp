#ifndef HUMANA_CLASS_HPP
# define HUMANA_CLASS_HPP
# include <iostream>
# include "Weapon.class.hpp"

class HumanA
{
public:

	HumanA(std::string name, Weapon &set);
	~HumanA(void);

	void			attack(void) const;
	
private:

	std::string		_name;
	Weapon			&_weapon;

};

#endif

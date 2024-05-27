#ifndef ZOMBIE_CLASS_HPP
# define ZOMBIE_CLASS_HPP
# include <iostream>

class Zombie
{
public:

	
	Zombie(void);
	~Zombie(void);

	
	void		announce(void);
	
	void		setName(std::string name);
	
private:

	
	std::string _name;

};

#endif

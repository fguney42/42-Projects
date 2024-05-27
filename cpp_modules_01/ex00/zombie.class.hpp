#ifndef ZOMBIE_CLASS_HPP
# define ZOMBIE_CLASS_HPP
# include <iostream>

class Zombie
{
public:

	
	Zombie(std::string init_name);
	~Zombie(void);

	
	void		announce(void);
	
private:

	
	std::string _name;

};

#endif

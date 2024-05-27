#include "Harl.hpp"


Harl::Harl()
{
}

Harl::~Harl()
{
}

void Harl::print_message(void) const
{
	std::cout << _message << std::endl;
}

void Harl::debug(void)
{
	_message = "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!";
	print_message();
}

void Harl::info(void)
{
	_message = "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!";
	print_message();
}

void Harl::warning(void)
{
	_message = "I think I deserve to have extra bacon for free. I've been coming here for years and you just started working here last month.";
	print_message();
}

void Harl::error(void)
{
	_message = "This is unacceptable, I want to speak to the manager now.";
	print_message();
}

void Harl::complain(std::string level)
{
	void (Harl::*functions[4])(void);

	functions[0] = &Harl::debug;
	functions[1] = &Harl::info;
	functions[2] = &Harl::warning;
	functions[3] = &Harl::error;

	for (static int i = 0; i < 4; i++)
	{
		(this->*functions[i])();
		return;
	}
}

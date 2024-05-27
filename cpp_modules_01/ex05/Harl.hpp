#ifndef Harl_HPP
#define Harl_HPP

#include <iostream>
#include <string>

class Harl
{
	public:
		Harl();
		~Harl();
		void complain(std::string level);

	private:
		void print_message(void) const;
		void debug(void);
		void info(void);
		void warning(void);
		void error(void);
		std::string _message;
};

#endif

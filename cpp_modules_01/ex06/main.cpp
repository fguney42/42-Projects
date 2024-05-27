#include "Harl.hpp"

int main(int argc, char **argv)
{
	Harl harl;

	if (argc != 2)
		std::cout << "Usage : ./harlFilter [Level]" << std::endl;
	else
		harl.complain(argv[1]);

	return 0;
}

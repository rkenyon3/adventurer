#include <iostream>

#include "config.h"
#include "manager.h"


int main(int argc, char * argv[])
{
	std::cout << "Adventurer Version " << VERSION_MAJOR << "." << VERSION_MINOR
	          << std::endl;
	
	Manager manager = Manager();
	manager.run();

	std::cout << "\n\nRun completed" << std::endl;
}


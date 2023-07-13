#ifndef MANAGER_H
#define MANAGER_H

#include <iostream>
#include <vector>

#include "presenter.h"
#include "text.h"

class Manager{
	public:
		Manager();
		void run();
	
	private:
		Presenter* presenter;
};

#endif


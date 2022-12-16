#pragma once

#include <iostream>

class Vector
{
	private:
		// number of elements in tab
		int	size;
		// size of tab (how much we need to malloc)
		int	capacity;
	public:
		vector();
		~vector();
};
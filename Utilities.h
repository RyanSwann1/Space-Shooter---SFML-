#ifndef UTILITIES_H
#define UTILITIES_H


#include <random>

namespace Utilities
{ 
	inline int getRandomNumber(const int a, const int b)
	{
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<> dis(a, b);

		return dis(gen);
	}

	inline void getWorkingDirectory(const std::string& id)
	{

	}
}
#endif // !UTILITIES_H


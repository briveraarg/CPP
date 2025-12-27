#ifndef B_HPP
#define B_HPP

#include "Base.hpp"

class B : public Base
{
	public:
		B() {}
		B(const B& other) : Base(other) {}
		B& operator=(const B& other) { 
			if (this != &other)
				Base::operator=(other);
			return *this; 
		}
		~B() {}
};

#endif

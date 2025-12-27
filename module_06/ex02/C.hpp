#ifndef C_HPP
#define C_HPP

#include "Base.hpp"

class C : public Base
{
	public:
		C() {}
		C(const C& other) : Base(other) {}
		C& operator=(const C& other) { 
			if (this != &other)
				Base::operator=(other);
			return *this; 
		}
		~C() {}
};

#endif

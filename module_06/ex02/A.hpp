#ifndef A_HPP
#define A_HPP

#include "Base.hpp"

class A : public Base
{
	public:
		A() {}
		A(const A& other) : Base(other) {}
		A& operator=(const A& other) { 
			if (this != &other)
				Base::operator=(other);
			return *this; 
		}
		~A() {}
};

#endif

#pragma once
#include <stdexcept>

class OutOfBoundsException :
    public std::logic_error
{

public:
	OutOfBoundsException():logic_error("Index out of bounds."){}
};


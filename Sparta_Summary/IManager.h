#pragma once

#include <iostream>
#include <string>
#include <algorithm>
#include "Book.h"

class IManager
{
public :
	virtual void displayBookInfo() = 0;
	virtual ~IManager() = default;
};
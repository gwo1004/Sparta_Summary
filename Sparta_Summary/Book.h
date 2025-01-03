#pragma once

#include "AbstractBook.h"

class Book : public AbstractBook
{
public :
	Book(const std::string& title, const std::string& author) : AbstractBook(title,author){}
};


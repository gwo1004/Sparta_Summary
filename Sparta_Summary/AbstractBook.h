#pragma once

#include <iostream>
#include <string>

class AbstractBook
{
public : 
	AbstractBook() = default;
	AbstractBook(const std::string& title, const std::string& author)
		: title(title), author(author) {}

	std::string getTitle() { return title; }
	std::string getAuthor() { return author; }
private:
	std::string title;
	std::string author;
public :
	~AbstractBook() = default;
};
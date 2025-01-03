#pragma once

#include <vector>
#include "IManager.h"

class BookManager : public IManager
{
public : 
	BookManager();

private:
	std::vector<Book> books;

public :
	void addBook(std::string title, std::string author);
	void displayBookInfo() override;

	Book* findBookByTitle(std::string title);
	std::vector<Book*> getBookByTitle(std::string title);
	std::vector<Book*> getBookByAuthor(std::string author);

	~BookManager();
};


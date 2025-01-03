#pragma once

#include <map>
#include <unordered_map>
#include "IManager.h"

class BorrowManager : public IManager
{
public : 
	BorrowManager();

private:
	std::unordered_map<std::string, int> stock;
	int quantity;

public :
	void initializeStock(Book book, int quantity = 3);
	void borrowBook(std::string title);
	void returnBook(std::string title);
	void displayBookInfo() override;

	~BorrowManager();
};


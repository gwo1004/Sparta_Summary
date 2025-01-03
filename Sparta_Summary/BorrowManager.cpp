#include "BorrowManager.h"

BorrowManager::BorrowManager()
{
}


void BorrowManager::initializeStock(Book book, int quantity)
{
	stock.insert(make_pair(book.getTitle(), quantity));
}

void BorrowManager::borrowBook(std::string title)
{
	auto it = stock.find(title);
	
	if (it == stock.end())
	{
		std::cout << "Not Valid Book. Borrow Failed." << std::endl;
		return;
	}

	if (it->second == 0)
	{
		std::cout << "Quantity Not Enough. Borrow Failed." << std::endl;
		return;
	}

	it->second--;
	std::cout << "Borrow Successed. " << std::endl;
	std::cout << "Title : " << it->first << std::endl;
	std::cout << "Quantity : " << it->second << std::endl;

}

void BorrowManager::returnBook(std::string title)
{
	auto it = stock.find(title);

	if (it == stock.end())
	{
		std::cout << "Not Valid Book. Return Failed." << std::endl;
		return;
	}

	it->second++;
	std::cout << "Return Successed. " << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "Book " << std::endl;
	std::cout << "Title : " << it->first << std::endl;
	std::cout << "Quantity : " << it->second << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
}

void BorrowManager::displayBookInfo()
{
	for (auto& it : stock)
	{
		std::cout << "Display All Books " << std::endl;
		std::cout << "---------------------------------------------" << std::endl;
		std::cout << "Book " << std::endl;
		std::cout << "Title : " << it.first << std::endl;
		std::cout << "Quantity : " << it.second << std::endl;
		std::cout << "---------------------------------------------" << std::endl;
	}
}

BorrowManager::~BorrowManager()
{
	stock.clear();
}

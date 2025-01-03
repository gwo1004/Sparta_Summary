#include "BookManager.h"

BookManager::BookManager()
{
}

Book* BookManager::findBookByTitle(std::string title)
{
	for (auto& book : books)
	{
		if (book.getTitle() == title)
		{
			return &book;
		}
	}
}

void BookManager::addBook(std::string title, std::string author)
{
	books.push_back(Book(title, author));
}

void BookManager::displayBookInfo()
{
	for (auto& book : books)
	{
		std::cout << "---------------------------------------------" << std::endl;
		std::cout << "Book  " << std::endl;
		std::cout << "Title : " << book.getTitle() << std::endl;
		std::cout << "Author : " << book.getAuthor() << std::endl;
		std::cout << "---------------------------------------------" << std::endl;
	}
}

std::vector<Book*> BookManager::getBookByTitle(std::string title)
{
	std::vector<Book*> result;

	for (auto& book : books)
	{
		if (book.getTitle().find(title) != std::string::npos) {
			result.push_back(&book);
			std::cout << "---------------------------------------------" << std::endl;
			std::cout << "Book  " << std::endl;
			std::cout << "Title : " << book.getTitle() << std::endl;
			std::cout << "Author : " << book.getAuthor() << std::endl;
			std::cout << "---------------------------------------------" << std::endl;
		}
	}

	return result;
}

std::vector<Book*> BookManager::getBookByAuthor(std::string author)
{
	std::vector<Book*> result;

	for (auto& book : books)
	{
		if (book.getAuthor().find(author) != std::string::npos) {
			result.push_back(&book);
			std::cout << "---------------------------------------------" << std::endl;
			std::cout << "Book  " << std::endl;
			std::cout << "Title : " << book.getTitle() << std::endl;
			std::cout << "Author : " << book.getAuthor() << std::endl;
			std::cout << "---------------------------------------------" << std::endl;
		}
	}

	return result;
}

BookManager::~BookManager()
{
	books.clear();
}

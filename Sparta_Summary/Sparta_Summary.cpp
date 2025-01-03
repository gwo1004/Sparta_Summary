#include <iostream>
#include "IManager.h"
#include "BookManager.h"
#include "BorrowManager.h"

int main() {

	BookManager* bookManager = new BookManager();
    BorrowManager* borrowManager = new BorrowManager();


	bookManager->addBook("God of Java1", "LeeSangMin");
	bookManager->addBook("God of Java2", "LeeSangMin");
	bookManager->addBook("Tobi Spring 3.1", "LeeIlMin");
	bookManager->addBook("Game Programming Pattern", "Rovert");
    bookManager->addBook("C++ Programming", "YoonSeongU");
    borrowManager->initializeStock(*bookManager->findBookByTitle("God of Java1"));
    borrowManager->initializeStock(*bookManager->findBookByTitle("God of Java2"));
    borrowManager->initializeStock(*bookManager->findBookByTitle("Tobi Spring 3.1"));
    borrowManager->initializeStock(*bookManager->findBookByTitle("Game Programming Pattern"));
    borrowManager->initializeStock(*bookManager->findBookByTitle("C++ Programming"));

    while (true) {
        std::cout << "\n도서관 관리 프로그램" << std::endl;
        std::cout << "1. 책 추가" << std::endl; 
        std::cout << "2. 모든 책 출력" << std::endl; 
        std::cout << "3. 책 제목 검색" << std::endl;
        std::cout << "4. 책 저자 검색" << std::endl;
        std::cout << "5. 책 대여 현황" << std::endl;
        std::cout << "6. 책 대여" << std::endl; 
        std::cout << "7. 책 반납" << std::endl;
        std::cout << "8. 종료" << std::endl;
        std::cout << "선택: ";

        int choice;
        std::cin >> choice;
        std::string title, author;

        if (choice == 1) {
            std::cout << "책 제목: ";
            std::cin.ignore();
            std::getline(std::cin, title);
            std::cout << "책 저자: ";
            std::getline(std::cin, author);
            bookManager->addBook(title, author);
            borrowManager->initializeStock(*bookManager->findBookByTitle(title));
        }
        else if (choice == 2) {
            bookManager->displayBookInfo();
        }
        else if (choice == 3) {
            std::cin.ignore();
            std::cout << "책 제목: ";
            std::getline(std::cin, title);
            bookManager->getBookByTitle(title);
        }
        else if (choice == 4) {
            std::cin.ignore();
            std::cout << "책 저자: ";
            std::getline(std::cin, author);
            bookManager->getBookByAuthor(author);
        }
        else if (choice == 5) {
            std::cin.ignore();
            std::cout << "책 대여 현황: ";
            borrowManager->displayBookInfo();
        }
        else if (choice == 6) {
            std::cin.ignore();
            std::cout << "책 대여: ";
            std::getline(std::cin, title);
            borrowManager->borrowBook(title);
        }
        else if (choice == 7) {
            std::cin.ignore();
            std::cout << "책 반납: ";
            std::getline(std::cin, title);
            borrowManager->returnBook(title);
        }
        else if (choice == 8) {
            std::cout << "프로그램을 종료합니다." << std::endl;
        }
        else {
            std::cout << "잘못된 입력입니다. 다시 시도하세요." << std::endl;
        }
    }
	return 0;

}
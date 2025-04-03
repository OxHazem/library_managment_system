#include "D:\DownLoad\projects\OOPproject\classes\header_files\library.h"
#include "D:\DownLoad\projects\OOPproject\classes\header_files\librarian.h"
#include "D:\DownLoad\projects\OOPproject\classes\header_files\member.h"
#include <iostream>
#include <memory>
#include <limits>

// Function declarations
// Menu function implementations
void displayMainMenu() {
    std::cout << "\n===== LIBRARY MANAGEMENT SYSTEM =====\n"
              << "1. Librarian Login\n"
              << "2. Member Login\n"
              << "3. Search Books\n"
              << "4. Exit\n"
              << "Enter your choice: ";
}

void librarianMenu(Librarian& librarian, Library& library) {
    int choice;
    do {
        std::cout << "\n===== LIBRARIAN MENU =====\n"
                  << "1. Add Book\n"
                  << "2. Remove Book\n"
                  << "3. View All Books\n"
                  << "4. Back to Main Menu\n"
                  << "Enter your choice: ";
        
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choice) {
            case 1: librarian.addBook(library.getBooks()); break;
            case 2: {
                std::vector<Book>& books = const_cast<std::vector<Book>&>(library.getBooks());
                librarian.removeBook(books);
                break;
            }
            case 3: librarian.displayAllBooks(library.getBooks()); break;
            case 4: return;
            default: std::cout << "Invalid choice!\n";
        }
    } while (true);
}

void memberMenu(Member& member, Library& library) {
    int choice;
    do {
        std::cout << "\n===== MEMBER MENU =====\n"
                  << "1. Borrow Book\n"
                  << "2. Return Book\n"
                  << "3. View Borrowed Books\n"
                  << "4. Back to Main Menu\n"
                  << "Enter your choice: ";
        
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choice) {
            case 1: {
                int bookId;
                std::cout << "Enter Book ID to borrow: ";
                std::cin >> bookId;
                library.borrowBook(bookId, member.getUserId());
                break;
            }
            case 2: {
                int bookId;
                std::cout << "Enter Book ID to return: ";
                std::cin >> bookId;
                library.returnBook(bookId, member.getUserId());
                break;
            }
            case 3: member.displayBorrowedBooks(library.getBooks()); break;
            case 4: return;
            default: std::cout << "Invalid choice!\n";
        }
    } while (true);
}
int main() {
    Library library;

    
    library.addUser(std::unique_ptr<User>(new Librarian(1, "Admin", "admin@library.com")));
    library.addUser(std::unique_ptr<User>(new Member(2, "John Doe", "john@example.com")));
    
    Book book1(101, "C++ Programming", "Bjarne Stroustrup", 5);
    Book book2(102, "Clean Code", "Robert Martin", 3);
    

    Librarian* admin = dynamic_cast<Librarian*>(library.getUser(1));
    if (admin) {
        std::vector<Book>& books = const_cast<std::vector<Book>&>(library.getBooks());
        books.push_back(book1);
        books.push_back(book2);
    }

    
    int choice;
    do {
        displayMainMenu();
        while (!(std::cin >> choice) || choice < 1 || choice > 4) {
            std::cout << "Invalid choice. Enter 1-4: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        switch (choice) {
            case 1: {  // Librarian Login
                Librarian* librarian = dynamic_cast<Librarian*>(library.getUser(1));
                if (librarian) {
                    librarianMenu(*librarian, library);
                } else {
                    std::cout << "Librarian not found!\n";
                }
                break;
            }
            case 2: {  // Member Login
                Member* member = dynamic_cast<Member*>(library.getUser(2));
                if (member) {
                    memberMenu(*member, library);
                } else {
                    std::cout << "Member not found!\n";
                }
                break;
            }
            case 3:  // Search Books
                library.searchBook();
                break;
            case 4:  // Exit
                std::cout << "Exiting the system...\n";
                break;
        }
    } while (choice != 4);

    return 0;
}

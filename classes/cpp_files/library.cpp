#include "D:\DownLoad\projects\OOPproject\classes\header_files\library.h"
#include "D:\DownLoad\projects\OOPproject\classes\header_files\librarian.h"
#include "D:\DownLoad\projects\OOPproject\classes\header_files\member.h"
#include <algorithm>

Book* Library::findBook(int bookId) {
    auto it = std::find_if(books.begin(), books.end(), 
                         [bookId](const Book& b) { return b.getBookId() == bookId; });
    return it != books.end() ? &(*it) : nullptr;
}

User* Library::getUser(int userId) {
    auto it = std::find_if(users.begin(), users.end(), 
                         [userId](const std::unique_ptr<User>& u) { 
                             return u->getUserId() == userId; 
                         });
    return it != users.end() ? it->get() : nullptr;
}

void Library::addUser(std::unique_ptr<User> user) {
    if (getUser(user->getUserId())) {
        std::cout << "User ID already exists!\n";
        return;
    }
    users.push_back(std::move(user));
    std::cout << "User added successfully!\n";
}

void Library::borrowBook(int bookId, int userId) {
    Book* book = findBook(bookId);
    if (!book) {
        std::cout << "Book not found!\n";
        return;
    }

    User* user = getUser(userId);
    if (!user || user->getRole() != "Member") {
        std::cout << "Invalid member ID.\n";
        return;
    }

    Member* member = dynamic_cast<Member*>(user);
    if (member->hasBorrowed(bookId)) {
        std::cout << "You already borrowed this book.\n";
        return;
    }

    if (book->getAvailableCopies() > 0) {
        member->borrowBook(bookId);
        book->decreaseCopies();
        std::cout << "Book borrowed successfully!\n";
    } else {
        std::cout << "No copies available.\n";
    }
}

void Library::returnBook(int bookId, int userId) {
    Book* book = findBook(bookId);
    if (!book) {
        std::cout << "Book not found!\n";
        return;
    }

    User* user = getUser(userId);
    if (!user || user->getRole() != "Member") {
        std::cout << "Invalid member ID.\n";
        return;
    }

    Member* member = dynamic_cast<Member*>(user);
    if (!member->hasBorrowed(bookId)) {
        std::cout << "You haven't borrowed this book.\n";
        return;
    }

    member->returnBook(bookId);
    book->increaseCopies();
    std::cout << "Book returned successfully!\n";
}

void Library::searchBook() const {
    if (books.empty()) {
        std::cout << "No books available.\n";
        return;
    }

    std::string title;
    std::cout << "Enter book title to search: ";
    std::cin.ignore();
    std::getline(std::cin, title);

    bool found = false;
    for (const auto& book : books) {
        if (book.getTitle().find(title) != std::string::npos) {
            book.displayBookInfo();
            std::cout << "-----------------\n";
            found = true;
        }
    }

    if (!found) {
        std::cout << "No books found with that title.\n";
    }
}

const std::vector<Book>& Library::getBooks() const { 
    return books; 
}
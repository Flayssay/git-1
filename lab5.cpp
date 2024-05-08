#include <iostream>
#include <string>
using namespace std;

class Book {
protected:
    string author;
    string title;
    int pages;
    int year;

public:
    Book(string author, string title, int pages, int year) : author(author), title(title), pages(pages), year(year) {}
    void display() {
        cout << "Author: " << author << endl;
        cout << "Title: " << title << endl;
        cout << "Pages: " << pages << endl;
        cout << "Year: " << year << endl;
    }
};

class LibraryBook : public Book {
private:
    string location;
    bool borrowed;

public:
    LibraryBook(string author, string title, int pages, int year, string location, bool borrowed)
        : Book(author, title, pages, year), location(location), borrowed(borrowed) {}

    void display() {
        Book::display(); 
        cout << "Location: " << location << endl;
        cout << "Borrowed: " << (borrowed ? "Yes" : "No") << endl;
    }
    void borrowBook() {
        borrowed = true;
    }
    void returnBook() {
        borrowed = false;
    }
};

int main() {
   
    LibraryBook book1("Taras Shevchenko", "Kobzar", 200, 2020, "A1", false);
    cout << "Info about book:" << endl;
    book1.display();

  
    return 0;
}

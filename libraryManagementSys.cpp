#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Book Class
class Book {
private:
    int id;
    string title;
    string author;
    bool isIssued;

public:
    Book(int i, string t, string a) {
        id = i;
        title = t;
        author = a;
        isIssued = false;
    }

    int getId() {
        return id;
    }

    string getTitle() {
        return title;
    }

    string getAuthor() {
        return author;
    }

    bool getIsIssued() {
        return isIssued;
    }

    void issue() {
        isIssued = true;
    }

    void returnBook() {
        isIssued = false;
    }
};

// Abstract User Class
class User {
protected:
    int userId;
    string name;

public:
    User(int id, string n) {
        userId = id;
        name = n;
    }

    int getUserId() {
        return userId;
    }

    string getName() {
        return name;
    }

    virtual void showUserType() = 0;
};

// Student Class derived from User
class Student : public User {
public:
    Student(int id, string n) : User(id, n) {}

    void showUserType() {
        cout << "User Type: Student" << endl;
    }
};

// Library Class
class Library {
private:
    vector<Book> books;
    vector<Student> students;

public:
    void addBook(int id, string title, string author) {
        books.push_back(Book(id, title, author));
        cout << "Book added successfully." << endl;
    }

    void registerStudent(int id, string name) {
        students.push_back(Student(id, name));
        cout << "Student registered successfully." << endl;
    }

    void issueBook(int bookId) {
        for (int i = 0; i < books.size(); i++) {
            if (books[i].getId() == bookId) {
                if (!books[i].getIsIssued()) {
                    books[i].issue();
                    cout << "Book issued successfully." << endl;
                } else {
                    cout << "Book is already issued." << endl;
                }
                return;
            }
        }
        cout << "Book not found." << endl;
    }

    void returnBook(int bookId) {
        for (int i = 0; i < books.size(); i++) {
            if (books[i].getId() == bookId) {
                if (books[i].getIsIssued()) {
                    books[i].returnBook();
                    cout << "Book returned successfully." << endl;
                } else {
                    cout << "Book was not issued." << endl;
                }
                return;
            }
        }
        cout << "Book not found." << endl;
    }

    void showAllBooks() {
        cout << "\nLibrary Books:" << endl;
        for (int i = 0; i < books.size(); i++) {
            cout << "ID: " << books[i].getId()
                 << ", Title: " << books[i].getTitle()
                 << ", Author: " << books[i].getAuthor()
                 << ", Issued: " << (books[i].getIsIssued() ? "Yes" : "No") << endl;
        }
    }
    void showIssuedBooks() {
    cout << "\nIssued Books:" << endl;
    for (int i = 0; i < books.size(); i++) {
        if (books[i].getIsIssued()) {
            cout << "ID: " << books[i].getId()
                 << ", Title: " << books[i].getTitle()
                 << ", Author: " << books[i].getAuthor() << endl;
        }
    }
}

};

// Main Function
int main() {
    Library lib;

    // Adding Books
    lib.addBook(101, "Wings of Fire", "A.P.J Abdul Kalam");
    lib.addBook(102, "India After Gandhi", "Ramachandra Guha");
    lib.addBook(103, "Train to Pakistan", "Khushwant Singh");
    lib.addBook(104, "The White Tiger", "Aravind Adiga");
    lib.addBook(105, "God of Small Things", "Arundhati Roy");
    lib.addBook(106, "Midnight's Children", "Salman Rushdie");
    lib.addBook(107, "The Guide", "R.K. Narayan");
    lib.addBook(108, "A Suitable Boy", "Vikram Seth");
    lib.addBook(109, "Gitanjali", "Rabindranath Tagore");
    lib.addBook(110, "The Discovery of India", "Jawaharlal Nehru");

    // Registering Students
    lib.registerStudent(1, "Keshav");
    lib.registerStudent(2, "Abhijit");
    lib.registerStudent(3, "Prithvi");
    lib.registerStudent(4, "Amit");

    // Showing all books
    lib.showAllBooks();

    // Sample Issue/Return Operations
    lib.issueBook(101);
    lib.issueBook(104);
    lib.showIssuedBooks();
    lib.showAllBooks();

    lib.returnBook(101);
    lib.showAllBooks();

    return 0;
}

#include <iostream>
#include <cstring> 
using namespace std;

class Book {
private:
    char* title_;
    char* author_;

public:
    Book(const char* title, const char* author) : title_(nullptr), author_(nullptr) {
        title_ = new char[strlen(title) + 1];
        strcpy(title_, title);
        
        author_ = new char[strlen(author) + 1];
        strcpy(author_, author);

        cout << "Constructor called: " << title_ << " by " << author_ << endl;
    }

    Book(const Book& other) : title_(nullptr), author_(nullptr) {
        title_ = new char[strlen(other.title_) + 1];
        strcpy(title_, other.title_);
        
        author_ = new char[strlen(other.author_) + 1];
        strcpy(author_, other.author_);

        cout << "Copy constructor called: " << title_ << " by " << author_ << endl;

    }

    Book& operator=(const Book& other) {
        if (this != &other) {
            delete[] title_;
            delete[] author_;

            title_ = new char[strlen(other.title_) + 1];
            strcpy(title_, other.title_);
            
            author_ = new char[strlen(other.author_) + 1];
            strcpy(author_, other.author_);

            cout << "Copy assignment operator called: " << title_ << " by " << author_ << endl;
        }
        return *this;
    }

    ~Book() {
        delete[] title_;
        delete[] author_;
        cout << "Destructor called" << endl;
    }

};

int main() {

    Book book1("Career Elevator", "Shozab Mehdi");
    Book book2 = book1; 
    Book book3("Naiki", "Ahmed");
    book3 = book2; 
    return 0;
}

#ifndef __Library
#define __Library

#include "book.hpp"

class Library
{
    private:
        Book* array;
        int size;
        int capacity;
        void copy(Library& other);
   
    //public:
        bool addBook(Book& book, bool write);
        bool removeBook(String& title, bool full);
        void printLib();
        Book* findBookByTitle(String title);
        Book* findBookByAuthor(String author);
        Book* findBookByISBN(String ISBN);
        Book* findBookByDescription(String description);
        Library getSortedByTitle(bool asc);
        Library getSortedByAuthor(bool asc);
        Library getSortedByRating(bool asc);
    public:
        Library();
        ~Library();
        Library(Library&);
        Library& operator=(Library& other);
    friend class CommandsInterface;
    friend int main();


};
#endif
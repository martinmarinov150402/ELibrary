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
   
    public:
        void addBook(Book& book);
        bool removeBook(String& title, bool full);
        void printLib();
        Book* findBookByTitle(String title);
        Book* findBookByAuthor(String author);
        Book* findBookByISBN(String ISBN);
        Book* findBookByDescription(String description);
        Library getSortedByTitle(bool asc);
        Library getSortedByAuthor(bool asc);
        Library getSortedByRating(bool asc);
        Library();
        ~Library();
        Library(Library&);
        Library& operator=(Library& other);


};
#endif
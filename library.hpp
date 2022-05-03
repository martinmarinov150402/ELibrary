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
        void printBook(int idx, bool lines);
        bool findBookByCriteria();
        Library();
        ~Library();
        Library(Library&);
        Library& operator=(Library& other);


};
#include "string.h"
#include <fstream>

class Book
{
    private:
        int rating;
        String author;
        String title;
        String fileName;
        String shortDesc;
        String ISBN;
    public:
        void writeInFile(std::ofstream& out);
        bool readFromFile(std::ifstream& in);
        static bool removeFromFile(String& _title, bool full);
        String getTitle();
        String getFileName();
        String getISBN();
        String getAuthor();
        String getDescription();
        int getRating();
        void printBook(bool lines);
        void printInfo();
        Book();
};
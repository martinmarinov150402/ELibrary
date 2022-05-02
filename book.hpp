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
        Book();
};
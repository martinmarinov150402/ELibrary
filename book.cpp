#include <iostream>
#include <fstream>
#include "string.h"
#include "book.hpp"

void Book::writeInFile(std::ofstream& out)
{
    out.write((char*)&rating, sizeof(rating));
    author.writeInFile(out);
    title.writeInFile(out);
    fileName.writeInFile(out);
    shortDesc.writeInFile(out);
    ISBN.writeInFile(out);
}
bool Book::readFromFile(std::ifstream& in)
{
    bool flag = true;
    flag = flag && in.read((char*)&rating, sizeof(rating));
    flag = flag && author.readFromFile(in) && title.readFromFile(in) && fileName.readFromFile(in) && shortDesc.readFromFile(in) && ISBN.readFromFile(in);
    return flag;
}
bool Book::removeFromFile(String& _title, bool full)
{
    bool flag = false;
    std::ofstream tmpFile;
    tmpFile.open("tmp.dat", std::ios::binary);
    std::ifstream in;
    in.open("books.dat", std::ios::binary);
    if(tmpFile && in)
    {
        Book tmp;
        while(tmp.readFromFile(in))
        {
            if(tmp.title == _title)
            {
                flag = true;
                if(full)
                {
                    remove(tmp.fileName.getData());
                }
            }
            else
            {
                tmp.writeInFile(tmpFile);
            }
        }
    }
    tmpFile.close();
    in.close();
    remove("books.dat");
    rename("tmp.dat", "books.dat");
    return flag;
}
Book::Book()
{
    std::cin>>rating;
    author.readLine(std::cin);
    title.readLine(std::cin);
    std::cin>>fileName;
    shortDesc.readTillEOF(std::cin);
    std::cin>>ISBN;


}
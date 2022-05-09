#include <iostream>
#include <fstream>
#include "string.h"
#include "book.hpp"

bool isDelimiter(char c)
{
    if(c == '.' || c == '!' || c == '?' || c == ':')
    {
        return true;
    }
    else
    {
        return false;
    }
}
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
void Book::printInfo()
{
    std::cout<<title<<", "<<author<<", ISBN:"<<ISBN<<std::endl;
}
void Book::printBook(bool lines)
{
    String tmp;
    std::ifstream in;
    in.open(getFileName().getData());
    if(in)
    {
        if(lines)
        {
            
            while(in)
            {
                tmp.readLine(in);
                if(tmp=="#")break;
                std::cout<<tmp<<"\n";
                std::cin.get();
            }
            
        }
        else
        {
            char c;
            while(in.get(c))
            {
                if(c!='#') std::cout<<c;
                if(isDelimiter(c))
                {
                    std::cin.get();
                }
            }
        }
    }
    else
    {
        std::cout<<"File not fould!";
    }
    
}
String Book::getAuthor()
{
    return author;
}
String Book::getDescription()
{
    return shortDesc;
}
String Book::getISBN()
{
    return ISBN;
}
String Book::getTitle()
{
    return title;
}
String Book::getFileName()
{
    return fileName;
}
int Book::getRating()
{
    return rating;
}
bool Book::removeFromFile(String& _title, bool full)
{
    bool flag = false;
    std::ofstream tmpFile;
    tmpFile.open("tmp.dat", std::ios::binary);
    std::ifstream in;
    in.open("library.dat", std::ios::binary);
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
    remove("library.dat");
    rename("tmp.dat", "library.dat");
    return flag;
}
Book::Book()
{
    
    rating = 1;
    author = "UNKNOWN";
    title = "BOOK";
    fileName = "NOFILE";
    shortDesc = "IOK";

}
void Book::readFromCin()
{
    std::cout<<"Въведете рейтинг: ";
    std::cin>>rating;
    std::cin.ignore();
    std::cout<<"Въведете автор: ";
    author.readLine(std::cin);
    std::cout<<"Въведете заглавие: ";
    title.readLine(std::cin);
    std::cout<<"Въведете име на файл в който е записана книгата: ";
    fileName.readLine(std::cin);
    std::cout<<"Въведете ISBN на книгата: ";
    std::cin>>ISBN;
    std::cout<<"Въведете кратко описание на книгата: \n";
    shortDesc.readLine(std::cin);
}
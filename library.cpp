#include "library.hpp"
#include "string.h"
#include <fstream>

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
void Library::addBook(Book& book)
{
    if(size == capacity)
    {
        capacity *= 2;
        Book* tmp = array;
        array = new Book[capacity];
        for(int i = 0; i < size; i++)
        {
            array[i] = tmp[i];
        }
        delete[] tmp;
    }
    array[size++] = book;
    std::ofstream out;
    out.open("library.dat", std::ios::binary);
    if(out)
    {
        book.writeInFile(out);
    }
}
bool Library::removeBook(String& title, bool full)
{
    int idx = 0;
    bool flag = false;
    for(int i = 0; i < size; i++)
    {
        if(array[i].getTitle() == title)
        {
            idx = i;
            flag = true;
            break;
        }
    }
    if(flag)
    {
        array[idx] = array[size-1];
        size--;
        Book::removeFromFile(title, full);
    }
    return flag;
}
Library::Library()
{
    capacity = 10;
    size = 0;
    array = new Book[capacity];
}
Library::~Library()
{
    delete[] array;
}
void Library::copy(Library& other)
{
    capacity = other.capacity;
    size = other.size;
    array = new Book[capacity];
    for(int i = 0; i < size; i++)
    {
        array[i] = other.array[i];
    }
}
Library::Library(Library& other)
{
    copy(other);
}
Library& Library::operator=(Library& other)
{
    if(this != &other)
    {
        delete[] array;
        copy(other);
    }
    return *this;
}
void Library::printBook(int idx, bool lines)
{
    String tmp;
    if(idx >= 0 && idx < size)
    {
        std::ifstream in;
        in.open(array[idx].getFileName().getData());
        if(in)
        {
            if(lines)
            {
                while(in)
                {
                    tmp.readLine(in);
                    std::cout<<tmp<<"\n";
                    std::cin.get();
                }
                
            }
            else
            {
                char c;
                while(in.get(c))
                {
                    std::cout<<c;
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
    else
    {
        std::cout<<"Book not found!";
    }
    
}
#include "library.hpp"
#include "string.h"
#include <fstream>

bool Library::addBook(Book& book)
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
        return out.good();
    }
    return false;
}

void Library::printLib()
{
    for(int i = 0; i < size; i++)
    {
        array[i].printInfo();
    }
}
String toLowerCase(String str)
{
    for(int i = 0; i < str.Size(); i++)
    {
        if(str[i]>='A' && str[i]<='Z')
        {
            str[i] -= 32;
        }
    }
    return str;
}
Book* Library::findBookByTitle(String title)
{
    String title1;
    title1 = toLowerCase(title).getData();
    for(int i =  0; i < size; i++)
    {
        String tit;
        tit = array[i].getTitle().getData();
        String cur ;
        cur = toLowerCase(tit).getData();
        if(cur == title1)
        {
            return &array[i];
        }
    }
    return nullptr;
}
Book* Library::findBookByAuthor(String author)
{
    String author1;
    author1 = toLowerCase(author).getData();
    for(int i =  0; i < size; i++)
    {
        String aut;
        aut = array[i].getAuthor().getData();
        String cur;
        cur  = toLowerCase(aut).getData();
        if(cur == author1)
        {
            return &array[i];
        }
    }
    return nullptr;
}
Library Library::getSortedByTitle(bool asc)
{
   Library result = *this;
   for(int i = 0; i < result.size; i++)
   {
       for(int j = i+1; j < result.size; j++)
       {
           String sec; 
           sec = result.array[j].getTitle().getData();
           if((result.array[i].getTitle() > sec) == asc )
           {
               //std::swap(result.array[i], result.array[j]);
                Book tmp = result.array[i];
                result.array[i] = result.array[j];
                result.array[j] = tmp;
           }
       }
   }
   return result;
}
Library Library::getSortedByAuthor(bool asc)
{
   Library result = *this;
   for(int i = 0; i < result.size; i++)
   {
       for(int j = i+1; j < result.size; j++)
       {
           String sec; 
           sec = result.array[j].getAuthor().getData();
           if((result.array[i].getAuthor() > sec) == asc )
           {
                Book tmp = result.array[i];
                result.array[i] = result.array[j];
                result.array[j] = tmp;
           }
       }
   }
   return result;
}
Library Library::getSortedByRating(bool asc)
{
   Library result = *this;
   for(int i = 0; i < result.size; i++)
   {
       for(int j = i+1; j < result.size; j++)
       {
           if((result.array[i].getRating() > result.array[i].getRating()) == asc )
           {
                Book tmp = result.array[i];
                result.array[i] = result.array[j];
                result.array[j] = tmp;
           }
       }
   }
   return result;
}
Book* Library::findBookByISBN(String ISBN)
{
    String ISBN1;
    ISBN1 = toLowerCase(ISBN).getData();
    for(int i =  0; i < size; i++)
    {
        String isbn;
        isbn = array[i].getISBN().getData();
        String cur;
        cur  = toLowerCase(isbn).getData();
        if(cur == ISBN1)
        {
            return &array[i];
        }
    }
    return nullptr;
}
Book* Library::findBookByDescription(String description)
{
    for(int i = 0; i < size; i++)
    {
        String desc1;
        desc1 = toLowerCase(description).getData();
        String d2;
        d2 = array[i].getDescription().getData();
        String desc2;
        desc2 = toLowerCase(d2).getData();
        if(desc2.hasSubstring(desc1))
        {
            return &array[i];
        }
    }
    return nullptr;
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

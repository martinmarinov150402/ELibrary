#include <iostream>
#include "CommandsInterface.hpp"
#include "string.h"
#include "library.hpp"

void CommandsInterface::printHelp()
{
    std::cout<<"Available commands: \n" 
             <<"listByAuthor - Извежда сортиран списък от книги спрямо автора\n"
             <<"listByTitle - Извежда сортиран списък от книги спрямо заглавието\n"
             <<"listByRating - Извежда сортиран списък от книги спрямо рейтинг \n"
             <<"findBookByTitle - Намира книга по заглавие\n"
             <<"findBookByAuthor - Намира книга по автор \n"
             <<"findBookByISBN - Намира книга по ISBN\n"
             <<"findBookByDesc - Намира книга по част от описание\n"
             <<"addBook - Добавя нова книга в библиотеката\n"
             <<"removeBook - Премахва книга от библиотеката\n"
             <<"printBook - Извежда книга\n";
}
void CommandsInterface::runCommand(Library& lib, String command)
{
    if(command == "listByAuthor")
    {
        std::cout<<"Да бъдат ли в нарастващ ред: (1 - да / 0 - не)\n";
        bool asc;
        std::cin>>asc;
        lib.getSortedByAuthor(asc).printLib();
    }
    else if(command == "listByTitle")
    {
        std::cout<<"Да бъдат ли в нарастващ ред: (1 - да / 0 - не)\n";
        bool asc;
        std::cin>>asc;
        lib.getSortedByTitle(asc).printLib();
    }
    else if(command == "listByRating")
    {
        std::cout<<"Да бъдат ли в нарастващ ред: (1 - да / 0 - не)\n";
        bool asc;
        std::cin>>asc;
        lib.getSortedByRating(asc).printLib();
    }
    else if(command == "findBookByTitle")
    {
        std::cout<<"Заглавие: ";
        String title;
        std::cin>>title;
        Book* found = lib.findBookByTitle(title);
        if(found != nullptr)
        {
            found->printInfo();
            std::cout<<found->getDescription()<<std::endl;
        }
        else
        {
            std::cout<<"Грешка: Книгата не е намерена";
        }
    }
    else if(command == "findBookByAuthor")
    {
        std::cout<<"Автор: ";
        String author;
        std::cin>>author;
        Book* found = lib.findBookByAuthor(author);
        if(found != nullptr)
        {
            found->printInfo();
            std::cout<<found->getDescription()<<std::endl;
        }
        else
        {
            std::cout<<"Грешка: Няма намерена книга на този автор";
        }
    }
    else if(command == "findBookByISBN")
    {
        std::cout<<"ISBN: ";
        String ISBN;
        std::cin>>ISBN;
        Book* found = lib.findBookByISBN(ISBN);
        if(found != nullptr)
        {
            found->printInfo();
            std::cout<<found->getDescription()<<std::endl;
        }
        else
        {
            std::cout<<"Грешка: Няма намерена книга с този ISBN";
        }
    }
}
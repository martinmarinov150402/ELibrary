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
CommandsInterface::CommandsInterface()
{
    adminPassword = "topSecretPass123";
}
void CommandsInterface::runCommand(Library& lib, String command)
{
    if(command == "listByAuthor")
    {
        std::cout<<"Да бъдат ли в нарастващ ред: (1 - да / 0 - не)\n";
        bool asc;
        String boolf;
        boolf.readLine(std::cin);
        asc = boolf[0] - '0';
        lib.getSortedByAuthor(asc).printLib();
    }
    else if(command == "listByTitle")
    {
        std::cout<<"Да бъдат ли в нарастващ ред: (1 - да / 0 - не)\n";
        bool asc;
        String boolf;
        boolf.readLine(std::cin);
        asc = boolf[0] - '0';
        lib.getSortedByTitle(asc).printLib();
    }
    else if(command == "listByRating")
    {
        std::cout<<"Да бъдат ли в нарастващ ред: (1 - да / 0 - не)\n";
        bool asc;
        String boolf;
        boolf.readLine(std::cin);
        asc = boolf[0] - '0';
        lib.getSortedByRating(asc).printLib();
    }
    else if(command == "findBookByTitle")
    {
        std::cout<<"Заглавие: ";
        String title;
        title.readLine(std::cin);
        Book* found = lib.findBookByTitle(title);
        if(found != nullptr)
        {
            std::cout<<found->getDescription()<<std::endl;
        }
        else
        {
            std::cout<<"Грешка: Книгата не е намерена\n";
        }
    }
    else if(command == "findBookByAuthor")
    {
        std::cout<<"Автор: ";
        String author;
        author.readLine(std::cin);
        Book* found = lib.findBookByAuthor(author);
        if(found != nullptr)
        {
            found->printInfo();
            std::cout<<found->getDescription()<<std::endl;
        }
        else
        {
            std::cout<<"Грешка: Няма намерена книга на този автор\n";
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
            std::cout<<"Грешка: Няма намерена книга с този ISBN\n";
        }
    }
    else if(command == "findBookByDesc")
    {
        std::cout<<"Въведете част от описанието: \n";
        String sdesc;
        sdesc.readLine(std::cin);
        Book* found = lib.findBookByDescription(sdesc);
        if(found != nullptr)
        {
            found->printInfo();
            std::cout<<found->getDescription()<<std::endl;
        }
        else
        {
            std::cout<<"Грешка: Няма намерена книга с такова описание\n";
        }
    }
    else if(command == "addBook")
    {   
        String pass;
        std::cout<<"Администраторска парола: ";
        pass.readLine(std::cin);
        if(pass == adminPassword)
        {
            Book newBook;
            newBook.readFromCin();
            bool added = lib.addBook(newBook, true);
            if(added)
            {
                std::cout<<"Книгата е добавена успешно!\n";
            }
            else
            {
                std::cout<<"Грешка: Книгата не можа да бъде добавена.\n";
            }
        }
        else
        {
            std::cout<<"Грешна администраторска парола!\n";
        }
    }
    else if(command == "removeBook")
    {
        String pass;
        std::cout<<"Администраторска парола: ";
        pass.readLine(std::cin);
        if(pass == adminPassword)
        {
            std::cout<<"Въведете заглавие на книгата която искате да премахнете: ";
            String title;
            title.readLine(std::cin);
            bool full;
            std::cout<<"Въведете дали искате изтриването да е пълно: (1 - да, 0 - не): ";
            String boolf;
            boolf.readLine(std::cin);
            full = boolf[0] - '0';
            bool success = lib.removeBook(title,full);
            if(success)
            {
                std::cout<<"Книгата е успешно премахната!\n";
            }
            else
            {
                std::cout<<"Грешка: Книгата не можа да се премахне!\n";
            }
        }
        else
        {
            std::cout<<"Грешна администраторска парола!\n";
        }
    }
    else if(command == "printBook")
    {
        std::cout << "Въведете заглавие: ";
        String title;
        title.readLine(std::cin);
        std::cout << "Как да се изведе? По редове или по изречения? (1 - по редове, 0 - по изречения): ";
        bool lines;
        String linesBuff;
        linesBuff.readLine(std::cin);
        lines = linesBuff[0] - '0';
        std::cout<<"Title:"<<title<<std::endl;
        Book* b = lib.findBookByTitle(title);
        if(b != nullptr)
        {
            lib.findBookByTitle(title)->printBook(lines);
        }
        else
        {
            std::cout<<"Книгата не е намерена!"<<std::endl;
        }
    }
    else
    {
        std::cout<<"Невалидна команда!\n";
    }

}

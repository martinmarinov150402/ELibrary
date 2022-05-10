#include "string.h"
#include "library.hpp"
#include "CommandsInterface.hpp"
#include <iostream>
#include <fstream>
#include <cstring>
#include <limits>

int main()
{
    CommandsInterface cli;
    Library lib;
    Book tmp;
    std::ifstream libf;
    libf.open("library.dat",std::ios::binary);
    if(libf)
    {
        //bool flag = false;
        while(tmp.readFromFile(libf))
        {
            lib.addBook(tmp, false);
            /*flag = true;
            break;*/
        }
    }
    String command;
    cli.printHelp();
    while(!(command == "exit"))
    {
        std::cout<<"Enter command: ";
        //std::cin.clear();
        //std::cin.ignore(std::numeric_limits<std::streamsize>::max(), EOF);
        while(std::cin.peek() == EOF)
        {
            std::cin.get();
        }
        std::cin.seekg(0);
        std::cin.clear();
        /*int s;
        s = std::cin.get();
        std::cout<<s<<std::endl;*/
        std::cin>>command;
        if(!(command=="exit"))
        {
            cli.runCommand(lib, command);      
        }
    }
}   
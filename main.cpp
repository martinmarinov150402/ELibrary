#include "string.h"
#include "library.hpp"
#include "CommandsInterface.hpp"
#include <iostream>
#include <fstream>
#include <cstring>
#include <limits>

int main()
{
    Library lib;
    String command;
    CommandsInterface::printHelp();
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
        std::cout<<command<<std::endl;
        if(!(command=="exit"))
        {
            CommandsInterface::runCommand(lib, command);      
        }
    }
}   
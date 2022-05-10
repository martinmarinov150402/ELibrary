#ifndef __COMIFACE
#define __COMIFACE

#include "string.h"
#include "library.hpp"

class CommandsInterface
{
    private:
        String adminPassword;
    public:
        void printHelp();
        void runCommand(Library& lib, String command);
        CommandsInterface();
};
#endif
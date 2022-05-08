#ifndef __COMIFACE
#define __COMIFACE

#include "string.h"
#include "library.hpp"

class CommandsInterface
{
    public:
        static void printHelp();
        static void runCommand(Library& lib, String command);
};
#endif
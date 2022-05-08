#include "string.h"
#include "library.hpp"

class CommandsInterface
{
    static void printHelp();
    static void runCommand(Library& lib, String command);
};
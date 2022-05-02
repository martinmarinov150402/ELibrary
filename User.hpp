#include <iostream>
#include "string.h"

#ifndef USER_HPP
#define USER_HPP

class User
{
    private:
        String username;
        String passHash;
        String email;
    public:
        static User* registerUser(String& _username, String& _password, String& _email);
        static User* loginUser(String _username, String _password);


};
#endif
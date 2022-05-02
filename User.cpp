#include <fstream>
#include <openssl/sha.h>
#include <cstring>
#include "User.hpp"

User* User::registerUser(String& _username, String& _password, String& _email)
{
    User* newUser = new User();
    newUser->username = _username;
    unsigned char* hashtmp = new unsigned char[65];
    SHA256((const unsigned char*)_password.getData(),_password.Size(),hashtmp);
    char* h = (char*) hashtmp;
    newUser->passHash = h;
    std::cout<<newUser->passHash<<std::endl;
    newUser->email = _email;
    std::ofstream fout;
    fout.open("user.db",std::ios::app|std::ios::binary);
    if(fout)
    {
        newUser->username.writeInFile(fout);
        newUser->passHash.writeInFile(fout);
        newUser->email.writeInFile(fout);
    }
    fout.close();
    return newUser;
}
User* User::loginUser(String _username, String _password)
{
    User* tmp = new User;
    bool flag = false;
    std::ifstream fin;
    fin.open("user.db",std::ios::binary);
    bool flag1 = true;
    while(!fin.eof() && flag1)
    {
        flag1 = flag1 && tmp->username.readFromFile(fin);
        flag1 = flag1 && tmp->passHash.readFromFile(fin);
        flag1 = flag1 && tmp->email.readFromFile(fin);
        
        unsigned char* hashtmp = new unsigned char[65];
        SHA256((const unsigned char*)_password.getData(),_password.Size(),hashtmp);
        String hash;
        
        hash = (char*)hashtmp;
        if(_username == tmp->username && hash == tmp->passHash)
        {
            flag = true;
            break;
        }
    }
    if(flag)
    {
        return tmp;
    }
    else
    {
        return nullptr;
    }
}
#include "User.hpp"
#include "string.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include "emailValidation.h"

int main()
{
    //BuildAutomat();
    String em1,em2,em3,em4;
    em1 = "martinmarinov150402@gmail.com";
    em2 = "1vancho!@abv..bg";
    em3 = "mariika@abv@as.bg";
    em4 = "ivan@abv.";
    std::cout<<validateEmail(em1)<<validateEmail(em2)<<validateEmail(em3)<<validateEmail(em4)<<std::endl;
    String uname, password,email;
    uname = "martin";
    password = "12345";
    email = "martinmarinov150402@gmail.com";
    String uname2, pass2, email2;
    uname2 = "BaiIvan";
    pass2 = "1234";
    email2 = "baiivan@gmail.com";
    User* tmp = User::loginUser(uname2,pass2);
    //User::registerUser(uname2,pass2,email2);
    std::cout << tmp;    

}   
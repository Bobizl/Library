#include"User.h"
#include<fstream>

User::User(std::string Username , std::string Password, bool Level_of_access)
{
  this->Username=Username;
  this->Password=Password;
  this->Level_of_access=Level_of_access;
}

void User::Input()
{
   std::cout<<"Input Username = ";
   std::cin>>Username;
   std::cout<<"Input password = ";
   std::cin>>Password;
   std::cout<<"Input Level of access = ";
   std::cin>>Level_of_access;
}

void User::Output()
{
    std::cout<<Username<<std::endl;
    std::cout<<Password<<std::endl;
    std::cout<<Level_of_access<<std::endl;
}
User::User()
{

}

User::~User()
{

  
}


User::User(const User& A)//coppy constructor
{
  this->Username=A.Username;
  this->Password=A.Password;
  this->Level_of_access=A.Level_of_access;
}

 std::string User::get_Name()
 {
   return Username;
 }
  std::string User::get_Password()
  {
     return Password;
  }

  void User::File_Input()
  {
    std::fstream FILE;
    FILE.open("new.txt", std::fstream::out);
    FILE<<Username<<std::endl;
    FILE<<Password<<std::endl;
    FILE<<Level_of_access<<std::endl;
  }
#pragma once
#ifndef _USER_CPP
#define _USER_CPP
#include<iostream>
#include<vector>
#include<string>


class User
{
  std::string Username;
  std::string Password;
  bool Level_of_access;

  public:
///конструктор с параметри
  User(std::string Username,std::string Password , bool Level_of_access);
  ///функция за въвеждане
  void Input();
  ///функция за извеждане 
  void Output();
  ///конструктор
  User();
  ///деструктор 
  ~User();
  ///coppy конструктор
  User(const User&);
  ///функция която връща името на потребителя
  std::string get_Name();
  ///функция която връща паролата на потребителя
  std::string get_Password();
  ///функция която пише във файл
  void File_Input();
};

#endif
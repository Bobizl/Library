	#ifndef _Library_h
#define _Library_h
#include <vector>
#include <string>
#include "Book.h"
#include "User.h"

class Library
{
  std::vector<Book *> books;
  std::vector<User> users;
  std::string operation;
  bool logged = false;

public:
  Library();
  Library(std::vector<Book*> books, std::vector<User> users, std::string operation, bool logged);
  ~Library();
///функция която добавя книга
  void add_Book(Book);
  ///функция която добавя потребител
  void add_User(User);
  ///функция която извежда всички книги
  void books_All();
  ///функция която извежда всички потребители
  void users_All();
  ///клас който намира книга по специален номер
  Book pick_by_Number(int Number);
  ///функция за намиране на книга
  void Books_Find(std::string, std::string);
  ///функция за намиране на книга по заглавие
  void Books_Find_By_Title(std::string);
  ///функция за намиране на книга по автор
  void Books_Find_By_Author(std::string);
  ///функция за намиране на книга по ключови думи
  void Books_Find_By_Tag(std::string);
  ///функция за добавяне на потребител
  void Push_User(User); 
  std::vector<User> get_User();
  ///функция за премахване на потребител
  void remove_User(std::string);
  ///функция за сортиране на книгите
  void Books_Sort(std::string);
  ///функция за вкарване на книгите и потребителите във файла
  void Files();
///функция за всички операции
  void Check_Operation();
  ///функция за помощ 
  void Help();
  ///функция за влизане  
  bool Login();
  ///функция за излизане
  void Logout();
  ///функция за изход 
  void Exit();
  ///функция за отваряне на файл
  void Open_Books(std::string);
///функция за запазване на информация във файл
  void Save_Books(std::string);
///при команда close се извиква тази функция за изтриване на книга
  void Delete_Books();
  ///функция за извеждане на всички потребители
  void Display_all_Users();
};
#endif

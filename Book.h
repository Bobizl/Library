#ifndef _Book_h
#define _Book_h
#include<iostream>
#include<vector>
#include<string>

class Book
{
  std::string Title;
  std::string Author;
  std::string Genre;
  std::vector<std::string> Keywords;
  int Year;
  int Special_Number;
  double Rating;
  
  public:
  Book();
  Book(const Book&);
  Book(std::string _title, std::string _author, std::string _genre, int _year, int _number, double _rating);
  ///деструктор
  ~Book();
///функция за въвеждане на книга
  void input();
///функция за извеждане на книга
  void output();
///функция която връща автора на книгата
  std::string get_Author();
///функция която връща заглавието на книгата
  std::string get_Title();
///функция която връща жанрът на книгата 
  std::string get_Genre();
  ///функция която връща годината на книгата
  int get_Year();
  ///функция която връща оценката на книгата
  double get_Rating();
///функция която връща специален номер на всяка книга
  int get_Special_Number ()
   {
    return Special_Number;
  }
  ///функция която връща информация за книгата
  std::vector<std::string> get_Tag();
   ///функция която пише във файл
  void File_input();
};
#endif



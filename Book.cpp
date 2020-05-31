#include "Book.h"
#include<fstream>


Book::Book()
{

}
Book::Book(std::string _title, std::string _author, std::string _genre, int _year, int _number, double _rating)
{
	Title = _title;
	Author = _author;
	Genre = _genre;
	Year = _year;
	Special_Number = _number;
	Rating = _rating;
}
Book::~Book()
{
   Title.clear();
   Author.clear();
   Genre.clear();
   Keywords.clear(); 
}

Book::Book(const Book& A)
{
  this->Title=A.Title;
  this->Author=A.Author;
  this->Genre=A.Genre;
  this->Keywords=A.Keywords;
  this->Year=A.Year;
  this->Special_Number=A.Special_Number;
  this->Rating=A.Rating;
}

void Book::input()
{
    std::cout<<"Input title = ";
    std::cin>>Title;
    std::cout<<"Input Author = ";
    std::cin>>Author;
    std::cout<<"Input Genre = ";
    std::cin>>Genre;
}

void Book::output()
{
    std::cout<<Title<<std::endl;
    std::cout<<Author<<std::endl;
    std::cout<<Genre<<std::endl;
}
std::string Book::get_Title()
{
    return Title;
}

std::string Book::get_Author()
{
    return Author;
}
std::vector<std::string> Book::get_Tag()
{
    return Keywords;
}
std::string Book::get_Genre()
{
  return Genre;
}
int Book::get_Year()
{
    return Year;
}

double Book::get_Rating()
{
    return Rating;
}

void Book::File_input()
{
   std::fstream file;
   file.open("new.txt", std::fstream::out);
   file<<Title<<std::endl;
   file<<Author<<std::endl;
   file<<Genre<<std::endl;
   for(int i=0;i<Keywords.size();i++)
   {
        file<<Keywords[i]<<std::endl;
   }
   file<<Year<<std::endl;
   file<<Rating<<std::endl;
}
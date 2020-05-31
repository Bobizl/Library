#include "Library.h"
#include "Book.h"
#include<fstream>
#include<string>

Library::Library()
{

}

Library::Library(std::vector<Book*> books, std::vector<User> users, std::string operation, bool logged)
{
	this->books = books;
	this->users = users;
	this->operation = operation;
	this->logged= logged;
}

Library::~Library()
{
   books.clear();
   users.clear();
}

void Library::add_Book(Book A)
{
  books.push_back(new Book (A));
}

void Library::add_User(User A)
{
    users.push_back(A);
}

void Library::books_All()
{
    for(int i=0;i<books.size();i++)
    {
        books[i]->output();
    }
}

void Library::users_All()
{
     for(int i=0;i<users.size();i++)
    {
        users[i].Output();
    }
}

Book Library::pick_by_Number(int number)
{
    Book A(*books[number]);
    return A;
}

void Library::Books_Find(std::string search,std::string option)
{
    if(option.compare("Author")==0)
    {
        Books_Find_By_Author(search);
    }
}

void Library::Books_Find_By_Author(std::string search)
{
    bool B=0;
    for(int i=0;i<books.size();++i)
    {
        
        if(books[i]->get_Author().compare(search)==0)
        {

            B=1;
            books[i]->output();
            
        }
    }
    if(B==0) 
    {
        std::cout<<"There is no such book ! ";
    }
}

void Library::Books_Find_By_Title(std::string search)
{
    bool A=0;
    for(int i=0;i<books.size();++i)
    {
        
        if(books[i]->get_Title().compare(search)==0)
        {

            A=1;
            books[i]->output();
            
        }
    }
    if(A==0) 
    {
        std::cout<<"There is no such book ! ";
    }
}

void Library::Books_Find_By_Tag(std::string search)
{
    bool C=0;
    for(int i=0;i<books.size();++i)
    {
     std::vector<std::string>Bs;
     Bs==books[i]->get_Tag();
     for(int j=0;j<Bs.size();++j)
       {
          if(Bs[j].compare(search)==0)
          {
            C=1;
            books[i]->output();   
          }
        } 
    }   
    if(C==0) 
    {
        std::cout<<"There is no such book ! ";
    }
}

void Library::Books_Sort(std::string str)
{
     if(str.compare("Author")==0)
     {
         for(int i=0;i<books.size()-1;i++)
         {
             for(int j=i+1;j<books.size();j++)
             {
                if(books[j]->get_Author().compare(books[i]->get_Author())<0)
                {
                    Book a=*books[j];
                    delete books[j];
                    books[j]=new Book(*books[i]);
                    delete books[i];
                    books[i]=new Book(a);
                }
             }
         }
     }
     if(str.compare("Title")==0)
     {
         for(int i=0;i<books.size()-1;i++)
         {
             for(int j=i+1;j<books.size();j++)
             {
                if(books[j]->get_Title().compare(books[i]->get_Title())<0)
                {
                    Book a=*books[j];
                    delete books[j];
                    books[j]=new Book(*books[i]);
                    delete books[i];
                    books[i]=new Book(a);
                }
             }
         }
     }

      if(str.compare("Year")==0)
     {
         for(int i=0;i<books.size()-1;i++)
         {
             for(int j=i+1;j<books.size();j++)
             {
                if(books[j]->get_Year()<books[i]->get_Year())
                {
                    Book a=*books[j];
                    delete books[j];
                    books[j]=new Book(*books[i]);
                    delete books[i];
                    books[i]=new Book(a);
                }
             }
         }
     }
      if(str.compare("Rating")==0)
     {
         for(int i=0;i<books.size()-1;i++)
         {
             for(int j=i+1;j<books.size();j++)
             {
                if(books[j]->get_Rating()<books[i]->get_Rating())
                {
                    Book a=*books[j];
                    delete books[j];
                    books[j]=new Book(*books[i]);
                    delete books[i];
                    books[i]=new Book(a);
                }
             }
         }
     }
     }

      void Library::Push_User(User Name)
      {
         users.push_back(Name);
      }

std::vector<User> Library::get_User()
{
    return users;
}

void Library::remove_User(std::string Gone)
{
    for(int i=0;i<users.size();i++)
    {
        if(users[i].get_Name().compare(Gone)==0)
        {
          users.erase(users.begin()+i);
        }
    }
}

void Library::Files()
{
    for(int i=0;i<users.size();i++)
    {
      users[i].File_Input();
    }
    for(int i=0;i<books.size();i++)
    {
        books[i]->File_input();
    }
}


void Library::Check_Operation()
{
    std::cin>>operation;
    if(operation.compare("Help")==0)
    {
      
       Help();
    }
     if(operation.compare("Login")==0)
    {
        
      Login();
    }
     if(operation.compare("Logout")==0)
    {
      Logout();
    }
    if(operation.compare("Remove")==0)
    {
        std::cin>>operation;
        remove_User(operation);
    }
    if(operation.compare("Display")==0)
    {
        std::cin>>operation;
    }
}

void Library::Help()
{
    std::cout<<"The following commands are supported:open <file>	opens <file>"<<std::endl;
    std::cout<<std::endl;
    std::cout<<"close"<<" "<<"closes currently opened file"<<std::endl;
    std::cout<<std::endl;
    std::cout<<"Save"<<" "<<"saves the currently open file"<<std::endl;;
    std::cout<<std::endl;
    std::cout<<"Saveas"<<" "<<"saves the currently open file in <file>"<<std::endl;;
}

void Library::Open_Books (std::string nameOfFile) 
{ 
    std::ifstream file(nameOfFile.c_str(), std::ios::in);
    while (!file.eof()) 
    {
        std::string _Author, _Name, _Genre;
        int _Year, _SNumber;
        double _rating;
        file>>_Name>>_Author>>_Genre>>_Year>>_SNumber>>_rating;
        books.push_back(new Book(_Name, _Author, _Genre, _Year, _SNumber, _rating));
    }
    file.close();
}

void Library::Save_Books (std::string Name_of_file) 
{ 
    
    std::ofstream file(Name_of_file.c_str(), std::ios::out | std::ios::trunc);
    for(int i=0;i<books.size();i++)
     {
        file<<books[i]->get_Title()<<" "<<books[i]->get_Author()<<" "<<books[i]->get_Genre()<<" "<<
        books[i]->get_Year()<<" "<<books[i]->get_Special_Number()<<" "<<books[i]->get_Rating()<<"\n";
    }
    file.close();
}

void Library::Delete_Books () 
{ 
 
    for(int i=0;i<books.size();i++) 
    {
        delete books[i];
    }
    books.clear();
}

bool Library::Login()
{ 
   std::string MYUser;
   std::cin>>MYUser;
   std::string MYPassword;
   std::cin>>MYPassword;
   for(int i=0;i<users.size();i++)
   {
       if(users[i].get_Name().compare(MYUser)==0 && users[i].get_Password().compare(MYPassword)==0)
       {
         logged=1;
         return 1;
       }
   }
    return 0; 
}

void Library::Logout()
{
  logged=0;
  std::cout<<"You logged out ! "<<std::endl;
}

void  Library::Display_all_Users()
{
   std::cout<<"Displaying all users ! "<<std::endl;
    for(int i=0;i<users.size();i++)
    {
       std::cout<<users[i].get_Name();
       std::cout<<std::endl;
    }
}

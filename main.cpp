#include <iostream>
#include "Library.h"

int main()
{
	User user("Bobi", "83424", true);
	std::cout << user.get_Name() << "  ";
	std::cout << user.get_Password() << std::endl;
	Book book("Steve Jobs", "Walter Isaacson", "", 2008, 123, 9.9);
	std::cout << book.get_Title() << "  ";
	std::cout << book.get_Author() << "  ";
	std::cout << book.get_Genre() << "  ";
	std::cout << book.get_Year() << "  ";
	std::cout << book.get_Special_Number() << "  ";
	std::cout << book.get_Rating() << std::endl;
	std::vector<Book*> books;
	std::vector<User> users;
	books.push_back(&book);
	users.push_back(user);
	Library library(books, users, "test", true);
	Library Q;
	bool X = 1;
  
	std::cout << "Input Help if you want help" << std::endl;
	std::cout << "Input Login if you want to login" << std::endl;
	std::cout << "Input Logout if you want to logout" << std::endl;
	std::cout << "Input Remove if you want to remove a User" << std::endl;
	std::cout << "Input Display if you want to see the users" << std::endl;

	if (std::cout << "Input Exit if you want to exit" << std::endl)
	{
		bool X = 0;
	}

	for (int i = 0; i < 3; i++)
	{
		Q.Check_Operation();
	}

	return 0;
}

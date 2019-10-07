#include "User.h"
#include <iostream>
#include <stdio.h>

using namespace std;


User::User()
{
}

User::User(char user_choice_arg)
{
	user_choice = user_choice_arg;
}

void User::make_choice()
{
	bool correct_value = false;
	while (correct_value == false)
	{
		cout << endl << endl << "Select R, P, or S" << endl;
		cout << "To start a new session select N" << endl;
		cout << "To quit the game select Q " <<endl;
		cin >> user_choice;
		cout << endl << endl << endl;
		user_choice = tolower(user_choice);

		if (user_choice == 'r' || user_choice == 'p' || user_choice == 's' || user_choice == 'n' || user_choice == 'q')
				correct_value = true;
		else
		{
			cout << "error, incorrect key picked, pick again" << endl;
			cout << endl;
		}
	}
}

char User::get_user_choice()
{
	return user_choice;
}


User::~User()
{
}

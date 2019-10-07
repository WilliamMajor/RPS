#pragma once
class User
{
public:
	User();
	User(char user_choice_arg);
	void make_choice();
	char get_user_choice();
	virtual ~User();
private:
	char user_choice;
};


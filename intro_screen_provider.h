#include "intro_file_work.h"

struct LoginProviderCheck
{
	string * users = nullptr;
	string * passwords = nullptr;
	int count = 0;
	FileWork file;
	LoginProviderCheck()
	{
		file.Read(users, passwords, count);
	}
	bool CheckLogin(string user, string password)
	{
		for (int i = 0; i < count; i++)
		{
			if (user == users[i] && password == passwords[i])
			{
				return true;
			}
		}
		return false;
	}

};

#include <iostream>
#include <fstream>
using namespace std;

struct FileWork
{
	fstream file;
	
	bool Write(string * user, string * password, int count)
	{
		file.open("login.bin", ios::out | ios::binary);
		if (!file.is_open())
		{
			cout << "Error opening file!" << endl;
			return false;
		}
		file.write((char*)&count, sizeof(count));
		for (int i = 0; i < count; i++)
		{
			file.write((char*)&user[i], sizeof(user[i]));
			file.write((char*)&password[i], sizeof(password[i]));
		}
		file.close();
		return true;

	}
	bool Read(string* &user, string *&password, int &count)
	{
		file.open("login.bin", ios::in | ios::binary);
		if (!file.is_open())
		{
			cout << "Error opening file!" << endl;
			return false;
		}
		file.read((char*)&count, sizeof(count));
		user = new string[count];
		password = new string[count];
		for (int i = 0; i < count; i++)
		{
			file.read((char*)&user[i], sizeof(user[i]));
			file.read((char*)&password[i], sizeof(password[i]));
		}
		file.close();
		return true;
	}

	bool Write(string user, string password)
	{
		file.open("login.bin", ios::out | ios::binary);
		if (!file.is_open())
		{
			cout << "Error opening file!" << endl;
			return false;
		}
		file.write((char*)&user, sizeof(user));
		file.write((char*)&password, sizeof(password));
		file.close();
		return true;
		
	}
	bool Read(string &user, string &password)
	{
		file.open("login.bin", ios::in | ios::binary);
		if (!file.is_open())
		{
			cout << "Error opening file!" << endl;
			return false;
		}
		file.read((char*)&user, sizeof(user));
		file.read((char*)&password, sizeof(password));
		file.close();
		return true;
	}
};

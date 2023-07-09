#include <iostream>
using namespace std;

struct Login
{
private:
	string username;
	string password;
public:
	Login()
	{
		username = "";
		password = "";
	}
	Login(string username, string password) : Login()
	{
		this->username = username;
		this->password = password;
	}
	void setUsername(string username) {
		if (username.empty() || username.size() < 5)
		{
			cout << "Username must be at least 5 characters long" << endl;
			return;
		}
		this->username = username;

	}
	void setPassword(string password) {
		if (password.empty() || password.size() < 8)
		{
			cout << "Password must be at least 8 characters long" << endl;
			return;
		}
		this->password = password;
	}
	string getUsername()
	{
		return username;
	}
	string getPassword() 
	{
		return password;
	}
};

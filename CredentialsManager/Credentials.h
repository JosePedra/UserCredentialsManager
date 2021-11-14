#ifndef CREDENTIALS_H
#define CREDENTIALS_H

#include <string>

using namespace std;

class Credentials {
	string url, username, password;

public:
	Credentials(string url0, string username0, string password0) :
		url(url0), username(username0), password(password0) {}

	string getUrl() const { return url; }
	string getUsername() const { return username; }
	string getPassword() const { return password; }

	/*
	* Describes its content through a string
	*/
	string toString() const;
};

#endif // !CREDENTIALS_H
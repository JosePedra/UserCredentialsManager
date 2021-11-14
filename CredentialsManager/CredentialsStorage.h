#ifndef CREDENTIALS_STORAGE_H
#define CREDENTIALS_STORAGE_H

#include <vector>
#include <string>

#include "Credentials.h"

using namespace std;

class CredentialsStorage {
	string name;
	vector<Credentials*> credentials;

	int findCredentialsIndex(string site, string user) const;
	void clear();
public:
	CredentialsStorage(string name0) : name(name0) {}
	~CredentialsStorage();

	string getName() { return name; }

	/*Adds a new credentials set to the vector of Credentials
	* @param site - url of the credentials to be added
	* @param user - username of the credentials to be added
	* @param password - password of the credentials to be added
	*/
	bool addSiteCredentials(string site, string user, string password);

	/*Obtains the password of a given account in a given site
	* @param site - url of the credentials
	* @param user - username of the credentials
	* @return Returns the password of the given account and site if existing, otherwise returns an empty string
	*/
	string getSitePassword(string site, string user) const;

	/* Obtains the amount of Credentials stored in the instance
	*/
	int getSize() const { return credentials.size(); }

	/*
	* Describes its content through a string
	* @return Returns a description of the data stored in each element of the vector credentials
	*/
	string toString() const;
};

#endif // !CREDENTIALS_STORAGE_H
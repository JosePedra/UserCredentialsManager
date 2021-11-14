#ifndef MANAGER_H
#define MANAGER_H

#include "CredentialsStorage.h"

using namespace std;

class Manager {
	vector<CredentialsStorage*> storages;

	/* Finds the position of the CredentialsStorage in the storages vector
	* @param name - Name of the CredentialsStorage to be found
	* @return Returns the index of the required CredentialsStorage if existing, otherwise returns -1
	*/
	int findStorageIndex(string name);

public:
	~Manager();

	/* Initializes a new Storage
	* @param name - Name of the storage to be created
	* @return Returns the storage created
	*/
	CredentialsStorage initCredentialsStorage(string name);

	/*Searches for a credential among all the existing storages
	* @param site - url of the credentials to be found
	* @param user - username of the credentials to be found
	* @return Returns the credentials. If the credentials are not found, returns nullptr
	*/
	Credentials* findCredentials(string site, string user) const;

	/*Adds a set of credentials in one of the storages
	* @param site - url of the credentials to be added
	* @param user - username of the credentials to be added
	* @param password - password of the credentials to be added
	*/
	bool addCredentials(string site, string user, string password);

	/*Describes its content through a string
	* @return Returns a description of the data stored in each element of the vector storages
	*/
	string toString() const;
};

#endif // !MANAGER_H
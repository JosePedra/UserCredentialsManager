#include "CredentialsStorage.h"
#include <sstream>

int CredentialsStorage::findCredentialsIndex(string site, string user) const {
    for (unsigned int i = 0; i < credentials.size(); i++)
        if (site == credentials[i]->getUrl() &&
            user == credentials[i]->getUsername())
            return i;
    return -1;
}

void CredentialsStorage::clear() {
    for (Credentials* c : credentials)
        delete c;
    credentials.clear();
}

CredentialsStorage::~CredentialsStorage() {
    clear();
}

bool CredentialsStorage::addSiteCredentials(string site, string user, string password) {
    if (site.empty() || user.empty() || password.empty())
        return false;

    credentials.push_back(new Credentials(site, user, password));

    return true;
}

string CredentialsStorage::getSitePassword(string site, string user) const {
    int index = findCredentialsIndex(site, user);

    if (index == -1)
        return "";

    return credentials[index]->getPassword();
}

string CredentialsStorage::toString() const {
    ostringstream oSS;

    oSS << "Name: " << name << "\n\tCredentials:\n";

    for (Credentials* c : credentials)
        oSS << "\t\t" << c->toString() << endl;

    return oSS.str();
}

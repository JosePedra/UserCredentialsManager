#include "Manager.h"
#include <sstream>
#include <algorithm>

int Manager::findStorageIndex(string name) {
    for (unsigned int i = 0; i < storages.size(); i++)
        if (storages[i]->getName() == name)
            return i;
    return -1;
}

Manager::~Manager() {
    for (CredentialsStorage* cS : storages)
        delete cS;

    storages.clear();
}

CredentialsStorage Manager::initCredentialsStorage(string name) {
    CredentialsStorage* cS = new CredentialsStorage(name);
    storages.push_back(cS);

    return *cS;
}

Credentials* Manager::findCredentials(string site, string user) const {
    string password;

    for (CredentialsStorage* cS : storages)
        if ((password = cS->getSitePassword(site, user)) != "")
            return new Credentials(site, user, password);
    return nullptr;
}

bool Manager::addCredentials(string site, string user, string password) {
    if (findCredentials(site, user) != nullptr)
        return false;

    if (!storages[0]->addSiteCredentials(site, user, password))
        return false;

    sort(storages.begin(), storages.end(), [](const CredentialsStorage* lhs, const CredentialsStorage* rhs) {
        return lhs->getSize() < rhs->getSize();
        });

    return true;
}

string Manager::toString() const {
    ostringstream oSS;

    oSS << "Storages (" << storages.size() << "):\n";

    for (CredentialsStorage* cS : storages)
        oSS << "\t" << cS->toString() << endl;

    return oSS.str();
}

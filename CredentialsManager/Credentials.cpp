#include "Credentials.h"
#include <sstream>

string Credentials::toString() const {
	ostringstream oSS;

	oSS << "URL: " << url << "; Username: " << username << "; Password: " << password;

	return oSS.str();
}

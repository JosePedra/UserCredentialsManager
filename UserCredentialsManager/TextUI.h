#ifndef TEXT_UI_H
#define TEXT_UI_H
#include "Manager.h"

class TextUI {
	Manager manager;

	int getChoice(vector<string> options);

	void createStorageMenu();
	void addCredencialMenu();
	void getCredentialMenu();
public:
	void mainMenu();
};

#endif // !TEXT_UI_H



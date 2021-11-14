#include "TextUI.h"
#include <iostream>

int TextUI::getChoice(vector<string> options) {
	string raw;
	int choice;

	while (true) {
		system("pause");
		system("cls");

		for (unsigned int i = 0; i < options.size(); i++)
			cout << i + 1 << " - " << options[i] << endl;
		cout << "> ";

		try {
			getline(cin, raw);
			choice = stoi(raw);

			if (choice >= 1 && choice <= options.size())
				return choice;
		}
		catch (const std::exception&) {}

		cout << "Invalid input" << endl;
	}
}

void TextUI::createStorageMenu() {
	string name;

	cout << "Insert the name of the storage to be created: ";

	do
		getline(cin, name);
	while (name.empty());

	manager.initCredentialsStorage(name);
	cout << "Storage created successfully" << endl;
}

void TextUI::addCredencialMenu() {
	string url, user, password;

	cout << "Insert the credentials url: ";
	getline(cin, url);
	cout << "Insert the credentials username: ";
	getline(cin, user);
	cout << "Insert the credentials password: ";
	getline(cin, password);

	if (manager.addCredentials(url, user, password))
		cout << "Credentials saved!" << endl;
	else
		cout << "[ERROR] Credentials not saved" << endl;
}

void TextUI::getCredentialMenu() {
	string url, user;
	Credentials* credentials;

	cout << "Insert the credentials url: ";
	getline(cin, url);
	cout << "Insert the credentials username: ";
	getline(cin, user);

	if ((credentials = manager.findCredentials(url, user)) != nullptr)
		cout << "Credentials found: " << credentials->toString() << endl;
	else
		cout << "[ERROR] Credentials not found" << endl;
}

void TextUI::mainMenu() {
	vector<string> options = { "Create Storage", "Add Credencial", "Get Credential", "Info", "Exit" };

	while (true) {
		switch (getChoice(options)) {
		case 1:
			createStorageMenu();
			break;
		case 2:
			addCredencialMenu();
			break;
		case 3:
			getCredentialMenu();
			break;
		case 4:
			cout << manager.toString() << endl;
			break;
		default:
			return;
		}
	}
}
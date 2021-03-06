#include "Header.h"
#include <conio.h>
#define __CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define new DEBUG_NEW

int main() {
	setlocale(0, "rus");
	char choice;
	char Exit;
	Book a;
	do {
		do {
			system("cls");
			show_menu();
			cout << "Выберите функцию: ";
			choice = _getch();
		} while (choice != '1' && choice != '2' && choice != '3' && choice != '4' && choice != '5' && choice != '6' && choice != '7');
		switch (choice) {
		case '1': {
			system("cls");
			a.add_Contact();
		}
				break;
		case '2': {
			system("cls");
			a.see_all_Contacts();
		}
				break;
		case '3': {
			system("cls");
			string Contact_to_find;
			cout << "Contact to find: ";
			getline(cin, Contact_to_find);
			int n_found = 0;
			string* found_Contacts = a.findContact(Contact_to_find, n_found);
			if (found_Contacts) {
				cout << "Found Contacts: " << endl;
				for (int i = 0; i < n_found; i++)
					cout << "[" << i + 1 << "]" << found_Contacts[i] << endl;
				delete[] found_Contacts;
			}
			else {
				cout << "no such note!" << endl;
			};
		}
				break;
		case '4': {
			system("cls");
			int count = 0;
			string* all_Contacts_arr = a.all_Contacts(count);
			cout << "All Contacts: " << endl;
			for (int i = 0; i < count; i++)
				cout << "[" << i + 1 << "]" << all_Contacts_arr[i] << endl;
			cout << "Number of Contact to remove: ";
			int choice = 0;
			cin >> choice;
			a.remove_Contact(all_Contacts_arr, count, choice);
			cout << "Your note removed" << endl;
			delete[] all_Contacts_arr;
			break;
		}
				break;
		case '5': {
			system("cls");
			a.remove_all_Contacts();
			cout << "Remove all Contacts!" << endl;
			break;
		}
				break;
		case '6': {
			system("cls");
			int count = 0;
			string* all_Contacts_arr = a.all_Contacts(count);
			cout << "All Contacts: " << endl;
			for (int i = 0; i < count; i++)
				cout << "[" << i + 1 << "]" << all_Contacts_arr[i] << endl;
			cout << "Number of note to edit: ";
			int choice = 0;
			cin >> choice;
			while (choice < 1 or choice > count) {
				cout << "Выберите корректный номер контакта, который хотите изменить: ";
				cin >> choice;
			}
			a.remove_Contact(all_Contacts_arr, count, choice);
			a.add_Contact();
			delete[] all_Contacts_arr;
			break;
		}
		case '7': {
			a.Sort();
			break;
		}
		}
	cout << endl << "Do you want to make another operation? (any button - yes, 0 - no)" << endl;
	fflush(stdin);
	Exit = _getch();
		} while (Exit != '0');
	return _CrtDumpMemoryLeaks();
}
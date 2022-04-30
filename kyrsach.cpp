#include <iostream>
#include <conio.h>
#include "Header.h"
#include <string>


int main() {
	setlocale(0, "rus");
	Contact book;
	char choice;
	char Exit;
	do {
		do {
			system("cls");
			show_menu();
			cout << "Выбери функцию: ";
			choice = _getch();
		} while (choice != '1' && choice != '2' && choice != '3' && choice != '4' && choice != '5' && choice != '6' && choice != '7');
		switch (choice) {
		case '1': {
			system("cls");
			cout << "Contact to add: ";
			add_Contact(); }
				break;
		case '2': {
			system("cls");
			see_all_Contacts(); }
				break;
		case '3': {
			system("cls");
			string Contact_to_find;
			cout << "Contact to find: ";
			getline(cin, Contact_to_find);
			int n_found = 0;
			string* found_Contacts = findContact(Contact_to_find, n_found);
			if (found_Contacts) {
				cout << "Found notes: ";
				for (int i = 0; i < n_found; i++)
					cout << found_Contacts[i] << endl;
				delete[] found_Contacts;
			}
			else {
				cout << "no such contact!" << endl;
			};
		}
				break;
		case '4': {
			system("cls");
			//Получаем все заметки
			int count = 0;
			string* all_notes_arr = all_Contacts(count);
			//Выводим их в консоль
			cout << "All contacts: " << endl;
			for (int i = 0; i < count; i++)
				cout << "[" << i + 1 << "]" << all_notes_arr[i] << endl;
			cout << "Number of contact to remove: ";
			int choice = 0;
			cin >> choice;
			remove_one_Contacts(all_notes_arr, count, choice);
			cout << "Your contact removed" << endl;
			delete[] all_notes_arr;;
		}
				break;
		case '5': {
			system("cls");
			remove_all_Contacts();
			cout << "Remove all contacts!" << endl;
		}
				break;
		case '6': {
			system("cls");
			//Получаем все контакты
			int count = 0;
			string* all_notes_arr = all_Contacts(count);
			//Выводим их в консоль
			cout << "All contacts: " << endl;
			for (int i = 0; i < count; i++)
				cout << "[" << i + 1 << "]" << all_notes_arr[i] << endl;
			cout << "Number of contacts to edit: ";
			int choice = 0;
			cin >> choice;
			remove_one_Contacts(all_notes_arr, count, choice);
			add_Contact();
			cout << "Contact changed!" << endl;
			delete[] all_notes_arr;
			break;
		}
		case '7': {
			Sort();
			break;
		}
		}
		cout << endl << "Do you want to make another operation? (1 - yes, 0 - no)" << endl;
		fflush(stdin);
		Exit = _getch();
	} while (Exit != '0');
}

// сортировка 
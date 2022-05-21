#include <iostream>
#include <conio.h>
#include "Header.h"
#include <string>


int main() {
	setlocale(0, "rus");
	Book a;
	char choice;
	char choice1;
	char choice2;
	char Exit;
	do {
		do {
			system("cls");
			show_menu();
			cout << "Выберите объект, с которым вы хотите работать: ";
			choice = _getch();
		} while (choice != '1' && choice != '2');
		switch (choice) {
		case '1': {
			do {
				system("cls");
				show_menu1();
					cout << "Выбери функцию: ";
				choice1 = _getch();
			} while (choice1 != '1' && choice1 != '2' && choice1 != '3' && choice1 != '4');
			switch (choice1) {
			case '1': {
				system("cls");
				cout << "Contact to add: ";
				a.add_Contact(); }
					break;
			case '2': {
				system("cls");
				string Contact_to_find;
				cout << "Contact to find: ";
				getline(cin, Contact_to_find);
				int n_found = 0;
				string* found_Contacts = a.findContact(Contact_to_find, n_found);
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
			case '3': {
				system("cls");
				//Получаем все заметки
				int count = 0;
				string* all_notes_arr = a.all_Contacts(count);
				//Выводим их в консоль
				cout << "All contacts: " << endl;
				for (int i = 0; i < count; i++)
					cout << "[" << i + 1 << "]" << all_notes_arr[i] << endl;
				cout << "Number of contact to remove: ";
				int choice = 0;
				cin >> choice;
				a.remove_Contact(all_notes_arr, count, choice);
				cout << "Your contact removed" << endl;
				delete[] all_notes_arr;
				break;
			}
			}
			break;
		}
		case'2': {
			do {
				system("cls");
				show_menu2();
					cout << "Выбери функцию: ";
				choice2 = _getch();
			} while (choice2 != '1' && choice2 != '2' && choice2 != '3');
			switch (choice2) {
			case'1': {
				system("cls");
				a.see_all_Contacts(); }
				   break;
			case'2': {
				system("cls");
				a.remove_all_Contacts();
				cout << "Remove all contacts!" << endl;
			}
				   break;
			case'3': {
				a.Sort();
				break; }
			}
		}
	}cout << endl << "Do you want to make another operation? (1 - yes, 0 - no)" << endl;
		fflush(stdin);
		Exit = _getch();
		} while (Exit != '0');
}

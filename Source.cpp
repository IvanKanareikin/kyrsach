#include <iostream>
#include "Header.h"
#include <fstream>
using namespace std;



void show_menu() {
	setlocale(0, "rus");
	cout << "[1] Контакт." << endl;
	cout << "[2] Книга." << endl;
}

void show_menu1() {
	setlocale(0, "rus");
	cout << "[1] Добавить контакт." << endl;
	cout << "[2] Найти контакт." << endl;
	cout << "[3] Удалить контакт." << endl;
}

void show_menu2() {
	setlocale(0, "rus");
	cout << "[1] Показать все контакты." << endl;
	cout << "[2] Удалить все контакты." << endl;
	cout << "[3] Отсортировать все контакты." << endl;
}

void Book::add_Contact() {
	setlocale(0, "rus");
	Contact a;
	ofstream file("notes.txt", ios::app);
	if (!file.is_open()) {
		cout << "[-] File is not opened!";
		exit(EXIT_FAILURE);
	}
	cout << "Введите Фамилию" << endl;
	a.SetSn();
	cout << "Введите Имя" << endl;
	a.SetFn();
	cout << "Введите возраст" << endl;
	a.SetAge();
	cout << "Введите адрес" << endl;
	a.SetAd();
	cout << "Введите номер телефона" << endl;
	a.SetP();
	file << a.GetSn() <<' ' << a.GetFn() <<' '<< a.GetAge() <<' '<< a.GetAd() <<' '<< a.GetP() << endl;
	file.close();
	cout << "Note added!" << endl;
}



void Book::see_all_Contacts() {
	setlocale(0, "rus");
	ifstream file("notes.txt");

	if (!file.is_open()) {
		cout << "No notes! Add them!" << endl;
		return;
	}
	string one_Contacts;
	cout << "Мои заметки: " << endl;
	for (int i = 1; !file.eof(); i++) {
		getline(file, one_Contacts);
		if (one_Contacts.empty())
			continue;
		cout << "[" << i << "]" << one_Contacts << endl;
	}
	file.close();
}



string* Book::findContact(const string& Contact_to_find, int& n_count) {
	setlocale(0, "rus");
	ifstream file("notes.txt");
	if (!file.is_open()) {
		cout << "No notes! Add them!" << endl;
		return nullptr;
	}
	string one_Contact;
	string* found_Contacts = nullptr;
	string* found_Contacts_tmp = nullptr;
	int count = 0;
	while (!file.eof()) {
		getline(file, one_Contact);
		if (one_Contact.find(Contact_to_find) != -1) {
			count++;
			found_Contacts_tmp = new string[count];
			// Копируем все найденные заметки
			for (int i = 0; i < count - 1; i++)
				found_Contacts_tmp[i] = found_Contacts[i];
			// добавляем найденную заметку
			found_Contacts_tmp[count - 1] = one_Contact;
			// Удаляем старое содержимое found_Contacts
			delete[] found_Contacts;
			// found_notes указывает на новый массив
			found_Contacts = found_Contacts_tmp;
		}
	}
	file.close();
	n_count = count;
	return found_Contacts;
}



string* Book::all_Contacts(int& n_count) {
	setlocale(0, "rus");
	string* all_Contacts = nullptr;
	string* all_Contacts_ptr = nullptr;
	ifstream file("notes.txt");
	if (!file.is_open()) {
		cout << "File is not opened!";
		exit(EXIT_FAILURE);
	}
	string one_Contact;
	int count1 = 0;
	while (!file.eof()) {
		getline(file, one_Contact);
		if (one_Contact.empty())
			continue;
		count1++;
		all_Contacts_ptr = new string[count1];
		//Копируем уже считанные заметки
		for (int i = 0; i < count1 - 1; i++)
			all_Contacts_ptr[i] = all_Contacts[i];
		//Добавляем новую заметку
		all_Contacts_ptr[count1 - 1] = one_Contact;
		//Очищаем старый массив all_notes
		delete[] all_Contacts;
		//all_Contacts указывает на новый массив;
		all_Contacts = all_Contacts_ptr;
		all_Contacts_ptr = nullptr;
	}
	file.close();
	n_count = count1;
	return all_Contacts;
}




void Book::remove_Contact(string* all_Contacts_arr, int count, int choice) {
	setlocale(0, "rus");
	ofstream file("notes.txt");
	if (!file.is_open()) {
		cout << "[-]Error! File is not opened!" << endl;
		exit(EXIT_FAILURE);
	}
	for (int i = 0; i < count; i++) {
		if (i + 1 == choice)
			continue;
		file << all_Contacts_arr[i] << endl;
	}
}


void Book::remove_all_Contacts() {
	setlocale(0, "rus");
	fstream file("notes.txt", ios::out);
	if (!file.is_open()) {
		cout << "File is not opened!" << endl;
		exit(EXIT_FAILURE);
	}
	file.close();
}

void Book:: Sort() {
	ifstream file("notes.txt");
	int n = 0;
	string* s_Contacts = new string[100];
	while (!file.eof()) {
		getline(file, s_Contacts[n]);
		n += 1;
	}
	string temp = "";
	for (int i = 0; i < n - 2; i++) {
		for (int j = i + 1; j < n - 1; j++) {
			if (s_Contacts[i][0] >= s_Contacts[j][0]) {
				temp = s_Contacts[i];
				s_Contacts[i] = s_Contacts[j];
				s_Contacts[j] = temp;
			}
		}
	}
	file.close();
	ofstream ofile("notes.txt", ofstream::trunc);
	for (int i = 0; i < n; i++) {
		if (i == n - 1)
			ofile << s_Contacts[i];
		else
			ofile << s_Contacts[i] << '\n';
	}
	ofile.close();
	delete[] s_Contacts;
}
#include <iostream>
#include "Header.h"
#include <fstream>
using namespace std;



void show_menu() {
	setlocale(0, "rus");
	cout << "[1] �������." << endl;
	cout << "[2] �����." << endl;
}

void show_menu1() {
	setlocale(0, "rus");
	cout << "[1] �������� �������." << endl;
	cout << "[2] ����� �������." << endl;
	cout << "[3] ������� �������." << endl;
	cout << "[4] �������� �������." << endl;
}

void show_menu2() {
	setlocale(0, "rus");
	cout << "[1] �������� ��� ��������." << endl;
	cout << "[2] ������� ��� ��������." << endl;
	cout << "[3] ������������� ��� ��������." << endl;
}

void Book::add_Contact() {
	setlocale(0, "rus");
	Contact a;
	ofstream file("notes.txt", ios::app);
	if (!file.is_open()) {
		cout << "[-] File is not opened!";
		exit(EXIT_FAILURE);
	}
	cout << "������� �������" << endl;
	a.SetSn();
	cout << "������� ���" << endl;
	a.SetFn();
	cout << "������� �������" << endl;
	a.SetAge();
	cout << "������� �����" << endl;
	a.SetAd();
	cout << "������� ����� ��������" << endl;
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
	cout << "��� �������: " << endl;
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
			// �������� ��� ��������� �������
			for (int i = 0; i < count - 1; i++)
				found_Contacts_tmp[i] = found_Contacts[i];
			// ��������� ��������� �������
			found_Contacts_tmp[count - 1] = one_Contact;
			// ������� ������ ���������� found_Contacts
			delete[] found_Contacts;
			// found_notes ��������� �� ����� ������
			found_Contacts = found_Contacts_tmp;
		}
	}
	file.close();
	n_count = count;
	return found_Contacts;
}



string* Book::all_Contacts(int& n_count) {
	setlocale(0, "rus");
	string* all_notes = nullptr;
	string* all_notes_ptr = nullptr;
	ifstream file("notes.txt");
	if (!file.is_open()) {
		cout << "File is not opened!";
		exit(EXIT_FAILURE);
	}
	string one_note;
	int count = 0;
	while (!file.eof()) {
		getline(file, one_note);
		if (one_note.empty())
			continue;
		count++;
		all_notes_ptr = new string[count];
		//�������� ��� ��������� �������
		for (int i = 0; i < count - 1; i++)
			all_notes_ptr[i] = all_notes[i];
		//��������� ����� �������
		all_notes_ptr[count - 1] = one_note;
		//������� ������ ������ all_notes
		delete[] all_notes;
		//all_notes ��������� �� ����� ������;
		all_notes = all_notes_ptr;
		all_notes_ptr = nullptr;
	}
	file.close();
	n_count = count;
	return all_notes;
}




void Book::remove_one_Contacts(string* all_notes_arr, int count, int choice) {
	setlocale(0, "rus");
	ofstream file("notes.txt");
	if (!file.is_open()) {
		cout << "[-]Error! File is not opened!" << endl;
		exit(EXIT_FAILURE);
	}
	for (int i = 0; i < count; i++) {
		if (i + 1 == choice)
			continue;
		file << all_notes_arr[i] << endl;
	}
}


void Book::remove_all_Contacts() {
	setlocale(0, "rus");
	fstream file("notes.txt", ios::out | ios::trunc);
	if (!file.is_open()) {
		cout << "File is not opened!" << endl;
		exit(EXIT_FAILURE);
	}
	file.close();
}

void Book:: Sort() {
	ifstream file("notes.txt");
	int n = 0;
	string* s_notes = new string[100];
	while (!file.eof()) {
		getline(file, s_notes[n]);
		n += 1;
	}
	string temp = "";
	for (int i = 0; i < n - 2; i++) {
		for (int j = i + 1; j < n - 1; j++) {
			if (s_notes[i][0] >= s_notes[j][0]) {
				temp = s_notes[i];
				s_notes[i] = s_notes[j];
				s_notes[j] = temp;
			}
		}
	}
	file.close();
	ofstream ofile("notes.txt", ofstream::trunc);
	for (int i = 0; i < n; i++) {
		if (i == n - 1)
			ofile << s_notes[i];
		else
			ofile << s_notes[i] << '\n';
	}
	ofile.close();
	delete[] s_notes;
}
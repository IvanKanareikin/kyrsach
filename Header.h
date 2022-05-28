#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Contact {
private:
	string fname;
	string sname;
	string age;
	string address;
	string phone;
public:
	void SetFn() {
		string name;
		cin >> name;
		fname = name;
	}
	void SetSn() {
		string secname;
		cin >> secname;
		sname = secname;
	}
	void SetAge() {
		string AGE;
		cin >> AGE;
		age = AGE;
	}
	void SetAd() {
		string adres;
		cin >> adres;
		address = adres;
	}
	void SetP() {
		string Phone;
		cin >> Phone;
		phone = Phone;
	}
	string GetFn() {
		return fname;
	}
	string GetSn() {
		return sname;
	}
	string GetAge() {
		return age;
	}
	string GetAd() {
		return address;
	}
	string GetP() {
		return phone;
	}
};

class Book {
public:
	void add_Contact();
	string* findContact(const string& Contact_to_find, int& n_count);
	string* all_Contacts(int& count);
	void remove_Contact(string* all_Contacts_arr, int count, int choice);
	void Sort();
	void remove_all_Contacts();
	void see_all_Contacts();
};

void show_menu();

#endif
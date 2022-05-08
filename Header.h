#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iterator>
#include <algorithm>

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
		getline(cin, name);
		fname = name;
	}
	void SetSn() {
		string secname;
		getline(cin, secname);
		sname = secname;
	}
	void SetAge() {
		string AGE;
		getline(cin, AGE);
		age = AGE;
	}
	void SetAd() {
		string adres;
		getline(cin, adres);
		address = adres;
	}
	void SetP() {
		string Phone;
		getline(cin,Phone);
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

	void add_Contact();
	void see_all_Contacts();
	string* findContact(const string& note_to_find, int& n_count);
	string* all_Contacts(int& count);
	void remove_one_Contacts(string* all_notes_arr, int count, int choice);
	void remove_all_Contacts();
	void Sort();
};

#endif
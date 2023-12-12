#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "../inc/User.h"
#include "../inc/IUserRepository.h"
#include "../inc/IUserManager.h"

using namespace std;


void IUserManager::SignIn() {
	string login, password;
	cout << "������� �����" << endl;
	cin >> login;
	cout << "������� ������" << endl;
	cin >> password;
	User user = user_repo.GetByLogin(login);

	if (!user.m_login.empty() && password == user.m_password) {
		current_user = user;
		ofstream file("../sessions.txt");
		file << user.m_id << " " << user.m_name << " " << user.m_login << " " << user.m_password << "\n";
		file.close();

		cout << "������������ " << user.m_login << " ��� ������� �����������." << endl;
	}
	else cout << "���-�� ��� ������" << endl;
}

void IUserManager::SignOut() {
	ofstream file("../sessions.txt");
	file << " ";
    file.close();
    cout << "�� ����� �� ��������." << endl;
	current_user = User();
}

void IUserManager::SignUp() {
	string login, password, name;
	cout << "������� �����" << endl;
	cin >> login;
	cout << "������� ������" << endl;
	cin >> password;
	cout << "������� ���" << endl;
	cin >> name;

	User tmp = user_repo.GetByLogin(login);
	if (!tmp.m_login.empty()) {
		cout << "����� �����" << endl;
	}
	else {
		User user;
		user.m_login = login;
		user.m_name = name;
		user.m_password = password;
		user.m_id = user_repo.GetNewId();
		user_repo.NewUser(user);
		cout << "������������ ���������������, ������� ������ ��� ���, ����� ����� � �������" << endl;
		SignIn();
	}
}

void IUserManager::RestoreLast() {
	ifstream file("../sessions.txt");
	int id = -1;
	if (file.is_open()) {
		file >> id;
		file.close();
	}
	User user = user_repo.GetById(id);
	if (!user.m_login.empty()) {
		current_user = user;
		cout << "������������ " << user.m_login << " ��� ������� �����������." << endl;
	}
	else {
		cout << "��������� ������ �� ����������" << endl;
	}
}

void IUserManager::LoginMenu() {
	while (true) {
		if (!IsAuthorized()) {
			cout << "�������:" << endl << "������������ ��������� ������ - 1" << endl << "����� � ������� �������� - 2" << endl << "������������������ - 3" << endl << "��������� ��������� - 4" << endl;
		}
		else cout << "�������:" << endl << "����� - 2" << endl << "��������� ��������� - 4" << endl;
		int command;
		cin >> command;
		if (command == 1 && !IsAuthorized()) {
			RestoreLast();
		}
		else if (command == 2) {
			if (!IsAuthorized()) SignIn();
			else SignOut();
		}
		else if (command == 3 && !IsAuthorized()) {
			SignUp();
		}
		else if (command == 4) {
			break;
		}
		else cout << "����������� �������" << endl;
	}
}

bool IUserManager::IsAuthorized() {
	return (!current_user.m_login.empty());
};

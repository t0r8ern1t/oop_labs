#pragma once
#include "../controls/Controls.hpp"
#include <iostream>

class LinuxButton : public Button {
public:
	void setText() {
		std::cout << "LinuxButton setText method called" << endl;
	};
	virtual void getText() {
		std::cout << "LinuxButton getText method called" << endl;
	};
	virtual void click() {
		std::cout << "LinuxButton click method called" << endl;
	};
};

class LinuxComboBox : public ComboBox {
public:
	void getSelectedIndex() {
		std::cout << "LinuxComboBox getSelectedIndex method called" << endl;
	};
	void setItems() {
		std::cout << "LinuxComboBox setItems method called" << endl;
	};
	void getItems() {
		std::cout << "LinuxComboBox getItems method called" << endl;
	};
};

class LinuxForm : public Form {
public:
	void addControl() {
		std::cout << "LinuxForm addControl method called" << endl;
	};
};

class LinuxLabel : public Label {
public:
	void setText() {
		std::cout << "LinuxLabel setText method called" << endl;
	};
	void getText() {
		std::cout << "LinuxLabel getText method called" << endl;
	};
};

class LinuxTextBox : public TextBox {
public:
	void setText() {
		std::cout << "LinuxTextBox setText method called" << endl;
	};
	void getText() {
		std::cout << "LinuxTextBox getText method called" << endl;
	};
	void onValueChanged() {
		std::cout << "LinuxTextBox onValueChecked method called" << endl;
	};
};
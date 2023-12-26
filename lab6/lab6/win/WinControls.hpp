#pragma once

#include "../controls/Controls.hpp"
#include <iostream>

class WinButton : public Button {
public:
	void setText() {
		std::cout << "WinButton setText method called" << endl;
	};
	virtual void getText() {
		std::cout << "WinButton getText method called" << endl;
	};
	virtual void click() {
		std::cout << "WinButton click method called" << endl;
	};
};

class WinComboBox : public ComboBox {
public:
	void getSelectedIndex() {
		std::cout << "WinComboBox getSelectedIndex method called" << endl;
	};
	void setItems() {
		std::cout << "WinComboBox setItems method called" << endl;
	};
	void getItems() {
		std::cout << "WinComboBox getItems method called" << endl;
	};
};

class WinForm : public Form {
public:
	void addControl() {
		std::cout << "WinForm addControl method called" << endl;
	};
};

class WinLabel : public Label {
public:
	void setText() {
		std::cout << "WinLabel setText method called" << endl;
	};
	void getText() {
		std::cout << "WinLabel getText method called" << endl;
	};
};

class WinTextBox : public TextBox {
public:
	void setText() {
		std::cout << "WinTextBox setText method called" << endl;
	};
	void getText() {
		std::cout << "WinTextBox getText method called" << endl;
	};
	void onValueChanged() {
		std::cout << "WinTextBox onValueChecked method called" << endl;
	};
};
#pragma once
#include "../controls/Controls.hpp"
#include <iostream>

class MacButton : public Button {
public:
	void setText() {
		std::cout << "MacButton setText method called" << endl;
	};
	virtual void getText() {
		std::cout << "MacButton getText method called" << endl;
	};
	virtual void click() {
		std::cout << "MacButton click method called" << endl;
	};
};

class MacComboBox : public ComboBox {
public:
	void getSelectedIndex() {
		std::cout << "MacComboBox getSelectedIndex method called" << endl;
	};
	void setItems() {
		std::cout << "MacComboBox setItems method called" << endl;
	};
	void getItems() {
		std::cout << "MacComboBox getItems method called" << endl;
	};
};

class MacForm : public Form {
public:
	void addControl() {
		std::cout << "MacForm addControl method called" << endl;
	};
};

class MacLabel : public Label {
public:
	void setText() {
		std::cout << "MacLabel setText method called" << endl;
	};
	void getText() {
		std::cout << "MacLabel getText method called" << endl;
	};
};

class MacTextBox : public TextBox {
public:
	void setText() {
		std::cout << "MacTextBox setText method called" << endl;
	};
	void getText() {
		std::cout << "MacTextBox getText method called" << endl;
	};
	void onValueChanged() {
		std::cout << "MacTextBox onValueChecked method called" << endl;
	};
};
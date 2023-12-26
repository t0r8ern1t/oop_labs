#pragma once
#include <vector>

using namespace std;

class Control {
protected:
	int position;
public:
	Control() { this->position = 0; };
	~Control() {};

	void setPosition(int position) {
		this->position = position;
	}

	int getPosition() {
		return position;
	}
};

class Button : public Control {
public:
	virtual void setText() {};
	virtual void getText() {};
	virtual void click() {};
};

class ComboBox : public Control {
public:
	virtual void getSelectedIndex() {};
	virtual void setItems() {};
	virtual void getItems() {};
};

class Form : public Control {
public:
	virtual void addControl() {};
};

class Label : public Control {
public:
	virtual void setText() {};
	virtual void getText() {};
};

class TextBox : public Control {
public:
	virtual void setText() {};
	virtual void getText() {};
	virtual void onValueChanged() {};
};
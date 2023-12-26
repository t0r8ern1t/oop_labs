#pragma once
#include "Controls.hpp"

class Factory {
public:
	virtual Button* createButton() { return new Button(); };
	virtual ComboBox* createComboBox() { return new ComboBox(); };
	virtual Form* createForm() { return new Form(); };
	virtual Label* createLabel() { return new Label(); };
	virtual TextBox* createTextBox() { return new TextBox(); };
};
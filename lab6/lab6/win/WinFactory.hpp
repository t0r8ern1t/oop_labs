#pragma once

#include "WinControls.hpp"
#include "../controls/Factory.hpp"

class WinFactory : public Factory {
public:
	Button* createButton() {
		return (Button*)new WinButton();
	};
	ComboBox* createComboBox() {
		return (ComboBox*)new WinComboBox();
	};
	Form* createForm() {
		return (Form*)new WinForm();
	};
	Label* createLabel() {
		return (Label*)new WinLabel();
	};
	TextBox* createTextBox() {
		return (TextBox*)new WinTextBox();
	};
};
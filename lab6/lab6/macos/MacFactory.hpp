#pragma once
#include "MacControls.hpp"
#include "../controls/Factory.hpp"

class MacFactory : public Factory {
public:
	Button* createButton() {
		return (Button*)new MacButton();
	};
	ComboBox* createComboBox() {
		return (ComboBox*)new MacComboBox();
	};
	Form* createForm() {
		return (Form*)new MacForm();
	};
	Label* createLabel() {
		return (Label*)new MacLabel();
	};
	TextBox* createTextBox() {
		return (TextBox*)new MacTextBox();
	};
};
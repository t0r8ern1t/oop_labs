#pragma once

#include "LinuxControls.hpp"
#include "../controls/Factory.hpp"

class LinuxFactory : public Factory {
public:
	Button* createButton() {
		return (Button*)new LinuxButton();
	};
	ComboBox* createComboBox() {
		return (ComboBox*)new LinuxComboBox();
	};
	Form* createForm() {
		return (Form*)new LinuxForm();
	};
	Label* createLabel() {
		return (Label*)new LinuxLabel();
	};
	TextBox* createTextBox() {
		return (TextBox*)new LinuxTextBox();
	};
};
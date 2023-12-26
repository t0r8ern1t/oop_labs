#include <iostream>
#include "controls/Factory.hpp"
#include "linux/LinuxFactory.hpp"
#include "macos/MacFactory.hpp"
#include "win/WinFactory.hpp"

using namespace std;

int main()
{
    Factory *factory = new Factory();
    int os = -1;
    while (os != 0) {
        cout << "Choose your OS\nWindows - 1\nLinux - 2\nMacOS - 3\nExit - 0\n";
        cin >> os;
        switch (os) {
        case 1:
            factory = (Factory*)new WinFactory();
            break;
        case 2:
            factory = (Factory*)new LinuxFactory();
            break;
        case 3:
            factory = (Factory*)new MacFactory();
            break;
        }
        factory->createButton()->click();
        factory->createComboBox()->getItems();
        factory->createForm()->addControl();
        factory->createLabel()->getText();
        factory->createTextBox()->getText();
        cout << endl << endl;
    }
}
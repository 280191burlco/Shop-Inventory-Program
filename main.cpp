#include <cmath> //needed for inventory calculations
#include <iostream> //needed for cout/cin
#include <vector> //number storing/adding + subtraction numbers from inv
#include <string> //text input
#include <functional> //required for function selection
using namespace std;

/* 
How to use:
Run the program
Select what part you are looking for
Select adding/subtracting
Select corresponding part # (eg 1 ohm = 1 so input should be 1)
Enter how many you are adding/removing
Re-loop for the part or return to main menu
Rinse and repeat for all of the other parts, or end the program*/

//fucntion list to be called
void intro (int& invChoice);
void resistorStockDisplay();
void miscStockDisplay();
void capacitorStockDisplay();
void potentiometerStockDisplay();
void icStockDisplay();
void batteryDisplay();
void bSDisplay();
void ledDisplay();
void endProgram();

vector<string> resistors = {
	"1 ohm", "1.2 ohm", "1.5 ohm", "1.8 ohm", "2.2 ohm", "2.7 ohm", "3.3 ohm", "3.9 ohm", "4.7 ohm", "5.6 ohm",
	"6.8 ohm", "8.2 ohm", "10 ohm", "12 ohm", "15 ohm", "18 ohm", "22 ohm", "27 ohm", "33 ohm", "39 ohm",
	"47 ohm", "56 ohm", "68 ohm", "82 ohm", "100 ohm", "120 ohm", "150 ohm", "180 ohm", "200 ohm", "220 ohm",
	"270 ohm", "300 ohm", "330 ohm", "390 ohm", "470 ohm", "560 ohm", "620 ohm", "680 ohm", "820 ohm", "1k ohm",
	"1.2k ohm", "1.5k ohm", "1.8k ohm", "2.2k ohm", "2.7k ohm", "3.3k ohm", "3.9k ohm", "4.7k ohm", "5.6k ohm", "6.8k ohm",
	"8.2k ohm", "10k ohm", "12k ohm", "15k ohm", "18k ohm", "22k ohm", "27k ohm", "33k ohm", "39k ohm", "47k ohm",
	"56k ohm", "68k ohm", "75k ohm", "82k ohm", "100k ohm", "120k ohm", "150k ohm", "180k ohm", "220k ohm", "270k ohm",
	"330k ohm", "390k ohm", "470k ohm", "560k ohm", "680k ohm", "820k ohm", "1M ohm","4.7M ohm","10M ohm", "22M ohm",
};

	vector<int> rstock = {//resistor stock matching the resistor list
    64, 98, 98, 100, 82, 100, 87, 90, 98, 91, 93, 81, 59, 95, 83, 87, 91, 82, 261, 79, 143, 23, 81, 75, 24, 18, 519, 450, 31, 26,
    459, 214, 595, 23, 357, 359, 266, 26, 35, 43, 390, 62, 255, 353, 291, 306, 103, 428, 275, 225, 194, 223, 64, 71, 1, 279, 350, 87,
    118, 92, 295, 93, 86, 114, 82, 253, 92, 169, 90, 75, 90, 386, 75, 216, 94, 103, 92, 1, 7, 37
	};

	vector<string> misc = {//list of available misc items
	    "10 uH", "22uH", "47uH", "220uH", "1mH", "2.2mH", "4.7mH", "10mH", "22mH", "33mH", "47mH", "100mH", "Bread Board"
	};

	vector<int> mstock = {//misc stock matching the misc list
	81, 88, 90, 60, 48, 42, 45, 33, 64, 50, 59, 76, 15
	};

	vector<string> capacitor = {//capacitor names
	"474k Radial", "105k Radial", "102k Radial", "224k Radial", "104k Radial", "473k Radial", "103k Radial", "101k Radial", ".1 J Radial",
	".47 Micro F", "1 Micro F", "220 Micro F", "4.7 Micro F Ax", "4.7 Micro F", "330 Micro F", "470 Micro F", "22 Micro F", "10 Micro F",
	"4700 Micro F", "47 Micro F", "1000 Micro F", "2200 Micro F", "100 Micro F Ax", "33 Micro F", "100 Micro F"
	};

	vector<int> cstock = { //capacitor stock
	25, 91, 149, 7, 2, 14, 14, 2, 2, 379, 203, 17, 111, 253, 0, 47, 946, 700, 0, 481, 31, 38, 2, 308, 271
	};

	vector<string> potentiometer = { //potentiometer names
	"1k ohm pot", "5k ohm pot", "50k ohm pot", "100k ohm pot", "1M ohm pot", "2M ohm pot"
	};

	vector<int> pstock = { //potentiometer stock
	1, 6, 1, 11, 1, 1
	};

	vector<string> icChips = {//icchip names
	"IC Chip 7409", "IC Chip 4001", "IC Chip 4017", "IC Chip 4029", "IC Chip 74157", "IC Chip 9526", "IC Chip 7420", "IC Chip 74595", "IC Chip 7719",
	"IC Chip 4511", "IC Chip 9525", "IC Chip 74151", "IC Chip 74193", "IC Chip 4011", "IC Chip 7488", "IC Chip 7489", "IC Chip 7402", "IC Chip 7411", "IC Chip 7409",
	"IC Chip 7490", "IC Chip 9226", "IC Chip 7414", "IC Chip 7400", "IC Chip 7408", "IC Chip 7402", "IC Chip 74147", "IC Chip 74037", "IC Chip 7432", "IC Chip 7486",
	"IC Chip 7451", "IC Chip MH7489", "IC Chip 7932", "IC Chip 7485", "IC Chip 74138", "IC Chip 7474", "IC Chip 74154", "IC Chip 74125", "IC Chip 74190",
	"IC Chip 7430", "IC Chip 74191", "IC Chip 74107", "IC Chip 74192", "IC Chip 74148", "IC Chip 7495", "IC Chip 7447", "IC Chip 7442", "IC Chip 74121",
	"IC Chip 7475", "IC Chip 74163", "IC Chip 74150", "IC Chip 74164"
	};

	vector<int> icstock = {//icchip stock
	7, 5, 8, 2, 3, 3, 2, 1, 4, 2, 5, 1, 2, 8, 1, 26, 89, 84, 7, 9, 3, 146, 77, 4, 9, 14, 28, 42, 89, 27, 197, 75, 70, 33, 47, 84, 25, 42, 74, 74, 56, 283, 64, 69,
	30, 3, 51, 47, 22, 30, 136
	};

	vector<string> battery = {//battery names
	"9V", "1.5V"
	};

	vector<int> bstock = {//battery stock
	5, 3
	};

	vector<string> bs = {//buttons and switches names
	"Buttons", "8 Prong Switch", "4 Prong Switch", "3 Prong Switch", "2 Prong Switch"
	};

	vector<int> bsstock = {//buttons and switches stock
	4, 1, 2, 10, 1
	};

	vector<string> led = {//led names
	"White LED", "Red LED", "Green LED", "Yellow LED"
	};

	vector<int> lstock = {//led stock
	66, 368, 102, 73
	};

int main() {

    //ints to be stored
	int invChoice;

	while (true) { //loop the inventory choice
    intro(invChoice);
}

return 0;
}

void intro (int& invChoice) { //List of functions to select from
    vector<function<void()>> functions = {
        resistorStockDisplay,
        miscStockDisplay,
        capacitorStockDisplay,
        potentiometerStockDisplay,
        icStockDisplay,
        batteryDisplay,
        bSDisplay,
        ledDisplay,
        endProgram
    };

    cout << "----------------------\n";
    cout << "    Shop Inventory    \n";
    cout << "----------------------\n";

    while (true) { //Begin the selection loop
        cout << "\n1. Resistor Inventory\n"
                "2. Inductor Inventory\n"
                "3. Capacitor Inventory\n"
                "4. Potentiometer Inventory\n"
                "5. IC Chip Inventory\n"
                "6. Battery Inventory\n"
                "7. Buttons/Switches Inventory\n"
                "8. LED Inventory\n"
                "9. End Program\n\n"
                "Input: ";
        cin >> invChoice;

        if (cin.fail()) { //Prevent a non-number from being entered
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input. Please enter a number.\n";
            continue;
        }

        if (invChoice >= 1 && invChoice <= functions.size()) { //Determine what function the user wants to view
            functions[invChoice - 1]();
            return;
        }

        cout << "Invalid selection.\n";
    }
}

void resistorStockDisplay() {
    while (true) {
        cout << "Current Resistor Stock:\n\n";

        for (int i = 0; i < resistors.size(); i++) {
            cout << i + 1 << ". " << resistors[i] << ": " << rstock[i] << endl;
        }

        cout << "\n1. Add Resistor\n"
                "2. Remove Resistor\n"
                "3. Return to Menu\n\n"
                "Input: ";
        int rOption;
        cin >> rOption;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input.\n\n";
            continue;
        }

        if (rOption == 1) {
            int index, amount;
            cout << "Enter resistor number to add: ";
            cin >> index;
            cout << "Enter amount to add: ";
            cin >> amount;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Invalid Input.\n\n";
                continue;
            }

            if (amount < 0) {
            cout << "Amount cannot be negative.\n\n";
            continue;
            }


            if (index >= 1 && index <= resistors.size()) {
                rstock[index - 1] += amount;

                cout << "Added successfully, new stock of "
                     << resistors[index - 1]
                     << " is "
                     << rstock[index - 1]
                     << "\n\n";
            } else {
                cout << "Invalid resistor number.\n\n";
            }
        } else if (rOption == 2) {
            int index, amount;
            cout << "Enter resistor number to remove: ";
            cin >> index;
            cout << "Enter amount to remove: ";
            cin >> amount;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Invalid Input.\n\n";
                continue;
            }

            if (amount < 0) {
               cout << "Amount cannot be negative.\n\n";
                continue;
            }

            if (index >= 1 && index <= resistors.size()) {
                if (rstock[index - 1] >= amount) {
                    rstock[index - 1] -= amount;

                    cout << "Removed successfully, new stock of "
                         << resistors[index - 1]
                         << " is "
                         << rstock[index - 1]
                         << "\n\n";
                } else {
                    cout << "Not enough stock.\n\n";
                }
            } else {
                cout << "Invalid resistor number.\n\n";
            }
        } else if (rOption == 3) {
            cout << "Returning to menu...\n\n";
            break;
        } else {
            cout << "Invalid selection.\n\n";
        }
    }
}

void miscStockDisplay() {
while(true) {
    cout << "Current Inductor Stock:\n\n";

    for (int i = 0; i < misc.size(); i++) {
        cout << i + 1 << ". " << misc[i] << ": " << mstock[i] << endl;
    }
    cout << "\n1. Add Inductor\n"
            "2. Remove Inductor\n"
            "3. Return to menu\n\n"
            "Input: ";
    int mOption;
    cin >> mOption;
    if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input.\n\n";
            continue;
        }
    if (mOption == 1) {
        int index, amount;
        cout << "Enter Inductor Number to add: ";
        cin >> index;
        cout << "Enter amount you are adding: ";
        cin >> amount;

    if (index >= 1 && index <= misc.size()) {
        mstock [index - 1] += amount;
        cout << "Added successfully, new stock of "
             << misc[index - 1]
             << " is "
             << mstock[index - 1]
             << "\n\n";
    } else {
    cout << "Invalid Inductor Number";
    }
    } else if (mOption ==2) {
    int index, amount;
    cout << "Enter Inductor to remove: ";
    cin >> index;
    cout << "Enter amount to remove: ";
    cin >> amount;

    if (index >=1 && index <= misc.size()) {
        if (mstock[index - 1] >= amount) {
            mstock[index - 1] -= amount;

            cout << "Removed successfully, new stock of "
                         << misc[index - 1]
                         << " is "
                         << mstock[index - 1]
                         << "\n\n";
        } else {
        cout << "Not enough Stock.\n\n";
        }
    } else {
    cout << "Invalid Inductor Selection.\n\n";
    }
    } else if (mOption == 3) {
    cout << "Returning to main menu...\n\n";
    break;
    } else {
    cout << "Invalid Selection.\n\n";
    }
}
}

void capacitorStockDisplay() {
while(true) {
    cout << "Current Capacitor Stock:\n\n";

    for (int i = 0; i < capacitor.size(); i++) {
        cout << i + 1 << ". " << capacitor[i] << ": " << cstock[i] << endl;
    }
    cout << "\n1. Add Capacitor\n"
            "2. Remove Capacitor\n"
            "3. Return to menu\n\n"
            "Input: ";
    int cOption;
    cin >> cOption;
    if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input.\n\n";
            continue;
        }
    if (cOption == 1) {
        int index, amount;
        cout << "Enter Capacitor Number to add: ";
        cin >> index;
        cout << "Enter amount you are adding: ";
        cin >> amount;

    if (index >= 1 && index <= capacitor.size()) {
        cstock [index - 1] += amount;
        cout << "Added successfully, new stock of "
             << capacitor[index - 1]
             << " is "
             << cstock[index - 1]
             << "\n\n";
    } else {
    cout << "Invalid Capacitor Number";
    }
    } else if (cOption ==2) {
    int index, amount;
    cout << "Enter capacitor number to remove: ";
    cin >> index;
    cout << "Enter amount to remove: ";
    cin >> amount;

    if (index >=1 && index <= capacitor.size()) {
        if (cstock[index - 1] >= amount) {
            cstock[index - 1] -= amount;

            cout << "Removed successfully, new stock of "
                         << capacitor[index - 1]
                         << " is "
                         << cstock[index - 1]
                         << "\n\n";
        } else {
        cout << "Not enough Stock.\n\n";
        }
    } else {
    cout << "Invalid Capacitor Number.\n\n";
    }
    } else if (cOption == 3) {
    cout << "Returning to main menu...\n\n";
    break;
    } else {
    cout << "Invalid Selection.\n\n";
    }
}
}

void potentiometerStockDisplay() {
while(true) {
    cout << "Current Potentiometer Stock:\n\n";

    for (int i = 0; i < potentiometer.size(); i++) {
        cout << i + 1 << ". " << potentiometer[i] << ": " << pstock[i] << endl;
    }
    cout << "\n1. Add Potentiometer Item\n"
            "2. Remove Potentiometer Item\n"
            "3. Return to menu\n\n"
            "Input: ";
    int pOption;
    cin >> pOption;
    if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input.\n\n";
            continue;
        }
    if (pOption == 1) {
        int index, amount;
        cout << "Enter Potentiometer number to add: ";
        cin >> index;
        cout << "Enter amount you are adding: ";
        cin >> amount;

    if (index >= 1 && index <= potentiometer.size()) {
        pstock [index - 1] += amount;
        cout << "Added successfully, new stock of "
             << potentiometer[index - 1]
             << " is "
             << pstock[index - 1]
             << "\n\n";
    } else {
    cout << "Invalid Misc Number";
    }
    } else if (pOption ==2) {
    int index, amount;
    cout << "Enter Potentiometer to remove: ";
    cin >> index;
    cout << "Enter amount to remove: ";
    cin >> amount;

    if (index >=1 && index <= potentiometer.size()) {
        if (pstock[index - 1] >= amount) {
            pstock[index - 1] -= amount;

            cout << "Removed successfully, new stock of "
                         << potentiometer[index - 1]
                         << " is "
                         << pstock[index - 1]
                         << "\n\n";
        } else {
        cout << "Not enough Stock.\n\n";
        }
    } else {
    cout << "Invalid Potentiometer Selection.\n\n";
    }
    } else if (pOption == 3) {
    cout << "Returning to main menu...\n\n";
    break;
    } else {
    cout << "Invalid Selection.\n\n";
    }
}
}

void icStockDisplay() {
    while (true) {
        cout << "Current IC Chip Stock:\n\n";

        for (int i = 0; i < icChips.size(); i++) {
            cout << i + 1 << ". " << icChips[i] << ": " << icstock[i] << endl;
        }

        cout << "\n1. Add IC Chip\n"
                "2. Remove IC Chip\n"
                "3. Return to Menu\n\n"
                "Input: ";
        int icOption;
        cin >> icOption;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input.\n\n";
            continue;
        }

        if (icOption == 1) {
            int index, amount;
            cout << "Enter IC Chip number to add: ";
            cin >> index;
            cout << "Enter amount to add: ";
            cin >> amount;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Invalid Input.\n\n";
                continue;
            }

            if (amount < 0) {
            cout << "Amount cannot be negative.\n\n";
            continue;
            }


            if (index >= 1 && index <= icChips.size()) {
                icstock[index - 1] += amount;

                cout << "Added successfully, new stock of "
                     << icChips[index - 1]
                     << " is "
                     << icstock[index - 1]
                     << "\n\n";
            } else {
                cout << "Invalid IC Chip number.\n\n";
            }
        } else if (icOption == 2) {
            int index, amount;
            cout << "Enter IC Chip number to remove: ";
            cin >> index;
            cout << "Enter amount to remove: ";
            cin >> amount;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Invalid Input.\n\n";
                continue;
            }

            if (amount < 0) {
               cout << "Amount cannot be negative.\n\n";
                continue;
            }

            if (index >= 1 && index <= icChips.size()) {
                if (icstock[index - 1] >= amount) {
                    icstock[index - 1] -= amount;

                    cout << "Removed successfully, new stock of "
                         << icChips[index - 1]
                         << " is "
                         << icstock[index - 1]
                         << "\n\n";
                } else {
                    cout << "Not enough stock.\n\n";
                }
            } else {
                cout << "Invalid IC Chip number.\n\n";
            }
        } else if (icOption == 3) {
            cout << "Returning to menu...\n\n";
            break;
        } else {
            cout << "Invalid selection.\n\n";
        }
    }
}

void batteryDisplay() {
while (true) {
        cout << "Current Battery Stock:\n\n";

        for (int i = 0; i < battery.size(); i++) {
            cout << i + 1 << ". " << battery[i] << ": " << bstock[i] << endl;
        }

        cout << "\n1. Add Battery\n"
                "2. Remove Battery\n"
                "3. Return to Menu\n\n"
                "Input: ";
        int bOption;
        cin >> bOption;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input.\n\n";
            continue;
        }

        if (bOption == 1) {
            int index, amount;
            cout << "Enter Battery number to add: ";
            cin >> index;
            cout << "Enter amount to add: ";
            cin >> amount;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Invalid Input.\n\n";
                continue;
            }

            if (amount < 0) {
            cout << "Amount cannot be negative.\n\n";
            continue;
            }


            if (index >= 1 && index <= battery.size()) {
                bstock[index - 1] += amount;

                cout << "Added successfully, new stock of "
                     << battery[index - 1]
                     << " is "
                     << bstock[index - 1]
                     << "\n\n";
            } else {
                cout << "Invalid battery number.\n\n";
            }
        } else if (bOption == 2) {
            int index, amount;
            cout << "Enter battery number to remove: ";
            cin >> index;
            cout << "Enter amount to remove: ";
            cin >> amount;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Invalid Input.\n\n";
                continue;
            }

            if (amount < 0) {
               cout << "Amount cannot be negative.\n\n";
                continue;
            }

            if (index >= 1 && index <= battery.size()) {
                if (bstock[index - 1] >= amount) {
                    bstock[index - 1] -= amount;

                    cout << "Removed successfully, new stock of "
                         << battery[index - 1]
                         << " is "
                         << bstock[index - 1]
                         << "\n\n";
                } else {
                    cout << "Not enough stock.\n\n";
                }
            } else {
                cout << "Invalid Battery number.\n\n";
            }
        } else if (bOption == 3) {
            cout << "Returning to menu...\n\n";
            break;
        } else {
            cout << "Invalid selection.\n\n";
        }
    }
}

void bSDisplay() {
while (true) {
        cout << "Current Buttons and Switches Stock:\n\n";

        for (int i = 0; i < bs.size(); i++) {
            cout << i + 1 << ". " << bs[i] << ": " << bsstock[i] << endl;
        }

        cout << "\n1. Add Button or Switch\n"
                "2. Remove Button or Switch\n"
                "3. Return to Menu\n\n"
                "Input: ";
        int bsOption;
        cin >> bsOption;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input.\n\n";
            continue;
        }

        if (bsOption == 1) {
            int index, amount;
            cout << "Enter Button or Switch number to add: ";
            cin >> index;
            cout << "Enter amount to add: ";
            cin >> amount;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Invalid Input.\n\n";
                continue;
            }

            if (amount < 0) {
            cout << "Amount cannot be negative.\n\n";
            continue;
            }


            if (index >= 1 && index <= bs.size()) {
                bsstock[index - 1] += amount;

                cout << "Added successfully, new stock of "
                     << bs[index - 1]
                     << " is "
                     << bsstock[index - 1]
                     << "\n\n";
            } else {
                cout << "Invalid Button or Switch number.\n\n";
            }
        } else if (bsOption == 2) {
            int index, amount;
            cout << "Enter Button or Switch number to remove: ";
            cin >> index;
            cout << "Enter amount to remove: ";
            cin >> amount;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Invalid Input.\n\n";
                continue;
            }

            if (amount < 0) {
               cout << "Amount cannot be negative.\n\n";
                continue;
            }

            if (index >= 1 && index <= bs.size()) {
                if (bsstock[index - 1] >= amount) {
                    bsstock[index - 1] -= amount;

                    cout << "Removed successfully, new stock of "
                         << bs[index - 1]
                         << " is "
                         << bsstock[index - 1]
                         << "\n\n";
                } else {
                    cout << "Not enough stock.\n\n";
                }
            } else {
                cout << "Invalid Button or Switch number.\n\n";
            }
        } else if (bsOption == 3) {
            cout << "Returning to menu...\n\n";
            break;
        } else {
            cout << "Invalid selection.\n\n";
        }
    }
}

void ledDisplay() {
while (true) {
        cout << "Current LED Stock:\n\n";

        for (int i = 0; i < led.size(); i++) {
            cout << i + 1 << ". " << led[i] << ": " << lstock[i] << endl;
        }

        cout << "\n1. Add LED\n"
                "2. Remove LED\n"
                "3. Return to Menu\n\n"
                "Input: ";
        int lOption;
        cin >> lOption;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input.\n\n";
            continue;
        }

        if (lOption == 1) {
            int index, amount;
            cout << "Enter LED number to add: ";
            cin >> index;
            cout << "Enter amount to add: ";
            cin >> amount;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Invalid Input.\n\n";
                continue;
            }

            if (amount < 0) {
            cout << "Amount cannot be negative.\n\n";
            continue;
            }


            if (index >= 1 && index <= led.size()) {
                lstock[index - 1] += amount;

                cout << "Added successfully, new stock of "
                     << led[index - 1]
                     << " is "
                     << lstock[index - 1]
                     << "\n\n";
            } else {
                cout << "Invalid LED number.\n\n";
            }
        } else if (lOption == 2) {
            int index, amount;
            cout << "Enter LED number to remove: ";
            cin >> index;
            cout << "Enter amount to remove: ";
            cin >> amount;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Invalid Input.\n\n";
                continue;
            }

            if (amount < 0) {
               cout << "Amount cannot be negative.\n\n";
                continue;
            }

            if (index >= 1 && index <= led.size()) {
                if (lstock[index - 1] >= amount) {
                    lstock[index - 1] -= amount;

                    cout << "Removed successfully, new stock of "
                         << led[index - 1]
                         << " is "
                         << lstock[index - 1]
                         << "\n\n";
                } else {
                    cout << "Not enough stock.\n\n";
                }
            } else {
                cout << "Invalid LED number.\n\n";
            }
        } else if (lOption == 3) {
            cout << "Returning to menu...\n\n";
            break;
        } else {
            cout << "Invalid selection.\n\n";
        }
    }
}

void endProgram(){
cout << "Exiting...\n";
exit(0);
}

#include <iostream>
using namespace std;

/* ---------- Safe Input Function ---------- */
int getBitInput(string name) {
    int value;

    while (true) {
        cout << "Enter " << name << " (0 or 1): ";
        cin >> value;

        if (cin.fail() || (value != 0 && value != 1)) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input. Please enter ONLY 0 or 1.\n";
        } else {
            return value;
        }
    }
}

/* ---------- Basic AND-OR Circuit ---------- */
void basicCircuit() {
    int A = getBitInput("A");
    int B = getBitInput("B");

    int C = A & B;
    int D = C | B;

    cout << "\n--- Circuit Output ---\n";
    cout << "A = " << A << endl;
    cout << "B = " << B << endl;
    cout << "C (A AND B) = " << C << endl;
    cout << "D (C OR B) = " << D << endl;
}

/* ---------- Half Adder ---------- */
void halfAdder() {
    int A = getBitInput("A");
    int B = getBitInput("B");

    int Sum = A ^ B;
    int Carry = A & B;

    cout << "\n--- Half Adder Output ---\n";
    cout << "Sum: " << Sum << endl;
    cout << "Carry: " << Carry << endl;
}

/* ---------- Full Adder ---------- */
void fullAdder() {
    int A = getBitInput("A");
    int B = getBitInput("B");
    int Cin = getBitInput("Cin");

    int Sum = A ^ B ^ Cin;
    int Cout = (A & B) | (B & Cin) | (A & Cin);

    cout << "\n--- Full Adder Output ---\n";
    cout << "Sum: " << Sum << endl;
    cout << "Carry Out: " << Cout << endl;
}

/* ---------- XOR Gate ---------- */
void xorGate() {
    int A = getBitInput("A");
    int B = getBitInput("B");

    int result = A ^ B;

    cout << "\n--- XOR Gate Output ---\n";
    cout << "Output: " << result << endl;
}

/* ---------- MAIN MENU ---------- */
int main() {

    int choice;

    while (true) {

        cout << "\n========== Logic Simulator ==========\n";
        cout << "1. Basic AND-OR Circuit\n";
        cout << "2. Half Adder\n";
        cout << "3. Full Adder\n";
        cout << "4. XOR Gate\n";
        cout << "5. Exit\n";
        cout << "Choose option: ";

        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid choice. Try again.\n";
            continue;
        }

        switch (choice) {
            case 1:
                basicCircuit();
                break;
            case 2:
                halfAdder();
                break;
            case 3:
                fullAdder();
                break;
            case 4:
                xorGate();
                break;
            case 5:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid option. Try again.\n";
        }
    }

    return 0;
}
#include <iostream>
using namespace std;

void basicAndOr() {
    int A, B;

    cout << "\nEnter A (0 or 1): ";
    cin >> A;
    cout << "Enter B (0 or 1): ";
    cin >> B;

    cout << "\nAND Output: " << (A & B) << endl;
    cout << "OR Output: " << (A | B) << endl;
}

void halfAdder() {
    int A, B;

    cout << "\nEnter A (0 or 1): ";
    cin >> A;
    cout << "Enter B (0 or 1): ";
    cin >> B;

    int Sum = A ^ B;
    int Carry = A & B;

    cout << "\nSum: " << Sum << endl;
    cout << "Carry: " << Carry << endl;
}

void fullAdder() {
    int A, B, Cin;

    cout << "\nEnter A (0 or 1): ";
    cin >> A;
    cout << "Enter B (0 or 1): ";
    cin >> B;
    cout << "Enter Cin (0 or 1): ";
    cin >> Cin;

    int Sum = A ^ B ^ Cin;
    int Cout = (A & B) | (B & Cin) | (A & Cin);

    cout << "\nSum: " << Sum << endl;
    cout << "Carry Out: " << Cout << endl;
}

int main() {
    int choice;

    while (true) {
        cout << "\n========== Logic Simulator ==========\n";
        cout << "1. Basic AND-OR Circuit\n";
        cout << "2. Half Adder\n";
        cout << "3. Full Adder\n";
        cout << "4. Exit\n";
        cout << "Choose option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                basicAndOr();
                break;
            case 2:
                halfAdder();
                break;
            case 3:
                fullAdder();
                break;
            case 4:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}

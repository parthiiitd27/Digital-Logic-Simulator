#include <iostream>
#include <string>

using namespace std;

/* ===========================
   HALF ADDER
=========================== */
void halfAdder() {
    int A, B;

    cout << "\n--- Half Adder ---\n";
    cout << "Enter A (0 or 1): ";
    cin >> A;
    cout << "Enter B (0 or 1): ";
    cin >> B;

    if ((A != 0 && A != 1) || (B != 0 && B != 1)) {
        cout << "Invalid input! Only 0 or 1 allowed.\n";
        return;
    }

    int sum = A ^ B;
    int carry = A & B;

    cout << "Sum: " << sum << endl;
    cout << "Carry: " << carry << endl;
}

/* ===========================
   FULL ADDER
=========================== */
void fullAdder() {
    int A, B, Cin;

    cout << "\n--- Full Adder ---\n";
    cout << "Enter A (0 or 1): ";
    cin >> A;
    cout << "Enter B (0 or 1): ";
    cin >> B;
    cout << "Enter Carry In (0 or 1): ";
    cin >> Cin;

    if ((A != 0 && A != 1) ||
        (B != 0 && B != 1) ||
        (Cin != 0 && Cin != 1)) {
        cout << "Invalid input! Only 0 or 1 allowed.\n";
        return;
    }

    int sum = A ^ B ^ Cin;
    int carry = (A & B) | (Cin & (A ^ B));

    cout << "Sum: " << sum << endl;
    cout << "Carry: " << carry << endl;
}

/* ===========================
   RIPPLE CARRY ADDER
=========================== */
void rippleCarryAdder() {
    string A, B;

    cout << "\n--- Ripple Carry Adder ---\n";
    cout << "Enter first binary number: ";
    cin >> A;
    cout << "Enter second binary number: ";
    cin >> B;

    // Make both same length
    while (A.length() < B.length())
        A = "0" + A;

    while (B.length() < A.length())
        B = "0" + B;

    int n = A.length();
    string result = "";
    int carry = 0;

    for (int i = n - 1; i >= 0; i--) {
        if ((A[i] != '0' && A[i] != '1') ||
            (B[i] != '0' && B[i] != '1')) {
            cout << "Invalid binary number!\n";
            return;
        }

        int a = A[i] - '0';
        int b = B[i] - '0';

        int sum = a ^ b ^ carry;
        carry = (a & b) | (carry & (a ^ b));

        result = char(sum + '0') + result;
    }

    if (carry)
        result = "1" + result;

    cout << "Result: " << result << endl;
}

/* ===========================
   MAIN MENU
=========================== */
int main() {
    int choice;

    while (true) {
        cout << "\n========== Logic Simulator ==========\n";
        cout << "1. Half Adder\n";
        cout << "2. Full Adder\n";
        cout << "3. Ripple Carry Adder\n";
        cout << "4. Exit\n";
        cout << "Choose option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                halfAdder();
                break;
            case 2:
                fullAdder();
                break;
            case 3:
                rippleCarryAdder();
                break;
            case 4:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid option. Try again.\n";
        }
    }

    return 0;
}
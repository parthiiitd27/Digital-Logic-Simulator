#include <iostream>
using namespace std;

/* ================= BASIC GATES ================= */

int AND(int a, int b) { return a & b; }
int OR(int a, int b) { return a | b; }
int XOR(int a, int b) { return a ^ b; }

/* ================= HALF ADDER ================= */

void halfAdder(int a, int b, int &sum, int &carry) {
    sum = XOR(a, b);
    carry = AND(a, b);
}

/* ================= FULL ADDER ================= */

void fullAdder(int a, int b, int cin, int &sum, int &carry) {
    int s1, c1, c2;

    halfAdder(a, b, s1, c1);
    halfAdder(s1, cin, sum, c2);
    carry = OR(c1, c2);
}

/* ================= RIPPLE CARRY ADDER ================= */

void rippleCarryAdder() {
    int n;

    cout << "\nEnter number of bits: ";
    cin >> n;

    int A[32], B[32];
    int sum[32];
    int carry = 0;

    cout << "Enter bits for A (LSB first): ";
    for (int i = 0; i < n; i++)
        cin >> A[i];

    cout << "Enter bits for B (LSB first): ";
    for (int i = 0; i < n; i++)
        cin >> B[i];

    for (int i = 0; i < n; i++) {
        fullAdder(A[i], B[i], carry, sum[i], carry);
    }

    cout << "\nResult: ";
    for (int i = n - 1; i >= 0; i--)
        cout << sum[i];

    cout << "\nFinal Carry: " << carry << endl;
}

/* ================= MAIN MENU ================= */

int main() {
    int choice;

    while (true) {
        cout << "\n========== Logic Simulator ==========\n";
        cout << "1. Basic AND-OR Circuit\n";
        cout << "2. Half Adder\n";
        cout << "3. Full Adder\n";
        cout << "4. Ripple Carry Adder\n";
        cout << "5. Exit\n";
        cout << "Choose option: ";
        cin >> choice;

        if (choice == 1) {
            int a, b;
            cout << "Enter A (0 or 1): ";
            cin >> a;
            cout << "Enter B (0 or 1): ";
            cin >> b;
            cout << "AND: " << AND(a, b) << endl;
            cout << "OR: " << OR(a, b) << endl;
        }

        else if (choice == 2) {
            int a, b, sum, carry;
            cout << "Enter A (0 or 1): ";
            cin >> a;
            cout << "Enter B (0 or 1): ";
            cin >> b;
            halfAdder(a, b, sum, carry);
            cout << "Sum: " << sum << endl;
            cout << "Carry: " << carry << endl;
        }

        else if (choice == 3) {
            int a, b, cin, sum, carry;
            cout << "Enter A (0 or 1): ";
            cin >> a;
            cout << "Enter B (0 or 1): ";
            cin >> b;
            cout << "Enter Carry In (0 or 1): ";
            cin >> cin;
            fullAdder(a, b, cin, sum, carry);
            cout << "Sum: " << sum << endl;
            cout << "Carry Out: " << carry << endl;
        }

        else if (choice == 4) {
            rippleCarryAdder();
        }

        else if (choice == 5) {
            cout << "Exiting...\n";
            break;
        }

        else {
            cout << "Invalid choice.\n";
        }
    }

    return 0;
}
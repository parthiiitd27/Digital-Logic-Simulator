#include <iostream>
using namespace std;

/* ================= BASIC GATES ================= */

int AND(int a, int b) { return a & b; }
int OR(int a, int b) { return a | b; }
int XOR(int a, int b) { return a ^ b; }
int NOT(int a) { return a ^ 1; }

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

void rippleCarryAdder(int A[], int B[], int n, int result[]) {
    int carry = 0;
    for (int i = 0; i < n; i++) {
        fullAdder(A[i], B[i], carry, result[i], carry);
    }
}

/* ================= SUBTRACTOR ================= */

void rippleCarrySubtractor(int A[], int B[], int n, int result[]) {
    int B_comp[32];

    // Invert B
    for (int i = 0; i < n; i++)
        B_comp[i] = NOT(B[i]);

    // Add 1 (2's complement)
    int carry = 1;
    for (int i = 0; i < n; i++)
        fullAdder(B_comp[i], 0, carry, B_comp[i], carry);

    rippleCarryAdder(A, B_comp, n, result);
}

/* ================= MULTI-BIT LOGIC OPS ================= */

void bitwiseAND(int A[], int B[], int n, int result[]) {
    for (int i = 0; i < n; i++)
        result[i] = AND(A[i], B[i]);
}

void bitwiseOR(int A[], int B[], int n, int result[]) {
    for (int i = 0; i < n; i++)
        result[i] = OR(A[i], B[i]);
}

void bitwiseXOR(int A[], int B[], int n, int result[]) {
    for (int i = 0; i < n; i++)
        result[i] = XOR(A[i], B[i]);
}

/* ================= ALU ================= */

void ALU() {
    int n;
    cout << "\nEnter number of bits: ";
    cin >> n;

    int A[32], B[32], result[32];

    cout << "Enter bits for A (LSB first): ";
    for (int i = 0; i < n; i++)
        cin >> A[i];

    cout << "Enter bits for B (LSB first): ";
    for (int i = 0; i < n; i++)
        cin >> B[i];

    cout << "\nSelect Operation:\n";
    cout << "1. ADD\n";
    cout << "2. SUBTRACT\n";
    cout << "3. AND\n";
    cout << "4. OR\n";
    cout << "5. XOR\n";
    cout << "Choice: ";

    int op;
    cin >> op;

    switch (op) {
        case 1:
            rippleCarryAdder(A, B, n, result);
            break;
        case 2:
            rippleCarrySubtractor(A, B, n, result);
            break;
        case 3:
            bitwiseAND(A, B, n, result);
            break;
        case 4:
            bitwiseOR(A, B, n, result);
            break;
        case 5:
            bitwiseXOR(A, B, n, result);
            break;
        default:
            cout << "Invalid operation.\n";
            return;
    }

    cout << "\nResult: ";
    for (int i = n - 1; i >= 0; i--)
        cout << result[i];
    cout << endl;
}

/* ================= MAIN MENU ================= */

int main() {
    int choice;

    while (true) {
        cout << "\n========== Logic Simulator ==========\n";
        cout << "1. Half Adder\n";
        cout << "2. Full Adder\n";
        cout << "3. Ripple Carry Adder\n";
        cout << "4. Binary Subtractor\n";
        cout << "5. ALU\n";
        cout << "6. Exit\n";
        cout << "Choose option: ";
        cin >> choice;

        if (choice == 1) {
            int a, b, sum, carry;
            cout << "Enter A (0 or 1): ";
            cin >> a;
            cout << "Enter B (0 or 1): ";
            cin >> b;
            halfAdder(a, b, sum, carry);
            cout << "Sum: " << sum << endl;
            cout << "Carry: " << carry << endl;
        }
        else if (choice == 2) {
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
        else if (choice == 3) {
            ALU(); // reuse ALU for addition
        }
        else if (choice == 4) {
            ALU(); // reuse ALU for subtraction
        }
        else if (choice == 5) {
            ALU();
        }
        else if (choice == 6) {
            cout << "Exiting...\n";
            break;
        }
        else {
            cout << "Invalid choice.\n";
        }
    }

    return 0;
}
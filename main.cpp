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

void rippleCarryAdder(int A[], int B[], int n, int result[], int &finalCarry) {
    int carry = 0;
    for (int i = 0; i < n; i++)
        fullAdder(A[i], B[i], carry, result[i], carry);
    finalCarry = carry;
}

/* ================= SUBTRACTOR ================= */

void rippleCarrySubtractor(int A[], int B[], int n, int result[], int &finalCarry) {
    int B_comp[32];

    for (int i = 0; i < n; i++)
        B_comp[i] = NOT(B[i]);

    int carry = 1;
    for (int i = 0; i < n; i++)
        fullAdder(B_comp[i], 0, carry, B_comp[i], carry);

    rippleCarryAdder(A, B_comp, n, result, finalCarry);
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

/* ================= FLAGS ================= */

bool zeroFlag(int result[], int n) {
    for (int i = 0; i < n; i++)
        if (result[i] != 0)
            return false;
    return true;
}

bool negativeFlag(int result[], int n) {
    return result[n - 1] == 1;
}

bool overflowFlag(int A[], int B[], int result[], int n) {
    return (A[n - 1] == B[n - 1]) && (result[n - 1] != A[n - 1]);
}

/* ================= USER HELPERS ================= */

void userRippleAdder() {
    int n;
    cout << "Enter number of bits: ";
    cin >> n;

    int A[32], B[32], result[32];
    int carry;

    cout << "Enter bits for A (LSB first): ";
    for (int i = 0; i < n; i++)
        cin >> A[i];

    cout << "Enter bits for B (LSB first): ";
    for (int i = 0; i < n; i++)
        cin >> B[i];

    rippleCarryAdder(A, B, n, result, carry);

    cout << "Result: ";
    for (int i = n - 1; i >= 0; i--)
        cout << result[i];
    cout << "\nCarry Out: " << carry << endl;
}

void userSubtractor() {
    int n;
    cout << "Enter number of bits: ";
    cin >> n;

    int A[32], B[32], result[32];
    int carry;

    cout << "Enter bits for A (LSB first): ";
    for (int i = 0; i < n; i++)
        cin >> A[i];

    cout << "Enter bits for B (LSB first): ";
    for (int i = 0; i < n; i++)
        cin >> B[i];

    rippleCarrySubtractor(A, B, n, result, carry);

    cout << "Result (A - B): ";
    for (int i = n - 1; i >= 0; i--)
        cout << result[i];
    cout << endl;
}

void ALU() {
    int n;
    cout << "Enter number of bits: ";
    cin >> n;

    int A[32], B[32], result[32];
    int finalCarry = 0;

    cout << "Enter bits for A (LSB first): ";
    for (int i = 0; i < n; i++)
        cin >> A[i];

    cout << "Enter bits for B (LSB first): ";
    for (int i = 0; i < n; i++)
        cin >> B[i];

    cout << "\nSelect Operation:\n";
    cout << "1. ADD\n2. SUBTRACT\n3. AND\n4. OR\n5. XOR\nChoice: ";
    int op;
    cin >> op;

    switch (op) {
        case 1: rippleCarryAdder(A, B, n, result, finalCarry); break;
        case 2: rippleCarrySubtractor(A, B, n, result, finalCarry); break;
        case 3: bitwiseAND(A, B, n, result); break;
        case 4: bitwiseOR(A, B, n, result); break;
        case 5: bitwiseXOR(A, B, n, result); break;
        default: cout << "Invalid operation\n"; return;
    }

    cout << "Result: ";
    for (int i = n - 1; i >= 0; i--)
        cout << result[i];

    cout << "\nZero: " << zeroFlag(result, n);
    cout << "\nNegative: " << negativeFlag(result, n);
    cout << "\nOverflow: " << overflowFlag(A, B, result, n);
    cout << "\nCarry: " << finalCarry << endl;
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
        cout << "5. ALU (with flags)\n";
        cout << "6. Exit\n";
        cout << "Choose option: ";
        cin >> choice;

        if (choice == 1) {
            int a, b, sum, carry;
            cout << "Enter A: ";
            cin >> a;
            cout << "Enter B: ";
            cin >> b;
            halfAdder(a, b, sum, carry);
            cout << "Sum: " << sum << "\nCarry: " << carry << endl;
        }
        else if (choice == 2) {
            int a, b, cin, sum, carry;
            cout << "Enter A: ";
            cin >> a;
            cout << "Enter B: ";
            cin >> b;
            cout << "Enter Carry In: ";
            cin >> cin;
            fullAdder(a, b, cin, sum, carry);
            cout << "Sum: " << sum << "\nCarry Out: " << carry << endl;
        }
        else if (choice == 3)
            userRippleAdder();
        else if (choice == 4)
            userSubtractor();
        else if (choice == 5)
            ALU();
        else if (choice == 6)
            break;
        else
            cout << "Invalid choice\n";
    }

    return 0;
}
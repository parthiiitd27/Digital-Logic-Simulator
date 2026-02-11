#include <iostream>
#include <vector>
#include "Wire.h"
#include "AndGate.h"
#include "OrGate.h"
#include "XorGate.h"
#include "Circuit.h"

int main() {

    Circuit circuit;

    Wire A("A");
    Wire B("B");
    Wire Cin("Cin");

    Wire X1("X1");
    Wire AandB("AandB");
    Wire X1andCin("X1andCin");

    Wire Sum("Sum");
    Wire Cout("Cout");

    circuit.addWire(&A);
    circuit.addWire(&B);
    circuit.addWire(&Cin);
    circuit.addWire(&X1);
    circuit.addWire(&AandB);
    circuit.addWire(&X1andCin);
    circuit.addWire(&Sum);
    circuit.addWire(&Cout);

    std::vector<Wire*> xor1Inputs = { &A, &B };
    XorGate xor1(xor1Inputs, &X1);

    std::vector<Wire*> xor2Inputs = { &X1, &Cin };
    XorGate xor2(xor2Inputs, &Sum);

    std::vector<Wire*> and1Inputs = { &A, &B };
    AndGate and1(and1Inputs, &AandB);

    std::vector<Wire*> and2Inputs = { &X1, &Cin };
    AndGate and2(and2Inputs, &X1andCin);

    std::vector<Wire*> orInputs = { &AandB, &X1andCin };
    OrGate or1(orInputs, &Cout);

    circuit.addComponent(&xor1);
    circuit.addComponent(&xor2);
    circuit.addComponent(&and1);
    circuit.addComponent(&and2);
    circuit.addComponent(&or1);

    std::cout << "A B Cin | Sum Cout\n";
    std::cout << "-------------------\n";

    for (int a = 0; a <= 1; a++) {
        for (int b = 0; b <= 1; b++) {
            for (int cin = 0; cin <= 1; cin++) {

                A.setValue(a);
                B.setValue(b);
                Cin.setValue(cin);

                circuit.simulate();

                std::cout << a << " "
                          << b << "  "
                          << cin << "  |  "
                          << Sum.getValue() << "    "
                          << Cout.getValue()
                          << std::endl;
            }
        }
    }

    return 0;
}
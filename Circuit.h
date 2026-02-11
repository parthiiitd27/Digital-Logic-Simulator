#ifndef CIRCUIT_H
#define CIRCUIT_H

#include <vector>
#include <iostream>
#include "Component.h"
#include "Wire.h"

class Circuit {
private:
    std::vector<Component*> components;
    std::vector<Wire*> wires;

public:
    void addComponent(Component* comp) {
        components.push_back(comp);
    }

    void addWire(Wire* wire) {
        wires.push_back(wire);
    }

    void simulate() {
        bool changed;
        int iteration = 0;
        const int MAX_ITER = 1000;

        do {
            changed = false;

            for (auto comp : components) {
                if (comp->evaluate()) {
                    changed = true;
                }
            }

            iteration++;

            if (iteration > MAX_ITER) {
                std::cout << "Simulation unstable! Possible feedback loop.\n";
                break;
            }

        } while (changed);
    }

    void printAllWires() {
        for (auto wire : wires) {
            std::cout << wire->getName()
                      << " = "
                      << wire->getValue()
                      << std::endl;
        }
    }
};

#endif
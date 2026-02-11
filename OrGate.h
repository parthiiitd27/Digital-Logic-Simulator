#ifndef ORGATE_H
#define ORGATE_H

#include "Component.h"
#include "Wire.h"
#include <vector>

class OrGate : public Component {
private:
    std::vector<Wire*> inputs;
    Wire* output;

public:
    OrGate(const std::vector<Wire*>& in, Wire* out)
        : inputs(in), output(out) {}

    bool evaluate() override {
        int result = 0;

        for (auto wire : inputs) {
            if (wire->getValue() == 1) {
                result = 1;
                break;
            }
        }

        if (output->getValue() != result) {
            output->setValue(result);
            return true;
        }

        return false;
    }
};

#endif
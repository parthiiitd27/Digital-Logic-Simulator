#ifndef ANDGATE_H
#define ANDGATE_H

#include "Component.h"
#include "Wire.h"
#include <vector>

class AndGate : public Component {
private:
    std::vector<Wire*> inputs;
    Wire* output;

public:
    AndGate(const std::vector<Wire*>& in, Wire* out)
        : inputs(in), output(out) {}

    bool evaluate() override {
        int result = 1;

        for (auto wire : inputs) {
            if (wire->getValue() == 0) {
                result = 0;
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
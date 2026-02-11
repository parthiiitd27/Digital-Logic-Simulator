#ifndef XORGATE_H
#define XORGATE_H

#include "Component.h"
#include "Wire.h"
#include <vector>

class XorGate : public Component {
private:
    std::vector<Wire*> inputs;
    Wire* output;

public:
    XorGate(const std::vector<Wire*>& in, Wire* out)
        : inputs(in), output(out) {}

    bool evaluate() override {
        int countOnes = 0;

        for (auto wire : inputs) {
            if (wire->getValue() == 1)
                countOnes++;
        }

        int result = countOnes % 2;

        if (output->getValue() != result) {
            output->setValue(result);
            return true;
        }

        return false;
    }
};

#endif
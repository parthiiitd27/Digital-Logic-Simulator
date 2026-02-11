#ifndef NOTGATE_H
#define NOTGATE_H

#include "Component.h"
#include "Wire.h"

class NotGate : public Component {
private:
    Wire* input;
    Wire* output;

public:
    NotGate(Wire* in, Wire* out)
        : input(in), output(out) {}

    bool evaluate() override {
        int result = (input->getValue() == 0) ? 1 : 0;

        if (output->getValue() != result) {
            output->setValue(result);
            return true;
        }

        return false;
    }
};

#endif
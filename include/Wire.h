#ifndef WIRE_H
#define WIRE_H

#include <string>

class Wire {
private:
    std::string name;
    int value;

public:
    Wire(std::string n) : name(n), value(0) {}

    void setValue(int v) {
        value = v;
    }

    int getValue() const {
        return value;
    }

    std::string getName() const {
        return name;
    }
};

#endif
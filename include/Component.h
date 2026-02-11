#ifndef COMPONENT_H
#define COMPONENT_H

class Component {
public:
    virtual bool evaluate() = 0;
    virtual ~Component() {}
};

#endif
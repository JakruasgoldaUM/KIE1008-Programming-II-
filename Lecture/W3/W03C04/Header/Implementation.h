#ifndef IMPLEMENTATION_H_INCLUDED
#define IMPLEMENTATION_H_INCLUDED

class Implementation
{
public:
    Implementation (int v) : value(v) {}
    void setValue(int v) { value = v; }
    int getValue () const { return value; }

private:
    int value;
};


#endif // IMPLEMENTATION_H_INCLUDED

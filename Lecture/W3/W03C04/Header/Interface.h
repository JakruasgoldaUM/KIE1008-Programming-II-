#ifndef INTERFACE_H_INCLUDED
#define INTERFACE_H_INCLUDED

class Implementation;  //forward class declaration

class Interface
{
    public:
        Interface(int);
        ~Interface();
        int getValue() const;
        void setValue (int);

    private:
        Implementation *ptr;
};

#endif // INTERFACE_H_INCLUDED


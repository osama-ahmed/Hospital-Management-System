#ifndef NURSE_H_INCLUDED
#define NURSE_H_INCLUDED

#include<string>
#include"Person.h"
using namespace std;

class Nurse:public Person
{
public:
    Nurse();
    void message();

    friend istream& operator >> (istream&, Nurse*);
    friend ostream& operator << (ostream&, Nurse*);
};

#endif

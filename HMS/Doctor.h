#ifndef DOCTOR_H_INCLUDED
#define DOCTOR_H_INCLUDED

#include<string>
#include"Person.h"
using namespace std;

class Doctor:public Person
{
public:
    Doctor();
    void message();
};

#endif // DOCTOR_H_INCLUDED

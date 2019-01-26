#ifndef PERSON_H_INCLUDED
#define PERSON_H_INCLUDED

#include<string>
#include"name_ID.h"
#include"Clinic.h"
using namespace std;

class Person:public name_ID
{
protected:
    string address;
    long tel;
    string clinic;

public:
    Person();
    void setAddress(string);
    void setTel(long);
    string getAddress();
    long getTel();
    string getClinic();
    void chooseClinic(Clinic**,int);
    virtual void add(Clinic**,int);
    virtual void display();

    friend class Reservation;

    template<typename T>
    friend class TextFile;
};

#endif // PERSON_H_INCLUDED

#ifndef Clinic_H_INCLUDED
#define Clinic_H_INCLUDED

#include<iostream>
#include<string>
#include"name_ID.h"
using namespace std;

class Clinic:public name_ID
{
private:
    float price;
    float payments;

public:
    Clinic();
    void setPrice(float);
    float getPrice();
    float getPayments();
    void increasePayments();
    void decreasePayments();
    void message();

    friend istream& operator >> (istream&, Clinic*);
    friend ostream& operator << (ostream&, Clinic*);

    template<typename T>
    friend class File;
};


#endif


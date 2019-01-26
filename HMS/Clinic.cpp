#include <iostream>
#include<string>
#include<fstream>
#include"Clinic.h"
using namespace std;


Clinic::Clinic():payments(0)
{
}

void Clinic::setPrice(float p)
{
    this->price=p;
}

float Clinic::getPrice()
{
    return this->price;
}

float Clinic::getPayments()
{
    return this->payments;
}

void Clinic::increasePayments()
{
    this->payments+=price;
}

 void Clinic::decreasePayments()
 {
     this->payments-=price;
 }

 void Clinic::message()
 {
     cout<<"";
 }

istream& operator >> (istream& s, Clinic* c)
{
      cout<<endl;
      cout<<"Enter Name: ";
      s>>c->name;
      cout<<"Enter ID: ";
      s>>c->ID;
      cout<<"Enter Price: ";
      s>>c->price;
      cout<<endl;

      return s;
}

ostream& operator << (ostream& s, Clinic* c)
{
        s<<endl;
        s<<"\tName: "<<c->name<<endl;
        s<<"\tID: "<<c->ID<<endl;
        s<<"\tPrice: "<<c->price<<endl;
        s<<"\tPayments: "<<c->payments<<endl;
        s<<endl;

        return s;
}

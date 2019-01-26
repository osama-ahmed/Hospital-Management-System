#include<iostream>
#include<string>
#include"Reservation.h"
using namespace std;

Reservation::Reservation()
{
}

void Reservation::setDate(string d)
{
    this->date=date;
}

void Reservation::setTime(float t)
{
    this->time=time;
}

string Reservation::getDate()
{
    return this->date;
}

float Reservation::getTime()
{
    return this->time;
}

string Reservation::getID()
{
    return (this->Pat.getID());
}

void Reservation::reserve(Clinic** Ptr,int n)
{
    cin>>(this);
    this->Pat.chooseClinic(Ptr,n);

    for(int i=0;i<n;i++)
    {
        if((*Ptr)->getName()==Pat.clinic)
        {
            (*Ptr)->increasePayments();
        }

        Ptr++;
    }
}

istream& operator >> (istream& s, Reservation* r)
{
    string name,id,address;
    int rn;
    long tel;

      cout<<endl;
      cout<<"Enter Name: ";
      s>>name;
      r->Pat.setName(name);
      cout<<"Enter ID: ";
      s>>id;
      r->Pat.setID(id);
      cout<<"Enter Address: ";
      s>>address;
      r->Pat.setAddress(address);
      cout<<"Enter Telephone: ";
      s>>tel;
      r->Pat.setTel(tel);
      cout<<"Enter room number: ";
      s>>rn;
      r->Pat.setRoomNumber(rn);
      cout<<"Enter date: ";
      s>>r->date;
      cout<<"Enter time:";
      s>>r->time;
      cout<<endl;

      return s;
}

ostream& operator << (ostream& s, Reservation* r)
{
        s<<endl;
        s<<"\tName: "<<r->Pat.getName()<<endl;
        s<<"\tID: "<<r->Pat.getID()<<endl;
        s<<"\tAddress: "<<r->Pat.getAddress()<<endl;
        s<<"\tTelephone: "<<r->Pat.getTel()<<endl;
        s<<"\tRoom Number: "<<r->Pat.getRoomNumber()<<endl;
		s<<"\tClinic name: "<<r->Pat.getClinic()<<endl;
        s<<"\tDate: "<<r->date<<endl;
        s<<"\tTime: "<<r->time<<endl;
        s<<endl;

        return s;
}


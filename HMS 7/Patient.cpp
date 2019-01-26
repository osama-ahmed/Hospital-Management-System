#include<iostream>
#include<string>
#include"Patient.h"
using namespace std;

Patient::Patient()
{
}

void Patient::setRoomNumber(int RN)
{
    this->roomNumber=RN;
}

int Patient::getRoomNumber()
{
    return this->roomNumber;
}

void Patient::message()
{
cout<<"";
}

void Patient::add(Clinic** ptr,int n)
{
    Person::add(ptr,n);
    cout<<"Enter room number:";
    cin>>roomNumber;
    cout<<endl;
}

void Patient::display()
{
    Person::display();
    cout<<"\tRoom number: "<<roomNumber;
    cout<<endl;
}


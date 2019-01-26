#include<iostream>
#include<string>
#include"Person.h"
using namespace std;

Person::Person()
{
}

void Person::setAddress(string a)
{
    this->address=a;
}

void Person::setTel(long t)
{
    this->tel=t;
}

long Person::getTel()
{
    return this->tel;
}

string Person::getAddress()
{
    return this->address;
}

string Person::getClinic()
{
    return this->clinic;
}

void Person::chooseClinic(Clinic** ptr,int n)
{
    cout<<"Choose Clinic name from menu:"<<endl;

    for(int i=0;i<n;i++)
    {
        cout<<"\t"<<i+1<<")"<<(*ptr)->getName()<<endl;
        ptr++;
    }

    cout<<"enter Clinic name:";
    cin>>clinic;
}

void Person::add(Clinic** ptr,int n)
{
    cout<<endl;
    cout<<"Enter name:";
    cin>>name;
    cout<<"Enter ID:";
    cin>>ID;
    cout<<"Enter address:";
    cin>>address;
    cout<<"Enter telephone number:";
    cin>>tel;
    this->chooseClinic(ptr,n);
}

void Person::display()
{
    cout<<endl;
    cout<<"\tName: "<<this->name<<endl;
    cout<<"\tID: "<<this->ID<<endl;
    cout<<"\tAddress: "<<this->address<<endl;
    cout<<"\tTelephone: "<<this->tel<<endl;
    cout<<"\tClinic: "<<this->clinic<<endl;
}

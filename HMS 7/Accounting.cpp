#include<iostream>
#include"Accounting.h"
using namespace std;

Accounting::Accounting():totalPayments(0),addedMoney(0),takenMoney(0),totalMoneyInHos(0)
{
}

void Accounting::setPayments(Clinic** ptr,int n)
{
    totalMoneyInHos-=totalPayments;
    totalPayments=0;

    for(int i=0;i<n;i++)
    {
        float x=(*ptr)->getPayments();
        totalPayments+=x;
        ptr++;
    }

    totalMoneyInHos+=totalPayments;
}


void Accounting::addMoney()
{
    float x;

    cout<<"\nEnter Money:";
    cin>>x;
    cout<<endl;

    addedMoney+=x;
    totalMoneyInHos+=x;
}

void Accounting::takeMoney()
{
    float x;

    cout<<"\nEnter Money:";
    cin>>x;
    cout<<endl;

    takenMoney+=x;
    totalMoneyInHos-=x;
}

void Accounting::setAddedMoney(float AM)
{
    addedMoney=AM;
}

void Accounting::setTakenMoney(float TM)
{
    takenMoney=TM;
}

float Accounting::getTotalPayments()
{
    return totalPayments;
}


float Accounting::getAddedMoney()
{
    return addedMoney;
}

float Accounting::getTakenMoney()
{
    return takenMoney;
}

float Accounting::getTotalMoneyInHos()
{
    return totalMoneyInHos;
}


ostream& operator << (ostream& s, Accounting* a)
{
        s<<endl;
        s<<"\tTotal Payments: "<<a->totalPayments;
        s<<"\n\tAdded Money: "<<a->addedMoney;
        s<<"\n\tTaken Money: "<<a->takenMoney;
        s<<"\n\tTotal Money In Hospital: "<<a->totalMoneyInHos;
        s<<endl;

        return s;
}

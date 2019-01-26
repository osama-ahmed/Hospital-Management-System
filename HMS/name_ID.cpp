#include<iostream>
#include<string>
#include"Clinic.h"
#include"Doctor.h"
#include"Patient.h"
#include"Reservation.h"
#include"Accounting.h"
using namespace std;

name_ID::name_ID()
{
}

void name_ID::setName(string n)
{
    this->name=n;
}

void name_ID::setID(string id)
{
    this->ID=id;
}

string name_ID::getName()
{
    return this->name;
}

string name_ID::getID()
{
    return this->ID;
}


#ifndef RESERVATION_H_INCLUDED
#define RESERVATION_H_INCLUDED

#include<string>
#include"Patient.h"
using namespace std;

class Reservation
{
private:
    string date;
    float time;
    Patient Pat;

public:
    Reservation();
    void setDate(string);
    void setTime(float);
    string getDate();
    float getTime();
    string getID();
    void reserve(Clinic**,int);

    friend istream& operator >> (istream&, Reservation*);
    friend ostream& operator << (ostream&, Reservation*);

    template<typename T>
    friend class File;
};

#endif // RESERVATION_H_INCLUDED

#ifndef PATIENT_H_INCLUDED
#define PATIENT_H_INCLUDED

#include<string>
#include"Person.h"
using namespace std;

class Patient:public Person
{
private:
	int roomNumber;

public:
	Patient();
	void setRoomNumber(int);
	int getRoomNumber();
	void message();
	void add(Clinic**,int);
	void display();

	template<typename T>
    friend class TextFile;
};

#endif // PATIENT_H_INCLUDED

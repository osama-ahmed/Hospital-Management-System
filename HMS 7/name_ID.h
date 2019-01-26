#ifndef NAME_ID_H_INCLUDED
#define NAME_ID_H_INCLUDED

#include<string>
#include"global.h"
using namespace std;

class name_ID
{
protected:
    string name;
    string ID;

public:
    name_ID();
    void setName(string);
    void setID(string);
    string getName();
    string getID();
    virtual void message()=0;
};


#endif // NAME_ID_H_INCLUDED

#ifndef ACCOUNTING_H_INCLUDED
#define ACCOUNTING_H_INCLUDED

#include<string>
#include"Clinic.h"
using namespace std;

class Accounting
{
   private:
        float totalPayments;
        float addedMoney;
        float takenMoney;
        float totalMoneyInHos;

   public:
       Accounting();
       void setPayments(Clinic**,int);
       void addMoney();
       void takeMoney();
       void setAddedMoney(float);
       void setTakenMoney(float);
       float getTotalPayments();
       float getAddedMoney();
       float getTakenMoney();
       float getTotalMoneyInHos();

    friend ostream& operator << (ostream&, Accounting*);

    template<typename T>
    friend class File;
};


#endif // ACCOUNTING_H_INCLUDED

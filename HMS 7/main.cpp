#include <iostream>
#include<fstream>
#include<typeinfo>
#include<stdlib.h>
#include"global.h"
#include"File.h"
#include"TextFile.h"
#include"Algorithm.h"
#include"name_ID.h"
#include"Clinic.h"
#include"Person.h"
#include"Doctor.h"
#include"Nurse.h"
#include"Patient.h"
#include"Reservation.h"
#include"Accounting.h"
using namespace std;

int main()
{
    Clinic* ClinicPtr[SIZE];
    Person* PersonPtr[SIZE];
    Reservation* ReservationPtr[SIZE];
    Accounting* AccountingPtr[SIZE];
    int ClinicNo=0;
    int PersonNo=0;
    int ReservationNo=0;
    int AccountingNo=0;
    char choice=' ';

    AccountingPtr[AccountingNo]=new Accounting();
    AccountingPtr[0]->setPayments(ClinicPtr,ClinicNo);

    File<Clinic>::GetDataClinic(ClinicPtr,&ClinicNo);
    File<Reservation>::GetDataReservation(ReservationPtr,&ReservationNo);
    File<Accounting>::GetDataAccounting(AccountingPtr,&AccountingNo);
	TextFile<Person>::GetDataPerson(PersonPtr,&PersonNo);

    //TextFile<Clinic>::GetDataClinic(ClinicPtr,&ClinicNo);
    //TextFile<Reservation>::GetDataReservation(ReservationPtr,&ReservationNo);
    //TextFile<Accounting>::GetDataAccounting(AccountingPtr,&AccountingNo);


cout<<"\n\t\t\t\tHospital Management"<<endl;

while(choice!='g')
{
    cout<<"\n--------------------------------";
    cout<<"\n\ta)Clinics Management"<<endl;
    cout<<"\n\tb)Doctors Management"<<endl;
    cout<<"\n\tc)Nurses Management"<<endl;
    cout<<"\n\td)Patients Management"<<endl;
    cout<<"\n\te)Rooms Reservation"<<endl;
    cout<<"\n\tf)Accounting"<<endl;
    cout<<"\n\tg)Exit"<<endl;
    cout<<"--------------------------------"<<endl;

    cout<<"\nenter your choise:";
    cin>>choice;

if(choice=='a')
{
    while(choice!='6')
    {
    cout<<"\nClincis Management"<<endl;
    cout<<"\n\t1)Add a clinic"<<endl;
    cout<<"\n\t2)Display all"<<endl;
    cout<<"\n\t3)Search for a Clinic"<<endl;
    cout<<"\n\t4)Update a Clinic"<<endl;
    cout<<"\n\t5)Delete a Clinic"<<endl;
    cout<<"\n\t6)Return to main menu"<<endl;

        cout<<"\nenter your choise:";
        cin>>choice;

switch(choice)
{
    case'1':
        ClinicPtr[ClinicNo]=new Clinic();
		cin>>ClinicPtr[ClinicNo];
        ClinicNo++;
    break;

    case'2':
        Algorithm<Clinic>::DisplayAll(ClinicPtr,ClinicNo);
    break;

    case'3':
        {
        Clinic* temp=Algorithm<Clinic>::Search(ClinicPtr,ClinicNo);
        cout<<temp;
        }
    break;

    case'4':
        Algorithm<Clinic>::Update(ClinicPtr,ClinicNo);
    break;

    case'5':
        Algorithm<Clinic>::Delete(ClinicPtr,ClinicNo);
        ClinicNo--;
    break;

    case'6':
        break;

    default:
        cout<<"error in choise...."<<endl;
}
    }//end of while
}

else if(choice=='b')
{
    while(choice!='6')
    {
    cout<<"\nDoctors Management"<<endl;
    cout<<"\n\t1)Add a doctor"<<endl;
    cout<<"\n\t2)Display all"<<endl;
    cout<<"\n\t3)Search for a doctor"<<endl;
    cout<<"\n\t4)Update a doctor"<<endl;
    cout<<"\n\t5)Delete a doctor"<<endl;
    cout<<"\n\t6)Return to main menu"<<endl;

        cout<<"\nenter your choise:";
        cin>>choice;

switch(choice)
{
    case'1':
        PersonPtr[PersonNo]=new Doctor();
        PersonPtr[PersonNo]->add(ClinicPtr,ClinicNo);
        PersonNo++;
    break;

    case'2':
        Algorithm<Person>::DisplayAllPerson(PersonPtr,PersonNo,"Doctor");
    break;

    case'3':
        {
        Person* temp=Algorithm<Person>::Search(PersonPtr,PersonNo);
        temp->display();
        }
    break;

    case'4':
        Algorithm<Person>::UpdatePerson(PersonPtr,PersonNo,ClinicPtr,ClinicNo);
    break;

    case'5':
        Algorithm<Person>::Delete(PersonPtr,PersonNo);
        PersonNo--;
    break;

    case'6':
        break;

    default:
        cout<<"error in choise...."<<endl;
}
    }//end of while
}

else if(choice=='c')
{
    while(choice!='6')
    {
    cout<<"\nNurses Management"<<endl;
    cout<<"\n\t1)Add a nurse"<<endl;
    cout<<"\n\t2)Display all"<<endl;
    cout<<"\n\t3)Search for a nurse"<<endl;
    cout<<"\n\t4)Update a nurse"<<endl;
    cout<<"\n\t5)Delete a nurse"<<endl;
    cout<<"\n\t6)Return to main menu"<<endl;

        cout<<"\nenter your choise:";
        cin>>choice;

switch(choice)
{
    case'1':
        PersonPtr[PersonNo]=new Nurse();
        PersonPtr[PersonNo]->add(ClinicPtr,ClinicNo);
        PersonNo++;
    break;

    case'2':
        Algorithm<Person>::DisplayAllPerson(PersonPtr,PersonNo,"Nurse");
    break;

    case'3':
        {
        Person* temp=Algorithm<Person>::Search(PersonPtr,PersonNo);
        cout<<temp;
        }
    break;

    case'4':
        Algorithm<Person>::UpdatePerson(PersonPtr,PersonNo,ClinicPtr,ClinicNo);
    break;

    case'5':
        Algorithm<Person>::Delete(PersonPtr,PersonNo);
        PersonNo--;
    break;

    case'6':
        break;

    default:
        cout<<"error in choise...."<<endl;
}
    }//end of while
}

else if(choice=='d')
{
    while(choice!='6')
    {
    cout<<"\nPatient Management"<<endl;
    cout<<"\n\t1)Add a Patient"<<endl;
    cout<<"\n\t2)Display all Patient"<<endl;
    cout<<"\n\t3)Search for Patient"<<endl;
    cout<<"\n\t4)Update Patient"<<endl;
    cout<<"\n\t5)Delete Patient"<<endl;
    cout<<"\n\t6)Return to main menu"<<endl;

cout<<"\nenter your choise:";
cin>>choice;

switch(choice)
{
  case'1':
        PersonPtr[PersonNo]=new Patient();
        PersonPtr[PersonNo]->add(ClinicPtr,ClinicNo);
        PersonNo++;
  break;

  case'2':
       Algorithm<Person>::DisplayAllPerson(PersonPtr,PersonNo,"Patient");
  break;

  case'3':
      {
        Person* temp=Algorithm<Person>::Search(PersonPtr,PersonNo);
        cout<<temp;
      }
  break;

  case'4':
        Algorithm<Person>::UpdatePerson(PersonPtr,PersonNo,ClinicPtr,ClinicNo);
  break;

  case'5':
        Algorithm<Person>::Delete(PersonPtr,PersonNo);
        PersonNo--;
  break;

    case'6':
        break;

    default:
        cout<<"error in choise.."<<endl;
}
    }//end of while
}


else if(choice=='e')
{
    while(choice!='5')
    {
    cout<<"\nReservation:"<<endl;
    cout<<"\n\t1)Reserve"<<endl;
    cout<<"\n\t2)Cancel Reservation"<<endl;
    cout<<"\n\t3)Update Reservation"<<endl;
    cout<<"\n\t4)Display All"<<endl;
    cout<<"\n\t5)Return to main menu"<<endl;

        cout<<"\nenter your choise:";
        cin>>choice;

switch(choice)
{
    case'1':
        ReservationPtr[ReservationNo]=new Reservation();
        ReservationPtr[ReservationNo]->reserve(ClinicPtr,ClinicNo);
        AccountingPtr[AccountingNo]->setPayments(ClinicPtr,ClinicNo);
        ReservationNo++;
    break;

    case'2':
        Algorithm<Reservation>::Delete(ReservationPtr,ReservationNo);
        ReservationNo--;
    break;

    case'3':
        Algorithm<Reservation>::Update(ReservationPtr,ReservationNo);
    break;

    case'4':
        Algorithm<Reservation>::DisplayAll(ReservationPtr,ReservationNo);
    break;

    case'5':
        break;

    default:
        cout<<"error in choise...."<<endl;
}
    }//end of while
}

else if(choice=='f')
{
    while(choice!='4')
    {
    cout<<"\nAccounting:"<<endl;
    cout<<"\n\t1)Display"<<endl;
    cout<<"\n\t2)Add Money"<<endl;
    cout<<"\n\t3)Take Money"<<endl;
    cout<<"\n\t4)Return to main menu"<<endl;

        cout<<"\nenter your choise:";
        cin>>choice;

switch(choice)
{
    case'1':
        cout<<AccountingPtr[AccountingNo];
    break;

    case'2':
        AccountingPtr[AccountingNo]->addMoney();
    break;

    case'3':
        AccountingPtr[AccountingNo]->takeMoney();
    break;

    case'4':
        break;

    default:
        cout<<"error in choise...."<<endl;
}//end of switch
    }//end of while loop
}//end of else if*/
    }//end of main while loop

    File<Clinic>::SaveDataClinic(ClinicPtr,&ClinicNo);
    File<Reservation>::SaveDataReservation(ReservationPtr,&ReservationNo);
    File<Accounting>::SaveDataAccounting(AccountingPtr,&AccountingNo);
	TextFile<Person>::SaveDataPerson(PersonPtr,&PersonNo);

    //TextFile<Clinic>::SaveDataClinic(ClinicPtr,&ClinicNo);
    //TextFile<Reservation>::SaveDataReservation(ReservationPtr,&ReservationNo);
    //TextFile<Accounting>::SaveDataAccounting(AccountingPtr,&AccountingNo);

    return 0;
}






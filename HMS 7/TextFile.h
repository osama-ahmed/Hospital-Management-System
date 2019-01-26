#ifndef TEXTFILE_H_INCLUDED
#define TEXTFILE_H_INCLUDED

template<class T>
class TextFile
{
public:
    static void SaveDataClinic(T**,int*);
    static void SaveDataPerson(T**,int*);
    static void SaveDataReservation(T**,int*);
    static void SaveDataAccounting(T**,int*);
    static void GetDataClinic(T**,int*);
    static void GetDataPerson(T**,int*);
    static void GetDataReservation(T**,int*);
    static void GetDataAccounting(T**,int*);
};


#endif // TEXTFILE_H_INCLUDED


template<class T>
void TextFile<T>::SaveDataClinic(T** ptr,int* n)
{
ofstream outfile;

outfile.open("ClinicFile.txt", ios::trunc | ios::out);

if(!outfile)
{ cout << "\nCan not open file\n"<<endl; }

for(int i=0;i<*n;i++)
{
if((*ptr)->ID=="")
break;

else
{
outfile<<(*ptr)->ID<<' '<<(*ptr)->name<<' '<<(*ptr)->price<<' '<<(*ptr)->payments<<endl;
ptr++;
}
}//end of for loop

if(!outfile.good())
    cout<<"\nFile is not good..."<<endl;

if(outfile.is_open())
    outfile.close();
}

template<class T>
void TextFile<T>::SaveDataReservation(T** ptr,int* n)
{
ofstream outfile;

outfile.open("ReservationFile.txt", ios::trunc|ios::out );

if(!outfile)
{ cout << "\nCan not open file\n"<<endl; }

for(int i=0;i<*n;i++)
{
if((*ptr)->Pat.ID=="")
break;

outfile<<(*ptr)->Pat.ID<<' '<<(*ptr)->Pat.name<<' '<<(*ptr)->Pat.address<<' '<<(*ptr)->Pat.tel<<' '<<(*ptr)->Pat.clinic<<' '<<(*ptr)->Pat.roomNumber<<' '<<(*ptr)->date<<' '<<(*ptr)->time<<endl;
if(!outfile)
{ cout << "\nCan not write to file\n"<<endl; }
ptr++;
}//end of for loop
if(outfile.is_open())
    outfile.close();
}

template<class T>
void TextFile<T>::SaveDataAccounting(T** ptr,int* n)
{
ofstream outfile;

outfile.open("AccountingFile.txt", ios::trunc);

if(!outfile)
{ cout << "\nCan not open file\n"<<endl; }


outfile<<(*ptr)->totalPayments<<' '<<(*ptr)->addedMoney<<' '<<(*ptr)->takenMoney<<' '<<(*ptr)->totalMoneyInHos<<endl;

if(!outfile)
{ cout << "\nCan not write to file\n"; return; }

if(outfile.is_open())
    outfile.close();
}

template<class T>
void TextFile<T>::GetDataClinic(T** ptr,int* n)
{
ifstream infile;

infile.open("ClinicFile.txt", ios::in);

if(!infile)
{ cout << "\nCan not open file\n"; }

while(!infile.eof())
{
(*ptr)=new Clinic();
 infile>>(*ptr)->ID>>(*ptr)->name>>(*ptr)->price>>(*ptr)->payments;

 if(!infile)
    {
        cout<<""<<endl;
        break;
    }

(*n)++;
ptr++;
}

if(infile.is_open())
    infile.close();
}

template<class T>
void TextFile<T>::GetDataReservation(T** ptr,int* n)
{
ifstream infile;

infile.open("ReservationFile.txt", ios::in);

if(!infile)
{ cout << "\nCan not open file\n"<<endl; }

while(!infile.eof())
{
(*ptr)=new Reservation();
infile>>(*ptr)->Pat.ID>>(*ptr)->Pat.name>>(*ptr)->Pat.address>>(*ptr)->Pat.tel>>(*ptr)->Pat.clinic>>(*ptr)->Pat.roomNumber>>(*ptr)->date>>(*ptr)->time;

 if(!infile)
 {
    cout<<""<<endl;
    break;
 }

(*n)++;
ptr++;
}

if(infile.is_open())
    infile.close();
}

template<class T>
void TextFile<T>::GetDataAccounting(T** ptr,int* n)
{
ifstream infile;

infile.open("AccountingFile.txt", ios::in);

if(!infile)
{ cout << "\nCan not open file\n"; return; }

 infile>>(*ptr)->totalPayments>>(*ptr)->addedMoney>>(*ptr)->takenMoney>>(*ptr)->totalMoneyInHos;

 if(!infile)
 {
     cout<<"";
     exit(1);
 }

    if(infile.is_open())
    infile.close();
}

template<class T>
void TextFile<T>::SaveDataPerson(T** ptr,int* n)
{
string type;
ofstream outfile;

outfile.open("PersonFile.txt", ios::out);

if(!outfile)
{ cout << "\nCan not open file\n"<<endl;}

for(int i=0;i<*n;i++)
{
if(typeid(**ptr)==typeid(Doctor))
{
    type="doctor";
    outfile<<type<<endl;
    outfile<<(*ptr)->ID<<' '<<(*ptr)->name<<' '<<(*ptr)->address<<' '<<(*ptr)->tel<<' '<<(*ptr)->clinic<<endl;
}

if(typeid(**ptr)==typeid(Nurse))
{
    type="nurse";
    outfile<<type<<endl;
    outfile<<(*ptr)->ID<<' '<<(*ptr)->name<<' '<<(*ptr)->address<<' '<<(*ptr)->tel<<' '<<(*ptr)->clinic<<endl;
}

if(typeid(**ptr)==typeid(Patient))
{
    type="patient";
    outfile<<type<<endl;
    outfile<<(*ptr)->ID<<' '<<(*ptr)->name<<' '<<(*ptr)->address<<' '<<(*ptr)->tel<<' '<<(*ptr)->clinic<<endl;
}

if(!outfile)
{ cout << "\nCan not write to file\n"<<endl; }

ptr++;
}//end of for loop
if(outfile.is_open())
    outfile.close();
}

template<class T>
void TextFile<T>::GetDataPerson(T** ptr,int* n)
{
string type;
ifstream infile;

infile.open("PersonFile.txt", ios::in);

if(!infile)
{
  cout << "\nCould not open file\n";
}

while(true)
{
if(infile.eof())
break;

infile>>type;

if(type=="doctor")
{
    (*ptr)=new Doctor();
    infile>>(*ptr)->ID>>(*ptr)->name>>(*ptr)->address>>(*ptr)->tel>>(*ptr)->clinic;
}

if(type=="nurse")
{
    (*ptr)=new Nurse();
    infile>>(*ptr)->ID>>(*ptr)->name>>(*ptr)->address>>(*ptr)->tel>>(*ptr)->clinic;
}

if(type=="patient")
{
    (*ptr)=new Patient();
    infile>>(*ptr)->ID>>(*ptr)->name>>(*ptr)->address>>(*ptr)->tel>>(*ptr)->clinic;
}


 if(!infile)
 {
     cout<<"";
     break;
 }

(*n)++;
ptr++;
}

if(infile.is_open())
    infile.close();
}
#ifndef FILE_H_INCLUDED
#define FILE_H_INCLUDED

template<class T>
class File
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


#endif // FILE_H_INCLUDED

template<class T>
void File<T>::SaveDataClinic(T** ptr,int* n)
{
int size=sizeof(Clinic);
ofstream outfile("ClinicFile.text", ios::trunc | ios::binary |ios::out);

if(!outfile)
{ cout << ""; }

for(int i=0;i<(*n);i++)
{
outfile.write( (char*)(*ptr),size);

if(!outfile)
{ cout << "\nCan not write to file\n"<<endl; }

ptr++;
}//end of for loop

if(outfile.is_open())
    outfile.close();
}

template<class T>
void File<T>::SaveDataReservation(T** ptr,int* n)
{
ofstream outfile;
int size=sizeof(Reservation);

outfile.open("ReservationFile.txt", ios::out | ios::binary|ios::trunc);

if(!outfile)
{ cout << ""; }

for(int i=0;i<(*n);i++)
{
outfile.write( (char*)(*ptr), size);
if(!outfile)
{ cout << "\nCan not write to file\n"<<endl; }

ptr++;
}//end of for loop
if(outfile.is_open())
    outfile.close();
}

template<class T>
void File<T>::SaveDataAccounting(T** ptr,int* n)
{
ofstream outfile;

outfile.open("AccountingFile.txt", ios::out | ios::binary|ios::trunc);

if(!outfile)
{ cout << "\nCan not open file\n"<<endl; }

outfile.write( (char*)(*ptr), sizeof(**ptr));

if(!outfile)
{ cout << "\nCan not write to file\n"<<endl; }

if(outfile.is_open())
    outfile.close();
}

template<class T>
void File<T>::GetDataClinic(T** ptr,int* n)
{
int size=sizeof(Clinic);
ifstream infile("ClinicFile.text", ios::in | ios::binary);

if(!infile)
{ cout << ""; }

while(!infile.eof())
{
(*ptr)=new Clinic();

 infile.read((char*)(*ptr),size);

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

template<class T>
void File<T>::GetDataReservation(T** ptr,int* n)
{
ifstream infile;

infile.open("ReservationFile.txt", ios::in | ios::binary);

if(!infile)
{ cout << ""; }

while(true)
{
 if(infile.eof())
 break;

(*ptr)=new Reservation();

 infile.read((char*)(*ptr),sizeof(**ptr));

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

template<class T>
void File<T>::GetDataAccounting(T** ptr,int* n)
{
ifstream infile;

infile.open("AccountingFile.txt", ios::in | ios::binary);

if(!infile)
{ cout << ""; }

 infile.read((char*)(*ptr),sizeof(**ptr));

 if(!infile)
 {
   cout<<"";
 }

    if(infile.is_open())
    infile.close();
}

template<class T>
void File<T>::SaveDataPerson(T** ptr,int* n)
{
int size=0;
string type;
ofstream outfile;

outfile.open("PersonFile.txt", ios::trunc | ios::binary|ios::out);

if(!outfile)
{ cout << ""; }

for(int i=0;i<*n;i++)
{
if(typeid(**ptr)==typeid(Doctor))
{
    size=sizeof(Doctor);
    type="doctor";
}

if(typeid(**ptr)==typeid(Nurse))
{
    size=sizeof(Nurse);
    type="nurse";
}

if(typeid(**ptr)==typeid(Patient))
{
    size=sizeof(Patient);
    type="patient";
}

outfile.write((char*)(&type),sizeof(type));
outfile.write( (char*)(*ptr), size);

if(!outfile)
{ cout << ""; }

ptr++;
}//end of for loop
if(outfile.is_open())
    outfile.close();
}

template<class T>
void File<T>::GetDataPerson(T** ptr,int* n)
{
int size;
string type;
ifstream infile;

infile.open("PersonFile.txt", ios::in | ios::binary);

if(!infile)
{ cout << ""; }

while(true)
{
if(infile.eof())
break;

infile.read( (char*)&type, sizeof(type) );

if(type=="doctor")
{
    size=sizeof(Doctor);
    (*ptr)=new Doctor();
}

if(type=="nurse")
{
    size=sizeof(Nurse);
    (*ptr)=new Nurse();
}

if(type=="patient")
{
    size=sizeof(Patient);
    (*ptr)=new Patient();
}

infile.read((char*)(*ptr),size);

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

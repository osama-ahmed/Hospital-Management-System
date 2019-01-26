#ifndef ALGORITHM_H_INCLUDED
#define ALGORITHM_H_INCLUDED

#include<string>
#include"Clinic.h"
using namespace std;
                                                        /* Algorithm */
template<class Type>
class Algorithm
{
public:
    static void DisplayAll(Type**,int);
    static void DisplayAllPerson(Type**,int,string);
    static Type* Search(Type**,int);
    static void Update(Type**,int);
    static void UpdatePerson(Type**,int,Clinic**,int);
    static void Delete(Type**,int);
    static int IDExist(Type**,int,string);
};

#endif // ALGORITHM_H_INCLUDED


template<class Type>
void Algorithm<Type>::DisplayAll(Type** ptr,int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<(*ptr);
        ptr++;
    }
}


template<class Type>
void Algorithm<Type>::DisplayAllPerson(Type** ptr,int n,string type)
{
    for(int i=0;i<n;i++)
    {
		if(type=="Doctor")
		{
		if(typeid(**ptr)==typeid(Doctor))
        (*ptr)->display();
		}

		if(type=="Nurse")
		{
		if(typeid(**ptr)==typeid(Nurse))
        (*ptr)->display();
		}

		if(type=="Patient")
		{
		if(typeid(**ptr)==typeid(Patient))
        (*ptr)->display();
		}

        ptr++;
    }
}

template<class Type>
Type* Algorithm<Type>::Search(Type** ptr,int n)
{
    int i;
    string id;

    cout<<"\nEnter ID: ";
    cin>>id;

    for(i=0;i<n;i++)
    {
        if((*ptr)->getID()==id)
        {
            return (*ptr);
            break;
        }

        ptr++;
    }
}

template<class Type>
void Algorithm<Type>::Update(Type** ptr,int n)
{
    Type* temp=Algorithm::Search(ptr,n);

    if(temp!=NULL)
    {
       cin>>temp;
       cout<<"\nItem updated successfully......"<<endl;
    }

    else
      cout<<"\nItem not found.........."<<endl;
}

template<class Type>
void Algorithm<Type>::UpdatePerson(Type** ptr,int n,Clinic** cPtr,int cNo)
{
    Type* temp=Algorithm::Search(ptr,n);

    if(temp!=NULL)
    {
       temp->add(cPtr,cNo);
       cout<<"\nItem updated successfully......"<<endl;
    }

    else
      cout<<"\nItem not found.........."<<endl;
}

template<class Type>
void Algorithm<Type>::Delete(Type** ptr,int n)
{
    Type* item=Algorithm::Search(ptr,n);

    if(item)
    {
        for(int i=0;i<n;i++)
        {
            if((*ptr)==item)
            {
                for(int j=i;j<n;j++)
                  {
                     Type** temp=++ptr;
                     --ptr;

                     (*ptr)=*temp;

                     ptr++;
                  }
                  break;
            }
            ptr++;
        }
        cout<<"\nItem deleted successfully...."<<endl;
    }

    else
      cout<<"\nItem not found.........."<<endl;
}


template<class Type>
int Algorithm<Type>::IDExist(Type** ptr,int n,string id)
{
    int i;

    for(i=0;i<n-1;i++)
    {
        if((*ptr)->getID()==id)
        {
            return 1;
            break;
        }

        ptr++;
    }

    if(i=n-1)
        return 0;
}

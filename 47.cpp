#include<conio.h>
#include<iostream>
using namespace std;
class ArrayADT
{
private:
    int capacity;
    int lastindex;
    int *ptr;
public:
    ArrayADT(){
        capacity=0;
        lastindex=0;
        ptr=NULL;
    }
    void createArray(int capacity);
    int getItem(int index);
    void setItem(int index,int value);
    void editItem(int index,int value);
    int countItem();
    void removeItem(int index);
    int searchItem(int value);
    void sortArray();
    friend ostream& operator<<(ostream&,ArrayADT);
    ~ArrayADT()
    {
        delete []ptr;
    }
    ArrayADT(ArrayADT &list)
    {
        capacity=list.capacity;
        lastindex=list.capacity;
        ptr=new int(capacity);
        for(int i=0;i<=list.lastindex;i++)
            ptr[i]=list.ptr[i];
    }
};
void ArrayADT::createArray(int capacity)
{
    this->capacity=capacity;
    lastindex=-1;
    ptr=new int[capacity];
}
int ArrayADT::getItem(int index)
{
    if(lastindex==-1){
        cout<<"\nList is empty:";
        return(-1);
    }
    if(index>lastindex || index<0){
        cout<<"\nInvalid Index:";
        return(-1);
    }
    return(ptr[index]);
}
void ArrayADT::setItem(int index,int value)
{
    int i;
    if(lastindex==capacity-1)
        cout<<"\nOverflow:";
    else if(index>capacity-1 || index<0)
        cout<<"\nInvalid Index:";
    else if(index>lastindex+1)
        cout<<"\nInvalid Index:";
    else if(index<=lastindex){
        lastindex++;
        i=lastindex;
        while(i!=index){
            ptr[i]=ptr[i-1];
            i--;
        }
        ptr[index]=value;
    }
    else if(index==lastindex+1){
        lastindex++;
        ptr[index]=value;
    }
}
void ArrayADT::editItem(int index,int value)
{
    if(index<0 || index>lastindex)
        cout<<"\nInvalid Index:";
    else
        ptr[index]=value;
}
int ArrayADT::countItem()
{
    return(lastindex+1);
}
void ArrayADT::removeItem(int index)
{
    int i;
    if(index<0 || index>lastindex)
        cout<<"\nEither Invalid Or overFlow Index:";
    else if(index<lastindex){
        i=index;
        while(i!=lastindex){
            ptr[i]=ptr[i+1];
            i++;
        }
        lastindex--;
    }
    else if(lastindex==index)
        lastindex--;
}
int ArrayADT::searchItem(int value)
{
    if(lastindex==-1){
        cout<<"\nList is empty:";
        return(-1);
    }
    int i;
    for(i=0;i<=lastindex;i++)
    {
        if(ptr[i]==value)
            return(i);
    }
    return(-1);
}
void ArrayADT::sortArray()
{
    int i,r,t;
    for(r=1;r<countItem();r++){
        for(i=0;i<countItem()-r;i++)
        if(ptr[i]>ptr[i+1]){
            t=ptr[i];
            ptr[i]=ptr[i+1];
            ptr[i+1]=t;
        }
    }
}
ostream& operator<<(ostream &dout,ArrayADT l)
{
    if(l.lastindex==-1)
        cout<<"\nList is empty:";
    for(int i=0;i<l.countItem();i++)
        cout<<" "<<l.getItem(i);
    return(dout);
}

int main()
{
    ArrayADT k1;
    k1.createArray(5);
    k1.setItem(0,10);
    k1.setItem(1,20);
    k1.setItem(2,30);
    k1.setItem(1,40);
    cout<<k1;
    getch();
}

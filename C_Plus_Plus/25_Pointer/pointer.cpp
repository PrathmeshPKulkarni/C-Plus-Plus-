/*
symbol table -: store mapping 
eg. int a=10;
mapp a (varible) to address 0x1200
*/
#define APPLICATION_START_DDR2_ADDRESS 0x10000
#include<iostream>
using namespace std;
unsigned char ReadByte(unsigned long mem_loc);
void intpointer();
void charpointer();
void nullPointer();
void doublepointer();
void copyPointer();
void pointer();
//pointer size remains same in all type because it store address
int main()
{      //* (star) is dereference operator
    // intpointer();
    // doublepointer();
    // charpointer();
    // nullPointer();
    // copyPointer();
    // pointer();
    ReadByte(100);
    return 0;
    
}

void intpointer()
{
    int num =5;  
    cout<<"****** int pointer *******"<<endl;
   int *ptr = &num; //store address of num it use for initilization 
   ptr = &num; // if you strore address of num
    *ptr=7;   // if you want to change value then use *ptr 
    cout<<" print Address="<<ptr<<endl; //print addrees in hex form eg. 0x61ff00
    cout<<num<<endl;
    // if you print value with use of pointer
    cout<<"Print value ="<<*ptr<<endl;
    // Address of operator - &
    cout<<"Address of num is "<<&num<<endl;
    cout<<"Print size="<<sizeof(ptr)<<endl;  // it may vary in differ machine by machine
    cout<<"size of int="<<sizeof(num)<<endl;

}

void charpointer()
{
    cout<<"****** Char pointer *******"<<endl;
    char *chpter;   //char pointer print 
    *chpter ='a';
    cout<<"print address in char form="<<chpter<<endl;    
    cout<<"Print value ="<<*chpter<<endl;
    cout<<"Print size="<<sizeof(chpter)<<endl;
}

void doublepointer()
{
    cout<<"****** double pointer *******"<<endl;
    double num =5;  
    double *ptr = &num; //store address of num
    *ptr=7;   // if you want to change value then use *ptr 
    cout<<" print Address="<<ptr<<endl; //print addrees in hex form eg. 0x61ff00
    cout<<num<<endl;
    // if you print value with use of pointer
    cout<<"Print value ="<<*ptr<<endl;
    // Address of operator - &
    cout<<"Address of num is "<<&num<<endl;
    cout<<"Print size="<<sizeof(ptr)<<endl;  // it may vary in differ machine by machine
    cout<<"size of double="<<sizeof(num)<<endl;

}
void nullPointer()
{
    cout<<"Segmentation fault";
    int *pointer;    //it store garbage value it means you point your pointer in unkown memory
    pointer=0;          //null pointer it point to null (zero) location 
    
    cout<<"Segmentation fault"<<*pointer<<endl;
}

void copyPointer()
{
    int i;
    int *p=&i;
    int *q = p;
    cout<<"Address p="<<p<<endl;
    cout<<"Address q="<<q<<endl;
}

void pointer()
{
    double *t;   //bad practice
    // t=0;
    cout<<"t="<<t<<endl;   //t=0x401f7b
    t= t+1;                  // value incremented by 4 because pointer size is 4
    cout<<"t+1="<<t<<endl; //t+1=0x401f7f
}

// void pointer()
// {
//     unsigned int *uivari= (unsigned char )
// }

unsigned char ReadByte(unsigned long mem_loc)
{
	unsigned char byt;
	volatile unsigned char* Mem_ptr = (volatile unsigned char*)APPLICATION_START_DDR2_ADDRESS;	// MX257
	byt = *(Mem_ptr + mem_loc);
    cout<<"byte="<<byt<<endl;
	return(byt);
}
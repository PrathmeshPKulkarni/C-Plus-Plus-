typedef unsigned int ui;
typedef unsigned char uc;
#include<stdio.h>
void printing(uc a);
int main()
{
    // void (*fun)(int)= &printing;
    void (*fun)(uc) = &printing;
    /* The above line is equivalent of following two
       void (*fun_ptr)(int);
       fun_ptr = &fun; 
    */
      (*fun)(10);
    return 0;
}

void printing(uc a)
{
 printf("\n value of a=%d",a);
}
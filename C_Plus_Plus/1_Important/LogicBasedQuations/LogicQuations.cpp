#include<iostream>
using namespace std;
int main()
{
    // char num =127;
    // num=num+1;
    // // cout<<num<<endl;
    // printf("\n%d",num);

/*
Explanation : Before entering into the for loop 
the CHECK CONDITION is “evaluated”. Here it is evaluated 
to 0 (false) and comes out of the loop, and i is incremented 
(note the semicolon after the for loop).
*/
    // char i = 0;
    // for (; i++; printf("%d", i))
    //     ;
    // printf("%d", i);
    
    // Explanation : The range of unsigned char is 0 to 255 and 
    // when the value of var will cross over 255, 
    // value will be 0 and again same process will happen.

    // unsigned char counter = 0;
    // for (counter = 0; counter <=255; counter++) {
    //     printf("%d ", counter);
    // }
 
 /*
 for(;;) it is possible in C, there is no need
  to place condition with in the for(), you can place 
  condition with in the body of the loop.
 */
     int count = 0;
    for (;;) {
        if (count == 10)
            break;
        printf("%d ", ++count);
    }
    return 0;
}
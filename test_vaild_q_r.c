#include <stdio.h>  
int Divide(int numerator, int denominator, int* ptr1, int* ptr2); 


int main() {
    int x = -25;
    int y = -8;
    int *ptr1 = &x;
    int *ptr2 = &y; 
    Divide(x, y,ptr1,ptr2);
    printf("q is %d and r is %d\n",*ptr1, *ptr2);
    
    return 0;
}

int Divide(int numerator, int denominator, int *ptr1, int *ptr2)
{  
    
   if (denominator == 0){return -1;}
    
       *ptr1 = numerator/ denominator;            
       *ptr2 = numerator % denominator;
   
  /*Without this "If" condition some compilers are providing invalid results, which means it is unexpectedly handling integer division, inconsistent with standard C behavior.*/
  if ((*ptr2 < 0 && numerator > 0) || (*ptr2 > 0 && numerator < 0))
    {
        if (denominator > 0)
        {
            *ptr2 += denominator;
            *ptr1 -= 1;
        }
        else
        {
            *ptr2 -= denominator;
            *ptr1 += 1;
        }
    }
    
    return 0;
}



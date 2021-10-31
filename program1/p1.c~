/*Name : Thai Bui
 * Class: CS320-01
 * Date: 9/19/21
 */
/*
 * File: p1.c -- C driver for dynamic stack
 */
#include "stackd.h"
#include <stdio.h>
#include <stdlib.h>

void show(stack s)
{
   PrintStack(s); printf("---\n");
}

boolean_t isOperator(char c) {
   int tmp = atoi(&c);
   return (tmp == 0 ? FALSE : TRUE);
}

int main(void)
{
   stack s = NULL;
   el_t e;
   char sequence[12] = "598+46**7*+";
   char *addrPtr;
   /* This pointer keeps the address of the first character of the given sequence */
   addrPtr = sequence;

   /* TODO:  Demonstrate the operation of this postfix expression.
    *        5 9 8 + 4 6 * * 7 * +
    */
   /* While the value at the pointing address is not the null character  */
   while (*addrPtr != '\0') {
      if (isOperator(*addrPtr)) {
         e = *addrPtr - '0';
         Push(&s, e);
         show(s);
      } else {
         int first, second;

         /* Pop the first two elements top down to perform the operation */
         Pop(&s, &first);
         Pop(&s, &second);

         switch (*addrPtr) {
            case '*': {
               first = first * second;
               break;
            }
            case '+': {
               first = first + second;
               break;
            }
            default: {break; }
         }
         Push(&s, first);
         show(s);
      }
      addrPtr++;
   }

   return 0;
}
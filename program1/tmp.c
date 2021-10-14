
#include "stackd.h"
#include <stdio.h>
#include <stdlib.h>

void show(stack s)
{
   PrintStackUp(s); printf("---\n");
}

int main(void)
{
   stack s = NULL;
   el_t e;
   Push(&s, 5);
    show(s);
    Push(&s, 9);
    show(s);
    Push(&s, 8);
    show(s);
    Pop(&s, &e);
    Pop(&s, &e);
    Push(&s, 17);
    show(s);
    Push(&s, 4);
    show(s);
    Push(&s, 6);
    show(s);
    Pop(&s, &e);
    Pop(&s, &e);
    Push(&s, 24);
    show(s);
    Pop(&s, &e);
    Pop(&s, &e);
    Push(&s, 408);
    show(s);
    Push(&s, 7);
    show(s);
    Pop(&s, &e);
    Pop(&s, &e);
    Push(&s, 2856);
    show(s);
    Pop(&s, &e);
    Pop(&s, &e);
    Push(&s, 2861);
    show(s);

   return 0;
}
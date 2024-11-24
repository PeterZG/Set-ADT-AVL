// COMP2521 22T2 Assignment 1

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "Set.h"
#include "SetStructs.h"


int main(int argc, char *argv[]) {
	Set s = SetNew();
	SetInsert(s, 5);
    printf("root is %d\n", s->tree->item);
	SetInsert(s, 2);
    printf("root is %d\n", s->tree->item);
	SetInsert(s, 8);
    printf("root is %d\n", s->tree->item);
	SetInsert(s, 4);
    printf("root is %d\n", s->tree->item);
	SetInsert(s, 7);
    printf("root is %d\n", s->tree->item);
	SetInsert(s, 2);
    printf("root is %d\n", s->tree->item);

	SetFree(s);
}


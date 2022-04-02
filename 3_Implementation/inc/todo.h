
#include <stdio.h>
#ifndef __TODO_H__
#define __TODO_H__

extern int tLength;
FILE *fp;

struct Todo 
{
    char title[50];
    char createdAt[50];
    _Bool isCompleted;
} todos[20];

#endif
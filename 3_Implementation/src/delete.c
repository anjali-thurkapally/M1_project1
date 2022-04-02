#include <stdio.h>
#include <string.h>
#include <delete.h>

int deleteTodo(int todoId)
{
    // int todoId;
    // printf("Enter the ID of todo \n>>");
    // scanf("%d", &todoId);
    if (todoId < 0 || todoId > tLength)
    {
        printf("Invalid todo id \n");
    }
    else
    {
        todoId--;
        memmove(todos + todoId, todos + todoId + 1, (tLength - todoId - 1) * sizeof(*todos));
        tLength--;
        printf("Your todo has been deleted \n");
    }
    return 0;
}

#include <display.h>

int printAllTodo()
{
    int cnt = 0;

    printf("+----+-------------------------------------+--------------+-------------+\n");
    printf("| ID |            Todo Title               |  Created at  |  Completed  |\n");
    printf("+----+-------------------------------------+--------------+-------------+\n");

    for (int i = 0; i < tLength; i++)
    {
        if (todos[i].isCompleted)
        {
            printf("\033[10m");
        }
        else
        {
            printf("\033[1m");
        }

        printf("|%3d | %-35s | %-12s | %-13s |\n", i + 1, todos[i].title, todos[i].createdAt, (!todos[i].isCompleted) ? " ❌  No  " : " ✅  Yes ");
        printf("+----+-------------------------------------+--------------+-------------+\n");
        cnt += 1;
    }

    return cnt;
}
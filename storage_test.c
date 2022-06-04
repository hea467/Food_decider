#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#include "storage_list.h"

bool compare_preference(storage_list_node *ST, int n)
{
    if (ST->preference > n)
        return true;
    return false;
}

int main()
{
    storage_list *test1 = new_storage_list(&compare_preference);
    add_list_node(test1, 6, 0.1, 'l', 'a', 11, "Hunan");
    add_list_node(test1, 8, 1.2, 'l', 'a', 14, "Ramen_Bar");
    add_list_node(test1, 1, 0.6, 'l', 's', 10, "Subway");
    add_list_node(test1, 7, 0.6, 'l', 'j', 10, "Sushi_Fuku");
    storage_list *res = decision(test1, 2);
    storage_list_node *curr = res->start;
    printf("Result list: ");
    while (curr != res->end)
    {
        printf("%s ->", curr->name);
        curr = curr->next;
    }
    printf("End \n");

    // random
    srand(time(0));
    int rando = rand() % 3;
    // printf("random = %d", rando);
    storage_list_node *point = res->start;
    for (int i = 0; i < rando; i++)
    {
        point = point->next;
    }
    printf("Randomly selected result: %s", point->name);
    free_storage_list(test1);
    free_storage_list(res);
    return 0;
}

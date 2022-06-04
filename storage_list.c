#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "storage_list.h"

storage_list *new_storage_list(compare_fn *cmpp)
{
    storage_list *new_ST = malloc(sizeof(storage_list));
    new_ST->start = malloc(sizeof(storage_list_node));
    new_ST->end = new_ST->start;
    new_ST->cmp = cmpp;
    return new_ST;
}

void add_list_node(storage_list *ST, int p, float d, char time, char tp, int costt, char *namee)
{
    storage_list_node *new_ST_node = malloc(sizeof(storage_list_node));
    ST->end->preference = p;
    ST->end->distance = d;
    ST->end->time = time;
    ST->end->type = tp;
    ST->end->cost = costt;
    ST->end->name = namee;
    ST->end->next = new_ST_node;
    ST->end = ST->end->next;
}

void free_storage_list(storage_list *ST)
// pls don't leak...
{
    storage_list_node *curr = ST->start;
    storage_list_node *next = NULL;
    while (curr != NULL)
    {
        next = curr->next;
        free(curr);
        curr = next;
    }
    // assert(next == NULL);
    free(ST);
}

storage_list *decision(storage_list *ST, int c)
{
    storage_list *result = new_storage_list(ST->cmp);
    storage_list_node *curr = ST->start;
    while (curr != NULL)
    {
        if ((ST->cmp)(curr, c))
        {
            // What is safety?
            add_list_node(result, curr->preference, curr->distance,
                          curr->time, curr->type, curr->cost, curr->name);
        }
        curr = curr->next;
    }
    return result;
}

int storage_list_len(storage_list *ST)
{
    storage_list_node *curr = ST->start;
    int res = 0;
    while (curr != NULL)
    {
        res++;
        curr = curr->next;
    }
    return res;
}

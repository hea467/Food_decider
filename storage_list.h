#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct st_list_header
{
    int preference;
    float distance;
    char time;
    char type;
    int cost;
    char *name;
    struct st_list_header *next;
};

typedef struct st_list_header storage_list_node;

typedef bool compare_fn(storage_list_node *st1, int n);

struct storage_list
{
    storage_list_node *start;
    storage_list_node *end;
    compare_fn *cmp;
};

typedef struct storage_list storage_list;

storage_list *new_storage_list(compare_fn *cmpp);

void add_list_node(storage_list *ST, int p, float d, char time, char tp, int costt, char *name);

void free_storage_list(storage_list *ST);

storage_list *decision(storage_list *ST, int c);

int storage_list_len(storage_list *ST);

#include <stdio.h>
#include <search.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "block.h"
#include "linkedlist.h"

#define NVOTES 10

extern hash string_hash(void *string);

typedef enum party_code_t {A, B, C, D} party_code;
char *party_name[D] = {"A", "B", "C"};


// THIS FUNCTIONS GETS THE INPUT FROM USER 
static party_code get_vote()
{
    int r;
    printf("\n\n");
    printf("Input 0 for Party A\n\tInput 1 for Party B\n\t\tInput 2 for Party C\n\n");
    scanf("%d",&r);
    if(r>=3 || r<0)
    {
        printf("\n INVALID INPUT.\n\tPLEASE READ THE INSTRUCTIONS CAREFULLY\n");
        return get_vote();
    }
    else{
        printf("\nVOTE SUCCESSFULLY REGISTERED\n");

        return r;
    }
    
}

void main(int argc, char const *argv[])
{  
    srand(time(NULL));

    NODE *head;
    DATA genesis_element;
    init(&head);

    // First block is created manually with hash = 0
    transaction genesis_transactions = {party_name[get_vote()]};
    block_t genesis_block = {0, string_hash(genesis_transactions), genesis_transactions};
    genesis_element.info = genesis_block;
    head = add(head, genesis_element);

    // Now, we are going to submmit 10 votes
    int i, previous_hash = genesis_element.info.previous_hash;
    transaction trans_list = (transaction) malloc(NVOTES * sizeof(char)*10);
    for(i=0;i<NVOTES;i++)
    {
        DATA *el = malloc(sizeof(DATA));
        block_t *b = malloc(sizeof(block_t));

        transaction t = {party_name[get_vote()]};
        strcat(trans_list, t);
        b->previous_hash = previous_hash;
        b->hash = string_hash(trans_list);
        b->transactions = t;
        el->info = *b;
        previous_hash = b->hash;
        head = add(head, *el);

    }

    print_list(head);
    
    return;

    
}

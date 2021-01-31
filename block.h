#ifndef BLOCK_H
#define BLOCK_H

typedef int hash;
typedef char *transaction;

typedef struct Block_T {
    hash previous_hash;
    hash hash;
    transaction transactions;    
}block_t;

#endif //BLOCK_H
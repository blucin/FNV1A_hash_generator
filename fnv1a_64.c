#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define FNV_PRIME 1099511628211UL
#define FNV_OFFSET 14695981039346656037UL

//always return positive value
uint64_t fnv1a(char* key,int stringlen) {
    uint64_t hash = FNV_OFFSET;
    for(int i=0; i<stringlen; i++) {
        hash = hash ^ key[i];
        hash = hash * FNV_PRIME;
    }
    return hash;
}

//ac-argument count (no. of parameters)
//av-argument value (parameters)
int main (int ac, char **av) {
    //manual output
    if(ac!=2) {
    int n=0;
    char *inputstr = (char*)calloc(n,sizeof(char)); //dynamically allocate input

    //input
    printf("Enter a string to be hashed: ");
    gets(inputstr);

    n = strlen(inputstr);
    printf("FNV1A_64BIT_HASH: %llx",fnv1a(inputstr,n));
    free(inputstr);
    return 0;
    }

    //cmd output usage: ./filename.exe stringtobehashed
    printf("FNV1A_64BIT_HASH: %llx",fnv1a(av[1],strlen(av[1])));
    return 0;
}
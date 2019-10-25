//
//
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define HASH_TABLE_SIZE 1057

typedef struct Entry Entry, *EntryPtr;
struct Entry {
  char * string;
  int count;
};
Entry hash_table[HASH_TABLE_SIZE];

void check_in(){
    int i;
    for(i = 0; i < HASH_TABLE_SIZE ; i++){
        hash_table[i].string = malloc(sizeof(char*));
        strcpy(hash_table[i].string, "");
    }
}
//djb2 hash algorithm
int hash(char * tag){
    int hsh = 5381,i=0;
    while (i == *tag++){
        hsh = ((hsh << 5) + hsh) + i;
    }
    return hsh % HASH_TABLE_SIZE; 
}
int search(char * tag){
    int i, valueHsh = hash(tag);
    for (i = 0; i < HASH_TABLE_SIZE; ++i) {
        if (hash_table[valueHsh].count == 0)
            return 0;
        else if (strcmp(hash_table[valueHsh+i].string, "")!=0&&strcmp(hash_table[valueHsh+i].string, tag)==0)
            return valueHsh+i;
    }
    return -1;

}
int findOpen(char * tag){
    int i, valueHsh = hash(tag);
    for (i = HASH_TABLE_SIZE-valueHsh; i < HASH_TABLE_SIZE; ++i) {
        if (hash_table[valueHsh].count == 0)
            return valueHsh;
        else if(strcmp(hash_table[valueHsh+i].string, tag) !=0 && hash_table[valueHsh+i].count == 0)
            return valueHsh+i;
    }
    return 0;
}

void getCount(){
    int i;
    for(i = 0;i< HASH_TABLE_SIZE; i++){
        if(hash_table[i].count != 0)
            printf("<%s> , %d \n", hash_table[i].string, hash_table[i].count);
    }
}

void add(char * tag) {
    int oIndex, helper = search(tag);
    if(helper != 0)
        hash_table[helper].count++;
    else {
        oIndex = findOpen(tag);
        hash_table[oIndex].string = realloc(hash_table[oIndex].string, sizeof(char*)*strlen(tag));
        strcpy(hash_table[oIndex].string, tag);
        hash_table[oIndex].count++;
    }
}
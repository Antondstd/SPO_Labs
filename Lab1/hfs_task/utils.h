//
// Created by ad3st on 29.04.2021.
//

#ifndef LAB1FINAL_UTILS_H
#define LAB1FINAL_UTILS_H

#include "hfs_structures.h"
#include <stdbool.h>
typedef struct BTree {
    void *data;
    BTHeaderRec *header;
} BTree;

typedef struct HFSPlus {
    int deviceDescriptor;
    HFSCatalogNodeID pwd;
    HFSPlusVolumeHeader *volumeHeader;
    BTree *catalog;
} HFSPlus;

typedef struct Node {
    BTNodeDescriptor *descriptor;
    uint16_t *record_offsets;
} Node;

typedef struct lsFile{
    bool type;
    char *name;
}lsFile;

typedef struct lsIter{
    int size;
    lsFile *file;
}lsIter;

typedef struct Record {
    void *data;
    uint32_t id;
    int16_t type;
    uint16_t size;
    uint16_t key_length;
    HFSPlusCatalogKey *key;
    char *name;
} Record;

HFSPlus *getHFSPlus(char *name);

Node *getNode(int nodeNumber, BTree *tree);

Record *getRecord(int recordNumber, Node *node);

void freeHFSPlus(HFSPlus *hfs);

void freeBTree(BTree *bTree);

void freeNode(Node *node);

void freeRecord(Record *record);

char* cd(HFSPlus *hfs, char *name);

char* ls(HFSPlus* hfs, char *path);

char* f_pwd(HFSPlus *hfs);

char *cp(HFSPlus *hfs, char *source, char *dest);

void* new_getChildrens(HFSPlus *hfs, uint32_t parent, lsIter *buffer);
void* new_ls(HFSPlus *hfs, char *path);
#endif //LAB1FINAL_UTILS_H

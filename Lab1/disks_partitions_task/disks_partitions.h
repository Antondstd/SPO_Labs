//
// Created by ad3st on 29.04.2021.
//

#ifndef LAB1FINAL_DISKS_PARTITIONS_H
#define LAB1FINAL_DISKS_PARTITIONS_H
#include <math.h>
#define Kb pow(2,10)
#define Mb pow(2,20)
#define Gb pow(2,30)
char* getDisksPartitions(char *mode);
char* getFormattedSize(long size);
#endif //LAB1FINAL_DISKS_PARTITIONS_H

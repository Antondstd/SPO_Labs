#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "hfs_task/utils.h"
#include "disks_partitions_task/disks_partitions.h"

int fsbrowse(char *filename) {
    HFSPlus *hfs = getHFSPlus(filename);
    if (hfs == NULL) {
        printf("This is not a HFSPlus system");
        return -1;
    }
    bool exit = false;
    char *inputString = malloc(1024);
    while (!exit) {
        printf("$:");
        fgets(inputString, 1024, stdin);
        char *command = strtok(inputString, " \n");
        if (command == NULL) {
            continue;
        }
        char *source = strtok(NULL, " \n");
        char *dest = strtok(NULL, " \n");
        if (strcmp(command, "exit") == 0) {
            exit = 1;
        }else if (strcmp(command, "ls") == 0) {
            char *message = ls(hfs, source);
            printf("%s", message);
            free(message);
        }else if (strcmp(command, "cd") == 0) {
            char *message = cd(hfs, source);
            if (message != NULL) {
                printf("%s", message);
                free(message);
            }
        } else if (strcmp(command, "pwd") == 0) {
            char *message = f_pwd(hfs);
            printf("%s", message);
            free(message);
        }  else if (strcmp(command, "cp") == 0) {
            char *message = cp(hfs, source, dest);
            printf("%s", message);
            free(message);
        } else {
            printf("Command not found\n");
        }
    }
    freeHFSPlus(hfs);
    return 0;
}

int main(int argc, char **argv) {
    if (argc == 3 && strcmp(argv[1], "fsfind") == 0 && (strcmp(argv[2],"0") == 0 || strcmp(argv[2],"1") == 0)) {
        printf("%s", getDisksPartitions(argv[2]));
        return 0;
    }
    if (argc >= 3 && strcmp(argv[1], "fsbrowse") == 0) {
        fsbrowse(argv[2]);
        return 0;
    }
    printf("Bad arguments");
    return 0;
}

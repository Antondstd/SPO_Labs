#include <stdio.h>
#include <string.h>
#include <regex.h>
#include <stdlib.h>
#include "disks_partitions.h"

char* getFormattedSize(long size){
    char *formatted = malloc(10);
    if(size >= Gb){
        sprintf(formatted,"%.2fGb",size / Gb );
    }
    else if (size >= Mb){
        sprintf(formatted,"%.2fMb",size / Mb);
    }
    else if(size >= Kb){
        sprintf(formatted,"%.3fKb",size / Kb);
    }
    else
    {
        sprintf(formatted,"%dbyte",size);
    }
    return formatted;
}

char* getDisksPartitions(char *mode){
    char *result = malloc(sizeof(char) * 1000);
    char *line = NULL;
    int reti;
    char *devFoulde = "/dev/";
    regex_t regex;
    regmatch_t matches[3];
    char *pattern = "/dev/(sd[^[:space:]]*)[ ]+[^[ ]*]*[ ]*([^[ ]*]*).*";
//    char *name_buff = malloc(sizeof (char) * 25);
//    char *file_system_buff = malloc(sizeof(char) * 25);
//    char *findFileBuffer = malloc(sizeof (char) * 25);
    size_t len = 0;
    //R(re, "/dev/(sd.[0-9])[[:space:]]+[\w]*[[:space:]]*[^[:space:]]*[[:space:]]*([^[:space:]]*).*");

    memset(result,0,1000);
    reti = regcomp(&regex, pattern, REG_EXTENDED);
    if (reti) {
        fprintf(stderr, "Could not compile regex\n");
        return 0;
    }

    FILE *f = fopen("/proc/mounts", "r");
    while ((getline(&line,&len,f)) != -1){
        reti = regexec(&regex, line, 3, matches, 0);
        if (!reti) {
//            memset(file_system_buff,0,25);

            char *name_buff = calloc(1,matches[1].rm_eo - matches[1].rm_so+1);
            name_buff[matches[1].rm_eo - matches[1].rm_so] = '\0';
            memcpy(name_buff, line + matches[1].rm_so, matches[1].rm_eo - matches[1].rm_so);
            char *file_system_buff = calloc(1,matches[2].rm_eo - matches[2].rm_so+1);
            memcpy(file_system_buff, line + matches[2].rm_so, matches[2].rm_eo - matches[2].rm_so);
            name_buff[matches[2].rm_eo - matches[2].rm_so] = '\0';
            char *lineBuffer = NULL;
            if (strcmp(mode,"0") == 0)
            {
                lineBuffer = calloc(1,strlen(name_buff)+1);
                sprintf(lineBuffer, "%s\n", name_buff);
            }
            else {
                char *findFileBuffer = calloc(1,strlen("/dev/%s") + strlen(name_buff) + 1);
                sprintf(findFileBuffer,"/dev/%s",name_buff);
                FILE *fd = fopen(findFileBuffer, "r");
                free(findFileBuffer);
                fseek(fd, 0L, SEEK_END);
                long size = ftell(fd);
                char *form = getFormattedSize(size);
                lineBuffer = calloc(1,strlen(name_buff)+ strlen(file_system_buff) + strlen(form)+2+1);
                sprintf(lineBuffer, "%s %s %s\n", name_buff, file_system_buff, form);
                free(form);
            }
            strcat(result, lineBuffer);
            free(lineBuffer);
            free(name_buff);
            free(file_system_buff);
        }
    }

    return result;
}

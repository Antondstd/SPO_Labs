cmake_minimum_required(VERSION 3.17)
project(Lab1Final C)

set(CMAKE_C_STANDARD 99)

add_executable(Lab1Final main.c disks_partitions_task/disks_partitions.h disks_partitions_task/disks_partitions.c hfs_task/utils.h hfs_task/utils.c hfs_task/hfs_structures.h hfs_task/hfs_structures.c)
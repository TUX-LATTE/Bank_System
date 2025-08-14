#ifndef FILE_STORE_H
#define FILE_STORE_H

#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>


//Writes data to files
void saveData(char *firstName, char *lastName, char *username, char *password);

#endif //FILE_STORE_H
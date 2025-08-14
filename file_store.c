#include "file_store.h"

void saveData(char *firstName, char *lastName, char *username, char *password)
{
    char path[256];  
    sprintf(path, "clients/%s.txt", username);

    int fileDescriptor = open(path, O_WRONLY | O_CREAT | O_APPEND, 0644);

    if(fileDescriptor == -1)
    {
        printf("Error");
        return;
    }
}
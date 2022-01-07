/*

author : udhayamoorthi
date   : 05-1-22

*/

#include<dirent.h>
#include <stdio.h>
#include <string.h>

void list(char *path);


int main()
{
    char path[100];

    printf("give the path: ");
    scanf("%s", path);

    list(path);

    return 0;
}


void list(char *base)
{
    char path[1000];
    struct dirent *dp;
    DIR *dir = opendir(base);

   //not in directory 
    if (!dir)
//printf("folder is not directory");

        return;

    while ((dp = readdir(dir)) != NULL)
    {
        if (strcmp(dp->d_name, ".") != 0 && strcmp(dp->d_name, "..") != 0)
        {
            printf("%s\n", dp->d_name);

            // Construct new path from our base path
            strcpy(path, base);
            strcat(path, "/");
            strcat(path, dp->d_name);
            list(path);
        
}

    }

//printf("folder is not directory"); 
   closedir(dir);

}

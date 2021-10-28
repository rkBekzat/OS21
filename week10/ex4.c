#include <errno.h>
#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#include <stdbool.h>

typedef struct{
    ino_t inode;
    char names[128];
    nlink_t links;
}File;

unsigned int cnt = 0;
bool found = 0;
File A[128];
struct stat es;
struct dirent *de;

int main(){
    DIR *dir=opendir("tmp");

    while((de=readdir(dir))!=0){
        
        char fileName[32];
        strcpy(fileName, "tmp/");
        strcat(fileName, de->d_name);

        if(stat(fileName, &es)!=0)
            return ENOENT;
        found=0;

        for(int i=0;i<cnt;i++){
            if(A[i].inode==es.st_ino){
                found=1;
                strcat(strcat(A[i].names, ", "), de->d_name);
                A[i].links++;
                break;
            }
        }

        if(found)
            continue;
        
        File x;
        x.links=1;
        x.inode=es.st_ino;
        strcpy(x.names, de->d_name);
        A[cnt++]=x;
    }

    closedir(dir);
    for(int j=0;j<cnt;j++) if(A[j].links>1) 
        printf("The files %s are linked and have inode: %llu\n", A[j].names, A[j].inode);
    return 0;
}

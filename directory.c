#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<dirent.h>

int get_file_num(const char * root)
{
    int total=0;
    DIR *dir=NULL;
    dir=opendir(root);
    if(dir==NULL)
    {
        perror("opendir error");
        exit(1);
    }
    struct dirent * ptr=NULL;
    while((ptr=readdir(dir))!=NULL)
    {
        if(strcmp(".",ptr->d_name)==0||strcmp("..",ptr->dname)==0)
        {
            continue;
        }
        //判断是不是普通文件
        if(ptr->d_type==DT_REG)
        {
            total++;
        }
        //if it is directory
        if(ptr->d_type==DT_DIR)
        {
            char path[1024]={0};
            sprintf(path,"%s,%s",root,ptr->d_name);
            total+=get_file_num(path);
        }
    }
    
    //close the directory.(just like close the file)
    closedir(dir);
    return total;
}

int main(int argc,const char* argv[])
{

    if(argc<2)
    {
        perror("a.out path");
        exit(1);
    }
    int total =get_file_num(argv[1]);
    printf("%s has regular files :%d\n",argv[1],total);
    return 0;
}
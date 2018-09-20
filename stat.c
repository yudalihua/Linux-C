#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc ,const char* argv[])
{
    struct stat st;
    int ret =stat("test",&st);
    if(ret==-1)
    {
        perror("stat error");
        exit(-1);
    }
    printf("file_size=%d\n",st.st_size);
   //file
    if((st.st_mode & S_IFMT)==S_IFREG)
    {
        printf("this is a regular  file\n");
    }
    //authority of file user
    if (st.st_mode & S_IRUSR)
    {
        printf ("   r\n");
    }
    if (st.st_mode & S_IWUSR)
    {
        printf ("   w\n");
    }
     if (st.st_mode & S_IXUSR)
    {
        printf ("   x\n");
    }

    return 0;
}
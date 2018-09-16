#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main (int argc ,const char* argv[])
{
    struct stat st;//这种方式创建了一块有效的内存。
    struct stat* st1;//这种方式必须要给st1赋初值。
    int ret =stat("test",&st);
    if(ret==-1)
    {
        perror("stat error");
        exit(-1);
    }
    printf("file_size=%d\n",st.st_size);


    return 0;
}

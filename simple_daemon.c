#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include<sys/types.h> 
#include<string.h>
#include<sys/stat.h>
#include<signal.h>
#include<time.h>
#include<fcntl.h>
#include<sys/time.h>

void do_work(int no)
{
    //get the current time
    time_t cur_time;
    time(&cur_time);
    char* ptr=ctime(&cur_time);
    int fd=open("/home/temp",O_CREAT|O_RDWR|O_APPEND,0664);
    write(fd,ptr,str(ptr)+1);   
    close(fd);
}

int main(int argc,const char* argv[])
{
    //create a session,and let the child process become the group  leader.
    pid_t pid=fork();
    if(pid>0)
    {
        exit(1);
        //raise(SIGKILL);
        //abort();
        //kill(getpid(),SIGKILL);
    }
    else if(pid==0)
    {
        setsid();
        //change default directory
        chdir("/root");
        //reset umask
        umask(0);
        //close file descriptors
        close(STDIN_FILENO);
        close(STDOUT_FILENO);
        close(STDERR_FILENO);

        //execute main operations.

        //register the sigaction() function.
        struct sigaction act;
        act.sa_flags=0;
        act.sa_handler=do_work;
        sigemptyset(&act.sa_mask);
        sigaction(SIGALRM,&act,NULL);



        //create a timer
        struct itimerval val;
        val.it_value.tv_sec=2;
        val.it_value.tv_usec=2;

        val.it_interval.tv_sec=1;
        val.it_interval.tv_sec=0;

        setitimer(ITIMER_REAL,&val,NULL);

        while(1);
    }
    return 0;
}

#include<sys/epoll.h>
#include <sys/time.h> 
#include<stdio.h>
#include<errno.h>
#include <pthread.h>

static pthread_cond_t condition;
static pthread_mutex_t mutex;

char * ep_file;
FILE *f;

void read(){

    printf("t0\n");
    struct timeval now;
    struct timespec outtime;
    printf("t1\n");
    pthread_mutex_lock(&mutex);
    printf("t2\n");

    while(1) {
        gettimeofday(&now, NULL);
        outtime.tv_sec = now.tv_sec + 2;
        outtime.tv_nsec = now.tv_usec * 1000;
        pthread_cond_timedwait(&condition,&mutex,&outtime);
        printf("t wait...\n");
        fputc('o',f);
        fflush(f);
        fclose(f);
    }

    pthread_mutex_unlock(&mutex);

}

main(int argc, char const *argv[])
{
    printf("0\n");
    int epfd = epoll_create(10);

    printf("1\n");
    ep_file = "/home/huanjinzi/workspace/c/epoll/epoll_file";
    printf("2\n");
    f = fopen(ep_file,"w");

    printf("3\n");
    int io_fd = fileno(f);
    printf("4\n");
    epoll_ctl(epfd,EPOLL_CTL_ADD,io_fd,EPOLLPRI | EPOLLIN | EPOLLOUT | EPOLLWAKEUP);

    printf("create thread...\n");

    pthread_t t_id;
    int t_err = pthread_create(&t_id,NULL,read,NULL);

    if(t_err != 0) {
        printf("create thread error...\n");
    }



    while(1) {
        errno = 0;
        int err = epoll_wait(epfd,EPOLLPRI | EPOLLIN | EPOLLOUT | EPOLLWAKEUP,20,-1);

        if (err == -1){

            printf("error code : %d\n",errno);

        } else {
            printf("event come\n");
        }
    }

    return 0;
}

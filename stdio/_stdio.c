#include<stdio.h>
#include<errno.h>

main(int argc, char const *argv[])
{
    
    size_t a = 10;

    printf("%d\n",a);
    printf("%d\n",FOPEN_MAX );

    FILE *error = stdout;

    fprintf(error,"%s\n","hello world");

    // file stream.

    // read file
    errno = 0;
    FILE *my = fopen("/home/huanjinzi/main.log","r");

    if(my == NULL){
        fprintf(error,"file open error: %d\n",errno);
        exit(errno);
    }

    char buf[1024];
    while(!feof(my)){

        fgets(buf,1024,my);
        printf("%s",buf);
    }

    fclose(my);

    return 0;
}


#include <string.h>
#include <stdio.h>


int main(int argc, char **argv)
{
    char *option = "-sync";
    char *s1 = "string 111!";
    void *s2 = "string 222!";
    char s3[] = "string 333!";
    argc++;
    char *args[argc];
    args[argc-1] = option;

    
    printf("\ns1:%s\n",s1);
    printf("s1:%d\n",s1);
    printf("s1 sizeof:%d\n",sizeof(s1));
    printf("*s1 sizeof:%d\n",sizeof(*s1));

    printf("\ns2:%s\n",s2);
    printf("s2:%d\n",s2);
    printf("s2 sizeof:%d\n",sizeof(s2));
    printf("*s2 sizeof:%d\n",sizeof(*s2));

    printf("\ns3:%d\n",s3);
    printf("s3:%d\n",s3);
    printf("s3 sizeof:%d\n",sizeof(s3));
    printf("*s3 sizeof:%d\n",sizeof(*s3));

    int a = 100;
    printf("\nint sizeof:%d\n",sizeof(a));
    printf("&int sizeof:%d\n",sizeof(&a));

    // addr(pointer) is 8 bytes[64-bits machine].
    // int is 4 bytes.
    // char is 1 byte.
    return 0;
}
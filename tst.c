#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>
#include<string.h>

int main(int ac, char **av)
{
    int id = fork();
    int n;
    int i;
    if (id == 0)
        n = 1;
    else 
        n = 6;
    if (id != 0)
        wait(NULL);
    for (i = n; i < n + 5; i++)
    {
        printf("%d", i);
        fflush(stdout);
    }
    if (id != 0)
        printf("\n");

    if (id != 0)
    {
        fork();
    }
    if (id == 0){
        printf("hello world from child process\n");
    }
    else { 
        printf("hello world from main process\n");
    }
    return 0;
     printf("hello world\n");
}
//put the test
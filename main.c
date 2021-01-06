#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

void grep(char *argv[])
{
    int fd,r,j=0;
    char temp,line[100];
    if((fd=open(argv[2],O_RDONLY)) != -1)
    {
        while((r=read(fd,&temp,sizeof(char)))!= 0)
        {
            if(temp!='\n')
            {
                line[j]=temp;
                j++;
            }
            else
            {
                if(strstr(line,argv[1])!=NULL)
                    printf("%s\n",line);
                memset(line,0,sizeof(line));
                j=0;
            }

        }
    }   
}

int main()
{
    puts("Making directory and file...");
    FILE* test;
    sleep(1);
    mkdir("directory", 0770);
    test = fopen("directory/test.txt", "w");
    puts("Made directory and file");
    sleep(3);
    puts("Removing directory and file...");
    sleep(1);
    remove("directory/test.txt");
    rmdir("directory");
    puts("Removed directory and file");

    return 0;
}
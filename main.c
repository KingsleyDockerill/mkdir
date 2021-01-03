#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>

int main()
{
    struct stat st = {0};
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
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

/* #include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

int main() {
    struct dirent **namelist;
    int n;
    n = scandir(".", &namelist, NULL, alphasort);
    if(n < 0) {
        perror("scandir");
    }
    else {
        while(n--) {
            printf("%s\n", namelist[n]->d_name);
            free(namelist[n]);
        }
        free(namelist);
    }
} */

/* #include <sys/types.h>
#include <regex.h>
#include <stdio.h>

int main(int argc, char *argv[]){
        regex_t regex;
        int reti;
        char msgbuf[100];

/ Compile regular expression /
        reti = regcomp(&regex, "^a[[:alnum:]]", 0);
        if( reti ){ fprintf(stderr, "Could not compile regex\n"); exit(1); }

/ Execute regular expression /
        reti = regexec(&regex, "abc", 0, NULL, 0);
        if( !reti ){
                puts("Match");
        }
        else if( reti == REG_NOMATCH ){
                puts("No match");
        }
        else{
                regerror(reti, &regex, msgbuf, sizeof(msgbuf));
                fprintf(stderr, "Regex match failed: %s\n", msgbuf);
                exit(1);
        }

/ Free compiled regular expression if you want to use the regex_t again /
	regfree(&regex);

        return 0;
}
 */

int main(int argc, char* argv[])
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
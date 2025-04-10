#include <stdio.h>
#include <getopt.h>
#include <assert.h>

#include "detect-palindrome.h"

void usage()
{
    puts(USAGE);
}

int ispal(const char *palstr)
{
    assert(palstr != NULL);
    const char *lp = palstr;
    const char *rp = palstr;
    while (*(++rp) != '\0');
    rp -= 1;
    while (lp < rp) {
        if (*lp != *rp) {
            return 0;
        }
        lp++;
        rp--;
    }
    return 1;
}

int parse_cmdargs(int argc, char **argv, char **palstr)
{
    int opt;
    while ((opt = getopt(argc, argv, "h")) != -1) {
        switch (opt) {
            case 'h':
                return 0;
            default:
                fprintf(stderr, "Invalid flag: -%c\n", opt);
                return 0;
        }
    }
    if (optind == argc - 1) {
        *palstr = argv[optind];
    } else {
        fprintf(stderr, "Invalid number of arguments.\n");
        return 0;
    }
    return 1;
}

int main(int argc, char **argv)
{
    assert(ispal("racecar"));
    assert(ispal("AMANAPLANACANALPANAMA"));
    assert(!ispal("hi"));
    char *palstr = NULL;
    if (!parse_cmdargs(argc, argv, &palstr)) {
        usage();
        return 0;
    }
    assert(palstr != NULL);
    if (ispal(palstr)) {
        printf("%s is a palindrome.\n", palstr);
    } else {
        printf("%s is NOT a palindrome.\n", palstr);
    }
}


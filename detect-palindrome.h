/**
 * Detect Palindrome header file
 */

#define USAGE "DETECT-PALINDROME: Authored by Mitch Feigenbaum\n" \
    "Usage: detect-palindrome <PALINDROME>\n" \
    "Options: \n" \
    "\t-h\t\tPrint this help message"
/**
 * Print help on using the program with its options.
 */
void usage();

/**
 * Take a string as input and return 1 if it is a palindrome and 0 if it is not a palindrome
 */
int ispal(const char *);


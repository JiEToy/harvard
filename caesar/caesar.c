#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// checking for cipher code
int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("error 51: no cipher given\n");
        return 1;
    }

// get plaintext
    string plain = get_string("plaintext: ");
    // make key
    int k = atoi(argv[1]);
    printf("ciphertext: ");
    // for each character of plaintext, calculate ciphertext using key(k)
    for (int i = 0, n = strlen(plain); i < n; i++)
    {
        if (isupper(plain[i]))
        {
            char cypher = ((plain[i] - 65 + k) % 26) + 65;
            printf("%c", cypher);
        }
        else if (islower(plain[i]))
        {
            char cypher = ((plain[i] - 97 + k) % 26) + 97;
            printf("%c", cypher);
        }
        // if character != alphabetical: print normally
        else
        {
            printf("%c", plain[i]);
        }
    }
    printf("\n");
    return 0;
}
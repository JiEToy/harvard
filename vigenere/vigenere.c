#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// checking for cipher code
int main(int argc, string argv[])
{
    // checking if there is a key and no more than one
    if (argc != 2)
    {
        printf("error 51: no or too many keys given\n");
        return 1;
    }
    // checking if key is alphabetical
    string k = (string) argv[1];
    for (int i = 0, n = strlen(k); i < n; i++)
    {
        if (isalpha(k[i]) == false)
        {
            printf("Error: Please put in an alphabetical key\n");
            return 1;
        }
    }

// get plaintext
    string plain = get_string("plaintext: ");
    // checking length of key, for wrapping around later
    int l = strlen(k);
    // converting key to 0 indexed
    for (int i = 0, n = strlen(k); i < n; i++)
    {
        if (isupper(k[i]))
        {
            k[i] = k[i] - 65;
        }
        else if (islower(k[i]))
        {
            k[i] = k[i] - 97;
        }
    }
    printf("ciphertext: ");
    // for each character of plaintext, calculate ciphertext using key(k)
    for (int i = 0, j = i, n = strlen(plain); i < n; i++)
    {
        if (isupper(plain[i]))
        {
            char cypher = ((plain[i] - 65 + k[j]) % 26) + 65;
            printf("%c", cypher);
            // only j++ when key[i] = alphabetical, and wrap around using key length
            j = (j + 1) % l;
        }
        else if (islower(plain[i]))
        {

            char cypher = ((plain[i] - 97 + k[j]) % 26) + 97;
            printf("%c", cypher);
            j = (j + 1) % l;
        }
        // if character != alphabetical: print normally
        else
        {
            printf("%c", plain[i]);
        }
    }
    // \n for style!
    printf("\n");
    return 0;
}
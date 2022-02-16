#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

string get_cipher(string key, string plain);

int main(int argc, string argv[])
{
    //reject more than one input
    if(argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    string key = argv[1];
    //reject if key is not 26 characters
    if(strlen(key) != 26)
    {
        printf("Key must contain 26 characters\n");
        return 1;
    }
    //check that key does not contain non alphabetic characters
    int i;
    for (i = 0; i < 26; i++)
    {
        if(!isupper(key[i]) && !islower(key[i]))
        {
            printf("Key must only contain alphabetic characters\n");
            return 1;
        }
    }
    
    //check that there are no repeated characters in key
    int seen[26] = {0};
    for (i = 0; i < 26; i++)
    {
        if(isupper(key[i]))
        {
            if(seen[key[i] - 65] == 0)
            {
                seen[key[i] - 65] = 1;
            }
            else 
            {
                printf("Key must not contain repeated characters\n");
                printf("%c\n", key[i]);
                return 1;
            }
        }
        else if(islower(key[i]))
        {
            if(seen[key[i] - 97] == 0)
            {
                seen[key[i] - 97] = 1;
            }
            else 
            {
                printf("Key must not contain repeated characters\n");
                printf("%c\n", key[i]);
                return 1;
            }
        }
    }
    
    string plain = get_string("plaintext:");
    // get corresponding ciphertext
    string cipher = get_cipher(key, plain);
    
    printf("ciphertext: %s\n", cipher);
    
    return 0;
}


string get_cipher(string key, string plain)
{
    int n = strlen(plain);
    int i;
    for (i = 0; i < n; i++)
    {
        if(isupper(plain[i]))
        {
            plain[i] = toupper(key[plain[i] - 65]);
        }
        else if(islower(plain[i]))
        {
            plain[i] = tolower(key[plain[i] - 97]);
        }
    }
    return plain;
}
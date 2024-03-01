#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>


void caesar_encrypt(char* plain, int len, int key, char* result)
{
    // Encrypt each character in the message
    for (int i = 0; i < len; i++)
    {
        char c = plain[i];

        if (isalpha(c) && c <=127)
        {
            char base = islower(c) ? 'a' : 'A';
            result[i] = (c - base + key) % 26 + base;
        }
        else
        {
            result[i] = c;  // Non-alphabetic characters remain unchanged
        }
    }
}

void caesar_decrypt(char* ciphertext,int len, int key, char* result)
{
    // Decrypt each character in the ciphertext
    for (int i = 0; i < len; i++)
    {
        char c = ciphertext[i];

        if (isalpha(c))
        {
            char base = islower(c) ? 'a' : 'A';
            result[i] = (c - base - key + 26) % 26 + base;
        }
        else
        {
            result[i] = c;  // Non-alphabetic characters remain unchanged
        }
    }
}

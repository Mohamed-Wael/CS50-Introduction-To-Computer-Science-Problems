#include <stdio.h>
#include <cs50.h>

void printHash(int n);
void printSpace(int n);

int main(void)
{
    int height;
    
    do
    {
        height = get_int("Height:\n");
    }
    while (height < 1 || height > 8);
    int hashes = 1;
    int spaces = height - 1;
    while (hashes <= height)
    {
        printSpace(spaces);
        printHash(hashes);
        printSpace(2);
        printHash(hashes);
        printf("\n");
        hashes++;
        spaces--;
    }
    
    
    
}

//printing hashes
void printHash(int n)
{
    int x;
    for (x = 0 ; x < n ; x++)
    {
        printf("#");
    }
}

//printing spaces
void printSpace(int n)
{
    int x;
    for (x = 0 ; x < n ; x++)
    {
        printf(" ");
    }
}
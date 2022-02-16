#include <stdio.h>
#include <cs50.h>


bool evaluateChecksum(long card);
int getLength(long card);
void displayType(long card, int length);

int main(void)
{
    long card = get_long("Enter card number:\n");
    
    
    bool checksum = evaluateChecksum(card);
    
    int length = getLength(card);
    
    if (checksum)
    {
        displayType(card, length);
    }
    else 
    {
        printf("INVALID\n");
    }
   
}


void displayType(long card, int length)
{
   long temp;
    if (length == 13)
    {
        int i = 0;
        temp = card;
        for (i = 0 ; i < 12 ; i++)
        {
            temp = temp / 10;
        }
        
        if (temp == 4)
        {
            printf("VISA\n");
        }
        else 
        {
            printf("INVALID\n");
        }
        
    }
    else if (length == 15)
    {
        int i = 0;
        temp = card;
        for (i = 0 ; i < 14 ; i++)
        {
            temp = temp / 10;
        }
        if (temp == 3)
        {
            temp = card;
            for (i = 0 ; i < 13 ; i++)
            {
               temp = temp / 10; 
            }
            if (temp%10 == 4 || temp%10 == 7)
            {
                   printf("AMEX\n"); 
            }
            else 
            {
              printf("INVALID\n");  
            }
        }
        else 
        {
          printf("INVALID\n");  
        }
            
        
    }
    else if(length == 16)
    {
        int i = 0;
        temp = card;
        for (i = 0 ; i < 15 ; i++)
        {
            temp = temp / 10;
        }
        if (temp == 5)
        {
            temp = card;
            for (i = 0 ; i < 14 ; i++)
            {
                temp = temp / 10;
            }
            if (temp%10 == 1 || temp%10 == 2 || temp%10 == 3 || temp%10 == 4 || temp%10 == 5)
            {
                printf("MASTERCARD\n");
            }
            else
            {
               printf("INVALID\n"); 
            }
            
        }
        else if (temp == 4)
        {
            printf("VISA\n");
        }
        else 
        {
            printf("INVALID\n");
        }
    }
    else 
    {
        printf("INVALID\n");
    }
    
    
}


int getLength(long card)
{
    int n = 0;
    while(card != 0)
    {
        card = card / 10;
        n++;
    }
    return n;
    
}

bool evaluateChecksum(long card)
{
    int sum1 = 0;
    int sum2 = 0;
    int index = 1;
    int temp;
    while (card != 0)
    {
        if (index % 2 == 0)
        {
            temp = 2 * (card % 10);
            while (temp != 0)
            {
                sum2 = sum2 + (temp % 10);
                temp = temp / 10;
            }
            card = card / 10;
            index++;
        }
        else
        {
            temp = card % 10;
            sum1 = sum1 + temp;
            card = card / 10;
            index++;
        }
    }
    
    int total = sum1 + sum2;
    if (total % 10 == 0)
    {
        return true;
    }
    else 
    {
        return false;
    }
}
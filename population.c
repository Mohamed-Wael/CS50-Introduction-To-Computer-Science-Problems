#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
    int start;
    do
    {
        start = get_int("Enter start size\n");
         
    }
    while (start < 9);
    

    // TODO: Prompt for end size
    int end;
    do
    {
        end = get_int("Enter end size\n");
        
    }
    while (end < start);
    
    // TODO: Calculate number of years until we reach threshold
    
    int years = 0;
    int population = start;
    int births;
    int deaths;
    
    while (population < end)
    {
        births = population / 3;
        deaths =  population / 4;
        population = population + births - deaths;
        years++;
    }

    // TODO: Print number of years
    
    printf("Years: %i\n", years);
}
#include <stdio.h>

char bigLetter(char letter)
{
    if(letter > 90){
        letter = letter-32;
    }
    return letter;
}

char soundex_value(char ll, char l)
{
    if((l == 'B' || l == 'F' || l == 'P' || l == 'V') && l != ll)
    {
        return 1;
    }else if((l == 'C' || l == 'G' || l == 'J' || l == 'K') && l != ll)
    {
        return 2;
    }else if((l == 'Q' || l == 'S' || l == 'X' || l == 'Z') && l != ll)
    {
        return 2;
    }else if((l == 'D' || l == 'T') && l != ll)
    {
        return 3;
    }else if((l == 'L') && l != ll)
    {
        return 4;
    }else if((l == 'M' || l == 'N') && l != ll)
    {
        return 5;
    }else if((l == 'R') && l != ll)
    {
        return 6;
    }else{
        return 0;
    }
}

void soundex(char *words[])
{
    char last_letter;
    char new_letter;
    int i = 0;
    while(words[i] != 0)
    {
        //Wortnummer ausgeben
        printf("%d ", i);
        
        //Wort ausgeben
        int z = 0;
        while(words[i][z] != 0)
        {
            printf("%c", words[i][z]);
            z++;
        }
        printf(" : ");
        
        // Soundex ausgeben
        printf("%c", bigLetter(words[i][0]));
        int x = 1;
        while(words[i][x] != 0 && x != 5)
        {
            new_letter = bigLetter(words[i][x]);
            if(new_letter != last_letter){
                printf("%d", soundex_value(last_letter, new_letter));
            }

            last_letter = new_letter;
            x++;
        }
        while(x < 6){
            printf("%d", 0);
            x++;
        }
        
        printf("\n");
        i++;
    }
}

int main(int args, char * argc[])
{
    soundex(&argc[1]);
    return 0;
}

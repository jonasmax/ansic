#include <stdio.h>

char rot13(char c)
{
    if( 'A' <= c && c <= 'Z' ) {
        if( c >= 'M' ) {
            c =  ('A'-1) + 13 - ('Z' - c);
        }else{
            c = c + 13;
        }
    }
    
    if( 'a' <= c && c <= 'z' ) {
        if( c >= 'm' ) {
            c =  ('a'-1) + 13 - ('z' - c);
        }else{
            c = c + 13;
        }
    }
    
    return c;
}

int main() 
{
    char c;
    while((c = getchar()) != EOF) {
        printf("%c", rot13(c));
    }
    return 0;
}

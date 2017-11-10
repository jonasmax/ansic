#include <stdio.h>
#include <a4RotB.h>
static int rotate_n = 0;

char rotate(char c)
{
    if( 'A' <= c && c <= 'Z' ) {
        if( c >= 'M' ) {
            c =  ('A'-1) + rotate_n - ('Z' - c);
        }else{
            c = c + rotate_n;
        }
    }
    
    if( 'a' <= c && c <= 'z' ) {
        if( c >= 'm' ) {
            c =  ('a'-1) + rotate_n - ('z' - c);
        }else{
            c = c + rotate_n;
        }
    }
    
    return c;
}

void set_rotate(int n){
	rotate_n = n;
}

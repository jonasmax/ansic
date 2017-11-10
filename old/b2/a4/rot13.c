#include <stdio.h>
#include <a4RotB.h>

int main() 
{
	set_rotate(13);
    char c;
    while((c = getchar()) != EOF) {
        printf("%c", rotate(c));
    }
    return 0;
}

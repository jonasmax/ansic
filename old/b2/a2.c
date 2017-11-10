#include <stdio.h>

enum { BREITE=800, HOEHE=600 };
int feld[HOEHE][BREITE];

void hintergrund(int rgb);
void rechteck(int p1h, int p1b, int p2h, int p2b, int rgb);
void kreis(int mp_x, int mp_y, int radius, int rgb);
void kreis_rand(int mp_x, int mp_y, int radius, int rgb, int rand);
int red(int rgb);
int green(int rgb);
int blue(int rgb);

void hintergrund(int rgb)
{
    for(int h = 0; h < HOEHE; h++)
    {
        for(int b = 0; b < BREITE; b++)
        {
            feld[h][b] = rgb;
        }
    }
}

void rechteck(int p1h, int p1b, int p2h, int p2b, int rgb)
{
    if(p1h > HOEHE || p2h > HOEHE || p1b > BREITE || p2b > BREITE)
    {
        printf("Rechteck-Eckpunkt nicht im gueltigen Bereich");
    }
    else{
        for(int h = p1h; h <= p2h; h++)
        {
            for(int b = p1b; b <= p2b; b++)
            {
                if((p1b+3) > b || (p2b-3) < b){
                    feld[h][b] = rgb;
                }
                
                if((p1h+3) > h || (p2h-3) < h){
                    feld[h][b] = rgb;
                }
            }
        }
    }
}

void kreis(int mp_x, int mp_y, int radius, int rgb)
{
    // Quadrat Eckpunkte errechnen
    int p1h = mp_x - radius;
    int p1b = p1h;
    int p2h = mp_x + radius;
    int p2b = p2h;
    
    if(p1h > HOEHE || p2h > HOEHE || p1b > BREITE || p2b > BREITE)
    {
        printf("Kreis-Eckpunkt nicht im gueltigen Bereich");
    }
    else{
        for(int h = p1h; h <= p2h; h++)
        {
            for(int b = p1b; b <= p2b; b++)
            {
                int a;
                int a_quadrat;
                if(h >= mp_y){
                    a = (h-mp_y);
                    a_quadrat = a * a;
                }else{
                    a = (mp_y-h);
                    a_quadrat = a * a;
                }
                int a2;
                int b_quadrat;
                if(b >= mp_x){
                    a2 = (b-mp_x);
                    b_quadrat = a2 * a2;
                }else{
                    a2 = (mp_x-b);
                    b_quadrat = a2 * a2;
                }
                
                int c_quadrat = a_quadrat + b_quadrat;
                int radius_quadrat = radius*radius;
                if(c_quadrat < radius_quadrat){
                    feld[h][b] = rgb;
                }
            }
        }
    }
}

void kreis_rand(int mp_x, int mp_y, int radius, int rgb, int rand){
    kreis(mp_x, mp_y, radius, rgb);
    kreis(mp_x, mp_y, radius-rand, 0x000000);
}

void zeichnen()
{   
    int rgb;
    for(int h = 0; h < HOEHE; h++)
    {
        for(int b = 0; b < BREITE; b++)
        {
            rgb = feld[h][b];
            printf("%d %d %d\n", red(rgb), green(rgb), blue(rgb));
        }
    }
}

void feld_default(){
    for(int h = 0; h < HOEHE; h++)
    {
        for(int b = 0; b < BREITE; b++)
        {
            feld[h][b] = 0;
        }
    }
}

int red(int rgb){
    return rgb >> 16;
}

int green(int rgb){
    rgb = rgb & 0x00FF00;
    return rgb >> 8;
}

int blue(int rgb){
    rgb = rgb & 0x0000FF;
    return rgb;    
}

int main(int argc, char * argv[])
{
    printf("P3\n");
    printf("800 600\n");
    printf("255\n");
    
    feld_default();
    hintergrund(0x666666);
    rechteck(400,400,500,500, 0x777777);
    kreis(100,100, 100, 0xEEEEEE);
    kreis_rand(300,300, 20, 0xEEEEEE, 2);
    
    zeichnen();

}

#include "acteurs.h"

Personnage::Personnage(float xi, float yi, float zi, BITMAP* p[3])
{
    for(int i=0;i<3;i++)img[i]=p[i];
    x = xi;
    y = yi;
    z = zi;
    pos = 0;
}

void Personnage::afficher(BITMAP* buffer)
{
    BITMAP* aff;
    switch(pos)
    {
        case 0:case 2:
            aff = img[0];
        break;

        case 1:
            aff = img[1];
        break;

        case 3:
            aff = img[2];
    }

    rotate_sprite(buffer,aff,(SCREEN_W-img[0]->w)/2,(SCREEN_H-img[0]->h)/2,itofix(a));
}

void Personnage::deplacement()
{
    a = atan2(mouse_y-(SCREEN_H-img[0]->h)/2-9,mouse_x-(SCREEN_W-img[0]->w)/2)*180/M_PI*64/90+64;

    if(key[KEY_W])
        y-=DEP;
    else if(key[KEY_S])
        y+=DEP;

    if(key[KEY_A])
        x-=DEP;
    else if(key[KEY_D])
        x+=DEP;

    if(key[KEY_W]||key[KEY_S]||key[KEY_A]||key[KEY_D])pos++;
    if(pos>3)pos=0;
}

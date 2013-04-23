#ifndef ACTEURS_H_INCLUDED
#define ACTEURS_H_INCLUDED
#include "projet.h"

class Personnage
{
    public:
        Personnage(float xi, float yi, float zi, BITMAP* p[3]);
        void afficher(BITMAP* buffer);
        void deplacement();

    private:
        float x,y,z;
        int pos,a;
        BITMAP* img[3];
};

#endif // ACTEURS_H_INCLUDED

#include <allegro.h>
#include "acteurs.h"

using namespace std;

int main()
{
    BITMAP* buffer = NULL;
    BITMAP* perso[3] = {NULL,NULL,NULL};

    allegro_init();
	install_keyboard();
	install_mouse();
	set_color_depth(desktop_color_depth());
	if(set_gfx_mode(GFX_AUTODETECT_WINDOWED, 800, 600, 0, 0))exit(EXIT_FAILURE);
	show_mouse(screen);

	buffer = create_bitmap(SCREEN_W,SCREEN_H);
	perso[0] = load_bitmap("img/acteurs/perso1.bmp",NULL);
	perso[1] = load_bitmap("img/acteurs/perso2.bmp",NULL);
	perso[2] = load_bitmap("img/acteurs/perso3.bmp",NULL);

	Personnage p1(10,10,1,perso);

	while(!key[KEY_ESC])
    {
        p1.deplacement();
        p1.afficher(buffer);
        draw_sprite(screen,buffer,0,0);
        clear_bitmap(buffer);
        rest(50);
    }

    return 0;
}END_OF_MAIN();

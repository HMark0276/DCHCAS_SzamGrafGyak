#include "app.h"
#include <stdio.h>
/**
 * Main function
 */
int main(int argc, char* argv[])
{
    App app;

    init_app(&app, 1280,720);
    while (app.is_running) {
		//SDL_ShowCursor(SDL_DISABLE);
        keyboard(&app);
        update_app(&app);
        render_app(&app);
    }
    destroy_app(&app);

    return 0;
}

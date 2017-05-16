#include <iostream>
#include "commonSocket.h"
#include <gtkmm.h>
#include <SDL2/SDL.h>


void on_jugar_clicked(Glib::RefPtr<Gtk::Application> app){
    std::cout << "Inicia el juego" << std::endl;
    // variables

    bool quit = false;
    SDL_Event event;
    int x = 288;
    int y = 208;

    // init SDL

    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window * window = SDL_CreateWindow("Z",
                                           SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, 0);
    SDL_Renderer * renderer = SDL_CreateRenderer(window, -1, 0);

    SDL_Surface * image = SDL_LoadBMP("spaceship.bmp");
    SDL_Texture * texture = SDL_CreateTextureFromSurface(renderer,
                                                         image);
    SDL_FreeSurface(image);

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

    // handle events

    while (!quit)
    {
        SDL_PollEvent(&event);

        switch (event.type)
        {
            case SDL_QUIT:
                quit = true;
                break;
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym)
                {
                    case SDLK_LEFT:  x--; break;
                    case SDLK_RIGHT: x++; break;
                    case SDLK_UP:    y--; break;
                    case SDLK_DOWN:  y++; break;
                }
                break;
            case SDL_BUTTON_LEFT:
                int mouseX = event.motion.x;
                int mouseY = event.motion.y;
                x = mouseX;
                y = mouseY;
                break;

        }

        SDL_Rect dstrect = { x, y, 64, 64 };

        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, texture, NULL, &dstrect);
        SDL_RenderPresent(renderer);
    }

    // cleanup SDL

    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void on_salir_clicked(Glib::RefPtr<Gtk::Application> app){
    std::cout << "Chau!" << std::endl;
    app->quit();
}

int main(int argc, char *argv[]) {

   // Socket socket;
   // socket.connectS(argv[1],16332);
   // socket.sendS(argv[2],5);
   // socket.shutdownS();
    auto app = Gtk::Application::create(argc, argv);

    Gtk::Window ventana;
    ventana.set_default_size(800, 640);
    Gtk::Box box;

    Gtk::Button jugar("Jugar");
    Gtk::Button salir("Salir");

    jugar.signal_clicked().connect(sigc::bind(sigc::ptr_fun(on_jugar_clicked), app));
    salir.signal_clicked().connect(sigc::bind(sigc::ptr_fun(on_salir_clicked), app));

    box.add(jugar);
    box.add(salir);
    ventana.add(box);
    ventana.show_all();

    return app->run(ventana);
}

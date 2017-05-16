#include <iostream>
#include "commonSocket.h"
#include <gtkmm.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>


void on_jugar_clicked(Glib::RefPtr<Gtk::Application> app){
    std::cout << "Inicia el juego" << std::endl;
    // variables

    bool quit = false;
    SDL_Event event;
    int x = 288;
    int y = 208;
    int xTipo = 10;
    int yTipo = 10;

    // init SDL

    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window * window = SDL_CreateWindow("Z",
                                           SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, 0);
    SDL_Renderer * renderer = SDL_CreateRenderer(window, -1, 0);

    SDL_Surface * imageNave = SDL_LoadBMP("spaceship.bmp");
    SDL_Surface * imageAnimacion = IMG_Load("tipito.png");
    SDL_Texture * textureAnimacion = SDL_CreateTextureFromSurface(renderer, imageAnimacion);
    SDL_Texture * textureNave = SDL_CreateTextureFromSurface(renderer,
                                                             imageNave);
    SDL_FreeSurface(imageNave);
    SDL_FreeSurface(imageAnimacion);

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

    // handle events
    int destinoX = 100;
    int destinoY = 100;
    while (!quit) {
        SDL_PollEvent(&event);
        Uint32 ticks = SDL_GetTicks();
        // Uint32 seconds = ticks / 1000;
        int sprite = (ticks / 100) % 4;


        switch (event.type) {
            case SDL_QUIT:
                quit = true;
                break;
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym) {
                    case SDLK_LEFT:
                        xTipo--;
                        break;
                    case SDLK_RIGHT:
                        xTipo++;
                        break;
                    case SDLK_UP:
                        yTipo--;
                        break;
                    case SDLK_DOWN:
                        yTipo++;
                        break;
                }
                break;
            case SDL_MOUSEBUTTONDOWN:
                destinoX = event.motion.x;
                destinoY = event.motion.y;
                break;
        }

        if ((ticks % 10) == 0) {

            if (x < destinoX) {
                x += 1;
            }

            if (x > destinoX) {
                x -= 1;
            }

            if (y < destinoY) {
                y += 1;
            }

            if (y > destinoY) {
                y -= 1;
            }
        }
        SDL_Rect dstrectNave = { x, y, 64, 64 };
        SDL_Rect srcrect = { sprite * 32, 0, 32, 64 };
        SDL_Rect dstrect = { xTipo, yTipo, 32, 64 };


        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, textureNave, NULL, &dstrectNave);
        SDL_RenderCopy(renderer, textureAnimacion, &srcrect, &dstrect);
        SDL_RenderPresent(renderer);
    }

    // cleanup SDL

    SDL_DestroyTexture(textureAnimacion);
    SDL_DestroyTexture(textureNave);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    IMG_Quit();
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
    ventana.set_default_size(700, 360);
    Gtk::Box box;

    Gtk::Button jugar("Jugar");
    Gtk::Button salir("Salir");

    jugar.signal_clicked().connect(sigc::bind(sigc::ptr_fun(on_jugar_clicked), app));
    salir.signal_clicked().connect(sigc::bind(sigc::ptr_fun(on_salir_clicked), app));

    Gtk::Image* image = new Gtk::Image("splash.jpg");


    box.add(jugar);
    box.add(*Gtk::manage(image));
    box.add(salir);
    ventana.add(box);
    ventana.show_all();

    return app->run(ventana);
}

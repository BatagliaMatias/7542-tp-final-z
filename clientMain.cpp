#include <iostream>
#include "commonSocket.h"
#include <gtkmm.h>


void on_button_clicked_init_game(){
    std::cout << "Inicia el juego" << std::endl;
}

void on_button_clicked_exit(){
    std::cout << "Chau!" << std::endl;
    //Salimos del loop de eventos
    Gtk::Main::quit();
}

int main(int argc, char *argv[]) {

   // Socket socket;
   // socket.connectS(argv[1],16332);
   // socket.sendS(argv[2],5);
   // socket.shutdownS();
    Gtk::Main kit(argc, argv);

    Gtk::Button boton("Iniciar Juego");
    boton.signal_clicked().connect(sigc::ptr_fun(&on_button_clicked_init_game));

    Gtk::Button botonExit("Salir");
    botonExit.signal_clicked().connect(sigc::ptr_fun(&on_button_clicked_exit));


    Gtk::Window ventana;
    Gtk::Box box;
    ventana.set_default_size(800, 640);
    ventana.set_border_width(10);
    box.add(boton);
    box.add(botonExit);
    ventana.add(box);


    ventana.show_all();


    Gtk::Main::run(ventana);
    return 0;
}

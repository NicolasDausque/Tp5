#include <gtkmm.h>

//g++ -std=c++14 -Wall -Wextra `pkg-config --cflags --libs gtkmm-2.4` main.cpp

// ifndef define
class ZoneDessin : public Gtk::DrawingArea{
private:
  std::vector<FigureGeometrique*> _figures;
public:
  ZoneDessin(){
    FigureGeometrique * fig1=new FigureGeometrique();
    FigureGeometrique * fig2=new FigureGeometrique();
    _figures.push_back(fig1);
    _figures.push_back(fig2);
    



  }
  ~ZoneDessin(){
    for(FigureGeometrique * fig : _figures){
      delete *fig;
      delete fig;
    }
  }
  bool on_expose_event(GdkEventExpose* event) override {return true;}
  bool gererClic(GdkEventButton* event){return true;}
};

}
class ViewerFigures{
private:
  Gtk::Main _kit;
  Gtk::Window _window;
  ZoneDessin _dessin;
public:
  ViewerFigures(int argc, char ** argv): _kit(argc,argv), _window(), _dessin{
    _window.set_title("ma fenetre");
    _window.set_default_size(480,640);
    _window.add(dessin);
    _window.show_all();
}
void run(){
  _kit.run(_window);
}
}; 

class MaFenetre : public Gtk::Window {
    private:
        Gtk::HPaned _paned; // un panneau pour aligner des elements
        Gtk::Label _label; // un texte
        Gtk::Button _button; // un bouton
    public:
        MaFenetre() : _paned(), _label("un texte"), _button("un bouton") {
            _paned.add1(_label); // ajoute le texte au panneau
            _paned.add2(_button); // ajoute le bouton au panneau
            add(_paned); // ajoute le panneau a la fenetre
            show_all(); // demande d'afficher tous les elements
            set_title("une fenetre");
        }
};
int main(int argc, char ** argv) {
  ViewerFigures a(argc, argv);
  a.run();
    return 0;
}

#ifndef GTKMM_NAVIGATION_BOX_H
#define GTKMM_NAVIGATION_BOX_H

#include <gtkmm.h>

class navigation_box : public Gtk::Frame
{
public:
  navigation_box(
    bool horizontal,
    const Glib::ustring& title,
    gint spacing,
    Gtk::ButtonBoxStyle layout
  );
protected:
  Gtk::Button create_flight, load_flight, remove_flight, close; // Create the buttons for the loading screen
};

#endif

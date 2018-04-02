#ifndef GTKMM_OPTIONS_BUTTONBOX_H
#define GTKMM_OPTIONS_BUTTONBOX_H

#include <gtkmm.h>

class optionsButtonBox : public Gtk::Frame
{
public:
  optionsButtonBox(
    bool horizontal,
    const Glib::ustring& title,
    gint spacing,
    Gtk::ButtonBoxStyle layout
  );
protected:
  Gtk::Button create_flight, load_flight, remove_flight, close; // Create the buttons for the loading screen
};

#endif

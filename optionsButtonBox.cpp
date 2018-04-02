#include "optionsButtonBox.h"

#include <iostream>
using namespace std;

optionsButtonBox::optionsButtonBox(bool horizontal,
    const Glib::ustring& title,
    gint spacing,
    Gtk::ButtonBoxStyle layout)
    : Gtk::Frame(title),
    create_flight("Create Flight"),
    load_flight("Load Flight"),
    remove_flight("Remove Flight"),
    close("Close")
{
  Gtk::ButtonBox* bbox = nullptr; // Create a pointer to a buttonbox widget

  // Create the actual widget (different depending on whether it's vertical or horizontal)
  if(horizontal)
    bbox = Gtk::manage(new Gtk::ButtonBox(Gtk::ORIENTATION_HORIZONTAL));
  else
    bbox = Gtk::manage(new Gtk::ButtonBox(Gtk::ORIENTATION_VERTICAL));

  bbox->set_border_width(5);  // Set the border width of the button box

  add(*bbox); // add the button box to something...

  /* Set the appearance of the Button Box */
  bbox->set_layout(layout);
  bbox->set_spacing(spacing);

  // Add the buttons to the buttonbox
  bbox->add(create_flight);
  bbox->add(load_flight);
  bbox->add(remove_flight);

}

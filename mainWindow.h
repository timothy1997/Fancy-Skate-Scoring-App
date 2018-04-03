#include <gtkmm.h>
#include <gtkmm/application.h>

#ifndef GTKMM_MWINDOW_H
#define GTKMM_MWINDOW_H

// Here we create the "Buttons" window, derived from the Gtk::Window, and has
// a single Gtk::Button as a member
class mainWindow : public Gtk::Window
{
public:
  mainWindow();
  virtual ~mainWindow();

  // Signal handlers
  void on_option_button_clicked(Glib::ustring data);
  void on_close_clicked();

protected:
  // Child widgets:
  Gtk::Box m_HBox_Main;  // The main container box of the frame
  Gtk::Frame navigation_frame;  // The frame element that will hold the options box
  Gtk::Frame work_frame;  // The box where work will be done (viewing, editing, etc..)
  Gtk::Box m_Options_Box;  // The box that will hold the main options
  void removeNavigation();
};

class navigation_box : public Gtk::Frame
{
public:
  navigation_box(
    bool horizontal,
    const Glib::ustring& title,
    gint spacing,
    Gtk::ButtonBoxStyle layout,
    mainWindow* window
  );
protected:
  Gtk::Button create_flight, load_flight, remove_flight, close; // Create the buttons for the loading screen
};

class create_box : public Gtk::Box
{
public:
  create_box();
  // virtual ~create_box();
protected:
  Gtk::Button create_new;
};

#endif

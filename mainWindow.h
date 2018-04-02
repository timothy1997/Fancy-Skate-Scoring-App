#ifndef GTKMM_MWINDOW_H
#define GTKMM_MWINDOW_H

#include <gtkmm.h>
#include <gtkmm/application.h>

// Here we create the "Buttons" window, derived from the Gtk::Window, and has
// a single Gtk::Button as a member
class mainWindow : public Gtk::Window
{
public:
  mainWindow();
  virtual ~mainWindow();

protected:
  // Signal handlers:
  void on_button_clicked();

  // Child widgets:
  Gtk::Box m_HBox_Main;  // The main container box of the frame
  Gtk::Frame navigation_frame;  // The frame element that will hold the options box
  Gtk::Frame work_frame;  // The box where work will be done (viewing, editing, etc..)
  Gtk::Box m_Options_Box;  // The box that will hold the main options
};

#endif

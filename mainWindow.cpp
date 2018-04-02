#include "mainWindow.h"
#include "navigation_box.h"

// class mainWindow : public Gtk::Window
// {
// public:
//   mainWindow();
//   virtual ~mainWindow();
//
// protected:
//   // Signal handlers:
//   void on_button_clicked();
//
//   // Child widgets:
//   Gtk::Box m_HBox_Main;  // The main container box of the frame
//   Gtk::Box m_Options_Box;  // The box that will hold the main options
//   Gtk::Frame navigation_frame;  // The frame element that will hold the options box
//   Gtk::Frame work_frame;  // The box where work will be done (viewing, editing, etc..)
// };
mainWindow::mainWindow()
: m_HBox_Main(Gtk::ORIENTATION_HORIZONTAL),
  navigation_frame("Options: "),
  work_frame("Data: ")
  {
      set_title("Fancy Skating App"); // Set the title of the window
      add(m_HBox_Main); // Add the main horizontal box to the window

      // Within the main horizontal box, pack the navigation box and the work box
      m_HBox_Main.pack_start(navigation_frame, Gtk::PACK_EXPAND_WIDGET, 10);
      m_HBox_Main.pack_start(work_frame, Gtk::PACK_EXPAND_WIDGET, 10);

      m_Options_Box.set_border_width(10); // Set the border width of the main horizontal box
      navigation_frame.add(m_Options_Box); // Add the options box to the main vertical frame

      // Here we pack into the main options box a new button box object
      // The manage() function marks a widget so that when the widget is added to a container, the container becomes responsible for deleting the widget.
      m_Options_Box.pack_start(*Gtk::manage(new navigation_box(false, "Options:", 5, Gtk::BUTTONBOX_SPREAD)), Gtk::PACK_EXPAND_WIDGET);

      show_all_children();
  }

mainWindow::~mainWindow()
{
}

void mainWindow::on_button_clicked()
{
  hide();
}

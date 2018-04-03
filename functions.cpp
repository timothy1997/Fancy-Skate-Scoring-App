#include "mainWindow.h"

#include <iostream>
using namespace std;

// mainWindow class member functions ---------------------------------------------------------------------------------------------
mainWindow::mainWindow()
: m_HBox_Main(Gtk::ORIENTATION_HORIZONTAL),
  navigation_frame("Options: "),
  work_frame("Data: ")
  {
      set_title("Fancy Skating App"); // Set the title of the window
      add(m_HBox_Main); // Add the main horizontal box to the window

      // Within the main horizontal box, pack the navigation box and the work box
      m_HBox_Main.pack_start(navigation_frame, Gtk::PACK_EXPAND_WIDGET, 10);

      m_Options_Box.set_border_width(10); // Set the border width of the main horizontal box
      navigation_frame.add(m_Options_Box); // Add the options box to the main vertical frame

      // Here we pack into the main options box a new button box object
      // The manage() function marks a widget so that when the widget is added to a container, the container becomes responsible for deleting the widget.
      m_Options_Box.pack_start(*Gtk::manage(new navigation_box(false, "Options:", 5, Gtk::BUTTONBOX_SPREAD, this)), Gtk::PACK_EXPAND_WIDGET);

      show_all_children();
  }

mainWindow::~mainWindow()
{
}

void mainWindow::on_option_button_clicked(Glib::ustring data)
{
  if(data == "create")
  {
    m_HBox_Main.remove(navigation_frame);
    m_HBox_Main.pack_start(*Gtk::manage(new create_box()), Gtk::PACK_EXPAND_WIDGET);
  }
  else if(data == "load")
    cout << "Load was pressed" << endl;
  else if(data == "remove")
    cout << "Remove was pressed" << endl;
}

void mainWindow::on_close_clicked()
{
  hide();
}

// Navigation box class member functions -----------------------------------------------------------------------------------

navigation_box::navigation_box(bool horizontal,
    const Glib::ustring& title,
    gint spacing,
    Gtk::ButtonBoxStyle layout,
    mainWindow* main)
    :
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

  bbox->set_border_width(50);  // Set the border width of the button box

  add(*bbox); // add the button box to something...

  /* Set the appearance of the Button Box */
  bbox->set_layout(layout);
  bbox->set_spacing(spacing);

  // Add the buttons to the buttonbox
  bbox->add(create_flight);
  bbox->add(load_flight);
  bbox->add(remove_flight);
  bbox->add(close);

  create_flight.signal_clicked().connect(sigc::bind<Glib::ustring>(sigc::mem_fun(main, &mainWindow::on_option_button_clicked), "create"));
  load_flight.signal_clicked().connect(sigc::bind<-1, Glib::ustring>(sigc::mem_fun(main, &mainWindow::on_option_button_clicked), "load"));
  remove_flight.signal_clicked().connect(sigc::bind<-1, Glib::ustring>(sigc::mem_fun(main, &mainWindow::on_option_button_clicked), "remove"));
  close.signal_clicked().connect(sigc::mem_fun(main, &mainWindow::on_close_clicked));
}

// Create Box class member functions ----------------------------------------------------------------
create_box::create_box() {
  // I WAS WORKING ON TRYING TO GET THE CREATE BUTTON TO SHOW....
  add(create_new);
  show_all_children();
}

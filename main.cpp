#include <gtkmm/application.h>
#include "mainWindow.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
  // Create the application
  auto app = Gtk::Application::create(argc, argv, "Fancy Skate Scoring");

  // Create the window
  mainWindow main;

  // Show the window and return when it is closed
  return app->run(main);
}

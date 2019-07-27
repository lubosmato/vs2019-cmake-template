#include <QApplication>

#include "qt_gui/gui.hpp"
#include "ui/main_window.hpp"

void show_window()
{
	char* argv[] = { "i_am_dirty.exe" };
	int argc = 1;

	QApplication app(argc, argv);
	MainWindow window;
	window.show();

	app.exec();
}
  
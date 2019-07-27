#include "ui/main_window.hpp"
#include "ui/ui_main_window.h"

MainWindow::MainWindow(QWidget* parent) 
	: QMainWindow(parent), ui(new Ui::MainWindow)
{
	ui->setupUi(this);
}

MainWindow::~MainWindow()
{
	delete ui;
}

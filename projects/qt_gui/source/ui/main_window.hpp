#ifndef MAIN_WINDOW_HPP_
#define MAIN_WINDOW_HPP_

#include <QMainWindow>

namespace Ui {
	class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit MainWindow(QWidget* parent = 0);
	~MainWindow();

private:
	Ui::MainWindow* ui;
};

#endif // MAIN_WINDOW_HPP_
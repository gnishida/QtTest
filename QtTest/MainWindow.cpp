#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
	ui.setupUi(this);

	this->setCentralWidget(&widget);

	connect(ui.actionExit, SIGNAL(triggered()), this, SLOT(close()));
}

#pragma once

#include <QtWidgets/QMainWindow>
#include "GLWidget.h"
#include "ui_MainWindow.h"

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = Q_NULLPTR);

private:
	Ui::MainWindowClass ui;

	GLWidget widget;
};

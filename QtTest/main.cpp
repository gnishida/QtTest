#include "GLWidget.h"

int main(int argc, char **argv)
{
	QApplication app(argc, argv);

	GLWidget * widget = new GLWidget();

	// Show window
	widget->show();
	widget->resize(1200, 800);

	return app.exec();
}
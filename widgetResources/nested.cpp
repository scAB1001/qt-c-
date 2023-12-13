#include <QtWidgets>

int main(int argc, char* argv[])
{
  QApplication app(argc, argv);

  QWidget* window = new QWidget();
  window->setWindowTitle("Nested Layout Test");

  // Create widgets

  // Arrange widgets

  // Activate UI

  window->show();

  return app.exec();
}

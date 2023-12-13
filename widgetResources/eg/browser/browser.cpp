#include <QtWidgets>

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);

  QUrl url = QUrl::fromLocalFile(":/page1.html");

  QTextBrowser* browser = new QTextBrowser();
  browser->setWindowTitle("Text Browser Demo");
  browser->setSource(url);
  browser->show();

  return app.exec();
}

#pragma once
#include <QtWidgets>

// Function to create the main window
QMainWindow* createMainWindow()
{
    QMainWindow* mainWindow = new QMainWindow();
    QWidget* centralWidget = new QWidget();
    mainWindow->setCentralWidget(centralWidget);
    return mainWindow;
}

// Function to set up the UI elements
void setupUI(QMainWindow* mainWindow)
{
    QVBoxLayout* layout = new QVBoxLayout(mainWindow->centralWidget());

    QLabel* boxTitleLabel = new QLabel("<h1>Library Management System</h1>");
    boxTitleLabel->setTextFormat(Qt::RichText);
    boxTitleLabel->setAlignment(Qt::AlignCenter);
    layout->addWidget(boxTitleLabel);

    QGridLayout* gridLayout = new QGridLayout();

    QLabel* isbnLabel = new QLabel("ISBN:");
    QLineEdit* isbnLineEdit = new QLineEdit();
    QLabel* titleLabel = new QLabel("Title:");
    QLineEdit* titleLineEdit = new QLineEdit();
    QLabel* authorLabel = new QLabel("Author:");
    QLineEdit* authorLineEdit = new QLineEdit();

    gridLayout->addWidget(isbnLabel, 0, 0);
    gridLayout->addWidget(isbnLineEdit, 0, 1);
    gridLayout->addWidget(titleLabel, 1, 0);
    gridLayout->addWidget(titleLineEdit, 1, 1);
    gridLayout->addWidget(authorLabel, 2, 0);
    gridLayout->addWidget(authorLineEdit, 2, 1);

    QPushButton* addButton = new QPushButton("Add");
    QPushButton* deleteButton = new QPushButton("Delete");
    QPushButton* searchButton = new QPushButton("Search");

    gridLayout->addWidget(addButton, 3, 0);
    gridLayout->addWidget(deleteButton, 3, 1);
    gridLayout->addWidget(searchButton, 3, 2);

    layout->addLayout(gridLayout);

    mainWindow->setWindowTitle("Library Management System");
    mainWindow->resize(600, 400);
}

// Function to handle the Search button click event
void handleSearchButtonClick(QLineEdit* isbnLineEdit, QLineEdit* titleLineEdit, QLineEdit* authorLineEdit)
{
    // Dictionary to hold books (ISBN as key, Title and Author as values)
    QHash<QString, QPair<QString, QString>> books;
    books.insert("978-0-13-110362-7", qMakePair("Clean Code", "Robert C. Martin"));
    books.insert("978-0-321-58469-0", qMakePair("Effective C++", "Scott Meyers"));
    books.insert("978-0-07-352332-3", qMakePair("Introduction to Algorithms", "Thomas H. Cormen"));

    QString searchISBN = isbnLineEdit->text();

    // Add danger/success messages
    QMessageBox msgBox;
    if (books.contains(searchISBN)) {
        titleLineEdit->setText(books.value(searchISBN).first);
        authorLineEdit->setText(books.value(searchISBN).second);
        msgBox.setText("Book found.");
        msgBox.setIcon(QMessageBox::Information);
    } else {
        titleLineEdit->clear();
        authorLineEdit->clear();
        qDebug() << "Book not found.";
        msgBox.setText("Book not found.");
        msgBox.setIcon(QMessageBox::Warning);
    }
    msgBox.exec();
}

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    QMainWindow* mainWindow = createMainWindow();
    setupUI(mainWindow);

    QLineEdit* isbnLineEdit = mainWindow->centralWidget()->findChild<QLineEdit*>("isbnLineEdit");
    QLineEdit* titleLineEdit = mainWindow->centralWidget()->findChild<QLineEdit*>("titleLineEdit");
    QLineEdit* authorLineEdit = mainWindow->centralWidget()->findChild<QLineEdit*>("authorLineEdit");

    QObject::connect(mainWindow->centralWidget()->findChild<QPushButton*>("searchButton"), &QPushButton::clicked, [&]() {
        handleSearchButtonClick(isbnLineEdit, titleLineEdit, authorLineEdit);
    });

    mainWindow->show();
    return app.exec();
}

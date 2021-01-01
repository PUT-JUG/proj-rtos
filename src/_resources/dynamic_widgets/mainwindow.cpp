#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QLineEdit>

#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_add_clicked() {
    // czyszczenie istniejacych widgetow w layoucie
    QLayoutItem *item;
    while((item = ui->verticalLayout->takeAt(0))) {
        if (item->widget()) {
           delete item->widget();
        }
        delete item;
    }

    // odczytujemy liczbe widgetow do utworzenia
    int widget_count = ui->spinBox_widget_count->value();

    // tworzymy widgety i dodajemy je do layoutu
    for (int i = 0; i < widget_count; i++) {
        QLineEdit* widget = new QLineEdit();
        ui->verticalLayout->addWidget(widget);
    }
}

void MainWindow::on_pushButton_fill_clicked() {
    // przegladamy wszystkie widgety w layoucie
    for (int i = 0; i < ui->verticalLayout->count(); i++) {
        QLayoutItem* item = ui->verticalLayout->itemAt(i); // wybieramy item w i-tym miejscu, w ktorym jest przechowywany widget
        QLineEdit* widget = dynamic_cast<QLineEdit*>(item->widget()); // zakladamy, ze elementami sa tylko QLineEdit
        widget->setText("Hello widget " + QString::number(i)); // wpisujemy tekst do i-tego widgetu
    }
    repaint(); // fix gdyby napisy nie odswiezyly sie samoczynnie
}

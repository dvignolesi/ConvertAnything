#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidgetItem>
#include <QTabWidget>
#include "modifiedspinbox.h"
#include "converttools.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionExit_triggered();
    void on_actionAbout_triggered();
    void on_listWidgetClicked(QListWidgetItem *item);
    void on_tabClicked();
    void on_userInput(QList<double> *numbersToConvert, int whoSignaled,
                      modifiedSpinbox *F, modifiedSpinbox *C, modifiedSpinbox *K, modifiedSpinbox *R);
    void tempMath(QList<double> *numbersToConvert, int whoSignaled);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

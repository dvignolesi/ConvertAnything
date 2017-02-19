#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "modifiedspinbox.h"
#include "converttools.h"
#include <QApplication>
#include <QListWidget>
#include <QGridLayout>
#include <QDoubleSpinBox>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    // Initializes: 1. A stringList for the conversion units in the listWidget
    //              2. A listWidget to list all of the conversion units
    //              2. A TabWidget for each conversion unit
    //              3. Widgets for each of the conversion units that go into
    //                  each new tab
    QStringList units;
    QString unitType;
    QList<double> numbersToConvert;

    //Makes tabs use available space
    ui->tabWidget->setUsesScrollButtons(0);

    QWidget *tempWidget = new QWidget(ui->tabWidget);
    QWidget *volWidget = new QWidget(ui->tabWidget);
    QWidget *distWidget = new QWidget(ui->tabWidget);
    QWidget *weightWidget = new QWidget(ui->tabWidget);
    QWidget *areaWidget = new QWidget(ui->tabWidget);
    QWidget *speedWidget = new QWidget(ui->tabWidget);
    QWidget *dataWidget = new QWidget(ui->tabWidget);
    QWidget *timeWidget = new QWidget(ui->tabWidget);
    QWidget *freqWidget = new QWidget(ui->tabWidget);
    QWidget *presWidget = new QWidget(ui->tabWidget);
    QWidget *energyWidget = new QWidget(ui->tabWidget);
    QWidget *angleWidget = new QWidget(ui->tabWidget);

    // Fills the stringList with strings and pushes them to the listWidget

    units << "Temperature" << "Volume" << "Distance"
          << "Weight" << "Area" << "Speed" << "Data" << "Time"
          << "Frequency" << "Pressure" << "Energy" << "Angle";

    ui->listWidget->addItems(units);

    // Creates each tab for the tabWidget
    ui->tabWidget->addTab(tempWidget,units.at(0));
    ui->tabWidget->addTab(volWidget,units.at(1));
    ui->tabWidget->addTab(distWidget,units.at(2));
    ui->tabWidget->addTab(weightWidget,units.at(3));
    ui->tabWidget->addTab(areaWidget,units.at(4));
    ui->tabWidget->addTab(speedWidget,units.at(5));
    ui->tabWidget->addTab(dataWidget,units.at(6));
    ui->tabWidget->addTab(timeWidget,units.at(7));
    ui->tabWidget->addTab(freqWidget,units.at(8));
    ui->tabWidget->addTab(presWidget,units.at(9));
    ui->tabWidget->addTab(energyWidget,units.at(10));
    ui->tabWidget->addTab(angleWidget,units.at(11));

    /* Connects the list of units on the left side with the tabs on top so when one
     selects a list item or tab, the other one will be selected*/

    connect(ui->listWidget,SIGNAL(currentItemChanged(QListWidgetItem*,QListWidgetItem*)),this,
            SLOT(on_listWidgetClicked(QListWidgetItem*)));

    connect(ui->tabWidget,SIGNAL(currentChanged(int)),this,
            SLOT(on_tabClicked()));

    // instantiates a new layout for the tempWidget
    QGridLayout *tempLayout = new QGridLayout(tempWidget);

    //creates labels for each option
    QLabel *FahrenheitLabel = new QLabel("Fahrenheit");
    QLabel *CelciusLabel = new QLabel("Celcius");
    QLabel *KelvinLabel = new QLabel("Kelvin");
    QLabel *RankineLabel = new QLabel("Rankine");

    // creates a custom spinbox for each option
    modifiedSpinbox *FahrenheitDblSpinbox = new modifiedSpinbox();
    modifiedSpinbox *CelciusDblSpinbox = new modifiedSpinbox();
    modifiedSpinbox *KelvinDblSpinbox = new modifiedSpinbox();
    modifiedSpinbox *RankineDblSpinbox = new modifiedSpinbox();

    // Sets the line edit and labels in a grid layout
    tempLayout->addWidget(FahrenheitDblSpinbox, 0, 2, 1, 1);
    tempLayout->addWidget(FahrenheitLabel, 0, 4, 1, 1);
    tempLayout->addWidget(CelciusDblSpinbox, 1, 2, 1, 1);
    tempLayout->addWidget(CelciusLabel, 1, 4, 1, 1);
    tempLayout->addWidget(KelvinDblSpinbox, 2, 2, 1, 1);
    tempLayout->addWidget(KelvinLabel, 2, 4, 1, 1);
    tempLayout->addWidget(RankineDblSpinbox, 3, 2, 1, 1);
    tempLayout->addWidget(RankineLabel, 3, 4, 1, 1);

    //Sets Min and Max values
    FahrenheitDblSpinbox->setRange(-459.67, 999999999);
    CelciusDblSpinbox->setRange(-273.15, 999999999);
    KelvinDblSpinbox->setRange(0, 999999999);
    RankineDblSpinbox->setRange(0, 999999999);

    connect(FahrenheitDblSpinbox,SIGNAL(valueChanged(double d)),this,
            SLOT(on_userInput(QList<double>* numbersToConvert, int i = 1,
                              modifiedSpinbox* FahrenheitDblSpinbox,modifiedSpinbox* CelciusDblSpinbox,
                              modifiedSpinbox* KelvinDblSpinbox, modifiedSpinbox* RankineDblSpinbox)));
}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionExit_triggered()
{
    QApplication::quit();
}

void MainWindow::on_actionAbout_triggered()
{
    //About Dave!
}

void MainWindow::on_listWidgetClicked(QListWidgetItem* item)
{
    ui->tabWidget->setCurrentIndex(ui->listWidget->row(item));
}

void MainWindow::on_tabClicked()
{
    ui->listWidget->setCurrentRow(ui->tabWidget->currentIndex());
}

void on_userInput(QList<double> *numbersToConvert, int whoSignaled,
                  modifiedSpinbox *F, modifiedSpinbox *C, modifiedSpinbox *K, modifiedSpinbox *R)
{
    ConvertTools *ct = new ConvertTools();
    ct->tempMath(*numbersToConvert, whoSignaled);
    switch(whoSignaled) {
    case 1:
        C->setValue(numbersToConvert->at(2));
        K->setValue(numbersToConvert->at(3));
        R->setValue(numbersToConvert->at(4));
        break;
    case 2:
        F->setValue(numbersToConvert->at(1));
        K->setValue(numbersToConvert->at(3));
        R->setValue(numbersToConvert->at(4));
        break;
    case 3:
        F->setValue(numbersToConvert->at(1));
        C->setValue(numbersToConvert->at(2));
        R->setValue(numbersToConvert->at(4));
        break;
    case 4:
        F->setValue(numbersToConvert->at(1));
        C->setValue(numbersToConvert->at(2));
        K->setValue(numbersToConvert->at(3));
        break;
    }

}

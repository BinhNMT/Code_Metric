#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "CodeMetric.h"
#include "WorkWithTable.h"
#include "operatingmode.h"
#include <QFileDialog>
#include <QComboBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->comboBox->addItem("Single");
    ui->comboBox->addItem("Multiple");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QString inputFile;
    inputFile = QFileDialog::getOpenFileName(this, "Select source file to open", "C:\\", "Text files (*.txt *.hpp *.cpp *.c)");
    ui->textEdit->setText(inputFile);
}


void MainWindow::on_pushButton_2_clicked()
{
    unsigned int stdEffort;
    float totalEffort;
    QString inputFile;

    // Get input Effort per Day
    stdEffort = ui->textEdit_Effort->toPlainText().toUInt();

    // Get input file's name
    inputFile = ui->textEdit->toPlainText();

    // Get operation input mode
    QString operationMode = ui->comboBox->currentText();

    // Main tasking
    OperatingMode Operate(this);

    if(operationMode == "Single")
    {
        totalEffort = Operate.singleFileExecution(inputFile, stdEffort);
        ui->textEdit_total->setText(QString::number(totalEffort));
    }

    else
    {
        totalEffort = Operate.multiFileMode(inputFile, stdEffort);
        ui->textEdit_total->setText(QString::number(totalEffort));
    }
}

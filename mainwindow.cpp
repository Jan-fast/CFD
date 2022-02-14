#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>

void MainWindow::initMainWindow()
{
    //维度下拉框选择
    ui->DimenComboBox->addItem("2");
    ui->DimenComboBox->addItem("3");

    //计算阶数下拉框选择
    ui->orderComboBox->addItem("0");
    ui->orderComboBox->addItem("1");
    ui->orderComboBox->addItem("2");
    ui->orderComboBox->addItem("3");
    ui->orderComboBox->setCurrentIndex(3);
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    initMainWindow();

    //加载网格数据
    connect(ui->actionLoad, &QAction::triggered, this, &MainWindow::LoadGrid);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::LoadGrid()
{
    gridPath = QFileDialog::getOpenFileName(this, "openFile", "D:\\");
    ui->pathLabel->setText(gridPath);
    QFile gridFile(gridPath);
}











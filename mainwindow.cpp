#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QDebug>

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

    //设置区域是否可以编辑
    Case_Opened_ = false;
    ui->settingScrollArea->setEnabled(Case_Opened_);
}

void MainWindow::initUiState(uiState state)
{
    switch (state)
    {
    case caseClose:
        ui->settingScrollArea->setEnabled(Case_Opened_);
        break;
    case caseOpenStop:
        ui->settingScrollArea->setEnabled(Case_Opened_);
        break;
    case caseOpenRun:
        ui->settingScrollArea->setEnabled(Case_Opened_);
        break;
    }
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    initMainWindow();

    //新建算例
    connect(ui->actionNew, &QAction::triggered, this, [=](){
        if (Case_Opened_) {

        }
        Case_Opened_ = true;
        initUiState(caseOpenStop);
    });

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











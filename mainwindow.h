#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    enum uiState {
        caseClose,
        caseOpenStop,
        caseOpenRun
    };
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    QString gridPath;

    bool Case_Opened_; //是否有算例打开

    void initMainWindow();
    void initUiState(uiState state);
    void LoadGrid();
};
#endif // MAINWINDOW_H

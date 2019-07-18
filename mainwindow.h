#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
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

    void time_update();//时间更新槽函数，状态栏显示时间

private:
    Ui::MainWindow *ui;
    QLabel *currentTimeLabel;//创建Qlabel对象
    QLabel *teamLabel;
};

#endif // MAINWINDOW_H

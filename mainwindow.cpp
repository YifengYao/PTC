#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>
#include <QDateTime>
#include <QTimer>
#include <QString>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //主界面设定标题
    setWindowTitle(tr("电加热器-电除霜自动检测系统"));
    currentTimeLabel = new QLabel; // 创建QLabel控件
    teamLabel = new QLabel;
    teamLabel->setText("武汉理工大学吴友宇教授团队");
    ui->statusBar->addWidget(currentTimeLabel); //在状态栏添加此控件
    ui->statusBar->addPermanentWidget(teamLabel);
    QTimer *timer = new QTimer(this);
    timer->start(1000); //每隔1000ms发送timeout的信号
    connect(timer, SIGNAL(timeout()),this,SLOT(time_update()));
    //ui->tabWidget->setTabPosition(QTabWidget::West);
    //ui->horizontalLayout_3->s

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::time_update()
{
    //[1] 获取时间
    QDateTime current_time = QDateTime::currentDateTime();
    QString timestr = current_time.toString( "yyyy年MM月dd日 hh:mm:ss"); //设置显示的格式

    currentTimeLabel->setText(timestr); //设置label的文本内容为时间

}


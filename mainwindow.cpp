#include "mainwindow.h"
#include <QGuiApplication>
#include <QScreen>
#include <QRect>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    i=1;
    /* 获取屏幕的分辨率，Qt官方建议使用这
     * 种方法获取屏幕分辨率，防上多屏设备导致对应不上
     * 注意，这是获取整个桌面系统的分辨率
     */
    QList <QScreen *> list_screen =  QGuiApplication::screens();

    /* 如果是ARM平台，直接设置大小为屏幕的大小 */
#if __arm__
    /* 重设大小 */
    this->resize(list_screen.at(0)->geometry().width(),
                 list_screen.at(0)->geometry().height());
//    this->setGeometry(0, 0, 446, 424);
#else
    /* 否则则设置主窗体大小为800x480 */
    this->setGeometry(0, 0, 446, 424);
#endif

//    /* 设置大小与位置 */
//    this->setGeometry(0, 0, 446, 424);

    /* 使用资源里的文件时格式是  :+前缀+文件路径  */
    QPixmap pixmap(":images/0.png");
    //QPixmap pixmap2(":images/1_446_424.bmp");

    //QPixmap pixmap4(":images/102_446_424.bmp");

    labelImage = new QLabel(this);

    /* 标签大小为452×132,根据图像的大小来设置 */
    labelImage->setGeometry(0, 0, 446, 424);
    /* 设置图像 */
    labelImage->setPixmap(pixmap);
    /* 开启允许缩放填充 */
    labelImage->setScaledContents(true);

//    labelString = new QLabel(this);
//    labelString->setText("标签演示文本");
//    labelString->setGeometry(300, 300, 100, 20);
}

MainWindow::~MainWindow()
{
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
#if __arm__
    /* 判断按下的按键，也就是板子KEY0按键 */
    if(event->key() == Qt::Key_VolumeDown) {
        /* 设置label的文本 */
//        label->setText("按键按下");
        if(i==1){
        QPixmap pixmap(":images/1.bmp");
        labelImage->setPixmap(pixmap);
        i=2;
        }
        else if(i==2){
        QPixmap pixmap2(":images/2.bmp");
        labelImage->setPixmap(pixmap2);
        i=3;
        }
        else if(i==3){
        QPixmap pixmap3(":images/3.bmp");
        labelImage->setPixmap(pixmap3);
        i=4;
        }
        else if(i==4){
        QPixmap pixmap4(":images/4.bmp");
        labelImage->setPixmap(pixmap4);
        i=5;
        }
        else if(i==5){
        QPixmap pixmap5(":images/5.bmp");
        labelImage->setPixmap(pixmap5);
        i=6;
        }
        else if(i==6){
        QPixmap pixmap6(":images/6.bmp");
        labelImage->setPixmap(pixmap6);
        i=7;
        }
        else if(i==7){
        QPixmap pixmap7(":images/7.bmp");
        labelImage->setPixmap(pixmap7);
        i=8;
        }
        else if(i==8){
        QPixmap pixmap8(":images/8.bmp");
        labelImage->setPixmap(pixmap8);
        i=9;
        }
        else if(i==9){
        QPixmap pixmap9(":images/9.bmp");
        labelImage->setPixmap(pixmap9);
        i=10;
        }
        else if(i==10){
        QPixmap pixmap10(":images/10.bmp");
        labelImage->setPixmap(pixmap10);
        i=11;
        }
        else if(i==11){
        QPixmap pixmap11(":images/11.bmp");
        labelImage->setPixmap(pixmap11);
        i=12;
        }
        else if(i==12){
        QPixmap pixmap12(":images/12.bmp");
        labelImage->setPixmap(pixmap12);
        i=13;
        }
        else if(i==13){
        QPixmap pixmap13(":images/01_446_424.bmp");
        labelImage->setPixmap(pixmap13);
        i=14;
        }
        else if(i==14){
        QPixmap pixmap14(":images/07_446_424.bmp");
        labelImage->setPixmap(pixmap14);
        i=15;
        }
        else if(i==15){
        QPixmap pixmap15(":images/102_446_424.bmp");
        labelImage->setPixmap(pixmap15);
        i=16;
        }
        else if(i==16){
        QPixmap pixmap16(":images/1_446_424.bmp");
        labelImage->setPixmap(pixmap16);
        i=1;
        }
        qDebug() << QKeySequence(event->key()).toString();
    }

#else
    /* 判断按下的按键，也就是"↓"方向键 */
    if(event->key() == Qt::Key_Down) {
        /* 设置label的文本 */
        QPixmap pixmap3(":images/1_446_424.bmp");
        labelImage->setPixmap(pixmap3);
            qDebug() << event->key() << endl;
    }

#endif
    /* 保存默认事件 */
    QWidget::keyPressEvent(event);
}

//void MainWindow::keyReleaseEvent(QKeyEvent *event)
//{
//#if __arm__
//    /* 判断松开的按键，也就是板子KEY0按键 */
//    if(event->key() == Qt::Key_VolumeDown) {
////    if(event->key() == 0) {
//        /* 设置label的文本 */
////        label->setText("按键松开");
//        QPixmap pixmap(":images/01_446_424.bmp");
//        labelImage->setPixmap(pixmap);
//    }
//qDebug() << QKeySequence(event->key()).toString();
//#else
//    /* 判断按下的按键，也就是"↓"方向键 */
//    if(event->key() == Qt::Key_Down) {
//        /* 设置label的文本 */
//        label->setText("Down按键松开");
//            qDebug() << event->key() << endl;
//    }
//#endif
//    /* 保存默认事件 */
//    QWidget::keyReleaseEvent(event);
//}

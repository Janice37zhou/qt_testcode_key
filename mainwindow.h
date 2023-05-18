#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>
#include <QLabel>
#include <QDebug>
#include <QEvent>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    int i;

private:
//    /* 用一个QLabel对象用于显示字符串 */
//    QLabel *labelString;

    /* 用一个QLabel对象用于显示图像 */
    QLabel *labelImage;

//    /* 标签文本 */
//    QLabel *label;

    /* 重写按键事件 */
    void keyPressEvent(QKeyEvent *event);
//    void keyReleaseEvent(QKeyEvent *event);
};
#endif // MAINWINDOW_H

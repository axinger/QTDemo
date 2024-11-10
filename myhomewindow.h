//
// Created by xing on 2024/11/9.
//

#ifndef MYHOMEWINDOW_H
#define MYHOMEWINDOW_H

#include <QMainWindow>


QT_BEGIN_NAMESPACE

namespace Ui
{
    class MyHomeWindow;
}

QT_END_NAMESPACE

class MyHomeWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MyHomeWindow(QWidget* parent = nullptr);

    ~MyHomeWindow() override;
protected:
    void showEvent(QShowEvent *event) override;  // 重写 showEvent
private:
    Ui::MyHomeWindow* ui{};
    void setupMenu();
    void setupToos();
    void createStatusBar();
    void createCenter();
};


#endif //MYHOMEWINDOW_H

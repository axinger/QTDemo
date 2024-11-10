//
// Created by xing on 2024/11/10.
//

#ifndef MYLOGOUTWIDGET_H
#define MYLOGOUTWIDGET_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class MyLogoutWidget; }
QT_END_NAMESPACE

class MyLogoutWidget : public QWidget {
Q_OBJECT

public:
    explicit MyLogoutWidget(QWidget *parent = nullptr);
    ~MyLogoutWidget() override;

private:
    Ui::MyLogoutWidget *ui;
};


#endif //MYLOGOUTWIDGET_H

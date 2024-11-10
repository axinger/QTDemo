//
// Created by xing on 2024/11/10.
//

#ifndef MYREGISTER_H
#define MYREGISTER_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class MyRegister; }
QT_END_NAMESPACE

class MyRegister : public QWidget {
Q_OBJECT

public:
    explicit MyRegister(QWidget *parent = nullptr);
    ~MyRegister() override;

private:
    Ui::MyRegister *ui;
};


#endif //MYREGISTER_H

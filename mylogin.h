//
// Created by xing on 2024/11/9.
//

#ifndef LOGIN_H
#define LOGIN_H

#include <QPushButton>
#include <QWidget>
#include "teacher.h"
#include "student.h"

QT_BEGIN_NAMESPACE

namespace Ui
{
    class MyLogin;
}

QT_END_NAMESPACE

class MyLogin : public QWidget
{
    Q_OBJECT

public:
    explicit MyLogin(QWidget* parent = nullptr);

    ~MyLogin() override;

private:
    Ui::MyLogin* ui={};
    QPushButton* loginButton{};
    void onButtonClicked() const;
    void teacherEat() const;
    void teacherEat2(const QString& name) const;
    Teacher* tea;

    Student* stu;
signals:
    void loginSuccessful();
};


#endif //LOGIN_H

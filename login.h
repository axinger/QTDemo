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
    class Login;
}

QT_END_NAMESPACE

class Login : public QWidget
{
    Q_OBJECT

public:
    explicit Login(QWidget* parent = nullptr);

    ~Login() override;

private:
    Ui::Login* ui={};
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

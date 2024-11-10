//
// Created by xing on 2024/11/10.
//

#ifndef APPLOGIN_H
#define APPLOGIN_H

#include <QWidget>


QT_BEGIN_NAMESPACE

namespace Ui
{
    class AppLogin;
}

QT_END_NAMESPACE

class AppLogin : public QWidget
{
    Q_OBJECT

public:
    explicit AppLogin(QWidget* parent = nullptr);
    ~AppLogin() override;
signals:
    void loginSuccessful();

private:
    Ui::AppLogin* ui;
};


#endif //APPLOGIN_H

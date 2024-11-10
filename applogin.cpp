//
// Created by xing on 2024/11/10.
//

// You may need to build the project (run Qt uic code generator) to get "ui_AppLogin.h" resolved

#include "applogin.h"
#include "ui_AppLogin.h"


AppLogin::AppLogin(QWidget *parent) :
    QWidget(parent), ui(new Ui::AppLogin) {
    ui->setupUi(this);
    setWindowTitle("登录");

}

AppLogin::~AppLogin() {
    delete ui;
}

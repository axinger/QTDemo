//
// Created by xing on 2024/11/10.
//

// You may need to build the project (run Qt uic code generator) to get "ui_AppLogin.h" resolved

#include "applogin.h"

#include <qformlayout.h>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

#include "ui_AppLogin.h"


AppLogin::AppLogin(QWidget *parent) :
    QWidget(parent), ui(new Ui::AppLogin) {
    ui->setupUi(this);
    setWindowTitle("登录");
    // 设置窗口大小
    resize(600, 400);

    // 创建一个水平布局管理器，用于使表单水平居中
    QHBoxLayout *horizontalLayout = new QHBoxLayout;
    horizontalLayout->addStretch();

    // 创建表单布局
    QFormLayout *formLayout = new QFormLayout;

    // 创建用户名和密码输入框
    QLineEdit *usernameEdit = new QLineEdit(this);
    // usernameEdit->setFixedSize(300, 30);
    QLineEdit *passwordEdit = new QLineEdit(this);
    // passwordEdit->setFixedSize(300, 30);
    passwordEdit->setEchoMode(QLineEdit::Password);

    // 将输入框添加到表单布局
    formLayout->addRow(new QLabel("用户名："), usernameEdit);
    formLayout->addRow(new QLabel("密码："), passwordEdit);

    // 创建登录按钮
    QPushButton *loginButton = new QPushButton("Login", this);
    loginButton->setFixedSize(120, 50);

    // 创建一个水平布局管理器，用于使按钮水平居中
    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout->addStretch();
    buttonLayout->addWidget(loginButton);
    buttonLayout->addStretch();

    // 将按钮布局添加到表单布局
    formLayout->addRow(buttonLayout);

    // 将表单布局添加到水平布局
    horizontalLayout->addLayout(formLayout);
    horizontalLayout->addStretch();

    // 创建一个垂直布局管理器，用于将表单居中
    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addStretch();
    mainLayout->addLayout(horizontalLayout);
    mainLayout->addStretch();

    // 设置窗口的布局
    setLayout(mainLayout);
}

AppLogin::~AppLogin() {
    delete ui;
}

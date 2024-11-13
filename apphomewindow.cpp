//
// Created by xing on 2024/11/11.
//

// You may need to build the project (run Qt uic code generator) to get "ui_AppHomeWindow.h" resolved

#include "apphomewindow.h"

#include <qevent.h>
#include <qmessagebox.h>
#include <QPushButton>
#include <QVBoxLayout>

#include "ui_AppHomeWindow.h"


AppHomeWindow::AppHomeWindow(QWidget* parent) :
    QMainWindow(parent), ui(new Ui::AppHomeWindow)
{
    ui->setupUi(this);
    this->resize(800, 600);


    QVBoxLayout *layout = new QVBoxLayout;
    QPushButton *logoutButton = new QPushButton("退出登录", this);

    layout->addWidget(logoutButton);

    QWidget *centralWidget = new QWidget(this);
    centralWidget->setLayout(layout);


    connect(logoutButton, &QPushButton::clicked, this,[=]
    {
        ignoreClose = true;
        emit this-> logout();
    });
}

AppHomeWindow::~AppHomeWindow()
{
    delete ui;
    qDebug() << "AppHomeWindow::~AppHomeWindow";
}

//拦截关闭按钮
void AppHomeWindow::closeEvent(QCloseEvent* event)
{
    if (ignoreClose)
    {
        event->accept();
        ignoreClose = false;
        return;
    }
    auto res = QMessageBox::question(this, "确认关闭", "确定要关闭程序吗？", QMessageBox::Yes | QMessageBox::No);

    if (res == QMessageBox::Yes)
    {
        event->accept();
    }
    else
    {
        event->ignore();
    }
};

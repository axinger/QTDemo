//
// Created by xing on 2024/11/11.
//

// You may need to build the project (run Qt uic code generator) to get "ui_AppHomeWindow.h" resolved

#include "apphomewindow.h"

#include <qevent.h>
#include <qmessagebox.h>

#include "ui_AppHomeWindow.h"


AppHomeWindow::AppHomeWindow(QWidget* parent) :
    QWidget(parent), ui(new Ui::AppHomeWindow)
{
    ui->setupUi(this);
}

AppHomeWindow::~AppHomeWindow()
{
    delete ui;
}

//拦截关闭按钮
void AppHomeWindow::closeEvent(QCloseEvent* event)
{
    auto res = QMessageBox::question(this, "提示", "确定关闭吗？", QMessageBox::Yes | QMessageBox::No);

    if (res == QMessageBox::Yes)
    {
        event->accept();
    }
    else
    {
        event->ignore();
    }
};

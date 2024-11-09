//
// Created by xing on 2024/11/9.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MyHomeWindow.h" resolved

#include "myhomewindow.h"

#include <iostream>
#include <qdockwidget.h>
#include <QLabel>
#include <QMenuBar>
#include <QPushButton>
#include <QStatusBar>
#include <qtextedit.h>
#include <QToolBar>
#include <QVBoxLayout>


MyHomeWindow::MyHomeWindow(QWidget* parent) :
    QMainWindow(parent)
{
    std::cout << "home创建了" << std::endl;
    setWindowTitle("首页");
    // setMinimumSize(500, 500);
    // setFixedSize(800,800);

    this->resize(800, 600);

    // QPalette::Background → QPalette::Window
    //
    // QPalette::Foreground → QPalette::WindowText
    //
    // QPalette::Base → 保持不变
    //
    // QPalette::Text → 保持不变
    //
    // QPalette::Button → 保持不变
    //
    // QPalette::ButtonText → 保持不变

    // setAutoFillBackground(true);
    QPixmap pix12;
    pix12.load(":/img/背景图_蓝.png");
    QPalette p;
    // p.setBrush(QPalette::Window, QBrush(pix12));
    p.setColor(QPalette::Window, Qt::gray);

    this->setPalette(p);

    // showMaximized();
    // QFont fot;
    // fot.setBold(30);
    // setFont(fot);
    setupMenu();
    setupToos();
    createStatusBar();
}

// 菜单栏
void MyHomeWindow::setupMenu()
{
    auto* menubar = new QMenuBar(this);
    this->setMenuBar(menubar);

    // 添加菜单
    auto* menu1 = new QMenu("文件");


    auto* action11 = new QAction("打开文件");
    QPixmap pix1;
    pix1.load(":/img/玉兔.png");
    action11->setIcon(pix1);

    connect(action11, &QAction::triggered, this, [=]
    {
        std::cout << "打开了文件" << std::endl;
    });
    auto* action12 = new QAction("关闭");
    QPixmap pix12;
    pix12.load(":/img/绣球.png");
    action12->setIcon(pix12);

    connect(action12, &QAction::triggered, this, &MyHomeWindow::close);

    const auto actions1 = {
        action11, action12,
    };

    menu1->addActions(actions1);

    auto* menu2 = new QMenu("保存");
    auto* menu3 = new QMenu("编辑");
    menubar->addMenu(menu1);
    menubar->addMenu(menu2);
    menubar->addMenu(menu3);
}

// 工具栏
void MyHomeWindow::setupToos()
{
    QToolBar* toolbar = new QToolBar(this);

    auto* ac1 = new QAction("工具1");

    toolbar->addAction(ac1);

    // toolbar->setMovable(false); //禁止移动
    this->addToolBar(toolbar);
}

// 工具栏
void MyHomeWindow::createStatusBar()
{
    // 状态栏，自带的，不需要创建
    auto* statusbar = statusBar();
    this->setStatusBar(statusbar);
    //     auto* ac2 = new QAction("状态栏1");
    // statusbar->addAction(ac2);

    // 临时信息
    statusbar->showMessage("页面显示成功", 5000);
    // QPushButton* btn0 = new QPushButton("状态0",this);
    // statusbar->addWidget(btn0,10);


    //正式信息，在右侧
    QPushButton* btn1 = new QPushButton("www.baidu.com", this);
    statusbar->addPermanentWidget(btn1); //addPermanentWidget放在右边

    //铆钉部件，浮动的窗口
    QDockWidget* qDockWidget = new QDockWidget("注册", this);

    this->addDockWidget(Qt::TopDockWidgetArea, qDockWidget);

    // QTextEdit *textEdit = new QTextEdit("文本编辑器",this);
    // this->setCentralWidget(textEdit);

    QWidget* widget = new QWidget(this);
    // widget->setStyleSheet("background-color: red;");
    // 如果这个QWidget直接show，是有背景色的，但是如果把它放到一个父Widget中时，它就没有了效果。
    widget->setAutoFillBackground(true);
    QPalette p;
    // p.setBrush(QPalette::Window, QBrush(pix12));
    // p.setColor(QPalette::Window, Qt::green);
    p.setBrush(this->backgroundRole(),QBrush(Qt::green));
    widget->setPalette(p);
    // QVBoxLayout *layout = new QVBoxLayout(widget);

    auto* label = new QLabel("这是一个标签", widget);
    // layout->addWidget(label);

    // widget->

    // QPalette palette;
    // palette.setColor(QPalette::Base, Qt::red); // 设置背景色为红色
    // widget -> setPalette(palette);
    this->setCentralWidget(widget);
}

MyHomeWindow::~MyHomeWindow()
{
    std::cout << "home销毁了" << std::endl;
}

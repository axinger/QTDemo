//
// Created by xing on 2024/11/10.
//

// You may need to build the project (run Qt uic code generator) to get "ui_AppLogin.h" resolved

#include "applogin.h"

#include <iostream>
#include <ostream>
#include <qevent.h>
#include <qformlayout.h>
#include <QLabel>
#include <QLineEdit>
#include <qpainter.h>
#include <qpainterpath.h>
#include <QPushButton>
#include <qstyleoption.h>

#include "myhomewindow.h"
#include "ui_AppLogin.h"


AppLogin::AppLogin(QWidget* parent) :
    QWidget(parent), ui(new Ui::AppLogin)
{
    ui->setupUi(this);
    setWindowTitle("登录");
    // 设置窗口大小
    resize(600, 400);

    // this->setObjectName("mainWidget");
    // this->setStyleSheet("#mainWidget { border: 1px solid red; }");
    // this->setStyleSheet("QWidget {  background-color:rgb(255, 85, 127) }");

    // setStyleSheet("background-color: white; "     // 设置背景颜色
    //                          "border: 2px solid #3498db;"    // 自定义边框颜色和宽度
    //                          "border-radius: 15px;");        // 设置圆角半径

    // this->setObjectName("contentWidget");
    // this->setStyleSheet("#contentWidget{background: lightgray; border-radius: 4px;}" // 定制圆角
    //                              ".QLabel{background: gray;}.QTextEdit{background: white;}");

    // 关闭了标题栏，就不能移动了，所以重写手势方法
    // this->setWindowFlags(Qt::Dialog|Qt::FramelessWindowHint);
    // 设置窗口标志为普通窗口且无边框
    // setWindowFlags(Qt::Window | Qt::FramelessWindowHint);

    // 设置窗口的透明背景
    this->setAttribute(Qt::WA_TranslucentBackground);
    // 设置无边框和无标题栏
    this->setWindowFlags(Qt::FramelessWindowHint);

    // this->setStyleSheet("AppLogin { border: 1px solid darkyellow; border-radius: 10px; }");

    // setFixedSize(600, 400);

    // 创建表单布局
    QFormLayout* formLayout = new QFormLayout;
    formLayout->setLabelAlignment(Qt::AlignRight);
    formLayout->setFieldGrowthPolicy(QFormLayout::FieldsStayAtSizeHint);
    formLayout->setFormAlignment(Qt::AlignHCenter);

    // 创建用户名和密码输入框
    QLineEdit* usernameEdit = new QLineEdit(this);
    // usernameEdit->setFixedWidth(200);  // 设置固定的宽度为 200 像素
    // usernameEdit->setFixedHeight(30);
    usernameEdit->setFixedSize(200, 30);

    QLineEdit* passwordEdit = new QLineEdit(this);
    // passwordEdit->setFixedWidth(200);  // 设置固定的宽度为 200 像素
    // passwordEdit->setFixedHeight(30);
    passwordEdit->setFixedSize(200, 30);
    passwordEdit->setEchoMode(QLineEdit::Password);

    // 将输入框添加到表单布局
    formLayout->addRow(new QLabel("用户名："), usernameEdit);
    formLayout->addRow(new QLabel("密码："), passwordEdit);

    // 创建登录按钮
    QPushButton* loginButton = new QPushButton("登录", this);
    loginButton->setFixedSize(200, 50);
    // color: red; background:red;
    // loginButton->setStyleSheet("QPushButton { font-size: 20px }");


    // :hover：当鼠标悬停在控件上时的状态。
    // :pressed：当按钮或类似控件被按下时的状态。
    // :checked：当复选框或单选按钮被选中时的状态。
    // :unchecked：当复选框或单选按钮未被选中时的状态。
    // :indeterminate：当复选框处于不确定状态时（例如，部分选中的树形结构中的节点）。
    // :disabled：当控件被禁用（不可交互）时的状态。
    // :enabled：当控件可用（可交互）时的状态。
    // :focus：当控件获得焦点时的状态，比如通过键盘Tab键切换到某个控件。
    // :selected：当列表项、表格单元格等被选中时的状态


    loginButton->setStyleSheet("QPushButton{"
        "background-color: red;"
        "} "
        "QPushButton:hover{"
        "background-color: red;"
        "}");


    // loginButton->setEnabled(false);

    // 补位一个左侧文字
    formLayout->addRow(new QLabel(""), loginButton);


    // 移除所有边距
    // setContentsMargins(0, 0, 0, 0);

    connect(loginButton, &QPushButton::clicked, this, [=]()
    {
        QString username = usernameEdit->text();
        QString password = passwordEdit->text();

        if (username.isEmpty() || password.isEmpty())
        {
            return;
        }
        // MyHomeWindow home_window;
        // // home_window.setWindowFlag(Qt::WindowCloseButtonHint, false);
        // home_window.show();
        // this->hide();
        // this->close();
        emit this->loginSuccessful();
    });

    // 创建登录按钮
    QPushButton* exitButton = new QPushButton("退出", this);
    exitButton->setFixedSize(200, 50);
    formLayout->addRow(new QLabel(""), exitButton);
    connect(exitButton, &QPushButton::clicked, this, [=]()
    {
        qApp->exit();
    });


    // 创建一个垂直布局管理器，用于将表单居中
    QVBoxLayout* mainLayout = new QVBoxLayout;
    mainLayout->addStretch(); //这里调用2次
    mainLayout->addLayout(formLayout);
    mainLayout->addStretch();
    // 设置窗口的布局
    setLayout(mainLayout);
}

AppLogin::~AppLogin()
{
    delete ui;
    std::cout << "登录页面消失===========" << std::endl;
}


void AppLogin::mousePressEvent(QMouseEvent* event)
{
    if (event->button() == Qt::LeftButton)
    {
        // 鼠标左键
        m_dragPosition = event->globalPosition().toPoint() - frameGeometry().topLeft();
        m_dragging = true;
    }
    event->accept();
}

void AppLogin::mouseMoveEvent(QMouseEvent* event)
{
    if (m_dragging)
    {
        // move(event->globalPos() - m_dragPosition);
        move(event->globalPosition().toPoint() - m_dragPosition);
        event->accept();
    }
}

void AppLogin::mouseReleaseEvent(QMouseEvent* event)
{
    m_dragging = false;
    event->accept();
}

// 去除边框去除标题栏后，自定义边框，绘制边框，设置边框，矩形，线
void AppLogin::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);

    // 设置圆角半径
    constexpr int borderRadius = 10;
    // 启用抗锯齿以确保边缘平滑
    painter.setRenderHint(QPainter::Antialiasing, true);

    // 使用 QPainterPath 创建圆角矩形路径
    QPainterPath path;
    path.addRoundedRect(this->rect(), borderRadius, borderRadius);

    // 填充背景色
    // painter.fillPath(path, Qt::white); // 这里可以设置其他背景颜色
    painter.fillPath(path, this->palette().window());
    // 设置边框颜色和宽度
    painter.setPen(QPen(Qt::darkYellow, 1));

    // 绘制边框
    painter.drawPath(path);
}

//
// Created by xing on 2024/11/9.
//

// You may need to build the project (run Qt uic code generator) to get "ui_Login.h" resolved

#include "login.h"

#include <iostream>
#include <QPushButton>
#include <QLabel>
#include <QtWidgets>



Login::Login(QWidget* parent) :
    QWidget(parent)
{

    // 修改标题
    this->setWindowTitle(" ");
    // this->setWindowTitle(nullptr);

    // this->setStyleSheet("background-color: green;"); // 设置背景色为绿色，子元素也会改变颜色

    QPalette palette;
    palette.setColor(QPalette::Window, Qt::red); // 设置背景色为红色
    setPalette(palette);

    // 窗口大小，可以拉伸
    // this->resize(800,600);
    //
    // // 窗口大小，不可用拉伸
    // this->setFixedSize(800,600);


    //最大化
    // setWindowState(Qt::WindowMaximized);
    //全屏无边框显示
    // setWindowState(Qt::WindowFullScreen);

    //无标题栏无边框
    // setWindowFlags(Qt::FramelessWindowHint);
    //最小尺寸
    setMinimumHeight(600);
    setMinimumWidth(600);

    //     w.showEvent()                   自定义大小
    //
    // w.showFullScreen();           全屏
    //
    // w.showMaximized();           最大化
    //
    // w.showMinimized();            最小化
    //
    // w.showNormal();                 正常


    // 最大化
    // showMaximized();

    // showNormal();

    //
    // showFullScreen();

    // 创建标签和按钮
    auto* label = new QLabel("这是一个标签", this);
    label->move(0, 0);

    //在这种情况下，当父窗口或父组件销毁时，loginBtn 会自动销毁，无需手动删除。
    auto* loginBtn = new QPushButton();
    // this->loginButton = loginBtn;

    loginBtn->setText("登录");
    loginBtn->setParent(this);
    QPalette palette2;
    palette2.setColor(QPalette::ButtonText, Qt::green); // 设置背景色为红色
    palette2.setColor(QPalette::Button, Qt::white); // 设置背景色为红色
    loginBtn->setPalette(palette2);
    //尺寸
    // loginBtn->setFixedSize(80, 80);
    // loginBtn->resize(80, 80);
    // // 位置
    // loginBtn->move(100, 50);

    loginBtn->setGeometry(80, 80, 80, 50);
    // pressed() —— 当鼠标在button上并点击左键的时候发射，最先执行；
    // released()——当鼠标左键被释放的时候
    // clicked() —— 当鼠标首先按下pressed，然后释放，最后执行；
    // toggled() —— 按下之后状态发生变化，触发toggled；
    // 使用 lambda 表达式作为槽函数
    const auto a = connect(loginBtn, &QPushButton::clicked, [=]()
    {
        // 在此处编写点击后的操作
        std::cout << "点击了" << ",label=" << label->isHidden() << std::endl;
        label->setHidden(!label->isHidden());

        // QMessageBox::warning(this, "Login Failed", "Invalid username or password");
        //
        // MyHomeWindow home;
        // home.show();
        //
        // home.activateWindow();
        //
        // this->hide(); // 隐藏登录窗口
        // this->deleteLater(); // 在事件循环结束后销毁登录窗口
        // // 将 HomeWindow 的所有权转移到 QApplication
        // static_cast<QApplication*>(QApplication::instance())->setActiveWindow(home);
        //
        // QApplication::instance()->set
        emit loginSuccessful();
    });
    (void)a;


    // 对象树，可以delete子对象，自动管理对象
    //关闭
    auto* closeBtn = new QPushButton();
    // this->loginButton = loginBtn;

    closeBtn->setText("关闭窗口");
    closeBtn->setParent(this);
    closeBtn->setGeometry(loginBtn->x(), loginBtn->y() + loginBtn->height() + 10, loginBtn->width(),
                          loginBtn->height());
    connect(closeBtn, &QPushButton::clicked, this, &QWidget::close);


    auto* test1Btn = new QPushButton();
    // this->loginButton = loginBtn;

    test1Btn->setText("自定义信号和槽");
    test1Btn->setParent(this);
    test1Btn->setGeometry(closeBtn->x(), closeBtn->y() + closeBtn->height() + 10, closeBtn->width(),
                          closeBtn->height());
    // loginBtn->click(); //通过编程方式触发点击事件
    connect(test1Btn, &QPushButton::clicked, this, &Login::onButtonClicked);


    //取消槽连接
    // disconnect(loginBtn, &QPushButton::clicked, this, &QWidget::close);

    // 自定义信号和槽
    tea = new Teacher();
    stu = new Student();

    // connect(this->tea,&Teacher::hungry,this->stu,&Student::eat);
    // 方法重载，无法区分，需要用函数指针，获取成员函数的地址
    void (Teacher::*hungry)() = &Teacher::hungry;
    // 在大多数现代编译器中，省略 & 操作符也是可以的，但为了代码的清晰和标准符合性，建议始终使用 &。
    void (Teacher::*hungry11)() = Teacher::hungry;
    connect(tea, hungry, this, &Login::teacherEat);

    // （函数名称）（参数） = 指向的函数名称，
    void (Teacher::*hungry2)(QString) = &Teacher::hungry;
    connect(tea, hungry2, this, &Login::teacherEat2);
}

void Login::onButtonClicked() const
{
    std::cout << "点击了" << std::endl;
    // this->loginButton;

    // emit 发出信号
    emit this->tea->hungry();
    emit this->tea->hungry("汉堡包");
}

void Login::teacherEat() const
{
    std::cout << tea << "老师饿了，我知道了" << std::endl;
}

void Login::teacherEat2(const QString& name) const
{
    std::cout << tea << "老师饿了，我知道了" << name.toStdString() << std::endl;
    qDebug() << name.toUtf8().toStdString();
}


Login::~Login()
{
    std::cout << "login销毁了========" << std::endl;

    // 使用完后删除
    delete loginButton;
}

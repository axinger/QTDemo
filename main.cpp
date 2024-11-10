#include <iostream>
#include <QApplication>
#include <QPushButton>
#include <QMainWindow>
#include <QtGui>
#include <QVBoxLayout>
#include <ui_AppLogin.h>

#include "applogin.h"
#include "myregister.h"

#include "mylogin.h"
#include "myhomewindow.h"
#include "mylogoutwidget.h"

void test_map()
{
    // QMap<QString, int> map;
    // map.insert("apple", 1);
    // map.insert("banana", 2);
    // map.insert("cherry", 3);
    //
    // QMap<QString, int>::const_iterator it;
    // for (it = map.constBegin(); it != map.constEnd(); ++it) {
    //     qDebug() << "Key:" << it.key() << "Value:" << it.value();
    // }
    // for (int map1 : map)
    // {
    //     std::cout << map1 << std::endl;
    // }


    QMap<QString, QString> map;
    map.insert("apple", "yi");
    map.insert("banana", "er");
    map.insert("cherry", "san");

    std::cout << "map取值" << map["apple"].toStdString() << std::endl;
    // 直接获得value
    for (const QString& map1 : map)
    {
        std::cout << map1.toStdString() << std::endl;
    }

    // //使用范围for循环遍历QMap（C++11）
    // for (const auto &pair : map) {
    //     qDebug() << "Key:" << pair << "Value:" << pair.second;
    // }

    QList<QString> list = {"one", "two", "three"};

    for (const auto& chars : list)
    {
        std::cout << chars.toStdString() << std::endl;
    }


    std::cout << "list取值=" << list[2].toStdString() << std::endl;

    QSet<QString> set = {"one", "two", "one"};
    for (const auto& chars : set)
    {
        std::cout << "set遍历=" << chars.toStdString() << std::endl;
    }
}

void test3_匿名函数()
{
    // [] 捕获列表，默认值传递， [=] 捕获所有，值传递， [&] 捕获所有，引用传递
    const std::string sex = "性别";
    const std::string address = "性别";
    int age = 10; //mutable 修改基本类型
    // auto f1 = [sex, address,age](const std::string& name)mutable
    // {
    //     std::cout << name << std::endl;
    //     std::cout << sex << std::endl;
    //     std::cout << address << std::endl;
    //   age=300;
    //     std::cout << age << std::endl;
    // };

    //[&] 捕获所有，引用传递
    auto f1 = [sex, address,&age](const std::string& name)
    {
        std::cout << name << std::endl;
        std::cout << sex << std::endl;
        std::cout << address << std::endl;
        age = 300;
        std::cout << age << std::endl;
    };
    f1("apple");

    std::cout << age << std::endl;
}

// 当调用 f1 函数时，会创建一个 std::string 类型的局部变量 name，
// 它是传入参数的一个副本。在这个函数内部对 name 的任何修改都不会影响到原始的字符串对象。
void f1(std::string name)
{
    name = "f1";
}

// 当调用 f2 函数时，name 是一个引用（即别名），
// 它直接指向传入的原始 std::string 对象。因此，在函数内部对 name 的任何修改都会反映到原始对象上。
void f2(std::string& name)
{
    name = "f2";
}

//当调用 f3 函数时，name 是一个指针，
//它指向传入的 std::string 对象。通过解引用指针（*name），可以在函数内部修改原始对象
void f3(std::string* name)
{
    *name = "f3";
}

// 值传递：创建副本，函数内部的修改不会影响原始数据。
// 引用传递：直接操作原始数据，函数内部的修改会影响原始数据。
// 指针传递：通过指针操作原始数据，可以传递 nullptr，需要进行空指针检查
void test4_引用和指针参数()
{
    std::string name = "1";

    // f1(name);

    // f2(name);
    f3(&name);
    std::cout << name << std::endl;
}

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    // 设置全局样式
    // a.setStyleSheet("QPushButton { background-color: red; }");
    // 设置全局样式表，为所有QPushButton设置统一的图标
    // QIcon globalIcon(":/绣球.png"); // 替换为你的图标文件路径
    // QString styleSheet = QString("QPushButton { icon: url(%1); }").arg(globalIcon.name());
    // app.setStyleSheet(styleSheet);
    // QApplication::setWindowIcon(globalIcon);

    // MyLogin login;
    // login.show();
    // MyHomeWindow home_window;
    // home_window.show();
    // home_window.hide();
    AppLogin login;
    login.show();
    MyHomeWindow home_window;
    QObject::connect(&login, &AppLogin::loginSuccessful, [&]()
    {
        home_window.show();
        login.close();
    });
    // QObject::connect(&login, &AppLogin::loginSuccessful, &login, &AppLogin::deleteLater, Qt::QueuedConnection);

    return QApplication::exec();


    // test_map();

    // test3_匿名函数();
    test4_引用和指针参数();
    return 0;
}

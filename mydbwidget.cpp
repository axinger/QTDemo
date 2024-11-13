//
// Created by xing on 2024/11/12.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MyDbWidget.h" resolved

#include "mydbwidget.h"
#include "ui_mydbwidget.h"
#include <iostream>
#include <QPushButton>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <qjsondocument.h>
#include <qjsonobject.h>
#include <QMessageBox>

#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>

MyDbWidget::MyDbWidget(QWidget* parent) :
    QWidget(parent), ui(new Ui::MyDbWidget)
{
    ui->setupUi(this);
}

MyDbWidget::~MyDbWidget()
{
    delete ui;
}

void MyDbWidget::on_pushButton_clicked()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("my_database.db");
    if (!db.open())
    {
        qDebug() << "打开数据库失败" << db.lastError().text();
        //如果数据库打开失败
        QMessageBox::warning(this, "错误", db.lastError().text());
    }
    else
    {
        qInfo() << "打开数据库成功";
    }
}

void MyDbWidget::on_pushButton_2_clicked()
{
    // 创建表
    QSqlQuery query;
    QString createTableQuery =
        "CREATE TABLE IF NOT EXISTS test_user (id INTEGER PRIMARY KEY AUTOINCREMENT, name TEXT, age INTEGER)";
    if (!query.exec(createTableQuery))
    {
        qDebug() << "Failed to create table.";
    }
    else
    {
        qInfo() << "创建表成功";
    }
}


void MyDbWidget::on_pushButton_3_clicked()
{
    // 插入数据

    QString insertQuery = "INSERT INTO test_user (name, age) VALUES (:name, :age)";
    QSqlQuery query;
    query.prepare(insertQuery);
    query.bindValue(":name", "John");
    query.bindValue(":age", 25);
    if (!query.exec())
    {
        qDebug() << "Failed to insert data.";
    }
    else
    {
        qInfo() << "插入数据成功";
    }
}


void MyDbWidget::on_pushButton_4_clicked()
{
    QSqlQuery query;
    // 查询数据
    QString selectQuery = "SELECT * FROM test_user";
    if (!query.exec(selectQuery))
    {
        qDebug() << "查询数据失败";
        return;
    }

    while (query.next())
    {
        int id = query.value("id").toInt();
        QString name = query.value("name").toString();
        int age = query.value("age").toInt();
        qInfo() << "ID:" << id << " Name:" << name << " Age:" << age;
    }
}

void MyDbWidget::on_pushButton_5_clicked()
{
    qDebug() << "ui槽格式： on_控件id_事件名称";
}

void MyDbWidget::on_testGet_clicked()
{

    // 设置请求 URL
    QUrl url("https://jsonplaceholder.typicode.com/todos/1");
    QNetworkRequest request(url);

    // 创建网络管理器
    networkManager = new QNetworkAccessManager(this);
    // 发送 GET 请求
    reply = networkManager->get(request);

    // 连接信号与槽
    connect(reply, &QNetworkReply::finished, this, [=]
    {

        // 读取响应
       if (reply->error() == QNetworkReply::NoError) {
           // 打印返回的内容
           // qDebug() << "Response: " << reply->readAll();

           QJsonDocument doc = QJsonDocument::fromJson( reply->readAll());
           if (doc.isObject()) {
                QJsonObject jsonObject = doc.object();
                // 打印 JSON 对象内容
                qDebug() << "ID:" << jsonObject["userId"].toInt();
                qDebug() << "UserID:" << jsonObject["userId"].toInt();
                qDebug() << "Title:" << jsonObject["title"].toString();
                qDebug() << "Completed:" << jsonObject["completed"].toBool();
            }else
            {
                qDebug()<< "!isObject";
            }

       } else {
           // 打印错误信息
           qDebug() << "Error: " << reply->errorString();
       }

       // 清理
       reply->deleteLater();
    });

}


//
// Created by xing on 2024/11/12.
//

#ifndef MYDBWIDGET_H
#define MYDBWIDGET_H

#include <QNetworkAccessManager>
#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class MyDbWidget; }
QT_END_NAMESPACE

class MyDbWidget : public QWidget {
    Q_OBJECT

    public:
    explicit MyDbWidget(QWidget *parent = nullptr);
    ~MyDbWidget() override;

    private slots:
        void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();
   static  void on_pushButton_5_clicked();
     void on_testGet_clicked();

private:
    Ui::MyDbWidget *ui;
    QNetworkAccessManager *networkManager;
    QNetworkReply *reply;
};


#endif //MYDBWIDGET_H

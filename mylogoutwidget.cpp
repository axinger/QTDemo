//
// Created by xing on 2024/11/10.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MyLogoutWidget.h" resolved

#include "mylogoutwidget.h"

#include <iostream>
#include <ostream>
#include <qbuttongroup.h>
#include <qdialog.h>
#include <QGroupBox>
#include <QPushButton>
#include <QRadioButton>
#include <QVBoxLayout>

#include "ui_MyLogoutWidget.h"


MyLogoutWidget::MyLogoutWidget(QWidget* parent) :
    QWidget(parent), ui(new Ui::MyLogoutWidget)
{
    ui->setupUi(this);
    this->resize(800, 600);


    QVBoxLayout* layout = new QVBoxLayout(this);

    // 创建 QGroupBox
    QGroupBox* groupBox = new QGroupBox("Options", this);
    groupBox->setFixedSize(200, 200);
    groupBox->move(0, 0);
    groupBox->setLayout(layout);

    // 创建 QRadioButton
    QRadioButton* radioButton1 = new QRadioButton("Option 1", this);
    QRadioButton* radioButton2 = new QRadioButton("Option 2", this);
    QRadioButton* radioButton3 = new QRadioButton("Option 3", this);
    radioButton1->setChecked(true);

    // 将按钮添加到 QButtonGroup
    QButtonGroup* buttonGroup = new QButtonGroup(this);
    buttonGroup->addButton(radioButton1);
    buttonGroup->addButton(radioButton2);
    buttonGroup->addButton(radioButton3);

    // 设置按钮的 ID（可选）
    buttonGroup->setId(radioButton1, 1);
    buttonGroup->setId(radioButton2, 2);
    buttonGroup->setId(radioButton3, 3);


    // 将按钮添加到 QGroupBox 的布局中
    layout->addWidget(radioButton1);
    layout->addWidget(radioButton2);
    layout->addWidget(radioButton3);


    QPushButton* groupButton = new QPushButton("获取值", this);
    groupButton->setGeometry(groupBox->x(), groupBox->y() + groupBox->height() + 10, 100, 60);
    connect(groupButton, &QPushButton::clicked, this, [=]()
    {
        std::cout << "checkedId=" << buttonGroup->checkedId() << std::endl;
    });


    // 阻塞方式，在栈
    QPushButton* dialogBtn1 = new QPushButton("对话框-阻塞", this);
    dialogBtn1->setGeometry(groupButton->x(), groupButton->y() + groupButton->height() + 10, 100, 60);
    connect(dialogBtn1, &QPushButton::clicked, this, [=]()
    {
        QDialog dialog;
        // dialog.setBaseSize(120,60 );
        dialog.setFixedSize(180, 90);
        dialog.setWindowTitle("请选择");

        dialog.exec();
    });

    // 非阻塞方式，在堆
    QPushButton* dialogBtn2 = new QPushButton("对话框-非阻塞", this);
    dialogBtn2->setGeometry(dialogBtn1->x(), dialogBtn1->y() + dialogBtn1->height() + 10, 100, 60);
    connect(dialogBtn2, &QPushButton::clicked, this, [=]()
    {
        // QDialog* dialog = new QDialog(this); //这个方式，必须当前页面，才能销毁
        QDialog* dialog = new QDialog;
        dialog->setAttribute(Qt::WA_DeleteOnClose); //关闭，就销毁
        // dialog.setBaseSize(120,60 );
        dialog->setFixedSize(180, 90);
        dialog->setWindowTitle("请选择");
        dialog->show();
    });

    QPushButton dialogBtn3 =  QPushButton("临时按钮", this);
    // 连接 destroyed 信号到槽函数
    connect(&dialogBtn3, &QWidget::destroyed, this, [=]()
    {
        std::cout << "dialogBtn3 已经销毁了" << std::endl;
    });


    dialogBtn3.setGeometry(dialogBtn2->x(), dialogBtn2->y() + dialogBtn2->height() + 10, 100, 60);
}

MyLogoutWidget::~MyLogoutWidget()
{
    delete ui;
}

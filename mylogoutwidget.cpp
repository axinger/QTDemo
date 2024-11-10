//
// Created by xing on 2024/11/10.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MyLogoutWidget.h" resolved

#include "mylogoutwidget.h"

#include <iostream>
#include <ostream>
#include <qbuttongroup.h>
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

    // QVBoxLayout *layout = new QVBoxLayout(this);
    //
    //
    // QRadioButton *radioButton1 = new QRadioButton("Option 1", this);
    //
    // radioButton1->setFixedSize(100, 50); // 设置固定大小
    // radioButton1->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed); // 设置策略为固定
    //
    // QRadioButton *radioButton2 = new QRadioButton("Option 2", this);
    //
    // radioButton2->setFixedSize(100, 50); // 设置固定大小
    // radioButton2->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed); // 设置策略为固定
    //
    // QRadioButton *radioButton3 = new QRadioButton("Option 3", this);
    //
    // radioButton3->setFixedSize(100, 50); // 设置固定大小
    // radioButton3->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed); // 设置策略为固定
    //
    //
    // QButtonGroup *buttonGroup = new QButtonGroup(this);
    // buttonGroup->addButton(radioButton1,1);
    // buttonGroup->addButton(radioButton2,2);
    // buttonGroup->addButton(radioButton3,3);
    //
    // layout->addWidget(radioButton1);
    // layout->addWidget(radioButton2);
    // layout->addWidget(radioButton3);
    //
    // setLayout(layout);


    // QGroupBox* groupBox = new QGroupBox(tr("Exclusive  Radio Buttons"),this);
    // groupBox->setFixedSize(200, 200);
    // groupBox->move(0, 0);
    //
    // QRadioButton* radio1 = new QRadioButton(tr("&Radio button 1"));
    // QRadioButton* radio2 = new QRadioButton(tr("R&adio button 2"));
    // QRadioButton* radio3 = new QRadioButton(tr("Ra&dio button 3"));
    // radio1->setChecked(true);
    // QVBoxLayout* vbox = new QVBoxLayout;
    // vbox->addWidget(radio1);
    // vbox->addWidget(radio2);
    // vbox->addWidget(radio3);
    // vbox->addStretch(2);
    //
    // groupBox->setLayout(vbox);
    //
    //
    // QPushButton* pushButton = new QPushButton("获取值", this);
    // pushButton->setGeometry(groupBox->x(),groupBox->y()+groupBox->height()+10,100,60);
    //
    // connect(pushButton, &QPushButton::clicked, this, [=]()
    // {
    //     // radio1->isChecked();
    //     // radio2->isChecked();
    //     // radio3->isChecked();
    //
    //
    //     std::cout << "radio1=" <<  radio1->isChecked() << std::endl;
    //     std::cout << "radio2=" << radio2->isChecked() << std::endl;
    //     std::cout << "radio3="<<  radio3->isChecked() << std::endl;
    // });


    QVBoxLayout* layout = new QVBoxLayout;

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


    QPushButton* pushButton = new QPushButton("获取值", this);
    pushButton->setGeometry(groupBox->x(), groupBox->y() + groupBox->height() + 10, 100, 60);
    connect(pushButton, &QPushButton::clicked, this, [=]()
    {
        std::cout << "checkedId=" << buttonGroup->checkedId() << std::endl;
    });
}

MyLogoutWidget::~MyLogoutWidget()
{
    delete ui;
}

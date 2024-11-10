//
// Created by xing on 2024/11/10.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MyRegister.h" resolved

#include "myregister.h"

#include <iostream>
#include <qbuttongroup.h>
#include <qlineedit.h>
#include <QMenuBar>

#include "ui_MyRegister.h"

// 定义全局组变量
QButtonGroup *group_sex;
MyRegister::MyRegister(QWidget *parent) :
    QWidget(parent), ui(new Ui::MyRegister) {
    ui->setupUi(this);

    // ui不会重名，不用递归查找
    // QLineEdit *line_edit = findChild<QLineEdit*>("username");
    // line_edit->setText("jim");
    ui->username->setText("jim");

    // 将RadioButton放入ButtonGroup组中
    group_sex = new QButtonGroup(this);
    group_sex->addButton(ui->radioButton_male,0);
    group_sex->addButton(ui->radioButton_female,1);
    group_sex->addButton(ui->radioButton_unknown,2);



    QPushButton *pushButton = new QPushButton("获取值",this);

    connect(pushButton,&QPushButton::clicked,this,[=]()
    {
        // int checkedId = ui->verticalGroupBox_3->checkedId();
        // std::cout << checkedId << std::endl;

    });

}

MyRegister::~MyRegister() {
    delete ui;
}

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
#include <qinputdialog.h>
#include <qmessagebox.h>
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
        dialog.setWindowFlag(Qt::WindowCloseButtonHint, false);
        dialog.setFixedSize(180, 90);
        dialog.setWindowTitle("请选择");

        QHBoxLayout layout;
        QPushButton btnOk("Ok");
        QPushButton btnCancel("Cancel");

        // 连接按钮的点击信号到对应的槽函数
        QObject::connect(&btnOk, &QPushButton::clicked, [&]()
        {
            QMessageBox::information(&dialog, "Information", "You clicked Ok.");
            dialog.accept(); // 接受对话框的当前状态
        });

        QObject::connect(&btnCancel, &QPushButton::clicked, [&]()
        {
            QMessageBox::information(&dialog, "Information", "You clicked Cancel.");
            dialog.reject(); // 拒绝对话框的当前状态
        });

        layout.addWidget(&btnOk);
        layout.addWidget(&btnCancel);

        dialog.setLayout(&layout);

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

    // 没有使用*创建对象，在栈中，临时对象，超出就会销毁
    QPushButton dialogBtn3 = QPushButton("临时按钮", this);
    // 连接 destroyed 信号到槽函数
    connect(&dialogBtn3, &QWidget::destroyed, this, [=]()
    {
        std::cout << "dialogBtn3 已经销毁了" << std::endl;
    });
    dialogBtn3.setGeometry(dialogBtn2->x(), dialogBtn2->y() + dialogBtn2->height() + 10, 100, 60);


    QPushButton* dialogBtn4 = new QPushButton("消息对话框", this);
    dialogBtn4->setGeometry(dialogBtn2->x(), dialogBtn2->y() + dialogBtn2->height() + 10, 100, 60);
    connect(dialogBtn4, &QPushButton::clicked, this, [=]()
    {
        // QMessageBox* msgBox = new QMessageBox();
        //
        // msgBox->setAttribute(Qt::WA_DeleteOnClose); //关闭，就销毁
        // // dialog.setBaseSize(120,60 );
        // msgBox->setFixedSize(180, 90);
        // msgBox->setWindowTitle("提示");
        // msgBox->show();

        // 在堆中
        QMessageBox::information(this, "Information", "You clicked Cancel.",
                                 QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel | QMessageBox::Ok,
                                 QMessageBox::Cancel);
        // QMessageBox::about(this, "about", "You clicked Cancel.");
        // QMessageBox::critical(this, "critical", "You clicked Cancel.");
        //
        // QMessageBox::warning(this, "warning", "You clicked Cancel.");
        // QMessageBox::aboutQt(this, "aboutQt");
        //
        // QMessageBox::StandardButton question = QMessageBox::question(this, "question", "You clicked Cancel.");
        //
        // std::cout << "question=" << ((question == QMessageBox::Yes) ? "确定" : "取消") << std::endl;
    });

    QPushButton* dialogBtn5 = new QPushButton("文本输入框弹窗", this);
    dialogBtn5->setGeometry(dialogBtn4->x(), dialogBtn4->y() + dialogBtn4->height() + 10, 100, 60);
    connect(dialogBtn5, &QPushButton::clicked, this, [=]()
    {
        bool ok;
        QString text = QInputDialog::getText(this, "输入文字", "222",
                                             QLineEdit::Normal,"默认文字",&ok);

        std::cout << text.toStdString() << std::endl;
    });
}

MyLogoutWidget::~MyLogoutWidget()
{
    delete ui;
}

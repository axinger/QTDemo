//
// Created by xing on 2024/11/10.
//

#ifndef APPLOGIN_H
#define APPLOGIN_H

#include <QWidget>


QT_BEGIN_NAMESPACE

namespace Ui
{
    class AppLogin;
}

QT_END_NAMESPACE

class AppLogin : public QWidget
{
    Q_OBJECT

public:
    explicit AppLogin(QWidget* parent = nullptr);
    ~AppLogin() override;
signals:
    void loginSuccessful();

private:
    Ui::AppLogin* ui;

protected:
    void mousePressEvent(QMouseEvent* event) override;

    void mouseMoveEvent(QMouseEvent* event) override;

    void mouseReleaseEvent(QMouseEvent* event) override;


    void paintEvent(QPaintEvent* event) override;

private:
    bool m_dragging; // 标记是否正在拖动
    QPoint m_dragPosition; // 拖动位置偏移量
};


#endif //APPLOGIN_H

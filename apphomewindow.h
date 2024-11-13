//
// Created by xing on 2024/11/11.
//

#ifndef APPHOMEWINDOW_H
#define APPHOMEWINDOW_H

#include <QMainWindow>
#include <QWidget>


QT_BEGIN_NAMESPACE

namespace Ui
{
    class AppHomeWindow;
}

QT_END_NAMESPACE

class AppHomeWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AppHomeWindow(QWidget* parent = nullptr);
    ~AppHomeWindow() override;

protected:
    void closeEvent(QCloseEvent* event) override;

private:
    Ui::AppHomeWindow* ui;

    bool ignoreClose;
signals:
    void logout();
};


#endif //APPHOMEWINDOW_H

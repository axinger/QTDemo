#include "student.h"

#include <iostream>
#include <QDebug>
Student::Student(QObject *parent)
    : QObject{parent}
{}


void Student::eat(){


    qDebug() << "i have eat============";
    std::cout << "吃饭了";

}

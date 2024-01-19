#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Demo_Inspection.h"

class Demo_Inspection : public QMainWindow
{
    Q_OBJECT

public:
    Demo_Inspection(QWidget *parent = nullptr);
    ~Demo_Inspection();

private:
    Ui::Demo_InspectionClass ui;
};

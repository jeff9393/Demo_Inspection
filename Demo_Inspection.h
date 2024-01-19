#pragma once

#include "ui_Demo_Inspection.h"
#include "src/Controller.h"


class Demo_Inspection : public QMainWindow
{
    Q_OBJECT

public:
    explicit Demo_Inspection(QWidget *parent = nullptr);
    ~Demo_Inspection();

    /* create inspection object */
    Controller* inspection = new Controller();

protected:
    /* interface for factory */

private:
    Ui::Demo_InspectionClass *ui;

signals:
    void TriggerInspection();

private slots:
    void on_StartButton_clicked();
};

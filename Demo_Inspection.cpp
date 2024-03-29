#include "Demo_Inspection.h"

Demo_Inspection::Demo_Inspection(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::Demo_InspectionClass)
{
    qDebug() << "UI thread: " << QThread::currentThreadId();

    /* connenct */
    QObject::connect(this, SIGNAL(TriggerInspection()), inspection, SLOT(StartInspection()));
    QObject::connect(this, SIGNAL(ChangeProduct(int)), inspection, SLOT(UpdateFactory(int)));
    QObject::connect(inspection, SIGNAL(NotifyResult(bool)), this, SLOT(UpdateResult(bool)));

    ui->setupUi(this);
    this->showNormal();
}

Demo_Inspection::~Demo_Inspection()
{
    delete inspection;
    delete ui;
}

void Demo_Inspection::on_StartButton_clicked()
{
    emit TriggerInspection();
}


void Demo_Inspection::on_comboBox_SelectProduct_currentIndexChanged(int index)
{
    emit ChangeProduct(index);
}

void Demo_Inspection::UpdateResult(bool result)
{
    QString result_text;
    result ? result_text = "PASS" : result_text = "FAIL";
    ui->label_Result->setText(result_text);
}
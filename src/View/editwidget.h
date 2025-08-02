#ifndef EDITWIDGET_H
#define EDITWIDGET_H
#include <QWidget>
#include <QPushButton>
#include <QPushButton>
#include <QVector>
#include <QLineEdit>
#include <QSpinBox>
#include <QTextEdit>
#include <QStackedLayout>
#include "mainwindow.h"
#include "../Sensor/abstractsensor.h"
#include "SensorEditor/abstractsensoreditor.h"
#include "../Sensor/Repo/jsonrepository.h"
namespace View {
class EditWidget: public QWidget{
    Q_OBJECT
private:
    Sensor::AbstractSensor* sensor;
    MainWindow* main_window;
    QSpinBox* id_imput;
    QLineEdit* name_imput;
    QLineEdit* stanza_imput;
    QSpinBox* DataNum_imput;
    QStackedLayout* stacked_editor;
    QVector<SensorEditor::AbstractSensorEditor*> editors;
    Sensor::Repo::JsonRepository* repo;
public:
    EditWidget(
        Sensor::AbstractSensor* s,
        MainWindow* m,
        Sensor::Repo::JsonRepository* rep = nullptr
    );
signals:
    void widgetClosed();
    void set_unit_event(int index);
public slots:
    void showType(int index);
    void apply();
    void closeWindow();
};
}
#endif // EDITWIDGET_H

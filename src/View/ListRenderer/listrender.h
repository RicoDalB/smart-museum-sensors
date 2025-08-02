#ifndef LISTRENDER_H
#define LISTRENDER_H
#include "View/sensorlistwidget.h"
#include "SListStrategy.h"
namespace View::SensorRenderer {
class ListRender:public SListStrategy{
private:
    QWidget* widget;
    QPushButton* view_button;
    QPushButton* edit_button;
    QPushButton* delete_button;
public:
    ListRender();
    void visit(const Sensor::Co2Sensor& co2_sen) override;
    void visit(const Sensor::HumiditySensor& humidity) override;
    void visit(const Sensor::TemperatureSensor& temperature) override;
    virtual QWidget* getWidget()const ;
    virtual QPushButton* getViewButton()const ;
    virtual QPushButton* getEditButton() const ;
    virtual QPushButton* getDeleteButton() const ;

};
}
#endif // LISTRENDER_H

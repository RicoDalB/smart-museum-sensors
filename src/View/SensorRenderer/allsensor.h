#ifndef ALLSENSOR_H
#define ALLSENSOR_H
#include "QtWidgets/QLabel"
#include "QtCharts/QChartView"
#include "View/ListRenderer/listrender.h"
#include  <QValueAxis>
namespace View::GraphRenderer {
class AllSensor: public Sensor::SConstVisitor{
private:
    QWidget* widget;
    QLabel* id;
    QLabel* name;
    QLabel* stanza;
    QLabel* data_num;
    QPushButton* simulate_button;
    QPushButton* edit_button;
    QPushButton* clear_button;
    QChart* chart;
    QValueAxis* assX;
    QValueAxis* assY;
    QChartView* view_chart;
public:
    AllSensor();
    void cleanArea();
    void visit(const Sensor::Co2Sensor& co2) override;
    void visit(const Sensor::HumiditySensor& humidity) override;
    void visit(const Sensor::TemperatureSensor& temperature) override;
    virtual QWidget* getWidget() const;
    virtual QLabel* getId()const;
    virtual QLabel* getName()const;
    virtual QLabel* getStanza()const;
    virtual QLabel* getDataNum() const;
    virtual QPushButton* getSimulateButton() const;
    virtual QPushButton* getEditButton() const;
    virtual QPushButton* getClearButton() const;
    virtual QChart* getChart() const;
    QValueAxis* getAssX() const;
    QValueAxis* getAssY() const;
    virtual QChartView* getChartView() const;

};
}
#endif // ALLSENSOR_H

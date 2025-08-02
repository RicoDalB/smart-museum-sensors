#ifndef SIMVISITOR_H
#define SIMVISITOR_H
#include "Sensor/SVisitor.h"
#include "QtWidgets/QWidget"
#include "QtWidgets/QLabel"
#include "QtWidgets/QPushButton"
#include "QtCharts/QChart"
#include "QtCharts/QChartView"
#include "QtCharts/QValueAxis"
namespace View::GraphRenderer {
class SimVisitor: public Sensor::SVisitor{
private:
    QChart* chart;
    QValueAxis *assX;
    QValueAxis *assY;
    QChartView* view_chart;
public:
    SimVisitor();
    void visit(Sensor::Co2Sensor& co2)override;
    void visit(Sensor::HumiditySensor& humidity)override;
    void visit(Sensor::TemperatureSensor& temperature) override;
    virtual QChart* getChart() const;
    SimVisitor& setChart(QChart* chart);
    QValueAxis* getXass() const;
    QValueAxis* getYass()const;
    SimVisitor& setXass(QValueAxis* x);
    SimVisitor& setYass(QValueAxis* y);
    virtual QChartView* getChartView() const;
    SimVisitor& setChartView(QChartView* view_chart);
};
}
#endif // SIMVISITOR_H

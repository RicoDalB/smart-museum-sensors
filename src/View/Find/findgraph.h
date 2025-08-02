#ifndef FINDGRAPH_H
#define FINDGRAPH_H

#include "QtWidgets/QWidget"
#include "QtWidgets/QPushButton"
#include "QtWidgets/QLabel"
#include "QtCharts/QChart"
#include "QtCharts/QChartView"
#include "QtCharts/QValueAxis"
#include "Sensor/abstractsensor.h"

namespace View {

class FindGraph{
private:
    Sensor::AbstractSensor* sensor;
    QWidget* widget;
    QLabel* id;
    QLabel* name;
    QLabel* stanza;
    QLabel* data_name;
    QPushButton* simulate_button;
    QPushButton* edit_button;
    QPushButton* clear_button;
    QChart* chart;
    QValueAxis* assX;
    QValueAxis* assY;
    QChartView* view_chart;

public:
    FindGraph(
        Sensor::AbstractSensor* sensor,
        QWidget* widget,
        QLabel* id,
        QLabel* name,
        QLabel* stanza,
        QLabel* data_name,
        QPushButton* simulate_button,
        QPushButton* edit_button,
        QPushButton* clear_button,
        QChart* chart,
        QValueAxis* assX,
        QValueAxis* assY,
        QChartView* view_chart
        );
    Sensor::AbstractSensor* getSensor() const;
    QWidget* getWidget() const;
    FindGraph& setWidget(QWidget* w);
    QLabel* getId()const;
    QLabel* getName()const;
    QLabel* getStanza() const;
    QLabel* getDataName()const;
    QPushButton* getSimulateButton() const;
    QPushButton* getEditButton() const;
    QPushButton* getClearButton() const;
    QChart* getChart() const;
    QValueAxis* getAssX();
    QValueAxis* getAssY();
    QChartView* getChartView() const;

};
}
#endif // FINDGRAPH_H

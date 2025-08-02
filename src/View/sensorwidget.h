#ifndef SENSORWIDGET_H
#define SENSORWIDGET_H
#include "View/Find/findgraph.h"
#include "SensorRenderer/SGraphRender.h"
#include "View/GraphSimulator/SGraphSimulator.h"

namespace View {
class SensorWidget:  public QWidget{
    Q_OBJECT
private:
    FindGraph* find;
    QGridLayout* layout;
    GraphRenderer::SGraphRender* render;
    GraphRenderer::SGraphSimulator* simulator;
public:
    explicit SensorWidget(QWidget* parent = 0);
    ~SensorWidget() override;
    FindGraph* getFind();
    bool isEmpty() const;
    void show(const Sensor::AbstractSensor* sensor);
    void clearChart();
    void hideSensorWidget();
    void clean();
    void clearView();

public slots:
    void simulate();
    void clear();
    void edit();


signals:
    void edit_event(Sensor::AbstractSensor* sen);
};
}
#endif // SENSORWIDGET_H

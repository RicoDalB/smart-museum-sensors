#ifndef ALLGRAPH_H
#define ALLGRAPH_H
#include "SGraphRender.h"
#include "allsensor.h"
#include "../sensorwidget.h"
#include "../../Sensor/abstractsensor.h"
namespace View::GraphRenderer {
class AllGraph: public SGraphRender{
private:
    AllSensor AllSen;
public:
    void render(QGridLayout* grid, const Sensor::AbstractSensor* sensor, FindGraph*& find)override;
};
}
#endif // ALLGRAPH_H

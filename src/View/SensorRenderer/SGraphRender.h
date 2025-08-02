#ifndef SGRAPHRENDER_H
#define SGRAPHRENDER_H
#include "../../Sensor/abstractsensor.h"
#include "View/Find/findgraph.h"
#include <QGridLayout>
namespace View::GraphRenderer{
class SGraphRender{
public:
    virtual ~SGraphRender() = default;
    virtual void render(QGridLayout* grid, const Sensor::AbstractSensor* sensor, FindGraph*& find) = 0;
};
}


#endif // SGRAPHRENDER_H

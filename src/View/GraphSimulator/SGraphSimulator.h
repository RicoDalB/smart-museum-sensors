#ifndef SGRAPHSIMULATOR_H
#define SGRAPHSIMULATOR_H
#include "Sensor/abstractsensor.h"
#include "View/Find/findgraph.h"
namespace View::GraphRenderer {
class SGraphSimulator{
public:
    virtual ~SGraphSimulator() = default;
    virtual void simulate(Sensor::AbstractSensor* sensor, FindGraph*& find) = 0;
};
}

#endif // SGRAPHSIMULATOR_H

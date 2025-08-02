#ifndef STDSIMULATOR_H
#define STDSIMULATOR_H
#include "SGraphSimulator.h"
#include "simvisitor.h"
#include "Sensor/abstractsensor.h"
#include "View/sensorwidget.h"
namespace View::GraphRenderer{
class StdSimulator:public SGraphSimulator{
private:
    SimVisitor simulation_visitor;
public:
    void simulate(Sensor::AbstractSensor* sensor, FindGraph*& find)override;
};
}
#endif // STDSIMULATOR_H

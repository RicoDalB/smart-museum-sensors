#ifndef SVISITOR_H
#define SVISITOR_H

namespace Sensor {

class Co2Sensor;
class HumiditySensor;
class TemperatureSensor;

class SVisitor{
public:
    virtual ~SVisitor() = default;
    virtual void visit(Co2Sensor& CSensor) = 0;
    virtual void visit(HumiditySensor& HSensor) = 0;
    virtual void visit(TemperatureSensor& TSensor) = 0;
};


}
#endif // SVISITOR_H

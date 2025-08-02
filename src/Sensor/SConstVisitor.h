#ifndef SCONSTVISITOR_H
#define SCONSTVISITOR_H

namespace Sensor {

class Co2Sensor;
class HumiditySensor;
class TemperatureSensor;

class SConstVisitor{
public:
    virtual ~SConstVisitor() = default;
    virtual void visit(const Co2Sensor& CSensor) = 0;
    virtual void visit(const HumiditySensor& HSensor) = 0;
    virtual void visit(const TemperatureSensor& TSensor) = 0;
};


}


#endif // SCONSTVISITOR_H

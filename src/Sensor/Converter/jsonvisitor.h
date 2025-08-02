#ifndef JSONVISITOR_H
#define JSONVISITOR_H

#include <QJsonObject>
#include"../SConstVisitor.h"
#include "../co2sensor.h"
#include "../humiditysensor.h"
#include "../temperaturesensor.h"

namespace Sensor::Converter {


class JsonVisitor: public SConstVisitor{
private:
    QJsonObject object;
public:
    QJsonObject getObject() const;
    void visit(const Co2Sensor& co2)override;
    void visit(const HumiditySensor& humidity)override;
    void visit(const TemperatureSensor& temperature)override;
};
}

#endif // JSONVISITOR_H

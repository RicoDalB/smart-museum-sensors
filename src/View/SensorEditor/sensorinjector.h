#ifndef SENSORINJECTOR_H
#define SENSORINJECTOR_H
#include "../../Sensor/SConstVisitor.h"
#include "co2sensoreditor.h"
#include "temperaturesensoreditor.h"
#include "humiditysensoreditor.h"
namespace View::SensorEditor {
class SensorInjector:public Sensor::SConstVisitor{
private:
    Co2SensorEditor& Co2_editor;
    HumiditySensorEditor& humidity_editor;
    TemperatureSensorEditor& temperature_editor;
public:
    SensorInjector(
        Co2SensorEditor& Co2_editor,
        HumiditySensorEditor& humidity_editor,
        TemperatureSensorEditor& temperature_editor
        );
    void visit(const Sensor::Co2Sensor& Co2) override;
    void visit(const Sensor::HumiditySensor& Humidity) override;
    void visit(const Sensor::TemperatureSensor& Temperature) override;
};
}
#endif // SENSORINJECTOR_H

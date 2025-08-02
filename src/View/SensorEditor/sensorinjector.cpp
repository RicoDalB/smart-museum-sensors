#include "sensorinjector.h"
namespace View::SensorEditor {
SensorInjector::SensorInjector(
    Co2SensorEditor& Co2_editor,
    HumiditySensorEditor& humidity_editor,
    TemperatureSensorEditor& temperature_editor
    ):Co2_editor(Co2_editor), humidity_editor(humidity_editor), temperature_editor(temperature_editor){}

void SensorInjector::visit(const Sensor::Co2Sensor& Co2_sensor){
    Co2_editor.setValues(Co2_sensor);
}
void SensorInjector::visit(const Sensor::HumiditySensor& humidity_sensor){
    humidity_editor.setValues(humidity_sensor);
}
void SensorInjector::visit(const Sensor::TemperatureSensor& temperature_sensor){
    temperature_editor.setValues(temperature_sensor);
}
}


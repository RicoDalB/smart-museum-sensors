#ifndef TEMPERATURESENSOREDITOR_H
#define TEMPERATURESENSOREDITOR_H
#include "abstractsensoreditor.h"
#include"../../Sensor/temperaturesensor.h"
#include <QDoubleSpinBox>
#include <QComboBox>
namespace View::SensorEditor {
class TemperatureSensorEditor: public AbstractSensorEditor{
private:
    QDoubleSpinBox* min;
    QDoubleSpinBox* max;
    QDoubleSpinBox* initial;
    Sensor::Enviroment::Temperature min_temp;
    Sensor::Enviroment::Temperature max_temp;
    Sensor::Enviroment::Temperature initial_temp;

public:
    explicit TemperatureSensorEditor(QWidget* parent = 0);
    ~TemperatureSensorEditor() override;
    Sensor::AbstractSensor* create(unsigned int identifier,
                                   const QString &name,
                                   const QString &stanza,
                                   unsigned int DataN) const override;
    void setValues(const Sensor::TemperatureSensor& temperature_sensor);
};
}

#endif // TEMPERATURESENSOREDITOR_H

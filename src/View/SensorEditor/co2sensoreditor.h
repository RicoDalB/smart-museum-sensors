#ifndef CO2SENSOREDITOR_H
#define CO2SENSOREDITOR_H
#include <QWidget>
#include <QDoubleSpinBox>
#include "abstractsensoreditor.h"

namespace View::SensorEditor {
class Co2SensorEditor: public AbstractSensorEditor{
private:
    QDoubleSpinBox* initial;
public:
    explicit Co2SensorEditor(QWidget* parent = 0);
    ~Co2SensorEditor() override;
    Sensor::AbstractSensor* create(
                unsigned int identifier,
                const QString& name,
                const QString& stanza,
                unsigned  int DataN) const override;
    void setValues(const Sensor::Co2Sensor& Co2_sensor);
};
}
#endif // CO2SENSOREDITOR_H

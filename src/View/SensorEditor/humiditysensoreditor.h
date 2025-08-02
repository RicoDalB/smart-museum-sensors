#ifndef HUMIDITYSENSOREDITOR_H
#define HUMIDITYSENSOREDITOR_H
#include "abstractsensoreditor.h"
#include "../../Sensor/humiditysensor.h"
#include <QDoubleSpinBox>
namespace View::SensorEditor {
class HumiditySensorEditor: public AbstractSensorEditor{
private:
    QDoubleSpinBox* initial;
public:
    explicit HumiditySensorEditor(QWidget* parent = 0);
    ~HumiditySensorEditor() override;
    Sensor::AbstractSensor* create(unsigned int identifier,
                                   const QString &name,
                                   const QString &stanza,
                                   unsigned int DataN) const override;
    void setValues(const Sensor::HumiditySensor& humidity_sensor);
};
}
#endif // HUMIDITYSENSOREDITOR_H

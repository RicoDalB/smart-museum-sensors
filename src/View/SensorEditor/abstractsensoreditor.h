#ifndef ABSTRACTSENSOREDITOR_H
#define ABSTRACTSENSOREDITOR_H

#include <QWidget>
#include <QString>
#include "../../Sensor/abstractsensor.h"

namespace View::SensorEditor {
class AbstractSensorEditor: public QWidget{
private:
    Q_OBJECT
public:
    explicit AbstractSensorEditor(QWidget* parent = 0);
    ~AbstractSensorEditor() override;
    virtual Sensor::AbstractSensor* create(
        unsigned int identifier,
        const QString& name,
        const QString& stanza,
        unsigned int DataN
        )const = 0;
};
}
#endif // ABSTRACTSENSOREDITOR_H

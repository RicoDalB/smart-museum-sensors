#ifndef SREADER_H
#define SREADER_H

#include <QJsonObject>
#include "../abstractsensor.h"

namespace Sensor::Converter {
class SReader{
public:
    virtual ~SReader() = default;
    virtual AbstractSensor* read(const QJsonObject& object) = 0;
};
}

#endif // SREADER_H

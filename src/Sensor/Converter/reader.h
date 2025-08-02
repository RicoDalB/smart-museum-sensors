#ifndef READER_H
#define READER_H
#include <map>
#include <QJsonObject>
#include "SReader.h"

namespace Sensor::Converter {

class Reader: public SReader{
private:
    std::map<unsigned int, AbstractSensor*> cache;
    static AbstractSensor* readCo2(const QJsonObject& object);
    static AbstractSensor* readHumidity(const QJsonObject& object);
    static AbstractSensor* readTemperature(const QJsonObject& object);

public:
    const std::map<unsigned int, AbstractSensor*>& getCache() const;
    Reader& clear();
    AbstractSensor* read(const QJsonObject& object) override;
};
}
#endif // READER_H

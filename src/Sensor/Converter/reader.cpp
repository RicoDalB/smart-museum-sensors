#include "reader.h"
#include "../co2sensor.h"
#include "../humiditysensor.h"
#include "../temperaturesensor.h"

namespace Sensor::Converter{

const std::map<unsigned int, AbstractSensor*>& Reader::getCache() const{
    return cache;
}
Reader& Reader::clear(){
    cache.clear();
    return *this;
}
AbstractSensor* Reader::read(const QJsonObject &object){
    QJsonValue type = object.value("type");
    if(type.isUndefined()){
        throw std::invalid_argument("missing type");
    }
    const unsigned int identifier = object.value("id").toInt();
    if(cache.count(identifier) > 0){
        return cache[identifier];
    }
    else if(type.toString().compare("Co2_sensor") == 0){
        cache[identifier] = readCo2(object);
    }
    else if(type.toString().compare("humidity_sensor") == 0){
        cache[identifier] = readHumidity(object);
    }
    else if(type.toString().compare("temperature_sensor") == 0){
        cache[identifier] = readTemperature(object);
    }
    else{
        throw std::invalid_argument("unknown type");
    }
    return cache[identifier];
}
AbstractSensor* Reader::readCo2(const QJsonObject& object){
    return new Co2Sensor(
        object.value("id").toInt(),
        object.value("name").toString().toStdString(),
        object.value("stanza").toString().toStdString(),
        object.value("dataNumber").toInt(),
        Sensor::Enviroment::Co2(object.value("initial ppm").toDouble(), true)
        );
}
AbstractSensor* Reader::readHumidity(const QJsonObject& object){
    return new HumiditySensor(
        object.value("id").toInt(),
        object.value("name").toString().toStdString(),
        object.value("stanza").toString().toStdString(),
        object.value("dataNumber").toInt(),
        Sensor::Enviroment::Humidity(object.value("initial humidity").toDouble())
        );
}
AbstractSensor* Reader::readTemperature(const QJsonObject& object){
    return new TemperatureSensor(
        object.value("id").toInt(),
        object.value("name").toString().toStdString(),
        object.value("stanza").toString().toStdString(),
        object.value("dataNumber").toInt(),
        Sensor::Enviroment::Temperature(object.value("initial min temp").toDouble()),
        Sensor::Enviroment::Temperature(object.value("initial max temp").toDouble()),
        Sensor::Enviroment::Temperature(object.value("initial temperature").toDouble())
        );
}
}

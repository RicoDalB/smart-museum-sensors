#include "jsonvisitor.h"

namespace Sensor::Converter {

QJsonObject JsonVisitor::getObject()const{
    return object;
}
void JsonVisitor::visit(const Co2Sensor& co2){
    QJsonObject co2_sens_object;
    co2_sens_object.insert("type", QJsonValue::fromVariant("Co2_sensor"));
    co2_sens_object.insert("id", QJsonValue::fromVariant(co2.getId()));
    co2_sens_object.insert("name", QJsonValue::fromVariant(co2.getName().c_str()));
    co2_sens_object.insert("stanza", QJsonValue::fromVariant(co2.getStanza().c_str()));
    co2_sens_object.insert("dataNumber", QJsonValue::fromVariant(co2.getDataN()));
    co2_sens_object.insert("initial ppm", QJsonValue::fromVariant(co2.getCInitial().getPpm()));
    object = co2_sens_object;
}
void JsonVisitor::visit(const HumiditySensor& humidity) {
    QJsonObject humidity_sens_object;
    humidity_sens_object.insert("type",QJsonValue::fromVariant("humidity_sensor"));
    humidity_sens_object.insert("id",QJsonValue::fromVariant(humidity.getId()));
    humidity_sens_object.insert("name",QJsonValue::fromVariant(humidity.getName().c_str()));
    humidity_sens_object.insert("stanza",QJsonValue::fromVariant(humidity.getStanza().c_str()));
    humidity_sens_object.insert("dataNumber",QJsonValue::fromVariant(humidity.getDataN()));
    humidity_sens_object.insert("initial humidity",QJsonValue::fromVariant(humidity.getHInitial().getHumidity()));
    object = humidity_sens_object;
}
void JsonVisitor::visit(const TemperatureSensor& temperature){
    QJsonObject temp_sens_object;
    temp_sens_object.insert("type",QJsonValue::fromVariant("temperature_sensor"));
    temp_sens_object.insert("id",QJsonValue::fromVariant(temperature.getId()));
    temp_sens_object.insert("name",QJsonValue::fromVariant(temperature.getName().c_str()));
    temp_sens_object.insert("stanza",QJsonValue::fromVariant(temperature.getStanza().c_str()));
    temp_sens_object.insert("dataNumber",QJsonValue::fromVariant(temperature.getDataN()));
    temp_sens_object.insert("initial min temp",QJsonValue::fromVariant(temperature.getTmin().getTemp()));
    temp_sens_object.insert("initial max temp",QJsonValue::fromVariant(temperature.getTmax().getTemp()));
    temp_sens_object.insert("initial temperature",QJsonValue::fromVariant(temperature.getTInitial().getTemp()));
    object = temp_sens_object;

}

}

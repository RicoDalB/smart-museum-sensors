#include "abstractsensor.h"
#include <utility>

namespace Sensor {

AbstractSensor::AbstractSensor(unsigned int id, std::string n, std::string s, unsigned int dn):
    identifier(id), name(std::move(n)), stanza(std::move(s)), DataN(dn) {}

AbstractSensor::~AbstractSensor() = default;
unsigned int AbstractSensor::getId()const{
    return identifier;
}
const std::string& AbstractSensor::getName() const{
    return name;
}
const std::string& AbstractSensor::getStanza() const{
    return stanza;
}
unsigned int AbstractSensor::getDataN() const {
    return DataN;
}
AbstractSensor& AbstractSensor::setName(const std::string& Nstr){
    this->name = Nstr;
    return *this;
}
AbstractSensor& AbstractSensor::setStanza(const std::string &Sstr){
    this -> stanza = Sstr;
    return *this;
}
AbstractSensor& AbstractSensor::setDataN(const unsigned int dn){
    this ->DataN = dn;
    return *this;
}

}


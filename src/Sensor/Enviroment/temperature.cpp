#include "temperature.h"

namespace Sensor::Enviroment {

Temperature::Temperature(double temp): temperature(temp) {}

Temperature::operator double() const{
    return temperature;
}
Temperature& Temperature::setTemp(const double t){
    this -> temperature = t;
    return *this;
}
double Temperature::getTemp()const{
    return temperature;
}


}

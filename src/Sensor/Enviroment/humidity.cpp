#include "humidity.h"
namespace Sensor::Enviroment {

Humidity::Humidity(double h): humidity(h) {}
Humidity::operator double() const{
    return humidity;
}
double Humidity::getHumidity()const {
    return humidity;
}
Humidity& Humidity::setHumidity(const double h){
    this -> humidity = h;
    return *this;
}


}

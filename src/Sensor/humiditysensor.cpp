#include "humiditysensor.h"
#include <utility>

namespace Sensor {


HumiditySensor::HumiditySensor(unsigned int id, std::string  n, std::string s, unsigned int dn,
                               Enviroment::Humidity init):
    AbstractSensor(id,std::move(n), std::move(s), dn), initial(init){}
Enviroment::Humidity HumiditySensor::getHInitial() const{
    return initial;
}
HumiditySensor& HumiditySensor::setHInitial(const Enviroment::Humidity init){
    this -> initial = init;
    return *this;
}
void HumiditySensor::accept(SConstVisitor &visitor) const {
    visitor.visit(*this);
}
void HumiditySensor::accept(SVisitor &visitor){
    visitor.visit(*this);
}
std::vector<double> HumiditySensor::getHData() const{
    std::vector<double> humidity_data;
    for(const auto & it : humidities){
        humidity_data.push_back(it.getHumidity());
    }
    return humidity_data;
}

void HumiditySensor::simulate(){
    humidities.clear();
    humidities.push_back(initial);
    double val = initial.getHumidity();
    std::random_device rand;
    std::mt19937 gen(rand());

    std::normal_distribution<> dis(0.0, 80);
    for(unsigned int i = 0; i < DataN; ++i){
        val = dis(gen);
        val = std::max(0.0, val);

        Sensor::Enviroment::Humidity new_data(val);
        humidities.push_back(new_data);
    }
}
void HumiditySensor::clear(){
    humidities.clear();
}

const Enviroment::Humidity HumiditySensor::min = Enviroment::Humidity(0.0);
const Enviroment::Humidity HumiditySensor::max = Enviroment::Humidity(100.0);



}

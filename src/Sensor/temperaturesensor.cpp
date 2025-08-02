#include "temperaturesensor.h"
#include <utility>

namespace Sensor {

TemperatureSensor::TemperatureSensor(unsigned int id,
                                     std::string  n,
                                     std::string  s,
                                     unsigned int dn,
                                     Enviroment::Temperature mn,
                                     Enviroment::Temperature mx,
                                     Enviroment::Temperature init
                                     ):
    AbstractSensor(id,std::move(n),std::move(s),dn),
    min(mn), max(mx), initial(init) {}


Enviroment::Temperature TemperatureSensor::getTmin() const{
    return min;
}
TemperatureSensor& TemperatureSensor::setTmin(const Enviroment::Temperature m){
    this -> min = m;
    return *this;
}
Enviroment::Temperature TemperatureSensor::getTmax() const{
    return max;
}
TemperatureSensor& TemperatureSensor::setTmax(const Enviroment::Temperature m){
    this -> max = m;
    return *this;
}
Enviroment::Temperature TemperatureSensor::getTInitial() const{
    return initial;
}
TemperatureSensor& TemperatureSensor::getTInitial(const Enviroment::Temperature init){
    this -> initial = init;
    return *this;
}
void TemperatureSensor::accept(SConstVisitor &visitor) const {
    visitor.visit(*this);
}
void TemperatureSensor::accept(SVisitor &visitor){
    visitor.visit(*this);
}


std::vector<double> TemperatureSensor::getTdataMin() const{
    std::vector<double> min_data;
    for (const auto & it : min_temp){
        min_data.push_back( it.getTemp() );
    }
    return min_data;
}

std::vector<double> TemperatureSensor::getTdataMax() const{
    std::vector<double> max_data;
    for (const auto & it : max_temp) {
        max_data.push_back( it.getTemp());
    }
    return max_data;
}

std::vector<double> TemperatureSensor::getTdataAv() const{
    std::vector<double> av_data;
    for (const auto & it : av_temp) {
        av_data.push_back( it.getTemp() );
    }
    return av_data;
}

void TemperatureSensor::simulate(){
    min_temp.clear();
    max_temp.clear();
    av_temp.clear();
    min_temp.push_back(initial);
    max_temp.push_back(initial);
    av_temp.push_back(initial);

    double val_min = initial.getTemp();
    double val_max = initial.getTemp();
    double val_av = initial.getTemp();

    std::random_device rand;
    std::mt19937 gen(rand());
    std::normal_distribution<> max_d(20, 40);
    std::normal_distribution<> min_d(0, 25 );
    //std::normal_distribution<> av_d(10, 30);
    for(unsigned int i = 0; i < DataN; ++i){
        val_min = min_d(gen);
        val_max = max_d(gen);
        //val_av = av_d(gen);
        val_av = (val_min + val_max) / 2;
        Sensor::Enviroment::Temperature dat_min(val_min);
        Sensor::Enviroment::Temperature dat_max(val_max);
        Sensor::Enviroment::Temperature dat_av(val_av);

        min_temp.push_back(dat_min);
        max_temp.push_back(dat_max);
        av_temp.push_back(dat_av);

    }
}
void TemperatureSensor::clear(){
    min_temp.clear();
    max_temp.clear();
    av_temp.clear();
}





}


#include "co2sensor.h"
#include <utility>
#include <QVector>
#include <vector>
#include <random>

namespace Sensor {

Co2Sensor::Co2Sensor(unsigned int id,
                      std::string  n,
                      std::string s,
                      unsigned int dn,
                      Enviroment::Co2 init
                      ):
                     AbstractSensor(id, std::move(n),std::move(s), dn),
                     initial(init)
                      {}
Enviroment::Co2 Co2Sensor::getCInitial()const{
    return initial;
}
double Co2Sensor::getPpmInitial()const{
    return initial.getPpm();
}
Co2Sensor& Co2Sensor::setCInitial(const Enviroment::Co2 init){
    this->initial = init;
    return *this;
}
Co2Sensor& Co2Sensor::setPpmInitial(const double ppm){
    this ->initial.setPpm(ppm);
    return *this;
}
void Co2Sensor::accept(SConstVisitor& visitor)const{
    visitor.visit(*this);
}
void Co2Sensor::accept(SVisitor& visitor){
    visitor.visit(*this);
}
std::vector<double> Co2Sensor::getPpmData()const{
    std::vector<double> ppm_data;
    for(const auto & it : Co2Data){
        ppm_data.push_back(it.getPpm());
    }
    return ppm_data;
}
std::vector<double> Co2Sensor::getCo2Data()const{
    std::vector<double> Co2_data;
    for(const auto & it : Co2Data){
        Co2_data.push_back(it.getIco2());
    }
    return Co2_data;
}
void Co2Sensor::simulate(){
    Co2Data.clear();
    Co2Data.push_back(initial);
    double val = initial.getPpm();
    std::random_device rand;
    std::mt19937 gen(rand());

    std::normal_distribution<> dis(0.0, 100.0);
    for(unsigned int i = 0; i < DataN; ++i){
        val = dis(gen);
        val = std::max(0.0, val);

        Sensor::Enviroment::Co2 new_data(val, true);
        Co2Data.push_back(new_data);
    }
}
void Co2Sensor::clear(){
    Co2Data.clear();
}



}

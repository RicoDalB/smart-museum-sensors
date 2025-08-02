#include "co2.h"

namespace Sensor::Enviroment {

Co2::Co2(double value, bool isPpm) {
    if(isPpm){
        ppm = value;
        updateCo2();
    }else{
        Co2Index = value;
        updatePpm();
    }
}
double Co2::getPpm() const{
    return ppm;
}
Co2& Co2::setPpm(const double Ppm){
    this -> ppm = Ppm;
    updatePpm();
    return *this;
}
double Co2::getIco2() const{
    return Co2Index;
}
Co2& Co2::setIndexCo2(const double Ico2){
    this -> Co2Index = Ico2;
    updatePpm();
    return *this;
}
Co2::operator double() const{
    return Co2Index;
}
void Co2::updatePpm(){
    ppm = (Co2Index * 1000000) / 100;
}
void Co2::updateCo2(){
    Co2Index = (ppm*100)/ 1000000;
}


}


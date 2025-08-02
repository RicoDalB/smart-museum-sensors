#include "sensorlist.h"
#include <algorithm>

namespace Engine {
SensorList::SensorList():sensors(){}
SensorList::~SensorList(){clear();}

SensorList& SensorList::add(const Sensor::AbstractSensor *sen){
    sensors.push_back(sen);
    return *this;
}
SensorList& SensorList::remove(const Sensor::AbstractSensor *sen){
    for(auto it = sensors.begin(); it != sensors.end(); ++it){
        if(*it == sen){
            sensors.erase(it);
            return *this;

        }
    }
    return *this;
}
SensorList& SensorList::removeAndDelete(const Sensor::AbstractSensor *sen){
    for(auto it = sensors.begin(); it != sensors.end(); ++it) {
        if(*it == sen) {
            sensors.erase(it);
            delete sen;
            return *this;
        }
    }
    return *this;
}

SensorList& SensorList::erase(const Sensor::AbstractSensor* sen){
    for(auto it = sensors.begin(); it != sensors.end(); ++it){
        if(*it == sen){
            sensors.erase(it);
            return *this;
        }
    }
    return *this;
}
bool SensorList::isEmpty(){
    return sensors.empty();
}
SensorList& SensorList::clear(){
    for(auto it = sensors.begin(); it != sensors.end(); ++it){
        *it = nullptr;
    }
    sensors.clear();
    return *this;
}
SensorList& SensorList::clean(){
    sensors.clear();
    return *this;
}
bool SensorList::find(const Sensor::AbstractSensor *sen) const{
    for(std::list<const Sensor::AbstractSensor*>::const_iterator it = sensors.begin(); it != sensors.end(); ++it){
        const Sensor::AbstractSensor* current = *it;
        if(current->getId() == sen->getId()) return true;
    }
    return false;
}
std::list<const Sensor::AbstractSensor*>::const_iterator SensorList::begin()const{
    return sensors.begin();
}
std::list<const Sensor::AbstractSensor*>::const_iterator SensorList::end()const{
    return sensors.end();
}
SensorList& SensorList::sortId(){
    sensors.sort([](const Sensor::AbstractSensor* x, const Sensor::AbstractSensor* y){
        return x->getId() < y->getId();
    });
    return *this;
}
SensorList& SensorList::sortName(){
    sensors.sort([](const Sensor::AbstractSensor* x, const Sensor::AbstractSensor* y){
        return x->getName() < y->getName();
    });
    return *this;
}
SensorList& SensorList::sortStanza(){
    sensors.sort([](const Sensor::AbstractSensor* x, const Sensor::AbstractSensor* y){
        return x->getStanza() <= y->getStanza();
    });
    return *this;
}
unsigned int SensorList::size() const {
    return sensors.size();
}
void SensorList::search(SensorList* result, const std::string& query) const{
    for(std::list<const Sensor::AbstractSensor*>::const_iterator it = sensors.begin(); it != sensors.end(); ++it){
        std::string id_s = std::to_string((*it)->getId());
        if((id_s).find(query) != std::string::npos || (*it)->getName().find(query) != std::string::npos){
            result->add(*it);
        }
    }

}





}

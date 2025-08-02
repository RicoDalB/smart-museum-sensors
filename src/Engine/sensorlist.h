#ifndef SENSORLIST_H
#define SENSORLIST_H

#include "../Sensor/abstractsensor.h"
#include <list>

namespace Engine {

class SensorList{
private:
    std::list<const Sensor::AbstractSensor*> sensors;
public:
    SensorList();
    ~SensorList();
    SensorList& add(const Sensor::AbstractSensor* sensors);
    SensorList& remove(const Sensor::AbstractSensor* sensors);
    SensorList& removeAndDelete(const Sensor::AbstractSensor* sensors);
    SensorList& erase(const Sensor::AbstractSensor* sensors);
    SensorList& clear();
    SensorList& clean();
    bool find(const Sensor::AbstractSensor* sensors) const;
    SensorList& sortId();
    SensorList& sortName();
    SensorList& sortStanza();
    unsigned int size() const;
    bool isEmpty();

    std::list<const Sensor::AbstractSensor*>& getSensors();
    std::list<const Sensor::AbstractSensor*>::const_iterator begin() const;
    std::list<const Sensor::AbstractSensor*>::const_iterator end() const;
    void search(SensorList* result, const std::string& query) const;

};
}

#endif // SENSORLIST_H

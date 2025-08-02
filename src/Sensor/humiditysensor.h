#ifndef HUMIDITYSENSOR_H
#define HUMIDITYSENSOR_H

#include "abstractsensor.h"
#include "Enviroment/humidity.h"
#include <vector>

namespace Sensor {

class HumiditySensor: public AbstractSensor{
private:
    Enviroment::Humidity initial;
    std::vector<Enviroment::Humidity> humidities;
public:
    static const Enviroment::Humidity min;
    static const Enviroment::Humidity max;
    HumiditySensor(unsigned int id, std::string n, std::string s, unsigned int dn, Enviroment::Humidity init);
    Enviroment::Humidity getHInitial() const;
    HumiditySensor& setHInitial(const Enviroment::Humidity init);
    virtual void accept(SConstVisitor& visitor) const final;
    virtual void accept(SVisitor& visitor) final;
    std::vector<double> getHData() const;
    void simulate() override;
    void clear() override;
};
}
#endif // HUMIDITYSENSOR_H

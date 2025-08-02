#ifndef TEMPERATURESENSOR_H
#define TEMPERATURESENSOR_H
#include "abstractsensor.h"
#include "Enviroment/temperature.h"
#include <vector>

namespace Sensor {


class TemperatureSensor: public AbstractSensor{
private:
    Enviroment::Temperature min;
    Enviroment::Temperature max;
    Enviroment::Temperature initial;
    std::vector<Enviroment::Temperature> av_temp;
    std::vector<Enviroment::Temperature> min_temp;
    std::vector<Enviroment::Temperature> max_temp;
public:
    TemperatureSensor(unsigned int id,
                      std::string  n,
                      std::string s,
                      unsigned int dn,
                      Enviroment::Temperature mn,
                      Enviroment::Temperature mx,
                      Enviroment::Temperature init
                      );


    Enviroment::Temperature getTmin() const;
    TemperatureSensor& setTmin(const Enviroment::Temperature m);
    Enviroment::Temperature getTmax() const;
    TemperatureSensor& setTmax(const Enviroment::Temperature m);
    Enviroment::Temperature getTInitial() const;
    TemperatureSensor& getTInitial(const Enviroment::Temperature init);
    virtual void accept(SConstVisitor& visitor) const final;
    virtual void accept(SVisitor& visitor) final;
    std::vector<double>getTdataMin() const;
    std::vector<double>getTdataMax() const;
    std::vector<double> getTdataAv() const;
    void simulate() override;
    void clear() override;




};
}

#endif // TEMPERATURESENSOR_H

#ifndef CO2SENSOR_H
#define CO2SENSOR_H
#include "abstractsensor.h"
#include "Enviroment/co2.h"
#include <vector>

namespace Sensor {

class Co2Sensor: public AbstractSensor{

private:
    Enviroment::Co2 initial;
    std::vector<Enviroment::Co2> Co2Data;
public:
    Co2Sensor(unsigned int id,
              std::string  n,
              std::string s,
              unsigned int dn,
              Enviroment::Co2 init
              );
    Enviroment::Co2 getCInitial()const;
    double getPpmInitial()const;
    Co2Sensor& setCInitial(const Enviroment::Co2 init);
    Co2Sensor& setPpmInitial(const double ppm);
    virtual void accept(SConstVisitor& visitor)const final;
    virtual void accept(SVisitor& visitor) final;
    std::vector<double> getPpmData()const;
    std::vector<double> getCo2Data()const;
    void simulate() override;
    void clear() override;


};

}
#endif // CO2SENSOR_H

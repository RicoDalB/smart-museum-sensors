#ifndef HUMIDITY_H
#define HUMIDITY_H
namespace Sensor::Enviroment {

class Humidity{
private:
    double humidity;
public:
    Humidity(double h);
    explicit operator double() const;
    double getHumidity() const;
    Humidity& setHumidity(const double h);
};
}
#endif // HUMIDITY_H

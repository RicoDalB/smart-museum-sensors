#ifndef TEMPERATURE_H
#define TEMPERATURE_H


namespace Sensor::Enviroment {


class Temperature{
private:
    double temperature;

public:
    Temperature(double temp);
    explicit operator double() const;

    Temperature& setTemp(const double t);
    double getTemp() const;

    static const double minTemp;
};
}
#endif // TEMPERATURE_H

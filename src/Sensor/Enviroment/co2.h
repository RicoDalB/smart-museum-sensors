#ifndef CO2_H
#define CO2_H

namespace Sensor::Enviroment {

class Co2 {
private:
    double Co2Index;
    double ppm;
    void updatePpm();
    void updateCo2();
public:
    Co2(double value, bool isPpm);
    double getPpm()const;
    Co2& setPpm(const double Ppm);
    double getIco2() const;
    Co2& setIndexCo2(const double Ico2);
    explicit operator double() const;
};
}
#endif // CO2_H

#ifndef ABSTRACTSENSOR_H
#define ABSTRACTSENSOR_H
#include <string>
#include <iostream>
#include <random>
#include "SConstVisitor.h"
#include "SVisitor.h"

namespace Sensor {


class AbstractSensor{
private:
    unsigned int identifier;
    std::string name;
    std::string stanza;
protected:
    unsigned int DataN;
public:
    AbstractSensor(unsigned int  id, std::string n, std::string s, unsigned int dn);
    virtual ~AbstractSensor();
    unsigned int getId() const;
    const std::string& getName() const;
    const std::string& getStanza() const;
    unsigned int getDataN() const;
    AbstractSensor& setName(const std::string& Nstr);
    AbstractSensor& setStanza(const std::string& Sstr);
    AbstractSensor& setDataN(const unsigned int dn);
    virtual void accept(SConstVisitor& visitor) const = 0;
    virtual void accept(SVisitor& visitor) = 0;

    virtual void simulate() = 0;
    virtual void clear() = 0;
};
}

#endif // ABSTRACTSENSOR_H

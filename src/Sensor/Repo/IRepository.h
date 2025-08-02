#ifndef IREPOSITORY_H
#define IREPOSITORY_H

#include <vector>
#include "../abstractsensor.h"

namespace Sensor::Repo {
class IRepository{
public:
    virtual ~IRepository() = default;
    virtual IRepository& create(AbstractSensor *item) = 0;
    virtual AbstractSensor* read(const unsigned int identifier)const = 0;
    virtual IRepository& update(AbstractSensor* item) = 0;
    virtual IRepository& remove(const unsigned int identifier) = 0;
    virtual std::vector<AbstractSensor*> readAll() const = 0;
};

}

#endif // IREPOSITORY_H

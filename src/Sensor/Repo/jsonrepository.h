#ifndef JSONREPOSITORY_H
#define JSONREPOSITORY_H

#include "IRepository.h"
#include <string>
#include <map>
#include "../DataMapper/jsonfile.h"
#include "../Converter/reader.h"

namespace Sensor::Repo {

class JsonRepository: public IRepository{
private:
    DataMapper::JsonFile data_mapper;
    std::map<unsigned int, AbstractSensor*> repository;
public:
    explicit JsonRepository(DataMapper::JsonFile data_mapper);
    ~JsonRepository() override;

    static JsonRepository* fromPath(const std::string path);

    const DataMapper::JsonFile& getDataMapper() const;
    const std::map<unsigned int, AbstractSensor*>& getRepository() const;
    const std::string& getPath() const;
    JsonRepository& setPath(std::string path);
    JsonRepository& create(AbstractSensor* sensor)override;
    AbstractSensor* read(const unsigned int identifier) const override;
    JsonRepository& update(AbstractSensor* item)override;
    JsonRepository& remove(const unsigned int identifier); //rimuove e dealloca
    virtual JsonRepository& erase(const unsigned int identifier); // rimuove e basta
    virtual std::vector<AbstractSensor*>readAll() const;
    JsonRepository& store();
    bool empty() const;

};

}
#endif // JSONREPOSITORY_H

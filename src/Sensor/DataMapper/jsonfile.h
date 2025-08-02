#ifndef JSONFILE_H
#define JSONFILE_H
#include <string>
#include <vector>
#include"../abstractsensor.h"
#include "../Converter/json.h"
#include "../Converter/reader.h"

namespace Sensor::DataMapper {

class JsonFile{
private:
    std::string path;
    Converter::Json& converter;
public:
    JsonFile(std::string path, Converter::Json& converter);
    static JsonFile fromPath(const std::string& path);
    const std::string& getPath() const;
    JsonFile& setPath(const std::string& path);
    const Converter::Json& getConverter() const;
    JsonFile& store(const std::vector<AbstractSensor*> items);
    std::vector<AbstractSensor*> load();
};
}

#endif // JSONFILE_H

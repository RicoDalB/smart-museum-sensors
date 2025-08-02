#ifndef TYPESELECTOR_H
#define TYPESELECTOR_H
#include "QtWidgets/QComboBox"
#include "Sensor/SConstVisitor.h"
namespace View{
class TypeSelector: public Sensor::SConstVisitor{
private:
    QComboBox* combo_box;
public:
    explicit TypeSelector(QComboBox* combo_box);
    void visit(const Sensor::Co2Sensor& Co2) override;
    void visit(const Sensor::HumiditySensor& humidity) override;
    void visit(const Sensor::TemperatureSensor& temperature) override;
    QComboBox* getComboBox();
    TypeSelector& setComboBox(QComboBox* combo);
};
}

#endif // TYPESELECTOR_H

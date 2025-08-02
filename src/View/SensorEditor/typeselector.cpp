#include "typeselector.h"
namespace View {
TypeSelector::TypeSelector(QComboBox* combo_box): combo_box(combo_box) {}
void TypeSelector::visit(const Sensor::Co2Sensor& Co2){
    (void) Co2;
    combo_box->setCurrentText("Co2 sensor");
    combo_box->setCurrentIndex(0);
}
void TypeSelector::visit(const Sensor::HumiditySensor& humidity){
    (void) humidity;
    combo_box->setCurrentText("Humidity sensor");
    combo_box->setCurrentIndex(1);
}
void TypeSelector::visit(const Sensor::TemperatureSensor& temperature){
    (void) temperature;
    combo_box->setCurrentText("Temperature sensor");
    combo_box->setCurrentIndex(2);
}
QComboBox* TypeSelector::getComboBox(){
    return combo_box;
}
TypeSelector& TypeSelector::setComboBox(QComboBox* combo){
    this->combo_box = combo;
    return *this;
}
}

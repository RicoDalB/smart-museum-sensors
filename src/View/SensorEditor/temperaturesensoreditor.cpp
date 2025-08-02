#include "temperaturesensoreditor.h"
#include <QFormLayout>
namespace View::SensorEditor {

TemperatureSensorEditor::TemperatureSensorEditor(QWidget* parent): AbstractSensorEditor(parent),
    min_temp(0), max_temp(0), initial_temp(0){

    QFormLayout* form = new QFormLayout(this);
    form->setObjectName("temperature form");
    form -> setLabelAlignment(Qt::AlignRight| Qt::AlignVCenter);

    min = new QDoubleSpinBox();
    min->setObjectName("min");
    min->setMinimum(-273);
    min->setValue(-10);
    min->setDecimals(5);
    min->setMaximum(std::numeric_limits<double>::max());
    form->addRow("min: ", min);

    max = new QDoubleSpinBox();
    max->setObjectName("max");
    max->setMinimum(-273);
    max->setValue(10);
    max->setDecimals(5);
    max->setMaximum(std::numeric_limits<double>::max());
    form->addRow("max: ", max);

    initial = new QDoubleSpinBox();
    initial->setObjectName("initial");
    initial->setMinimum(-273);
    initial->setDecimals(5);
    initial->setMaximum(std::numeric_limits<double>::max());
    form->addRow("initial: ", initial);

}
TemperatureSensorEditor::~TemperatureSensorEditor() = default;

Sensor::AbstractSensor* TemperatureSensorEditor::create(unsigned int i,
                                                        const QString& n,
                                                        const QString& s,
                                                        unsigned int dn) const{
    return new Sensor::TemperatureSensor(
        i,n.toStdString(), s.toStdString(), dn,
        Sensor::Enviroment::Temperature(min->value()),
        Sensor::Enviroment::Temperature(max->value()),
        Sensor::Enviroment::Temperature(initial->value()));
}

void TemperatureSensorEditor::setValues(const Sensor::TemperatureSensor& temperature_sensor){
    min_temp = (temperature_sensor.getTmin());
    max_temp = (temperature_sensor.getTmax());
    initial_temp = (temperature_sensor.getTInitial());
}























}

#include "humiditysensoreditor.h"
#include "abstractsensoreditor.h"
#include <QFormLayout>
namespace View::SensorEditor {

HumiditySensorEditor::HumiditySensorEditor(QWidget* parent): AbstractSensorEditor(parent) {
    QFormLayout* form = new QFormLayout(this);
    form -> setObjectName("Humidity Form");
    form -> setLabelAlignment(Qt::AlignRight | Qt::AlignVCenter);

    initial = new QDoubleSpinBox();
    initial->setObjectName("initial humidity");
    initial->setSuffix("%");
    initial->setRange(0,100);
    initial->setDecimals(5);
    form->addRow("initial humidity: ", initial);

}
HumiditySensorEditor::~HumiditySensorEditor() = default;
Sensor::AbstractSensor* HumiditySensorEditor::create(unsigned int i,
                                                     const QString& n,
                                                     const QString& s,
                                                     unsigned int dn) const {
    return new Sensor::HumiditySensor(
        i, n.toStdString(), s.toStdString(), dn, Sensor::Enviroment::Humidity(initial->value())
        );
}
void HumiditySensorEditor::setValues(const Sensor::HumiditySensor& humidity_sensor){
    initial->setValue(double(humidity_sensor.getHInitial()));
}

}

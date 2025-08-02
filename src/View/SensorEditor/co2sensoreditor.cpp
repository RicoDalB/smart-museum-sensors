#include "co2sensoreditor.h"
#include <QFormLayout>
#include "../../Sensor/co2sensor.h"
#include "abstractsensoreditor.h"

namespace View::SensorEditor {

Co2SensorEditor::Co2SensorEditor(QWidget* parent): AbstractSensorEditor(parent) {
    QFormLayout* form = new QFormLayout(this);
    form -> setObjectName("Co2Form");
    form->setLabelAlignment(Qt::AlignRight | Qt::AlignVCenter);

    initial = new QDoubleSpinBox();
    initial->setObjectName("Set Initial Ppm");
    initial->setMinimum(0);
    initial->setDecimals(4);
    initial->setMaximum(std::numeric_limits<double>::max());
    form->addRow("initial ppm:", initial);

}
Co2SensorEditor::~Co2SensorEditor() = default;

Sensor::AbstractSensor* Co2SensorEditor::create(
    const unsigned int i,
    const QString& n,
    const QString& s,
    const unsigned int dn
)const{
    return new Sensor::Co2Sensor(
        i,
        n.toStdString(),
        s.toStdString(),
        dn,
        Sensor::Enviroment::Co2(initial->value(), true)
        );
}
void Co2SensorEditor::setValues(const Sensor::Co2Sensor& Co2_sensor){
    initial->setValue(Co2_sensor.getPpmInitial());
}
}

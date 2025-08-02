#ifndef FINDWIDGET_H
#define FINDWIDGET_H
#include "QtWidgets/QWidget"
#include "QtWidgets/QPushButton"
#include "Sensor/abstractsensor.h"

namespace View {
class FindWidget{
private:
    const Sensor::AbstractSensor* sensor;
    QWidget* widget;
    QPushButton* view_button;
    QPushButton* edit_button;
    QPushButton* delete_button;
public:
    FindWidget(
        const Sensor::AbstractSensor* sensor,
        QWidget* widget,
        QPushButton* view_button,
        QPushButton* edit_button,
        QPushButton* delete_button
        );
    const Sensor::AbstractSensor* getSensor() const;
    QWidget* getWidget() const;
    QPushButton* getViewButton() const;
    QPushButton* getEditButton() const;
    QPushButton* getDeleteButton() const;
};
}

#endif // FINDWIDGET_H

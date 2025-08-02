#ifndef SLISTSTRATEGY_H
#define SLISTSTRATEGY_H
#include "QtWidgets/QWidget"
#include "QtWidgets/QPushButton"
#include "Sensor/abstractsensor.h"
#include "Sensor/SConstVisitor.h"
namespace View::SensorRenderer {
class SListStrategy: public Sensor::SConstVisitor{
public:
    virtual QWidget* getWidget() const = 0;
    virtual QPushButton* getViewButton() const = 0;
    virtual QPushButton* getEditButton() const = 0;
    virtual QPushButton* getDeleteButton() const = 0;
};
}

#endif // SLISTSTRATEGY_H

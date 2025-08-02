#ifndef LISTRENDERSTRATEGY_H
#define LISTRENDERSTRATEGY_H

#include <QGridLayout>
#include <QVector>
#include "View/Find/findwidget.h"
#include"../../Engine/sensorlist.h"
namespace View::ListRenderer {
class ListRenderStrategy{
public:
    virtual ~ListRenderStrategy() = default;
    virtual void render(QGridLayout* grid, Engine::SensorList* list, QVector<FindWidget>* find) = 0;
};






}

#endif // LISTRENDERSTRATEGY_H

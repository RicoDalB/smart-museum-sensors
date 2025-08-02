#ifndef LIST_H
#define LIST_H
#include <QGridLayout>
#include <QVector>
#include <QWidget>

#include "ListRenderStrategy.h"
#include  "listrender.h"
#include "../sensorlistwidget.h"
#include "../../Engine/sensorlist.h"

namespace View::ListRenderer {
class List: public ListRenderStrategy{
private:
    SensorRenderer::ListRender list_sensor;
public:
    void render(QGridLayout* grid, Engine::SensorList* list, QVector<FindWidget>* find) override;
};
}
#endif // LIST_H

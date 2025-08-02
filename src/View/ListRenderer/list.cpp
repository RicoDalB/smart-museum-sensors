#include "list.h"


namespace View::ListRenderer {
void List::render(QGridLayout* grid, Engine::SensorList* list, QVector<FindWidget>* find){
    for(std::list<const Sensor::AbstractSensor*>::const_iterator it = list->begin(); it != list->end(); ++it){
        (*it)->accept(list_sensor);
        QWidget* widget = list_sensor.getWidget();
        grid->addWidget(widget, grid->rowCount(), 0);
        find->push_back(FindWidget(*it,
                                   widget,
                                   list_sensor.getViewButton(),
                                   list_sensor.getEditButton(),
                                   list_sensor.getDeleteButton()));
    }
}
}

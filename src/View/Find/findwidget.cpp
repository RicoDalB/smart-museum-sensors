#include "findwidget.h"


namespace View {


FindWidget::FindWidget(
    const Sensor::AbstractSensor* sensor,
    QWidget* widget,
    QPushButton* view_button,
    QPushButton* edit_button,
    QPushButton* delete_button
    ): sensor(sensor), widget(widget), view_button(view_button), edit_button(edit_button), delete_button(delete_button) {}

const Sensor::AbstractSensor* FindWidget::getSensor()const{
    return sensor;
}
QWidget* FindWidget::getWidget()const{
    return widget;
}

QPushButton* FindWidget::getViewButton()const{
    return view_button;
}
QPushButton* FindWidget::getEditButton()const{
    return edit_button;
}
QPushButton* FindWidget::getDeleteButton()const{
    return delete_button;
}
}

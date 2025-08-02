#include "listrender.h"
#include "QtWidgets/QLabel"
#include "QtWidgets/QGridLayout"
#include "QtWidgets/QGroupBox"
#include "QtWidgets/QPushButton"
#include "Sensor/co2sensor.h"
#include "Sensor/humiditysensor.h"
#include "Sensor/temperaturesensor.h"


namespace View::SensorRenderer {

ListRender::ListRender() {}

void ListRender::visit(const Sensor::Co2Sensor& co2_sen){
    widget = new QGroupBox();
    QGridLayout* grid = new QGridLayout();

    QLabel* icon = new QLabel();
    icon->setPixmap(QIcon(":/Asset/icons/co2.svg").pixmap(15,15));
    QLabel* name = new QLabel("name: " + QString::fromStdString(co2_sen.getName()));
    QLabel* id = new QLabel("id: "+ QString::number(co2_sen.getId()));
    QLabel* stanza = new QLabel("stanza. " + QString::fromStdString(co2_sen.getStanza()));
    view_button = new QPushButton(QIcon(":/Asset/icons/search_new.svg"),"");
    edit_button = new QPushButton(QIcon(":/Asset/icons/Edit.svg"),"");
    delete_button = new QPushButton(QIcon(":/Asset/icons/Delete.svg"),"");

    QHBoxLayout *button_layout = new QHBoxLayout();
    button_layout->addWidget(view_button);
    button_layout->addWidget(edit_button);
    button_layout->addWidget(delete_button);

    QWidget* button_container = new QWidget();
    button_container->setLayout(button_layout);
    //row, column, rowSpan, columnSpan
    grid->addWidget(name, 0, 0, 1, 4);
    grid->addWidget(id, 1, 0, 1 , 2 );
    grid->addWidget(stanza, 1, 3, 1, 2);
    grid->addWidget(button_container, 2, 2, 2 , 2 );
    grid->addWidget(icon,0,4,1,1);
    widget->setLayout(grid);
}
void ListRender::visit(const Sensor::HumiditySensor& humidity){
    widget = new QGroupBox();
    QGridLayout* grid = new QGridLayout();

    QLabel* icon = new QLabel();
    icon->setPixmap(QIcon(":/Asset/icons/hum.svg").pixmap(15,15));
    QLabel* name = new QLabel("name: " + QString::fromStdString(humidity.getName()));
    QLabel* id = new QLabel("id: "+ QString::number(humidity.getId()));
    QLabel* stanza = new QLabel("stanza. " + QString::fromStdString(humidity.getStanza()));
    view_button = new QPushButton(QIcon(":/Asset/icons/search_new.svg"),"");
    edit_button = new QPushButton(QIcon(":/Asset/icons/Edit.svg"),"");
    delete_button = new QPushButton(QIcon(":/Asset/icons/Delete.svg"),"");

    QHBoxLayout *button_layout = new QHBoxLayout();
    button_layout->addWidget(view_button);
    button_layout->addWidget(edit_button);
    button_layout->addWidget(delete_button);

    QWidget* button_container = new QWidget();
    button_container->setLayout(button_layout);
    //row, column, rowSpan, columnSpan
    grid->addWidget(name, 0, 0, 1, 4);
    grid->addWidget(id, 1, 0, 1 , 2 );
    grid->addWidget(stanza, 1, 3, 1, 2);
    grid->addWidget(button_container, 2, 2, 2 , 2 );
    grid->addWidget(icon,0,4,1,1);
    widget->setLayout(grid);
}
void ListRender::visit(const Sensor::TemperatureSensor& temperature){
    widget = new QGroupBox();
    QGridLayout* grid = new QGridLayout();

    QLabel* icon = new QLabel();
    icon->setPixmap(QIcon(":/Asset/icons/temp.svg").pixmap(15,15));
    QLabel* name = new QLabel("name: " + QString::fromStdString(temperature.getName()));
    QLabel* id = new QLabel("id: "+ QString::number(temperature.getId()));
    QLabel* stanza = new QLabel("stanza. " + QString::fromStdString(temperature.getStanza()));
    view_button = new QPushButton(QIcon(":/Asset/icons/search_new.svg"),"");
    edit_button = new QPushButton(QIcon(":/Asset/icons/Edit.svg"),"");
    delete_button = new QPushButton(QIcon(":/Asset/icons/Delete.svg"),"");

    QHBoxLayout *button_layout = new QHBoxLayout();
    button_layout->addWidget(view_button);
    button_layout->addWidget(edit_button);
    button_layout->addWidget(delete_button);

    QWidget* button_container = new QWidget();
    button_container->setLayout(button_layout);
    //row, column, rowSpan, columnSpan
    grid->addWidget(name, 0, 0, 1, 4);
    grid->addWidget(id, 1, 0, 1 , 2 );
    grid->addWidget(stanza, 1, 3, 1, 2);
    grid->addWidget(button_container, 2, 2, 2 , 2 );
    grid->addWidget(icon,0,4,1,1);
    widget->setLayout(grid);
}



QWidget* ListRender::getWidget()const{
    return widget;
}
QPushButton* ListRender::getViewButton() const{
    return view_button;
}
QPushButton* ListRender::getEditButton() const{
    return edit_button;
}
QPushButton* ListRender::getDeleteButton() const{
    return delete_button;
}
}





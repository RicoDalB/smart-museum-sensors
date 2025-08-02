#include "findgraph.h"

#include "QtWidgets/QWidget"
#include "QtWidgets/QPushButton"

namespace View {

FindGraph::FindGraph(
    Sensor::AbstractSensor* sen,
    QWidget* w,
    QLabel* i,
    QLabel* n,
    QLabel* s,
    QLabel* d,
    QPushButton* sim,
    QPushButton* edit,
    QPushButton* clear,
    QChart* c,
    QValueAxis* x,
    QValueAxis* y,
    QChartView* vc):sensor(sen),
    widget(w),
    id(i),
    name(n),
    stanza(s),
    data_name(d),
    simulate_button(sim),
    edit_button(edit),
    clear_button(clear),
    chart(c),
    assX(x),
    assY(y),
    view_chart(vc)
 {}

Sensor::AbstractSensor* FindGraph::getSensor()const{
    return sensor;
}
QWidget* FindGraph::getWidget()const{
    return widget ? widget : nullptr;
}
FindGraph& FindGraph::setWidget(QWidget* w){
    if(w){
        this->widget = w;
    }
    return *this;
}
QLabel* FindGraph::getId()const{
    return id;
}
QLabel* FindGraph::getName()const{
    return name;
}
QLabel* FindGraph::getStanza()const{
    return stanza;
}
QLabel* FindGraph::getDataName()const{
    return data_name;
}
QPushButton* FindGraph::getSimulateButton()const{
    return simulate_button ? simulate_button : nullptr;
}
QPushButton* FindGraph::getEditButton()const{
    return edit_button;
}
QPushButton* FindGraph::getClearButton()const{
    return clear_button;
}
QChart* FindGraph::getChart()const{
    return chart;
}
QValueAxis* FindGraph::getAssX(){
    return assX;
}
QValueAxis* FindGraph::getAssY(){
    return assY;
}
QChartView* FindGraph::getChartView()const{
    return view_chart;
}




}






















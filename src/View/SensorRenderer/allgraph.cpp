#include "allgraph.h"
namespace View::GraphRenderer {
void AllGraph::render(QGridLayout* grid, const Sensor::AbstractSensor* sensor, FindGraph*& find){
    sensor->accept(AllSen);
    find = new FindGraph(
        const_cast<Sensor::AbstractSensor*>(sensor),
        AllSen.getWidget(),
        AllSen.getId(),
        AllSen.getName(),
        AllSen.getStanza(),
        AllSen.getDataNum(),
        AllSen.getSimulateButton(),
        AllSen.getEditButton(),
        AllSen.getClearButton(),
        AllSen.getChart(),
        AllSen.getAssX(),
        AllSen.getAssY(),
        AllSen.getChartView()
        );
    QWidget* widget = AllSen.getWidget();
    grid->addWidget(widget,0,0);
}
}



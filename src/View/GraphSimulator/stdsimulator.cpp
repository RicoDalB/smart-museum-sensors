#include "stdsimulator.h"
namespace View::GraphRenderer{
void StdSimulator::simulate(Sensor::AbstractSensor* sensor, View::FindGraph*& find){
    simulation_visitor.setChart(find->getChart());
    simulation_visitor.setXass(find->getAssX());
    simulation_visitor.setYass(find->getAssY());
    simulation_visitor.setChartView(find->getChartView());

    sensor->clear();
    sensor->simulate();
    sensor->accept(simulation_visitor);
}
}

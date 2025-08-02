#include "sensorwidget.h"
#include "SensorRenderer/allgraph.h"
#include "View/GraphSimulator/stdsimulator.h"
#include "mainwindow.h"
namespace View {
SensorWidget::SensorWidget(QWidget* parent): QWidget(parent), find(nullptr){
    render = new GraphRenderer::AllGraph();
    layout = new QGridLayout(this);
    simulator = new GraphRenderer::StdSimulator();
}
SensorWidget::~SensorWidget(){
    delete render;
    delete simulator;
    if (find) delete find;
}
FindGraph* SensorWidget::getFind(){
    return find;
}
bool SensorWidget::isEmpty()const{
    return layout->isEmpty();
}
void SensorWidget::show(const Sensor::AbstractSensor* sensor){
    //clean();

    if(!sensor){
        qWarning() << "sensor is null in SensorWidget::show";
        return;
    }
    if (!find) {

        QWidget* parentWidget = this;
        QLabel* idLabel = new QLabel(parentWidget);
        QLabel* nameLabel = new QLabel(parentWidget);
        QLabel* stanzaLabel = new QLabel(parentWidget);
        QLabel* dataNameLabel = new QLabel(parentWidget);
        QPushButton* simulateButton = new QPushButton("Simulate", parentWidget);
        QPushButton* editButton = new QPushButton("Edit", parentWidget);
        QPushButton* clearButton = new QPushButton("Clear", parentWidget);
        QChart* chart = new QChart();
        QValueAxis* axisX = new QValueAxis();
        QValueAxis* axisY = new QValueAxis();
        QChartView* chartView = new QChartView(chart);

        find = new FindGraph(
            const_cast<Sensor::AbstractSensor*>(sensor),
            parentWidget,
            idLabel,
            nameLabel,
            stanzaLabel,
            dataNameLabel,
            simulateButton,
            editButton,
            clearButton,
            chart,
            axisX,
            axisY,
            chartView
            );
    }
    if(find && render){
        render->render(layout, sensor, find);
        simulate();
    }
    if(find->getSimulateButton()){
        connect(find->getSimulateButton(), &QPushButton::clicked, this, &SensorWidget::simulate);

    }
    if(find->getEditButton()){
        connect(find->getEditButton(), &QPushButton::clicked, this, &SensorWidget::edit);
    }
    if(find->getClearButton()){
        connect(find->getClearButton(), &QPushButton::clicked, this, &SensorWidget::clear);
    }
}


void SensorWidget::clearChart(){
    if(find){
        QChart* chart = find->getChart();
        if(chart){
            QList<QAbstractSeries*> seriesList = chart->series();
            for(auto series : seriesList){
                chart->removeSeries(series);
                delete series;
            }
            chart->legend()->markers().clear();
        }
    }
}

void SensorWidget::simulate(){
    if(find){
        clearChart();
        Sensor::AbstractSensor* sensor = find->getSensor();
        if(sensor){
            simulator->simulate(sensor, find);
        }
    }


}

void SensorWidget::clear(){
    clearChart();
}
void SensorWidget::clean(){
    if(isEmpty()){
        if(find && find->getWidget()){
            delete find->getWidget();
        }
    }
}
void SensorWidget::edit(){
    emit edit_event(find->getSensor());
}
void SensorWidget::hideSensorWidget(){
    find->getWidget()->setVisible(false);
}
}

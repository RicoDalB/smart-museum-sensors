#include "simvisitor.h"
#include "Sensor/co2sensor.h"
#include "Sensor/humiditysensor.h"
#include "Sensor/temperaturesensor.h"
#include <vector>
#include "QtCharts/QLineSeries"
#include "QtCharts/QBarSet"
#include "QtCharts/QStackedBarSeries"
#include "QtCharts/QLegendMarker"

namespace View::GraphRenderer {

SimVisitor::SimVisitor() {}
void SimVisitor::visit(Sensor::Co2Sensor& co2){
    std::vector<double> ppm_data = co2.getPpmData();
    std::vector<double> co2_data = co2.getCo2Data();

    double max = 0;

    QLineSeries* series_ppm = new QLineSeries();
    unsigned int i = 0;
    for(auto it = ppm_data.begin(); it!=ppm_data.end(); ++it){
        series_ppm->append(i, *it);
        if(max < *it) max = *it;
        i++;
    }
    QLineSeries* series_co2 = new QLineSeries();
    unsigned int j = 0;
    for(auto it = co2_data.begin(); it != co2_data.end(); ++it){
        series_co2->append(j, *it);
        if(max < *it) max = *it;
        j++;
    }

    chart->addSeries(series_co2);

    series_co2->attachAxis(assX);
    series_co2->attachAxis(assY);
    series_ppm->attachAxis(assX);
    series_ppm->attachAxis(assY);

    qreal maxX = 0;
    qreal maxY = 0;
    for(QAbstractSeries *series : chart->series()){
        QLineSeries *lineSeries = dynamic_cast<QLineSeries*>(series);
        if(lineSeries != nullptr){
            for(QPointF point : lineSeries->points()){
                maxX = qMax(maxX, point.x());
                maxY = qMax(maxY, point.y());
            }
        }
    }

    assX->setRange(0, maxX);
    assY->setRange(0, maxY);

    //view

    series_co2->setName("Co2");
    assY->setTitleText("Co2");

    QColor arancione = QColor (255, 137, 0);

    QPen co2_pen;
    co2_pen.setColor(arancione);
    co2_pen.setStyle(Qt::DashLine);
    series_co2->setPen(co2_pen);

    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignRight);
    chart->setAnimationOptions(QChart::SeriesAnimations);
}
void SimVisitor::visit(Sensor::HumiditySensor& humidity){
    std::vector<double> h_data = humidity.getHData();
    double min = Sensor::HumiditySensor::min.getHumidity();

    QLineSeries* series = new QLineSeries();
    unsigned int i = 0;
    for(auto it = h_data.begin(); it != h_data.end(); ++it){
        series->append(i, *it);
        if(min > *it) min = *it;
        i++;
    }
    chart->addSeries(series);
    series->attachAxis(assX);
    series->attachAxis(assY);
    series->setName("humidity %");

    assX->setRange(0,i);
    assY->setRange(0,100);

    int count = 0;
    for(QLegendMarker* marker : chart->legend()->markers()){
        marker->setVisible(count < 3);
        count++;
    }
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignRight);
}
void SimVisitor::visit(Sensor::TemperatureSensor& temperature){

    std::vector<double> min_data = temperature.getTdataMin();
    std::vector<double> max_data = temperature.getTdataMax();
    std::vector<double> av_data = temperature.getTdataAv();

    QLineSeries* series_min = new QLineSeries();
    unsigned int i = 0;
    for(auto it = min_data.begin(); it != min_data.end(); ++it){
        series_min->append(i, *it);
        i++;
    }
    QLineSeries* series_max = new QLineSeries();
    unsigned int j = 0;
    for(auto it = max_data.begin(); it != max_data.end(); ++it){
        series_max->append(j, *it);
        j++;
    }
    chart->addSeries(series_min);
    chart->addSeries(series_max);
    series_min->attachAxis(assX);
    series_min->attachAxis(assY);
    series_max->attachAxis(assX);
    series_max->attachAxis(assY);

    series_min->setName("min");
    series_max->setName("max");

    QLineSeries* series_av = new QLineSeries();
    unsigned int k = 0;
    for(auto it = av_data.begin(); it != av_data.end(); ++it){
        series_av->append(k, *it);
        k++;
    }
    chart->addSeries(series_av);
    series_av->attachAxis(assX);
    series_av->attachAxis(assX);
    series_av->setName("media");

    assX->setRange(0, k);
    assY->setRange(-50, 50);



    assY->setTitleText("temperature Celsius");
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignRight);
}

QChart* SimVisitor::getChart() const{
    return chart;
}
SimVisitor& SimVisitor::setChart(QChart* c){
    this->chart = c;
    return *this;
}
QValueAxis* SimVisitor::getXass()const{
    return assX;
}
QValueAxis* SimVisitor::getYass()const{
    return assY;
}
SimVisitor& SimVisitor::setXass(QValueAxis* x){
    this->assX = x;
    return *this;
}
SimVisitor& SimVisitor::setYass(QValueAxis* y){
    this->assY = y;
    return *this;
}
QChartView* SimVisitor::getChartView() const{
    return view_chart;
}
SimVisitor& SimVisitor::setChartView(QChartView* vc){
    this->view_chart = vc;
    return *this;
}
}

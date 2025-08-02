#include "allsensor.h"
#include "QtWidgets/QLabel"
#include "QtWidgets/QVBoxLayout"
#include "QtWidgets/QHBoxLayout"
#include "QtGui/QPixmap"
#include "QtWidgets/QPushButton"
#include "QtWidgets/QGroupBox"
#include <QComboBox>
#include "QtCharts/QChart"
#include "QtCharts/QChartView"
#include "QtCharts/QLineSeries"
#include "Sensor/co2sensor.h"
#include "Sensor/humiditysensor.h"
#include "Sensor/temperaturesensor.h"
namespace View::GraphRenderer {
AllSensor::AllSensor() {}

void AllSensor::cleanArea(){
    if(widget){
        QLayout* layout = widget->layout();
        if(layout){
            QLayoutItem* item;
            while((item = layout->takeAt(0)) != nullptr){
                if(item->widget()){
                    item->widget()->hide();
                    delete item->widget();
                }
                delete item;
            }
        }
    }
}

void AllSensor::visit(const Sensor::Co2Sensor& co2){
    cleanArea();
    widget = new QWidget();
    QGridLayout* grid = new QGridLayout();

    QLabel* icon = new QLabel();
    icon->setPixmap(QIcon(":/Asset/icons/co2.svg").pixmap(50,50));

    QWidget* primo_info = new QWidget();
    QVBoxLayout* primo = new QVBoxLayout();
    name = new QLabel("name: " + QString::fromStdString(co2.getName()));
    id = new QLabel("ID: " + QString::number(co2.getId()));
    primo->addWidget(name);
    primo->addWidget(id);
    primo_info->setLayout(primo);//prima_info

    QWidget* seconda_info = new QWidget();
    QVBoxLayout* secondo = new QVBoxLayout();
    stanza = new QLabel("stanza: " + QString::fromStdString(co2.getStanza()));
    data_num = new QLabel("data num: " + QString::number(co2.getDataN()));
    secondo->addWidget(stanza);
    secondo->addWidget(data_num);
    seconda_info->setLayout(secondo);//seconda_info

    QWidget* titolo = new QWidget();
    QVBoxLayout* prima_cella = new QVBoxLayout();
    QLabel* tipo = new QLabel("Co2 Sensor");
    prima_cella->addWidget(tipo);
    titolo->setLayout(prima_cella);//titolo

    QWidget* terza_info = new QWidget();
    QVBoxLayout* terza_cella = new QVBoxLayout();
    QLabel* initial_ppm = new QLabel("initial ppm: " + QString::number(co2.getPpmInitial()));
    terza_cella->addWidget(initial_ppm);
    terza_info->setLayout(terza_cella);//terza_info

    QWidget* bottoni = new QWidget();
    QVBoxLayout* all_buttons = new QVBoxLayout();
    simulate_button = new QPushButton("simulate");
    edit_button = new QPushButton("edit");
    clear_button = new QPushButton("clear");
    all_buttons -> addWidget(simulate_button);
    all_buttons -> addWidget(edit_button);
    all_buttons -> addWidget(clear_button);
    bottoni->setLayout(all_buttons);//bottoni

    chart = new QChart();
    assX = new QValueAxis();
    assX->setTitleText("data num");
    assX->setRange(0,100);
    chart->addAxis(assX, Qt::AlignBottom);
    assY = new QValueAxis();
    assY->setRange(0,100);
    chart->addAxis(assY, Qt::AlignLeft);

    view_chart = new QChartView(chart);
    view_chart->setRenderHint(QPainter::Antialiasing);

    grid->addWidget(icon,0,3,1,1);
    grid->addWidget(titolo, 0,0,1,1);
    grid->addWidget(primo_info,1,0,1,2);
    grid->addWidget(seconda_info,1,2,1,2);
    grid->addWidget(terza_info,1,1,1,2);
    grid->addWidget(bottoni,2,3,3,1);
    grid->addWidget(view_chart,2,0,3,3);
    widget->setLayout(grid);

}

void AllSensor::visit(const Sensor::HumiditySensor& humidity){
    cleanArea();
    widget = new QWidget();
    QGridLayout* grid = new QGridLayout();

    QLabel* icon = new QLabel();
    icon->setPixmap(QIcon(":/Asset/icons/hum.svg").pixmap(50,50));

    QWidget* titolo = new QWidget();
    QVBoxLayout* prima_cella = new QVBoxLayout();
    QLabel* type = new QLabel("HUMIDITY SENSOR");
    prima_cella->addWidget(type);
    titolo->setLayout(prima_cella);

    QWidget* primo = new QWidget();
    QVBoxLayout* prima_info = new QVBoxLayout();
    QLabel* name = new QLabel("Name: " + QString::fromStdString(humidity.getName()));
    QLabel* id = new QLabel("ID: " + QString::number(humidity.getId()));
    prima_info->addWidget(name);
    prima_info->addWidget(id);
    primo->setLayout(prima_info);

    QWidget* secondo = new QWidget();
    QVBoxLayout* seconda_info = new QVBoxLayout();
    QLabel* stanza = new QLabel("stanza: " + QString::fromStdString(humidity.getStanza()));
    QLabel* data_num = new QLabel("data num: " + QString::number(humidity.getDataN()));
    seconda_info->addWidget(stanza);
    seconda_info->addWidget(data_num);
    secondo->setLayout(seconda_info);

    QWidget* terzo = new QWidget();
    QVBoxLayout* terza_info = new QVBoxLayout();
    QLabel* initial = new QLabel("Initial: " + QString::number(double(humidity.getHInitial())) + "%");
    terza_info->addWidget(initial);
    terzo->setLayout(terza_info);

    QWidget* bottoni = new QWidget();
    QVBoxLayout* all_buttons = new QVBoxLayout();
    simulate_button = new QPushButton("simulate");
    edit_button = new QPushButton("edit");
    clear_button = new QPushButton("clear");
    all_buttons -> addWidget(simulate_button);
    all_buttons -> addWidget(edit_button);
    all_buttons -> addWidget(clear_button);
    bottoni->setLayout(all_buttons);

    chart = new QChart();
    assX = new QValueAxis();
    assX->setTitleText("Num Data");
    assX->setRange(0,100);
    chart->addAxis(assX, Qt::AlignBottom);
    assY = new QValueAxis();
    assY->setRange(0,100);
    chart->addAxis(assY, Qt::AlignLeft);
    view_chart = new QChartView(chart);
    view_chart->setRenderHint(QPainter::Antialiasing);

    grid->addWidget(icon,0,3,1,1);
    grid->addWidget(titolo, 0,0,1,1);
    grid->addWidget(primo,1,0,1,2);
    grid->addWidget(secondo,1,2,1,2);
    grid->addWidget(terzo,1,1,1,2);
    grid->addWidget(bottoni,2,3,3,1);
    grid->addWidget(view_chart,2,0,3,3);
    widget->setLayout(grid);


}
void AllSensor::visit(const Sensor::TemperatureSensor& temperature){
    cleanArea();
    widget = new QWidget();
    QGridLayout* grid = new QGridLayout();

    QLabel* icon = new QLabel();
    icon->setPixmap(QIcon(":/Asset/icons/temp.svg").pixmap(50,50));

    QWidget* titolo = new QWidget();
    QVBoxLayout* prima_cella = new QVBoxLayout();
    QLabel* type = new QLabel("TEMPERATURE SENSOR");
    prima_cella->addWidget(type);
    titolo->setLayout(prima_cella);

    QWidget* primo = new QWidget();
    QVBoxLayout* prima_info = new QVBoxLayout();
    QLabel* name = new QLabel("Name: " + QString::fromStdString(temperature.getName()));
    QLabel* id = new QLabel("ID: " + QString::number(temperature.getId()));
    prima_info->addWidget(name);
    prima_info->addWidget(id);
    primo->setLayout(prima_info);

    QWidget* secondo = new QWidget();
    QVBoxLayout* seconda_info = new QVBoxLayout();
    QLabel* stanza = new QLabel("stanza: " + QString::fromStdString(temperature.getStanza()));
    QLabel* data_num = new QLabel("data num: " + QString::number(temperature.getDataN()));
    seconda_info->addWidget(stanza);
    seconda_info->addWidget(data_num);
    secondo->setLayout(seconda_info);

    QWidget* terzo = new QWidget();
    QVBoxLayout* terza_info = new QVBoxLayout();
    QLabel *initial = new QLabel("Initial: " + QString::number(double(temperature.getTInitial())) + "C°");
    QLabel *maxi = new QLabel("Max : " + QString::number(double(temperature.getTmax()))+ "C°");
    QLabel *mini = new QLabel("Min : " + QString::number(double(temperature.getTmin()))+ "C°");
    terza_info->addWidget(initial);
    terza_info->addWidget(maxi);
    terza_info->addWidget(mini);
    terzo->setLayout(terza_info);

    QWidget* bottoni = new QWidget();
    QVBoxLayout* all_buttons = new QVBoxLayout();
    simulate_button = new QPushButton("simulate");
    edit_button = new QPushButton("edit");
    clear_button = new QPushButton("clear");
    all_buttons -> addWidget(simulate_button);
    all_buttons -> addWidget(edit_button);
    all_buttons -> addWidget(clear_button);
    bottoni->setLayout(all_buttons);

    chart = new QChart();
    assX = new QValueAxis();
    assX->setTitleText("Num Data");
    assX->setRange(0,100);
    chart->addAxis(assX, Qt::AlignBottom);
    assY = new QValueAxis();
    assY->setRange(0,100);
    chart->addAxis(assY, Qt::AlignLeft);
    view_chart = new QChartView(chart);
    view_chart->setRenderHint(QPainter::Antialiasing);

    grid->addWidget(icon,0,3,1,1);
    grid->addWidget(titolo, 0,0,1,1);
    grid->addWidget(primo,1,0,1,2);
    grid->addWidget(secondo,1,3,1,2);
    grid->addWidget(terzo,1,1,1,2);
    grid->addWidget(bottoni,2,3,3,1);
    grid->addWidget(view_chart,2,0,3,3);
    widget->setLayout(grid);

}

QWidget* AllSensor::getWidget() const{
    return widget;
}
QLabel* AllSensor::getId() const{
    return id;
}
QLabel* AllSensor::getName()const{
    return name;
}
QLabel* AllSensor::getStanza()const{
    return stanza;
}
QLabel* AllSensor::getDataNum()const{
    return data_num;
}
QPushButton* AllSensor::getEditButton()const{
    return edit_button;
}
QPushButton* AllSensor::getSimulateButton()const{
    return simulate_button;
}
QPushButton* AllSensor::getClearButton()const{
    return clear_button;
}
QChart* AllSensor::getChart() const{
    return chart;
}
QValueAxis* AllSensor::getAssX()const{
    return assX;
}
QValueAxis* AllSensor::getAssY()const{
    return assY;
}
QChartView* AllSensor::getChartView()const{
    return view_chart;
}






}





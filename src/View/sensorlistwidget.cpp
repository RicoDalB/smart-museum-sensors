#include "sensorlistwidget.h"
#include "ListRenderer/list.h"
#include "sensorwidget.h"
#include "mainwindow.h"
#include <QLabel>
#include <functional>
namespace View {

SensorListWidget::SensorListWidget(SensorWidget* sw, QWidget* parent)
    :QWidget(parent), sensor_widget(sw) {
    if(!sensor_widget){
        sensor_widget = new SensorWidget(this);
    }

    QVBoxLayout* box = new QVBoxLayout(this);
    box->setAlignment(Qt::AlignLeft | Qt::AlignTop);

    QLabel* lista = new QLabel("lista Sensori");
    lista->setAlignment(Qt::AlignCenter);
    box->addWidget(lista);

    QHBoxLayout* sortLayout = new QHBoxLayout();
    QPushButton* sort_id_b = new QPushButton("Sort id");
    sortLayout->addWidget(sort_id_b);
    QPushButton* sort_name_b = new QPushButton("sort Nome");
    sortLayout->addWidget(sort_name_b);
    QPushButton* sort_stanza_b = new QPushButton("sort Stanza");
    sortLayout->addWidget(sort_stanza_b);
    QWidget* sort_box = new QWidget();
    sort_box->setLayout(sortLayout);
    box->addWidget(sort_box);

    layout = new QGridLayout();
    layout->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    QWidget* container = new QWidget();
    container->setLayout(layout);
    QScrollArea* scroll_area = new QScrollArea();
    scroll_area->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    scroll_area->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    scroll_area->setWidgetResizable(true);
    scroll_area->setWidget(container);
    box->addWidget(scroll_area);
    render = new ListRenderer::List();

    connect(sort_id_b, &QPushButton::clicked, this, &SensorListWidget::sortId);
    connect(sort_name_b, &QPushButton::clicked, this, &SensorListWidget::sortName);
    connect(sort_stanza_b, &QPushButton::clicked, this, &SensorListWidget::sortStanza);
}

SensorListWidget::~SensorListWidget(){
}

void SensorListWidget::showList(Engine::SensorList* list, Sensor::Repo::JsonRepository* repo, Engine::SensorList* query) {
    clean();

    if(query != nullptr && !query->isEmpty()){
        render->render(layout, list, &find);
    }else{
        render->render(layout, list, &find);
    }
    for(QVector<FindWidget>::const_iterator it = find.begin(); it!=find.end(); it++){
        if(it->getViewButton()){
            connect(it->getViewButton(), &QPushButton::clicked, this, [=](){
                if(sensor_widget && it->getSensor()){
                    sensor_widget->show(it->getSensor());}
            });
        }
        if(it->getEditButton()) {
            connect(it->getEditButton(), &QPushButton::clicked, [this, it]() {
                editSensor(it);
            });
        }
        if(it->getDeleteButton()){
            connect(it->getDeleteButton(), &QPushButton::clicked, [this, it, list, repo, query](){
                deleteSensor(it, list, repo, query);
            });
        }

    }
}


void SensorListWidget::editSensor(QVector<FindWidget>::const_iterator it){
    Sensor::AbstractSensor* sen = const_cast<Sensor::AbstractSensor*>(it->getSensor());
    emit edit_event(sen);
}
void SensorListWidget::deleteSensor(QVector<FindWidget>::const_iterator it, Engine::SensorList* list, Sensor::Repo::JsonRepository* repo, Engine::SensorList* query){

    if (repo) repo->erase(it->getSensor()->getId());
    if (query && !query->isEmpty()) query->erase(it->getSensor());
    list->erase(it->getSensor());

    if (sensor_widget && !sensor_widget->isEmpty() && sensor_widget->getFind()->getSensor()->getId() == it->getSensor()->getId()) {
        sensor_widget->hideSensorWidget();
    }

    if (it->getSensor()) {
        delete it->getSensor();
    }
    if (it->getWidget()) {
        it->getWidget()->setParent(nullptr);
        it->getWidget()->deleteLater();
    }

    find.erase(it);


}
void SensorListWidget::clean(){
    while (!find.isEmpty()) {
        FindWidget info = find.takeLast();
        if (info.getWidget()) {
            info.getWidget()->setParent(nullptr);
            info.getWidget()->deleteLater();
        }
    }

}
void SensorListWidget::sortId(){
    emit sortId_event();
}
void SensorListWidget::sortName(){
    emit sortName_event();
}
void SensorListWidget::sortStanza(){
    emit sortStanza_event();
}

}

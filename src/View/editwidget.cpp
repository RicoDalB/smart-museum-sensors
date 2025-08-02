#include "editwidget.h"
#include "View/SensorEditor/typeselector.h"
#include "SensorEditor/co2sensoreditor.h"
#include"SensorEditor/humiditysensoreditor.h"
#include "SensorEditor/temperaturesensoreditor.h"
#include "SensorEditor/sensorinjector.h"
#include <iostream>
#include <QFormLayout>
#include <QLabel>
#include <QPushButton>
#include <QFileDialog>
#include <QComboBox>
#include <QMessageBox>
namespace View {
EditWidget::EditWidget(
    Sensor::AbstractSensor* s,
    MainWindow* m,
    Sensor::Repo::JsonRepository* rep): sensor(s), main_window(m), repo(rep) {

    QBoxLayout* layout = new QVBoxLayout(this);
    layout->setAlignment(Qt::AlignTop | Qt::AlignTop);
    layout->setObjectName("edit widget");

    QLabel* title = new QLabel("Modifica Sensore");
    title->setObjectName("Titolo");
    layout->addWidget(title);

    QFormLayout* form = new QFormLayout();
    form->setObjectName("Propietà");
    form->setLabelAlignment(Qt::AlignRight | Qt::AlignTop);
    layout->addLayout(form);

    id_imput = new QSpinBox();
    id_imput->setObjectName("ID imput");
    id_imput->setRange(0,100);
    if(sensor != nullptr){
        id_imput->setValue(sensor->getId());
    }
    form->addRow("Identifier", id_imput);

    name_imput = new QLineEdit();
    name_imput->setObjectName("Name Imput");
    name_imput->setPlaceholderText("Sensor Name");
    name_imput->setMaxLength(20);
    if(sensor != nullptr){
        name_imput->setText(QString::fromStdString(sensor->getName()));
    }
    form->addRow("Name", name_imput);

    stanza_imput = new QLineEdit();
    stanza_imput->setObjectName("Stanza Imput");
    stanza_imput->setPlaceholderText("Imput Stanza");
    stanza_imput->setMaxLength(20);
    if(sensor != nullptr){
        stanza_imput->setText(QString::fromStdString(sensor->getStanza()));
    }
    form->addRow("Stanza", stanza_imput);

    DataNum_imput = new QSpinBox();
    DataNum_imput->setObjectName("Data Number Input");
    DataNum_imput->setRange(1, 10000);
    DataNum_imput->setValue(100);

    if(sensor != nullptr){

        DataNum_imput->setValue(sensor->getDataN());
    }
    form->addRow("Data Number", DataNum_imput);

    QComboBox* type_imput = new QComboBox();
    type_imput->setObjectName("Type imput");
    type_imput->addItem("Co2Sensor");
    type_imput->addItem("HumiditySensor");
    type_imput->addItem("TemperatureSensor");
    if(sensor != nullptr){
        TypeSelector type_selector(type_imput);
        sensor->accept(type_selector);
    }
    form->addRow("Type", type_imput);

    stacked_editor = new QStackedLayout();
    layout->addLayout(stacked_editor);

    SensorEditor::Co2SensorEditor* co2_editor = new SensorEditor::Co2SensorEditor();
    stacked_editor->addWidget(co2_editor);
    editors.push_back(co2_editor);
    SensorEditor::HumiditySensorEditor* humidity_editor = new SensorEditor::HumiditySensorEditor();
    stacked_editor->addWidget(humidity_editor);
    editors.push_back(humidity_editor);
    SensorEditor::TemperatureSensorEditor* temperature_editor = new SensorEditor::TemperatureSensorEditor();
    stacked_editor->addWidget(temperature_editor);
    editors.push_back(temperature_editor);

    if(sensor != nullptr){
        SensorEditor::SensorInjector sensor_injector(
            *co2_editor, *humidity_editor, *temperature_editor);
        sensor->accept(sensor_injector);
    }
    showType(type_imput->currentIndex());

    layout->addStretch();

    QHBoxLayout* actions = new QHBoxLayout();
    actions->setObjectName("Actions");
    actions->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    layout->addLayout(actions);

    actions->addStretch();

    QPushButton* apply_button = new QPushButton("Applica");
    apply_button->setObjectName("Applica");
    actions->addWidget(apply_button);

    QPushButton* cancel_button = new QPushButton("Cancella");
    cancel_button->setObjectName("cancella");
    actions->addWidget(cancel_button);

    connect(type_imput, qOverload<int>(&QComboBox::currentIndexChanged), this, &EditWidget::showType);
    connect(apply_button, &QPushButton::clicked, this, &EditWidget::apply);
    connect(cancel_button, &QPushButton::clicked, this, &EditWidget::closeWindow);
}
void EditWidget::showType(int index){
    stacked_editor->setCurrentIndex(index);
}
void EditWidget::apply(){

    int id = id_imput->value();
    QString name = name_imput->text();
    QString stanza = stanza_imput->text();
    int dn = DataNum_imput->value();
    SensorEditor::AbstractSensorEditor* editor = editors[stacked_editor->currentIndex()];

    Engine::SensorList* list = main_window->getList();


    if(sensor != nullptr){
        if(repo != nullptr) repo->erase(sensor->getId());
            list->removeAndDelete(sensor);
    }
    sensor = editor->create(id, name, stanza, dn);

    if(list->find(sensor)){
        QMessageBox::critical(this, "Errore", "Id taken");
    }else{
        list->add(sensor);

        if(repo != nullptr){
            repo->update(sensor);
        }
        main_window->finishEdit();
    }
}
void EditWidget::closeWindow(){
    main_window->closedEdit();
}






































}

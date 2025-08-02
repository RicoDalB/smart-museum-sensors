#include "mainwindow.h"
#include "editwidget.h"
#include <QStatusBar>
#include <QMenu>
#include <QMenuBar>
#include <QToolBar>
#include <QSplitter>
#include <QLabel>
#include <QWindow>
#include <QFileDialog>
#include <QMessageBox>
#include <QWidget>

namespace View {
MainWindow::MainWindow(Engine::SensorList* mem, QWidget* parent)
    :QMainWindow(parent), sensor_list(mem),repo(nullptr){
    query = new Engine::SensorList();

    create = new QAction(QIcon(":/Asset/icons/New.svg"), "New");
    open = new QAction(QIcon(QPixmap(":/Asset/icons/Open.svg")),"Apri");
    save = new QAction(QIcon(QPixmap(":/Asset/icons/Save.svg")),"Salva");
    saveAs = new QAction(QIcon(QPixmap(":/Asset/icons/SaveAs.svg")),"Salva come");
    createSen = new QAction(QIcon(QPixmap(":/Asset/icons/Add.svg")), "Nuovo Sensore");


    toolbar = addToolBar("ToolBar");
    toolbar->setOrientation(Qt::Horizontal);
    addToolBar(Qt::TopToolBarArea, toolbar);
    toolbar->addAction(create);
    toolbar->addAction(open);
    toolbar->addAction(save);
    toolbar->addAction(saveAs);
    toolbar->addAction(createSen);



    QSplitter* Horizontal_splitter = new QSplitter(Qt::Horizontal, this);
    setCentralWidget(Horizontal_splitter);

    search_widget = new SearchWidget(this);
    Horizontal_splitter->addWidget(search_widget);

    QSplitter* splitter = new QSplitter(this);
    Horizontal_splitter->addWidget(splitter);

    sensor_widget = new SensorWidget(this);
    sensor_list_widget = new SensorListWidget(sensor_widget, this);

    splitter->addWidget(sensor_list_widget);
    splitter->addWidget(sensor_widget);

    Horizontal_splitter->setHandleWidth(0);
    Horizontal_splitter->setSizes(QList<int>() << 150 << 3000);
    splitter->setSizes(QList<int>() << 1000 << 3000);

    edit_window = new EditWindow();



    connect(create, &QAction::triggered, this, &MainWindow::newDataset);
    connect(open, &QAction::triggered, this, &MainWindow::openDataset);
    connect(save, &QAction::triggered, this, &MainWindow::saveDataset);
    connect(saveAs, &QAction::triggered, this, &MainWindow::saveAsDataset);
    connect(createSen, &QAction::triggered, this, &MainWindow::createItem);
    connect(edit_window, &EditWindow::windowClosed, this, &MainWindow::closedEdit);
    connect(search_widget, &SearchWidget::search_event, this, &MainWindow::search);
    connect(sensor_list_widget, &SensorListWidget::sortId_event, this, &MainWindow::sortSensorId);
    connect(sensor_list_widget, &SensorListWidget::sortName_event, this, &MainWindow::sortSensorName);
    connect(sensor_list_widget, &SensorListWidget::sortStanza_event, this, &MainWindow::sortSensorStanza);
    connect(sensor_list_widget, &SensorListWidget::edit_event, this, &MainWindow::editItem);
    connect(sensor_widget, &SensorWidget::edit_event, this, &MainWindow::editItem);

    showStatusBar("Pronto");
}
MainWindow::~MainWindow(){
    query->clean();
    delete query;
    delete sensor_list;
    delete edit_window;

    delete open;
    delete save;
    delete saveAs;
    delete createSen;
}
MainWindow& MainWindow::ClearMem(){
    repo = nullptr;
    sensor_list->clear();
    return *this;
}
MainWindow& MainWindow::reloadMem(){
    std::vector<Sensor::AbstractSensor*> sensors(repo->readAll());
    for(auto it = sensors.begin(); it != sensors.end(); ++it){
        sensor_list->add(*it);
    }
    return *this;
}
MainWindow& MainWindow::ClearQuery(){
    query->clean();
    return *this;
}

void MainWindow::newDataset(){
    ClearQuery();
    QString path = QFileDialog::getSaveFileName(
        this, "crea nuovo Dataset", "./Asset/Data/", "JSON files *.json");
    if(path.isEmpty()){
        return;
    }try{
        Sensor::Repo::JsonRepository* r = Sensor::Repo::JsonRepository::fromPath(path.toStdString());
        if(!r->empty()){
            throw std::runtime_error("repository non è vuota");
        }
        ClearMem();
        repo = r;
        sensor_widget->clean();
        sensor_list_widget->clean();
        sensor_list_widget->showList(sensor_list, repo, query);
        showStatusBar("nuovo Dataset creato.");
    }catch (const std::exception& e){
        qDebug() << "Errore creazione nuovo dataset: " << e.what();
        QMessageBox::critical(this, "Errore", e.what());
    }
}
void MainWindow::saveDataset(){
    if(repo == nullptr){
        return;
    }
    repo->store();
    showStatusBar("Dataset saved.");
}
void MainWindow::openDataset(){
    ClearQuery();
    QString path = QFileDialog::getOpenFileName(
        this,
        "Dataset Aperto",
        "./Assets/Data/",
        "final *.json"
        );
    if(path.isEmpty()){
        return;
    }

    try{
        ClearMem();
        repo = Sensor::Repo::JsonRepository::fromPath(path.toStdString());
        if(sensor_widget){
            sensor_widget->clean();}
        sensor_list_widget->clean();
        reloadMem();
        sensor_list_widget->showList(sensor_list, repo, query);
        showStatusBar("Dati caricati" + path + ".");
        //new
    }catch(const std::exception& e){
        qDebug() << "Errore nell'apertura File" << e.what();
        QMessageBox::critical(this, "errore", e.what());
    }
}

void MainWindow::saveAsDataset(){
    QString path = QFileDialog::getSaveFileName(
        this, "Crea nuovo Dataset", "./Assets/Data/", "Json files *.json");
    if(path.isEmpty() || repo == nullptr){
        return;
    }
    repo->setPath(path.toStdString()).store();
    showStatusBar("Dati salvati come \"" + path + "\".");
}
void MainWindow::createItem(){
    ClearQuery();
    createSen->setEnabled(false);
    EditWidget* edit = new EditWidget(nullptr, this, repo);
    edit_window->setCentralWidget(edit);
    edit_window->show();
    showStatusBar("Crea nuovo oggetto");
}
void MainWindow::editItem(Sensor::AbstractSensor* s){
    createSen->setEnabled(false);
    EditWidget* edit = new EditWidget(s, this, repo);
    edit_window->setCentralWidget(edit);
    edit_window->show();
    showStatusBar("Modifica un Sensore");
}
void MainWindow::finishEdit(){
    edit_window->close();
    delete edit_window->centralWidget();
    createSen->setEnabled(true);
    ClearQuery();

    sensor_list_widget->showList(sensor_list, repo);
    if(!sensor_widget->isEmpty()) sensor_widget->hideSensorWidget();
    showStatusBar("pronto");
}
void MainWindow::closedEdit(){
    edit_window->close();
    delete edit_window->centralWidget();
    createSen->setEnabled(true);
    showStatusBar("Pronto");
}
void MainWindow::search(const std::string& query_text){
    ClearQuery();
    sensor_list->search(query, query_text);
    if(query->isEmpty()){
        showStatusBar("No match per la query " + QString::fromStdString(query_text) + "\",");
    }else{
        sensor_list_widget->showList(sensor_list, repo, query);
        showStatusBar("Trovato" + QString::fromStdString(std::to_string(query->size())) + "match per Query" + QString::fromStdString(query_text) + "\".");
    }
}
void MainWindow::sortSensorId(){
    if(!query->isEmpty()){
        query->sortId();
        sensor_list_widget->showList(sensor_list, repo, query);
    }else{
        sensor_list->sortId();
        sensor_list_widget->showList(sensor_list, repo);
    }
}
void MainWindow::sortSensorName(){
    if(!query->isEmpty()){
        query->sortName();
        sensor_list_widget->showList(sensor_list, repo, query);
    }else{
        sensor_list->sortName();
        sensor_list_widget->showList(sensor_list, repo);
    }
}
void MainWindow::sortSensorStanza(){
    if(!query->isEmpty()){
        query->sortStanza();
        sensor_list_widget->showList(sensor_list, repo, query);
    }else{
        sensor_list->sortStanza();
        sensor_list_widget->showList(sensor_list, repo);
    }
}
SensorListWidget* MainWindow::getSenListWidget(){
    return sensor_list_widget;
}
Engine::SensorList* MainWindow::getList()const{
    return sensor_list;
}
Sensor::Repo::JsonRepository* MainWindow::getRepo()const{
    return repo;
}
QAction* MainWindow::getCreateItem(){
    return createSen;
}
void MainWindow::showStatusBar(const QString& m){
    statusBar()->showMessage(m);
}


































}

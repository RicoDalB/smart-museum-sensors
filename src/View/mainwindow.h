#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>
#include "../Sensor/Repo/jsonrepository.h"
#include "searchwidget.h"
#include "sensorlistwidget.h"
#include "editwindow.h"
namespace View {
class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    QToolBar* toolbar;
    Engine::SensorList* sensor_list;
    Sensor::Repo::JsonRepository* repo;
    Engine::SensorList* query;
    SearchWidget* search_widget;
    SensorWidget* sensor_widget;
    EditWindow* edit_window;
    SensorListWidget* sensor_list_widget;


    QAction* create;
    QAction* open;
    QAction* save;
    QAction* saveAs;
    QAction* createSen;

    MainWindow& reloadMem();
    MainWindow& ClearMem();
    MainWindow& ClearQuery();

public:
    explicit MainWindow(Engine::SensorList* mem, QWidget *parent = 0);
    ~MainWindow() override;
    SensorListWidget* getSenListWidget();
    Engine::SensorList* getList() const;
    Sensor::Repo::JsonRepository* getRepo() const;
    QAction* getCreateItem();
    void showStatusBar(const QString& m);

public slots:
    void newDataset();
    void openDataset();
    void saveDataset();
    void saveAsDataset();
    void createItem();
    void editItem(Sensor::AbstractSensor* s);
    void finishEdit();
    void closedEdit();
    void search(const std::string& query_text);
    void sortSensorId();
    void sortSensorName();
    void sortSensorStanza();
};
}
#endif // MAINWINDOW_H

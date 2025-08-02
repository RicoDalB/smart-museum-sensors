#ifndef SENSORLISTWIDGET_H
#define SENSORLISTWIDGET_H
#include "View/Find/findwidget.h"
#include "ListRenderer/ListRenderStrategy.h"
#include "sensorwidget.h"
#include "../Sensor/Repo/jsonrepository.h"
#include <QVector>
#include <QGridLayout>
#include <QWidget>
namespace View {
class SensorListWidget: public QWidget{
    Q_OBJECT
private:
    SensorWidget* sensor_widget;
    QVector<FindWidget> find;
    QGridLayout* layout;
    ListRenderer::ListRenderStrategy* render;
public:
    explicit SensorListWidget(SensorWidget* sw, QWidget* parent = nullptr);
    ~SensorListWidget() override;
    void showList(Engine::SensorList* list, Sensor::Repo::JsonRepository* repo = nullptr, Engine::SensorList* query = nullptr);
    void editSensor(QVector<FindWidget>::const_iterator i);
    void deleteSensor(QVector<FindWidget>::const_iterator it, Engine::SensorList* list, Sensor::Repo::JsonRepository* repo, Engine::SensorList* query);
    void clean();


public slots:
    void sortId();
    void sortName();
    void sortStanza();

signals:
    void sortId_event();
    void sortName_event();
    void sortStanza_event();
    void edit_event(Sensor::AbstractSensor* sen);
};
}
#endif // SENSORLISTWIDGET_H

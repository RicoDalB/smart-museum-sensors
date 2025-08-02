QT       += core gui
QT += charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Engine/sensorlist.cpp \
    Sensor/Converter/json.cpp \
    Sensor/Converter/jsonvisitor.cpp \
    Sensor/Converter/reader.cpp \
    Sensor/DataMapper/jsonfile.cpp \
    Sensor/Enviroment/co2.cpp \
    Sensor/Enviroment/humidity.cpp \
    Sensor/Enviroment/temperature.cpp \
    Sensor/Repo/jsonrepository.cpp \
    Sensor/abstractsensor.cpp \
    Sensor/co2sensor.cpp \
    Sensor/humiditysensor.cpp \
    Sensor/temperaturesensor.cpp \
    View/Find/findgraph.cpp \
    View/Find/findwidget.cpp \
    View/GraphSimulator/simvisitor.cpp \
    View/GraphSimulator/stdsimulator.cpp \
    View/ListRenderer/list.cpp \
    View/ListRenderer/listrender.cpp \
    View/SensorEditor/abstractsensoreditor.cpp \
    View/SensorEditor/co2sensoreditor.cpp \
    View/SensorEditor/humiditysensoreditor.cpp \
    View/SensorEditor/sensorinjector.cpp \
    View/SensorEditor/temperaturesensoreditor.cpp \
    View/SensorEditor/typeselector.cpp \
    View/SensorRenderer/allgraph.cpp \
    View/SensorRenderer/allsensor.cpp \
    View/editwidget.cpp \
    View/editwindow.cpp \
    View/searchwidget.cpp \
    View/sensorlistwidget.cpp \
    View/sensorwidget.cpp \
    main.cpp \
    View/mainwindow.cpp

HEADERS += \
    Engine/sensorlist.h \
    Sensor/Converter/SReader.h \
    Sensor/Converter/json.h \
    Sensor/Converter/jsonvisitor.h \
    Sensor/Converter/reader.h \
    Sensor/DataMapper/jsonfile.h \
    Sensor/Enviroment/co2.h \
    Sensor/Enviroment/humidity.h \
    Sensor/Enviroment/temperature.h \
    Sensor/Repo/IRepository.h \
    Sensor/Repo/jsonrepository.h \
    Sensor/SConstVisitor.h \
    Sensor/SVisitor.h \
    Sensor/abstractsensor.h \
    Sensor/co2sensor.h \
    Sensor/humiditysensor.h \
    Sensor/temperaturesensor.h \
    View/Find/findgraph.h \
    View/Find/findwidget.h \
    View/GraphSimulator/SGraphSimulator.h \
    View/GraphSimulator/simvisitor.h \
    View/GraphSimulator/stdsimulator.h \
    View/ListRenderer/ListRenderStrategy.h \
    View/ListRenderer/SListStrategy.h \
    View/ListRenderer/list.h \
    View/ListRenderer/listrender.h \
    View/SensorEditor/abstractsensoreditor.h \
    View/SensorEditor/co2sensoreditor.h \
    View/SensorEditor/humiditysensoreditor.h \
    View/SensorEditor/sensorinjector.h \
    View/SensorEditor/temperaturesensoreditor.h \
    View/SensorEditor/typeselector.h \
    View/SensorRenderer/SGraphRender.h \
    View/SensorRenderer/allgraph.h \
    View/SensorRenderer/allsensor.h \
    View/editwidget.h \
    View/editwindow.h \
    View/searchwidget.h \
    View/sensorlistwidget.h \
    View/sensorwidget.h \
    View/mainwindow.h




RESOURCES += risorses.qrc

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target



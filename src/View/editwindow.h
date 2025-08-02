#ifndef EDITWINDOW_H
#define EDITWINDOW_H
#include <QMainWindow>
namespace View {
class EditWindow: public QMainWindow{
    Q_OBJECT
signals:
    void windowClosed();
protected:
    void closeEvent(QCloseEvent* event)override;
};
}
#endif // EDITWINDOW_H

#include "editwindow.h"
namespace View {
void EditWindow::closeEvent(QCloseEvent* event){
    emit windowClosed();
    QMainWindow::closeEvent(event);
}
}

#ifndef SEARCHWIDGET_H
#define SEARCHWIDGET_H

#include <QWidget>
#include <QLineEdit>


namespace View {


class SearchWidget:public QWidget{
    Q_OBJECT
private:
    QLineEdit* query;
public:
    explicit SearchWidget(QWidget* parent = 0);

public slots:
    void search();

signals:
    void search_event(std::string query_text);
};
}
#endif // SEARCHWIDGET_H

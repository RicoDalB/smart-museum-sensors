#include "searchwidget.h"

#include <QHBoxLayout>
#include <QPushButton>

namespace View {

SearchWidget::SearchWidget(QWidget* parent):QWidget(parent){
    QHBoxLayout* layout = new QHBoxLayout(this);
    layout->setAlignment(Qt::AlignLeft| Qt::AlignTop);

    query = new QLineEdit();
    query->setPlaceholderText("sensore");
    query->setFixedWidth(300);
    layout->addWidget(query);

    QPushButton* search_button = new QPushButton(QIcon(QPixmap(":/Asset/icons/Search.svg")), "search");
    search_button->setFixedWidth(90);//160
    layout->addWidget(search_button);

    connect(search_button, &QPushButton::clicked, this, &SearchWidget::search);
}
void SearchWidget::search(){
    std::string query_text = query->text().toStdString();
    emit search_event(query_text);
}





}


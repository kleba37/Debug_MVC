#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QDebug>
#include <Model.h>
#include <View.h>

class Controller : public QObject
{
    Q_OBJECT
private:
    Model * m_model;
    View * m_view;
public:
    explicit Controller() : m_model(nullptr), m_view(nullptr){
        //QObject::connect(this, &Controller::signalScale, this, &Controller::scale);
    };
    ~Controller(){};
    void setModel(Model * model){
        this->m_model = model;
    };
    void setView(View * view){
        this->m_view = view;
    };
public slots:
    void scale(){
        this->m_model->getModel()->setSize(QSize(this->m_model->getModel()->width() * 2, this->m_model->getModel()->height() * 2));
        emit this->m_view->modelChanged();
        qDebug() << "scale";
    }
signals:
    void signalScale();
};

#endif // CONTROLLER_H

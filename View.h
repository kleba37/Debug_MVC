#ifndef VIEW_H
#define VIEW_H

#include <QObject>
#include <QDebug>
#include <QWidget>
#include <QPainter>
#include <Model.h>

class View : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(Model* model WRITE setModel NOTIFY modelChanged)

private:
    Model * m_model;
public:
    explicit View(QWidget *parent = nullptr) : QWidget(parent), m_model(new Model()){
        QObject::connect(this, &View::modelChanged, this, &View::changed);
    };
    View * operator=(View & view){
        this->m_model = view.m_model;
        return this;
    }
    void setModel(Model *newModel){
        this->m_model = newModel;
        emit modelChanged();
    };
public slots:
    void changed(){
        this->repaint();
        qDebug() << "change";
    }
signals:
    void modelChanged();

protected:
    void paintEvent(QPaintEvent *event)
    {
        QPainter painter(this);
        painter.drawEllipse(*this->m_model->getModel());
        qDebug() << "=== Paint";
    }
};


#endif // VIEW_H

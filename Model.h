#ifndef MODEL_H
#define MODEL_H

#include <QObject>
#include <QRect>

class Model : public QObject
{
    Q_OBJECT
private:
    QRect *m_model;
public:
    explicit Model(QRect * model = new QRect(0,0, 50,50)): m_model(model){};
    QRect * getModel(){return this->m_model;}
signals:

};

#endif // MODEL_H

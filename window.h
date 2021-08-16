#ifndef WINDOW_H
#define WINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QGridLayout>
#include <QPushButton>
#include <controller.h>
#include <View.h>

class Window : public QMainWindow
{
    Q_OBJECT
private:
    View * m_view;
    Controller * m_controller;
public:
    Window(QWidget *parent = nullptr) : QMainWindow(parent), m_controller(new Controller()){
        QWidget *mainWidget = new QWidget(this);
        this->setCentralWidget(mainWidget);

        QGridLayout *mainLayout = new QGridLayout();
        mainWidget->setLayout(mainLayout);

        this->m_view = new View(mainWidget);
        mainLayout->addWidget(this->m_view);

        QPushButton *button = new QPushButton("Тест", mainWidget);
        mainLayout->addWidget(button);

        this->setMinimumSize(300,300);

        QObject::connect(button, &QPushButton::clicked, this, &Window::scale);
    };
    ~Window(){};
    void setView(View * view){
        *(this->m_view) = *view;
    };
    void setController(Controller * controller){
        this->m_controller = controller;
    };
public slots:
    void scale(){
        this->m_controller->scale();
    }
};
#endif // WINDOW_H

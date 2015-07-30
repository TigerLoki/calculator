#ifndef WINDOW_H
#define WINDOW_H

#include <QMainWindow>

class window : public QMainWindow
{
    Q_OBJECT

public:
    window(QWidget *parent = 0);
    ~window();
};

#endif // WINDOW_H

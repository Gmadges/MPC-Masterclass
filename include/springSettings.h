#ifndef SPRINGSETTINGS_H
#define SPRINGSETTINGS_H

#include <QWidget>

class Model;

namespace Ui {
class SpringSettings;
}

//TODO
// Consider making this inherit from a generic settings class

class SpringSettings : public QWidget
{
    Q_OBJECT
public:
    
    SpringSettings(QWidget *parent = 0);
    virtual ~SpringSettings();

    Ui::SpringSettings *ui;
};

#endif 

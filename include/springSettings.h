#ifndef SPRINGSETTINGS_H
#define SPRINGSETTINGS_H

#include <QWidget>
#include "settings.h"

class SpringSettings : public Settings
{
    Q_OBJECT
public:
    
    SpringSettings(QWidget *parent = 0);
    virtual ~SpringSettings();

private:
    void initUI();
};

#endif 

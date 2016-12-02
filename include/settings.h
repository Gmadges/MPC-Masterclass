#ifndef SETTINGS_H
#define SETTINGS_H

#include <QWidget>

class Settings : public QWidget
{
    Q_OBJECT
public:
    
    Settings(QWidget *parent = 0);
    virtual ~Settings();

    // TODO abstract method that returns settings
    //virtual void getSettings() = 0;
    
private:
    virtual void initUI() = 0;
};

#endif 

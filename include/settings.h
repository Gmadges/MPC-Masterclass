#ifndef SETTINGS_H
#define SETTINGS_H

#include <QWidget>

namespace Ui {
class Settings;
}

class Settings : public QWidget
{
    Q_OBJECT
public:
    
    Settings(QWidget *parent = 0);
    virtual ~Settings();

public:
    Ui::Settings *ui;
};

#endif 

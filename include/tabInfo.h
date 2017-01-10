#ifndef TABINFO_H
#define TABINFO_H

#include <QWidget>
#include <memory>
#include "types.h"

class Model;
class Settings;

namespace Ui {
class TabInfo;
}

class TabInfo : public QWidget
{
    Q_OBJECT
public:
    
    TabInfo(std::shared_ptr<Model> _model, QWidget *parent = 0);
    virtual ~TabInfo();

private:
    void initConnections();
    void initUI();

    void setMaxSphereCount(int num);
    void setSphereOverlap(bool enable);
    void setSphereMaxSize(double size);
    void setSphereMinSize(double size);

    //plastic
    void setPlasticDeform(bool _deform);
    void setMaxPlasticForce(double _value);
    void setMinPlasticForce(double _value);

    void setShowMesh(bool set);
    void setShowPhys(bool set);
    void reset();
    void setConstraintType(int idx);
    BodyConstraintType getConstType(int idx);
    void displaySettings(BodyConstraintType type);

    void applyConstraintSettings();

private:
    std::shared_ptr<Model> pModel;

    Ui::TabInfo *ui;

    Settings *pCurrentSettings;
};

#endif 

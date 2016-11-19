#ifndef TABINFO_H
#define TABINFO_H

#include <QWidget>
#include <memory>

class Model;

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

    void setShowMesh(bool set);
    void setShowPhys(bool set);
    void reset();

private:
    std::shared_ptr<Model> pModel;

    Ui::TabInfo *ui;
};

#endif // GLSCENE_H

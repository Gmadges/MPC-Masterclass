#ifndef TABINFO_H
#define TABINFO_H

#include <QWidget>
#include <memory>

class Model;

class TabInfo : public QWidget
{
    Q_OBJECT
public:
    
    TabInfo(std::shared_ptr<Model> _model, QWidget *parent = 0);
    virtual ~TabInfo();

private:
    std::shared_ptr<Model> pModel;
};

#endif // GLSCENE_H

#include "tabInfo.h"
#include "model.h"

TabInfo::TabInfo(std::shared_ptr<Model> _model, QWidget *parent) :
    QWidget(parent),
    pModel(_model)
{

}

TabInfo::~TabInfo()
{
}
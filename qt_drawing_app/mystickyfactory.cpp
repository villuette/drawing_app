#include "mystickyfactory.h"

MyStickyFactory::MyStickyFactory()
{

}
MyShape* MyStickyFactory::createShape(QWidget *parent){
    auto sticky = new MyStickyShape(parent);
    if(auto dr = qobject_cast<DrawingArea*>(parent)){
        dr->addObserver(sticky);
    }
    return sticky;
}

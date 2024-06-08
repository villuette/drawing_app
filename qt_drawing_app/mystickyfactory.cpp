#include "mystickyfactory.h"

MyStickyFactory::MyStickyFactory()
{

}
MyShape* MyStickyFactory::createShape(QWidget *parent){
    return new MyStickyShape(parent);
}

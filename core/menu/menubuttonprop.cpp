#include "menubuttonprop.h"

#include "prop.h"

int MenuButtonProp::size()
{
    return Prop::btn_menu;
}

QString MenuButtonProp::accessibleName()
{
    return "menu";
}

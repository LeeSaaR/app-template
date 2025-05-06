#ifndef APPMENU_H
#define APPMENU_H


#include "menupage.h"

class AppMenu
{
private:
    AppMenu(){};
public:
    static void setMenuPage(MenuPage::Menu page);
    static void enableNavigation(const bool &enable);
};

#endif // APPMENU_H

#ifndef MENUFACTORY_H
#define MENUFACTORY_H

/*
 * SINGLETON:
 * MenuFactory is called in AppInitializer
 * It is just used for creating WidgetMenuBar and WidgetMenuPage of AppWindow,
 * that are defined in this Class.
 */

#include "menupage.h"
#include <QList>
class MenuFactory
{
protected:
    static MenuFactory *m_instance;
private:
    QList<MenuPage::Menu> m_menu_pages = {
        MenuPage::Menu0,
        MenuPage::Menu1,
        MenuPage::Menu2,
        MenuPage::Menu3,
        MenuPage::Menu4,
        MenuPage::Menu5,
        MenuPage::Menu6
    };
    int page_index = 0;
private:
    MenuFactory(){}
public:
    MenuFactory(MenuFactory &other) = delete;
    void operator=(const MenuFactory &other) = delete;
    static MenuFactory *GetInstance();
private:
    MenuPage::Menu usePage();
public:
    void createMenuButtons();
    void createMenuPages();
};

#endif // MENUFACTORY_H

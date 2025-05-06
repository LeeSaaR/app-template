#include "appmenu.h"

#include "appwindow.h"
#include "widgetmenubar.h"

void AppMenu::setMenuPage(MenuPage::Menu page)
{
    WidgetMenuBar* menuBar = AppWindow::MenuBar();
    menuBar->activateMenu(page);
}

void AppMenu::enableNavigation(const bool &enable)
{
    WidgetMenuBar* menuBar = AppWindow::MenuBar();
    menuBar->enableNavigation(enable);
}

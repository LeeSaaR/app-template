#include "menufactory.h"
#include <QLabel>

#include "appwindow.h"

MenuFactory *MenuFactory::m_instance = nullptr;

MenuFactory *MenuFactory::GetInstance()
{
    if (m_instance == nullptr)
        m_instance = new MenuFactory();

    return m_instance;
}

MenuPage::Menu MenuFactory::usePage()
{
    if (page_index == m_menu_pages.size())
        page_index = 0;
    return m_menu_pages.at(page_index++);
}

void MenuFactory::createMenuButtons()
{
    qDebug() << __FUNCTION__;
    AppWindow* app_window = AppWindow::get();
    AppMenuBar* menu_bar = app_window->MenuBar();

    page_index = 0;
    // ADD YOUR MENU BUTTONS HERE
    menu_bar->addButton(usePage(), "Home", ":/icons/home.svg", ":/icons/home.svg");
    menu_bar->addButton(usePage(), "Page 1", ":/icons/group.svg", ":/icons/group.svg");
    // menu_bar->addButton(usePage(), "Page 2", ":/icons/car.svg", ":/icons/car.svg");
    menu_bar->setMenuHome();
}

void MenuFactory::createMenuPages()
{
    qDebug() << __FUNCTION__;
    AppWindow* app_window = AppWindow::get();
    WidgetMenuPage* menu_pages = app_window->MenuPages();
    AppMenuBar* menu_bar = app_window->MenuBar();

    // ADD YOUR WIDGETS HERE
    QLabel* wgt_1 = new QLabel("Home", app_window);
    QLabel* wgt_2 = new QLabel("Page", app_window);

    menu_pages->addMenu(wgt_1);
    menu_pages->addMenu(wgt_2);
    // menu_pages->addMenu(wgt_3);

    // CONNECT YOUR WIDGETS HERE
    // QObject::connect( wgt_1, &MyCustomWidget::sendSomething, wgt_2, &MyCustomWidget::onSendSomething );
    // QObject::connect( wgt_2, &MyCustomWidget::sendSomething, wgt_1, &MyCustomWidget::onSendSomething );

    /**
     *
     * NOTE: See menupage.h
     * There you can define:
     * MenuPage::State and MenuPage::Menu
     *
     */
    // LOAD INITIAL MENU STATE
    menu_bar->setMenuState( MenuPage::LoadedProject );
}

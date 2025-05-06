/*
 * Apps Menu Bar Widget
 * Add a Menu Button:
 * 1. Copy a menu button in widgetmenubar.ui with Qt Designer
 * and place it behind the other buttons in the frame.
 *
 * 2. For consistency rename it to something like btn_menu_"mybutton".
 *
 * 3. Add a menu name to the WidgetMenuBar::Menu enum in widgetmenubar.h.
 *
 * 4. Add a page to the stacked widget in appwindow.ui with Qt Designer
 * and make sure that the page indecies of the stacked widget are matching
 * the WidgetMenuBar::Menu enum.
 *
 * Connect the Button:
 * 1. In WidgetMenuBar::initConnection() connect the button like
 * connect your btn_menu_"mybutton" clicked signal to onClickedMenuButton slot like:
 * connect(ui->btn_menu_"mybutton", &QPushButton::clicked, this, &WidgetMenuBar::onClickedMenuButton);
 *
 * 2. In WidgetMenuBar::onClickedMenuButton() add another else if statement
 * and emit the signal menuButtonClicked with proper WidgetMenuBar::Menu like:
 * ...
 * else if (ui->btn_menu_"mybutton" == menuButton)
 * {
 *    emit menuButtonClicked(WidgetMenuBar::Other);
 * }
 *
 * Optional Set Icon:
 * The menu button's size is 50px * 50px.
 * 1. Get two 50px*50px sized .png images for the button.
 * One should be have a black the other should have a white symbol.
 * Place them into ./res/icons folder.
 * Add these .png files with the Resource Editor.
 *
 * 2. Add two QIcon in widgetmenubar.h. and name them like:
 * QIcon menu_"mybutton"_dark
 * QIcon menu_"mybutton"_light
 *
 * 3. Add File to the QIcons:
 * menu_"mybutton"_dark.addFile(":/icons/my_icon_white.png", QSize(50,50), QIcon::Normal, QIcon::On);
 * menu_"mybutton"_light.addFile(":/icons/my_icon_black.png", QSize(50,50), QIcon::Normal, QIcon::Off);
 * Note that the dark icon has to get the white image, the light icon the black image.
 *
 * 4. Set icon in WidgetMenuBar::setTheme(bool dark) like
 * the others and resize the icon to 50x50
*/

#include "appmenubar.h"
#include "menubutton.h"

#include <QButtonGroup>
#include <QDebug>

AppMenuBar* AppMenuBar::m_instance = nullptr;

AppMenuBar::AppMenuBar(QWidget *parent) :
    WidgetMenuBar(parent)
{
    m_instance = this;
    menu_button_group = new QButtonGroup();
    menu_button_group->setExclusive(true);
}

AppMenuBar::~AppMenuBar()
{

}

void AppMenuBar::setMenuHome()
{
    menu_buttons.first()->setChecked(true);
    current_menu = MenuPage::Menu0;
}

void AppMenuBar::setMenuState(MenuPage::State state)
{
    /**
     * See: menufactory.cpp
     * MODIFY THIS
     */
    switch (state) {
    case MenuPage::LoadedProject:
        showMenu(MenuPage::Menu0, true);
        showMenu(MenuPage::Menu1, true);
        activateMenu(MenuPage::Menu0);
        break;
    default:
        break;
    }
}

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

#include "widgetmenubar.h"
#include "ui_widgetmenubar.h"

#include "appwindow.h"
#include "menubutton.h"
#include "menubuttonprop.h"
#include "appconfiguration.h"

#include <QButtonGroup>
#include <QDebug>


WidgetMenuBar::WidgetMenuBar(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WidgetMenuBar)
{
    ui->setupUi(this);
    // menu_button_group = new QButtonGroup();
    // menu_button_group->setExclusive(true);
}

WidgetMenuBar::~WidgetMenuBar()
{
    delete ui;
}

void WidgetMenuBar::addButton(MenuPage::Menu menu, const QString &name, const QString &icon_light, const QString &icon_dark)
{
    MenuButton *btn = new MenuButton(this);
    btn->setMenu(menu);
    btn->setText(name);
    menu_buttons.append(btn);
    map_menu[menu] = btn;
    menu_button_group->addButton(btn);
    ui->frame_buttons->layout()->addWidget(btn);
    connect(btn, &MenuButton::selected, this, &WidgetMenuBar::onClickedMenuButton);
    addIcon(btn, icon_light, icon_dark);
}

void WidgetMenuBar::addIcon(MenuButton* btn, const QString &icon_light, const QString &icon_dark)
{
    if (!icon_light.isEmpty()) {
        btn->setText("");
    }

    const int size = MenuButtonProp::size();
    menu_dark_icon[btn] = QIcon();
    menu_dark_icon[btn].addFile(icon_dark, QSize(size,size), QIcon::Normal, QIcon::On);
    menu_dark_icon[btn].addFile(icon_light, QSize(size,size), QIcon::Normal, QIcon::Off);

    menu_light_icon[btn] = QIcon();
    menu_light_icon[btn].addFile(icon_light, QSize(size,size), QIcon::Normal, QIcon::On);
    menu_light_icon[btn].addFile(icon_dark, QSize(size,size), QIcon::Normal, QIcon::Off);
}

void WidgetMenuBar::removeItems(QSpacerItem *spacer_left, QSpacerItem *spacer_right, QSpacerItem *spacer_top, QSpacerItem *spacer_bottom, QList<QPushButton *> menu_btns)
{
    // Remove Items From Layout
    ui->frame_menubar->layout()->removeItem(spacer_left);
    ui->frame_menubar->layout()->removeItem(spacer_right);
    ui->frame_menubar->layout()->removeItem(spacer_top);
    ui->frame_menubar->layout()->removeItem(spacer_bottom);

    QPushButton* btn;
    foreach (btn, menu_btns)
        ui->frame_menubar->layout()->removeWidget(btn);
}

void WidgetMenuBar::addHorizontalLayout()
{
    QHBoxLayout* new_layout = new QHBoxLayout;
    new_layout->setContentsMargins(0,0,0,0);
    new_layout->setSpacing(0);
    delete ui->frame_menubar->layout();
    ui->frame_menubar->setLayout(new_layout);
}

void WidgetMenuBar::addVerticalLayout()
{
    QVBoxLayout* new_layout = new QVBoxLayout;
    new_layout->setContentsMargins(0,0,0,0);
    new_layout->setSpacing(0);
    delete ui->frame_menubar->layout();
    ui->frame_menubar->setLayout(new_layout);
}

void WidgetMenuBar::setVerticalTop()
{
    // Get Items
    QSpacerItem *spacer_left = ui->spacer_left;
    QSpacerItem *spacer_right = ui->spacer_right;
    QSpacerItem *spacer_top = ui->spacer_top;
    QSpacerItem *spacer_bottom = ui->spacer_bottom;
    QList<QPushButton*> menu_btns = findChildren<QPushButton*>();

    // Remove Items From Layout
    removeItems(spacer_left, spacer_right, spacer_top, spacer_bottom, menu_btns);

    // Change Layout Type
    addVerticalLayout();

    // add items to frame
    QPushButton* btn;
    foreach (btn, menu_btns) {
        ui->frame_menubar->layout()->addWidget(btn);
    }
    ui->frame_menubar->layout()->addItem(spacer_bottom);
}

void WidgetMenuBar::setVerticalCenter()
{
    // Get Items
    QSpacerItem *spacer_left = ui->spacer_left;
    QSpacerItem *spacer_right = ui->spacer_right;
    QSpacerItem *spacer_top = ui->spacer_top;
    QSpacerItem *spacer_bottom = ui->spacer_bottom;
    QList<QPushButton*> menu_btns = findChildren<QPushButton*>();

    // Remove Items From Layout
    removeItems(spacer_left, spacer_right, spacer_top, spacer_bottom, menu_btns);

    // Change Layout Type
    addVerticalLayout();

    // Re-Add Items
    ui->frame_menubar->layout()->addItem(spacer_top);
    QPushButton* btn;
    foreach (btn, menu_btns) {
        ui->frame_menubar->layout()->addWidget(btn);
    }
    ui->frame_menubar->layout()->addItem(spacer_bottom);
}

void WidgetMenuBar::setHorizontalLeft()
{
    // Get Items
    QSpacerItem *spacer_left = ui->spacer_left;
    QSpacerItem *spacer_right = ui->spacer_right;
    QSpacerItem *spacer_top = ui->spacer_top;
    QSpacerItem *spacer_bottom = ui->spacer_bottom;
    QList<QPushButton*> menu_btns = findChildren<QPushButton*>();

    // Remove Items From Layout
    removeItems(spacer_left, spacer_right, spacer_top, spacer_bottom, menu_btns);

    // Change Layout Type
    addHorizontalLayout();

    // Re-Add Items
    QPushButton* btn;
    foreach (btn, menu_btns) {
        ui->frame_menubar->layout()->addWidget(btn);
    }
    ui->frame_menubar->layout()->addItem(spacer_right);
}

void WidgetMenuBar::setHorizontalCenter()
{
    // Get Items
    QSpacerItem *spacer_left = ui->spacer_left;
    QSpacerItem *spacer_right = ui->spacer_right;
    QSpacerItem *spacer_top = ui->spacer_top;
    QSpacerItem *spacer_bottom = ui->spacer_bottom;
    QList<QPushButton*> menu_btns = findChildren<QPushButton*>();

    // Remove Items From Layout
    removeItems(spacer_left, spacer_right, spacer_top, spacer_bottom, menu_btns);

    // Change Layout Type
    addHorizontalLayout();

    // Re-Add Items
    ui->frame_menubar->layout()->addItem(spacer_left);
    QPushButton* btn;
    foreach (btn, menu_btns) {
        ui->frame_menubar->layout()->addWidget(btn);
    }
    ui->frame_menubar->layout()->addItem(spacer_right);
}

void WidgetMenuBar::enableButtons(const bool &enable)
{
    MenuButton* btn;
    foreach (btn, menu_buttons)
        btn->setEnabled(enable);
}

void WidgetMenuBar::updateMenuPosition()
{
    AppWindow *app_window = AppWindow::get();
    AppConfiguration* appConfig = AppConfiguration::GetInstance();
    WidgetMenuBar::MenuPosition menu_pos = app_window->MenuBar()->getMenuPosition(appConfig->getConfigData("MenuPosition"));
    app_window->MenuBar()->setMenuPosition(
        app_window->menuLeft->layout(),
        app_window->menuTop->layout(),
        app_window->menuRight->layout(),
        app_window->menuBottom->layout(),
        menu_pos );
}

WidgetMenuBar::MenuPosition WidgetMenuBar::getMenuPosition(const QString &name)
{
    if (name == "Left Top") {
        return MenuPosition::LeftTop;
    }
    else if (name == "Left Center") {
        return MenuPosition::LeftCenter;
    }
    else if (name == "Top Left") {
        return MenuPosition::TopLeft;
    }
    else if (name == "Top Center") {
        return MenuPosition::TopCenter;
    }
    else if (name == "Right Top") {
        return MenuPosition::RightTop;
    }
    else if (name == "Right Center") {
        return MenuPosition::RightCenter;
    }
    else if (name == "Bottom Left") {
        return MenuPosition::BottomLeft;
    }
    else if (name == "Bottom Center") {
        return MenuPosition::BottomCenter;
    }
    return MenuPosition::LeftTop;
}

QList<QString> WidgetMenuBar::getMenuPositions()
{
    return {
        "Left Top",
        "Left Center",
        "Top Left",
        "Top Center",
        "Right Top",
        "Right Center",
        "Bottom Left",
        "Bottom Center"
    };
}

void WidgetMenuBar::setMenuPosition(QLayout *left, QLayout *top, QLayout *right, QLayout *bottom, MenuPosition menu_pos)
{
    switch (menu_pos) {
    case MenuPosition::TopLeft:
        setHorizontalLeft();
        top->addWidget(this);
        break;

    case MenuPosition::TopCenter:
        top->addWidget(this);
        setHorizontalCenter();
        break;

    case MenuPosition::LeftTop:
        setVerticalTop();
        left->addWidget(this);
        break;

    case MenuPosition::LeftCenter:
        setVerticalCenter();
        left->addWidget(this);
        break;

    case MenuPosition::BottomLeft:
        setHorizontalLeft();
        bottom->addWidget(this);
        break;

    case MenuPosition::BottomCenter:
        setHorizontalCenter();
        bottom->addWidget(this);
        break;

    case MenuPosition::RightTop:
        setVerticalTop();
        right->addWidget(this);
        break;

    case MenuPosition::RightCenter:
        setVerticalCenter();
        right->addWidget(this);
        break;

    default:
        setVerticalTop();
        left->addWidget(this);
        break;
    }
}

void WidgetMenuBar::setTheme(const bool &dark)
{
    const int size = MenuButtonProp::size();
    MenuButton* btn;
    foreach (btn, menu_buttons) {
        if (dark)
            btn->setIcon(menu_dark_icon[btn]);
        else
            btn->setIcon(menu_light_icon[btn]);
        btn->setIconSize(QSize(size,size));
    }
}

void WidgetMenuBar::activateMenu(MenuPage::Menu menu)
{
    if (!m_nav_enabled) return;
    if (current_menu == menu) return;

    menu_buttons.at(menu)->setChecked(true);
    current_menu = menu;
    emit menuButtonClicked(menu);
}

void WidgetMenuBar::enableNavigation(const bool &enable)
{
    qDebug() << __FUNCTION__;
    m_nav_enabled = enable;
    enableButtons(m_nav_enabled);
}

void WidgetMenuBar::showMenu(MenuPage::Menu menu, const bool &toggle)
{
    map_menu[menu]->setVisible(toggle);
}

void WidgetMenuBar::setMenuHome()
{

}

void WidgetMenuBar::setMenuState(MenuPage::State state)
{

}

void WidgetMenuBar::onClickedMenuButton(MenuPage::Menu menu)
{
    if (!m_nav_enabled) return;
    if (current_menu == menu) return;

    current_menu = menu;
    emit menuButtonClicked(menu);
}

void WidgetMenuBar::onActivatedMenuButton(MenuPage::Menu menu)
{
    activateMenu( menu );
}

#ifndef WIDGETMENUBAR_H
#define WIDGETMENUBAR_H

#include <QPushButton>
#include <QSpacerItem>
#include <QWidget>
#include "menubutton.h"
#include "menupage.h"

namespace Ui {
class WidgetMenuBar;
}

class WidgetMenuBar : public QWidget
{
    Q_OBJECT

private:
    Ui::WidgetMenuBar *ui;
protected:
    MenuPage::Menu current_menu;
    QIcon menu_home_dark;
    QIcon menu_home_light;
    QButtonGroup *menu_button_group;
    QMap<MenuButton*, QIcon> menu_dark_icon;
    QMap<MenuButton*, QIcon> menu_light_icon;
    QList<MenuButton*> menu_buttons;
    QMap<MenuPage::Menu, MenuButton*> map_menu;
    bool m_nav_enabled = true;
public:
    explicit WidgetMenuBar(QWidget *parent = nullptr);
    ~WidgetMenuBar();
    enum MenuPosition {
        LeftTop = 0,
        LeftCenter = 1,
        TopLeft,
        TopCenter,
        RightTop,
        RightCenter,
        BottomLeft,
        BottomCenter
    };

protected:
    void addIcon(MenuButton *btn, const QString &icon_light, const QString &icon_dark);
    void removeItems(QSpacerItem *spacer_left, QSpacerItem *spacer_right, QSpacerItem *spacer_top, QSpacerItem *spacer_bottom, QList<QPushButton *> menu_btns);
    void addHorizontalLayout();
    void addVerticalLayout();
    void setVerticalTop();
    void setVerticalCenter();
    void setHorizontalLeft();
    void setHorizontalCenter();
    void enableButtons(const bool &enable);
public:
    static void updateMenuPosition();
    void addButton(MenuPage::Menu menu, const QString &name, const QString &icon_light, const QString &icon_dark);
    MenuPosition getMenuPosition(const QString &name);
    static QList<QString> getMenuPositions();
    void setMenuPosition(QLayout* left, QLayout* top, QLayout* right, QLayout* bottom, MenuPosition menu_pos);
    void setTheme(const bool &dark);
public:
    void activateMenu(MenuPage::Menu menu);
    void enableNavigation(const bool &enable);
    void showMenu(MenuPage::Menu menu, const bool& toggle);
    virtual void setMenuHome();
    virtual void setMenuState(MenuPage::State state);
public slots:
    void onClickedMenuButton(MenuPage::Menu menu);
    void onActivatedMenuButton(MenuPage::Menu menu);
signals:
    void menuButtonClicked(MenuPage::Menu menu);
};

#endif // WIDGETMENUBAR_H

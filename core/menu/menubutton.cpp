#include "menubutton.h"
#include "menubuttonprop.h"
MenuButton::MenuButton(QWidget *parent)
    : QPushButton(parent)
{
    connect(this, &MenuButton::clicked, this, &MenuButton::onClicked);
    setMinimumHeight(MenuButtonProp::size());
    setMaximumHeight(MenuButtonProp::size());
    setMinimumWidth(MenuButtonProp::size());
    setMaximumWidth(MenuButtonProp::size());
    setAccessibleName(MenuButtonProp::accessibleName());
    setCheckable(true);
    setChecked(false);
}

void MenuButton::setMenu(MenuPage::Menu menu)
{
    m_menu = menu;
}

void MenuButton::onClicked()
{
    emit selected(m_menu);
}

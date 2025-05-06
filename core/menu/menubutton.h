#ifndef MENUBUTTON_H
#define MENUBUTTON_H

#include <QPushButton>
#include <QWidget>

#include "menupage.h"

class MenuButton : public QPushButton
{
    Q_OBJECT

private:
    MenuPage::Menu m_menu;
public:
    explicit MenuButton(QWidget *parent = nullptr);

signals:
    void selected(MenuPage::Menu menu);

public:
    void setMenu(MenuPage::Menu menu);

public slots:
    void onClicked();
};

#endif // MENUBUTTON_H

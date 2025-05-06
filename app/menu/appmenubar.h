#ifndef APPMENUBAR_H
#define APPMENUBAR_H

#include "widgetmenubar.h"
#include "menupage.h"

#include <QPushButton>
#include <QSpacerItem>
#include <QWidget>

class AppMenuBar : public WidgetMenuBar
{
    Q_OBJECT

private:
    static AppMenuBar* m_instance;
public:
    explicit AppMenuBar(QWidget *parent = nullptr);
    ~AppMenuBar();
    static AppMenuBar* get() {return m_instance;}
public:
    virtual void setMenuHome() override;
    virtual void setMenuState(MenuPage::State state) override;
};

#endif // APPMENUBAR_H

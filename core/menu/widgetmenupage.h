#ifndef WIDGETMENUPAGE_H
#define WIDGETMENUPAGE_H

#include <QWidget>
#include "menupage.h"

namespace Ui {
class WidgetMenuPage;
}

class WidgetMenuPage : public QWidget
{
    Q_OBJECT

private:
    Ui::WidgetMenuPage *ui;
    QList<QWidget*> m_list_widgets;
public:
    explicit WidgetMenuPage(QWidget *parent = nullptr);
    ~WidgetMenuPage();

public:
    void setMenu(MenuPage::Menu menu);
    void addMenu(QWidget *widget);

public slots:
    void onClickedMenuButton(MenuPage::Menu menu);
};

#endif // WIDGETMENUPAGE_H

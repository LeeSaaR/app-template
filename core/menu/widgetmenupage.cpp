#include "widgetmenupage.h"
#include "ui_widgetmenupage.h"

#include <QDebug>

WidgetMenuPage::WidgetMenuPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WidgetMenuPage)
{
    ui->setupUi(this);
}

WidgetMenuPage::~WidgetMenuPage()
{
    delete ui;
}

void WidgetMenuPage::setMenu(MenuPage::Menu menu)
{
    ui->stackedWidget->setCurrentIndex(menu);
}

void WidgetMenuPage::addMenu(QWidget *widget)
{
    const int count = ui->stackedWidget->count();
    ui->stackedWidget->insertWidget(count, widget);
    m_list_widgets.append(widget);
}

void WidgetMenuPage::onClickedMenuButton(MenuPage::Menu menu)
{
    setMenu(menu);
}

#include "widgetpropsection.h"
#include "./ui_widgetpropsection.h"

WidgetPropSection::WidgetPropSection(QWidget *parent, const QString &sectionName, const bool &isTop) :
    QWidget(parent),
    ui(new Ui::WidgetPropSection)
{
    ui->setupUi(this);
    if (isTop) {
        ui->label_sub->hide();
        ui->label_top->setText(sectionName);
    }
    else {
        ui->label_top->hide();
        ui->label_sub->setText(sectionName);
    }
}

WidgetPropSection::~WidgetPropSection()
{
    delete ui;
}

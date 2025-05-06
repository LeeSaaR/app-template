#ifndef PROPITEMSCONTROLLER_H
#define PROPITEMSCONTROLLER_H

#include <QWidget>
#include "configdata.h"

#include "widgetpropdir.h"
#include "widgetpropfile.h"
#include "widgetpropdropdown.h"
#include "widgetpropdropdownfile.h"
#include "widgetpropsection.h"
#include "widgetproptext.h"

class PropItemsController
{
private:
    QWidget *m_parent;

public:
    PropItemsController(QWidget *parent = nullptr);
    ~PropItemsController();

public:
    // Methods
    WidgetPropSection *addItemPropSection(const QString &sectionName, const bool &isTop = false);
    QWidget *addItem(ConfigData* config_data);

    WidgetPropDir *addItemDir(ConfigData* config_data);
    WidgetPropDropDown *addItemDropDown(ConfigData *config_data);
    WidgetPropDropDownFile *addItemDropDownFile(ConfigData* config_data);
    WidgetPropFile *addItemFile(ConfigData *config_data);
    WidgetPropText *addItemText(ConfigData *config_data);
};

#endif // PROPITEMSCONTROLLER_H

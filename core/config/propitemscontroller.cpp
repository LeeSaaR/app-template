#include "propitemscontroller.h"

#include <QDebug>


PropItemsController::PropItemsController(QWidget *parent)
    : m_parent(parent)
{
}

PropItemsController::~PropItemsController()
{
}

QWidget *PropItemsController::addItem(ConfigData *config_data)
{
    switch (config_data->type()) {
    case ConfigData::Dir:
        return addItemDir(config_data);
        break;

    case ConfigData::DropDown:
        return addItemDropDown(config_data);
        break;

    case ConfigData::DropDownFile:
        return addItemDropDownFile(config_data);
        break;

    case ConfigData::File:
        return addItemFile(config_data);

        break;

    case ConfigData::Text:
        return addItemText(config_data);
        break;

    default:
        return nullptr;
        break;
    }
    return nullptr;
}

WidgetPropSection *PropItemsController::addItemPropSection(const QString &sectionName, const bool &isTop)
{
    return new WidgetPropSection(m_parent, sectionName, isTop);
}

WidgetPropDir *PropItemsController::addItemDir(ConfigData* config_data)
{
    return new WidgetPropDir(config_data, m_parent);
}

WidgetPropDropDown *PropItemsController::addItemDropDown(ConfigData* config_data)
{
    return new WidgetPropDropDown(config_data, m_parent);
}

WidgetPropDropDownFile *PropItemsController::addItemDropDownFile(ConfigData *config_data)
{
    return new WidgetPropDropDownFile(config_data, m_parent);
}

WidgetPropFile *PropItemsController::addItemFile(ConfigData *config_data)
{
    return new WidgetPropFile(config_data, m_parent);
}

WidgetPropText *PropItemsController::addItemText(ConfigData *config_data)
{
    return new WidgetPropText(config_data, m_parent);
}



#include "propoptions.h"

#include "appdata.h"
#include "appio.h"

PropOptions* PropOptions::m_instance = nullptr;

PropOptions *PropOptions::GetInstance()
{
    if (m_instance == nullptr)
        m_instance = new PropOptions();
    return m_instance;
}

QList<QString> PropOptions::Themes() const
{
    // Configuration Options
    AppData* appData = AppData::GetInstance();
    return AppIO::listFiles(appData->dir_theme());
}

QList<QString> PropOptions::MenuPositions() const
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

QList<QString> PropOptions::Languages() const
{
    return {
        "Deutsch",
        "English"
    };
}

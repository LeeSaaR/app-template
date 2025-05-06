#include "themeloader.h"

#include <QDebug>
#include "appdata.h"
#include "appconfiguration.h"
#include "prop.h"

ThemeLoader* ThemeLoader::m_instance = nullptr;

ThemeLoader* ThemeLoader::GetInstance()
{
    if (m_instance == nullptr)
        m_instance = new ThemeLoader();

    return m_instance;
}

QString ThemeLoader::styleSheet()
{
    AppData* appData = AppData::GetInstance();
    AppConfiguration* appConfig = AppConfiguration::GetInstance();
    QFile file(appData->dir_theme() +"/"+ appConfig->getConfigData("CurrentTheme"));
    if (!file.open(QTextStream::ReadOnly | QTextStream::Text))
        qDebug() << "Could not load theme. :" << appConfig->getConfigData("CurrentTheme") << "skipping...";

    const QString style_sheet = file.readAll();
    file.close();

    setDarkTheme(style_sheet);

    return setVariables(style_sheet);
}

const bool ThemeLoader::isDarkTheme() &
{
    return m_is_dark_theme;
}

void ThemeLoader::setDarkTheme(const QString &styleSheet)
{
    if (styleSheet.at(2) == 'D')
        m_is_dark_theme = true;
    else
        m_is_dark_theme = false;
}

const QString ThemeLoader::setVariables(QString styleSheet)
{
    styleSheet.replace("<FONTSIZE_TITLE>",    Prop::fontsize_title);
    styleSheet.replace("<FONTSIZE_H1>",       Prop::fontsize_h1);
    styleSheet.replace("<FONTSIZE_DEFAULT>",  Prop::fontsize_default);
    styleSheet.replace("<FONTSIZE_BIG>",      Prop::fontsize_title);
    styleSheet.replace("<FONTSIZE_SMALL>",    Prop::fontsize_small);
    styleSheet.replace("<FONTSIZE_STATUS>",   Prop::fontsize_status);
    styleSheet.replace("<COLOR_MAIN>",        Prop::color_main);
    styleSheet.replace("<COLOR_MAIN_DARK>",   Prop::color_main_dark);
    styleSheet.replace("<COLOR_TEXT_STATUS>", Prop::color_text_status);
    styleSheet.replace("<BACKGROUND>",        Prop::back_main);
    styleSheet.replace("<MENU_BAR>",          Prop::back_menubar);
    styleSheet.replace("<MENU_BAR_SEL>",      Prop::back_menubar_sel);
    styleSheet.replace("<MENU_BAR_HOV>",      Prop::back_menubar_hov);
    styleSheet.replace("<MENU_BAR_COLOR>",    Prop::color_menubar);
    return styleSheet;
}

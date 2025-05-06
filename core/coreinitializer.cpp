#include "coreinitializer.h"

#include "appwindow.h"
#include "appconfiguration.h"
#include "appconnector.h"
#include "appdata.h"
#include "appinitializer.h"
#include "msgboxdata.h"
#include "apptext.h"
#include "coredialog.h"
#include "themeloader.h"

#include <QDebug>
#include <QObject>

bool CoreInitializer::is_initialized = false;

void CoreInitializer::initAppConfiguration()
{
    AppConfiguration* appConfig = AppConfiguration::GetInstance();
    if (!appConfig->is_initialized())
        appConfig->init();
}

void CoreInitializer::initAppData()
{
    AppWindow* app_window = AppWindow::get();
    AppData* appData = AppData::GetInstance();
    if (!appData->is_initialized())
        appData->init();

    app_window->setWindowTitle(appData->appName());
}

void CoreInitializer::initAppLanguage()
{
    AppText::setLanguage();
}

void CoreInitializer::initAppMessageBox()
{
    MsgBoxData::initData();
}

void CoreInitializer::initCoreDialog()
{
    AppWindow *app_window = AppWindow::get();
    CoreDialog::GetInstance(app_window);
    AppConnector::connectCoreDialog(true);
}

void CoreInitializer::initAppMenu()
{
    AppInitializer::initAppMenu();
}

void CoreInitializer::initNewProjectPages(WidgetProjectNew *widget_project_new)
{
    QList<WgtNewProject *> list = {};
    WidgetProjectName *wgt = new WidgetProjectName(widget_project_new);
    list.append(wgt);
    widget_project_new->initPages(list);
}

bool CoreInitializer::isFinished()
{
    return is_initialized;
}

void CoreInitializer::updateLanguage()
{
    initAppLanguage();
}

void CoreInitializer::initTheme()
{
    AppWindow* app_window = AppWindow::get();
    ThemeLoader *theme = ThemeLoader::GetInstance();
    app_window->setStyleSheet(theme->styleSheet());
}

void CoreInitializer::init()
{
    initAppData();
    initAppConfiguration();      // Dependency: initAppData()
    initAppLanguage();           // Dependency: initAppConfiguration()
    initTheme();                 // Dependency: initAppConfiguration()
    initAppMessageBox();         // Dependency: initAppLanguage()
    initCoreDialog();             // Dependency: initAppLanguage()
    AppInitializer::init();
    is_initialized = true;
}

void CoreInitializer::updateApp()
{
    updateTheme();
    updateLanguage();
    AppInitializer::updateApp();
}

void CoreInitializer::updateTheme()
{
    initTheme();
}

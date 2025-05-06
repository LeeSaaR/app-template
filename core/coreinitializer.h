#ifndef COREINITIALIZER_H
#define COREINITIALIZER_H

#include "wgtnewproject.h"
#include "widgetprojectnew.h"

class CoreInitializer
{
private:
    CoreInitializer(){}

private:
    static bool is_initialized;

private:
    static void initAppConfiguration();
    static void initAppData();
    static void initAppLanguage();
    static void initAppMessageBox();
    static void initCoreDialog();
    static void initMenu();
    static void initTheme();
    static void initAppMenu();

public:
    static void initNewProjectPages(WidgetProjectNew *widget_project_new);

public:
    static void init();
    static bool isFinished();

public:
    static void updateLanguage();
    static void updateApp();
    static void updateTheme();
};

#endif // COREINITIALIZER_H

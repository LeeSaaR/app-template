#ifndef APPINITIALIZER_H
#define APPINITIALIZER_H

#include "appwindow.h"
#include "wgtnewproject.h"
#include "widgetprojectnew.h"

class AppInitializer
{
private:
    AppInitializer(){}

public:
    static void init();

public:
    static void initAppMenu();
    static void initPdfViewer();
    static void initMenu();
    static void initMenuButtons();
    static void initPdfLetter();

public:
    static void updateApp();
    static void updateAppMenu();
    static void updateMenuButtons();
};

#endif // APPINITIALIZER_H

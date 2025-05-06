#include "appinitializer.h"

#include <QDebug>
#include <QObject>
#include <QLayout>
#include "appconnector.h"
#include "widgetmenupage.h"
#include "menufactory.h"
#include "appmenubar.h"
#include "themeloader.h"
#include "appwindow.h"
#include "pdfviewer.h"
#include "pdfletterinitializer.h"

void AppInitializer::init()
{
    qDebug() << __FUNCTION__;
    initAppMenu();
    initMenu();
    initMenuButtons();
    initPdfLetter();
    initPdfViewer();
}

void AppInitializer::initAppMenu()
{
    qDebug() << __FUNCTION__;
    AppConnector::createAppMenu();
}

void AppInitializer::initPdfViewer()
{
    qDebug() << __FUNCTION__;
    PdfViewer::GetInstance(AppWindow::get());
}

void AppInitializer::initMenu()
{
    qDebug() << __FUNCTION__;
    AppWindow *app_window = AppWindow::get();
    app_window->frameMain->layout()->addWidget(app_window->MenuPages());
    QObject::connect(
        AppWindow::MenuBar(), &AppMenuBar::menuButtonClicked,
        AppWindow::MenuPages(), &WidgetMenuPage::onClickedMenuButton);

    MenuFactory *menu_factory = MenuFactory::GetInstance();
    menu_factory->createMenuButtons();
    menu_factory->createMenuPages();
    AppWindow::MenuBar()->updateMenuPosition();
}

void AppInitializer::initMenuButtons()
{
    qDebug() << __FUNCTION__;
    AppWindow *app_window = AppWindow::get();
    ThemeLoader *theme = ThemeLoader::GetInstance();
    app_window->MenuBar()->setTheme(theme->isDarkTheme());
}

void AppInitializer::initPdfLetter()
{
    qDebug() << __FUNCTION__;
    PdfLetterInitializer::init();
}

void AppInitializer::updateApp()
{
    qDebug() << __FUNCTION__;
    AppWindow *app_window = AppWindow::get();
    updateAppMenu();
    app_window->MenuBar()->updateMenuPosition();
    updateMenuButtons();
}

void AppInitializer::updateAppMenu()
{
    qDebug() << __FUNCTION__;
    initAppMenu();
}

void AppInitializer::updateMenuButtons()
{
    qDebug() << __FUNCTION__;
    initMenuButtons();
}

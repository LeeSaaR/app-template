#ifndef APPCONNECTOR_H
#define APPCONNECTOR_H
/*
 * STATIC CLASS:
 * This class defines the QMenuBar of AppWindow.
 * It is only called on AppInitializer::init()
 * and on AppInitializer::updateApp().
 * Add more QAction in createAppMenu() and use
 * QObject::connect() to connect to other slots
 * via Fassade Objects.
*/

#include <QWidget>

class AppConnector
{
private:
    AppConnector(){}
    const static QString dots;
public:
    static void createAppMenu();
    static void clearAppMenu();
    static void connectCoreDialog(const bool &connect_dialog);
};

#endif // APPCONNECTOR_H

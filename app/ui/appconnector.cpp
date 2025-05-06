#include "appconnector.h"

#include "appwindow.h"
#include "apptext.h"
#include "coredialog.h"
#include <QMenuBar>
#include <QAction>
#include <QGraphicsDropShadowEffect>

const QString AppConnector::dots = "...";

void AppConnector::createAppMenu()
{
    qDebug() << __FUNCTION__;
    clearAppMenu();
    AppWindow *appWindow = AppWindow::get();
    CoreDialog* coreDialog = CoreDialog::GetInstance();

    QMenuBar *appMenu = appWindow->AppMenu();
    QAction* action = nullptr;

    // MENU
    QMenu* menu_menu    = appMenu->addMenu(AppText::menu_menu());
    // ACTION NEW
    action = menu_menu->addAction(AppText::action_new()+dots, QKeySequence("Ctrl+N"));
    QObject::connect(action, &QAction::triggered, [=](){coreDialog->openDialog(CoreDialog::New, appWindow);});

    // ACTION OPEN
    action = menu_menu->addAction(AppText::action_open()+dots, QKeySequence("Ctrl+O"));
    QObject::connect(action, &QAction::triggered, [=](){coreDialog->openDialog(CoreDialog::Open, appWindow);});

    // ACTION SAVE
    menu_menu->addSeparator();
    menu_menu->addAction(AppText::action_save(), QKeySequence("Ctrl+S"));
    menu_menu->addAction(AppText::action_save_as()+dots, QKeySequence("Ctrl+Shift+S"));

    // ACTION PREFERENCES
    menu_menu->addSeparator();
    action = menu_menu->addAction(AppText::action_preferences()+dots);
    QObject::connect(action, &QAction::triggered, [=](){coreDialog->openDialog(CoreDialog::Preferences, appWindow);});

    // ACTION EDIT
    menu_menu->addSeparator();
    action = menu_menu->addAction(AppText::action_exit());
    QObject::connect(action, &QAction::triggered, appWindow, &AppWindow::onExit);

    // EDIT
    // QMenu* menu_edit    = appMenu->addMenu(AppText::menu_edit());

    // ACTION UNDO/REDO
    // action = menu_edit->addAction(AppText::action_undo(), QKeySequence("Ctrl+Z"));
    // action = menu_edit->addAction(AppText::action_redo(), QKeySequence("Ctrl+Shift+Z"));

    // HELP
    QMenu* menu_help    = appMenu->addMenu(AppText::menu_help());

    // ACTION ABOUT
    action = menu_help->addAction(AppText::action_about()+dots);
    QObject::connect(action, &QAction::triggered, [=](){coreDialog->openDialog(CoreDialog::About, appWindow);});
}

void AppConnector::clearAppMenu()
{
    AppWindow *appWindow = AppWindow::get();
    QMenuBar *appMenu = appWindow->AppMenu();
    QList<QAction*> actions = appMenu->actions();
    QList<QAction*> delete_actions;
    for (QAction* action : std::as_const(actions)) {
        appMenu->removeAction(action);
        delete_actions.append(action);
    }
    if (!delete_actions.isEmpty())
        qDeleteAll(delete_actions);
    appMenu->clear();
}

void AppConnector::connectCoreDialog(const bool &connect_dialog)
{
    CoreDialog* coreDialog = CoreDialog::GetInstance();
    AppWindow* appWindow = AppWindow::get();
    if (connect_dialog) {
        QObject::connect(coreDialog, &CoreDialog::notifyExit, appWindow, &AppWindow::onExit);
        QObject::connect(coreDialog, &CoreDialog::notifyCancel, appWindow, &AppWindow::onCancel);
        QObject::connect(coreDialog, &CoreDialog::notifyApply, appWindow, &AppWindow::onApply);
        QObject::connect(coreDialog, &CoreDialog::notifyOpenProject, appWindow, &AppWindow::onOpenProject);
        QObject::connect(coreDialog, &CoreDialog::notifyRestart, appWindow, &AppWindow::onRestart);
        QObject::connect(coreDialog, &CoreDialog::notifyUpdate, appWindow, &AppWindow::onUpdate);
    }
    else {
        QObject::disconnect(coreDialog, &CoreDialog::notifyExit, appWindow, &AppWindow::onExit);
        QObject::disconnect(coreDialog, &CoreDialog::notifyCancel, appWindow, &AppWindow::onCancel);
        QObject::disconnect(coreDialog, &CoreDialog::notifyApply, appWindow, &AppWindow::onApply);
        QObject::disconnect(coreDialog, &CoreDialog::notifyOpenProject, appWindow, &AppWindow::onOpenProject);
        QObject::disconnect(coreDialog, &CoreDialog::notifyRestart, appWindow, &AppWindow::onRestart);
        QObject::disconnect(coreDialog, &CoreDialog::notifyUpdate, appWindow, &AppWindow::onUpdate);
    }
}




#include "coredialog.h"

#include <QDebug>

#include "dialogopenproject.h"
#include "dialognewproject.h"
#include "dialogstartscreen.h"
#include "dialogpreferences.h"
#include "dialogabout.h"

CoreDialog* CoreDialog::m_instance = nullptr;

CoreDialog *CoreDialog::GetInstance(QObject* parent)
{
    if (m_instance == nullptr)
        m_instance = new CoreDialog(parent);
    return m_instance;
}

void CoreDialog::DeleteInstance()
{
    delete m_instance;
    m_instance = nullptr;
}

void CoreDialog::sendExitCode(const AppState& exit_state)
{
    qDebug() << __FUNCTION__;
    switch (exit_state) {
    case AppState::None:
        return;
    case AppState::Continue:
        return;
    case AppState::New:
        return;
    case AppState::Open:
        return;
    case AppState::Save:
        return;
    case AppState::Exit:
        emit notifyExit(); return;
    case AppState::Cancel:
        emit notifyCancel(); return;
    case AppState::Apply:
        emit notifyApply(); return;
    case AppState::OpenProject:
        emit notifyOpenProject(); return;
    case AppState::Restart:
        emit notifyRestart(); return;
    case AppState::UpdateWindow:
        emit notifyUpdate(); return;
    }
}

void CoreDialog::openDialog(const DialogType &dialog_type, QWidget *app_window)
{
    qDebug() << __FUNCTION__;
    switch (dialog_type) {
    case DialogType::StartScreen:
        dialogStartScreen(app_window); return;
    case DialogType::About:
        dialogAbout(app_window); return;
    case DialogType::Open:
        dialogOpenProject(app_window); return;
    case DialogType::New:
        dialogNewProject(app_window); return;
    case DialogType::Preferences:
        dialogPreferences(app_window); return;
    }
}

void CoreDialog::dialogStartScreen(QWidget *app_window)
{
    qDebug() << __FUNCTION__;
    DialogStartScreen *dialog = new DialogStartScreen(app_window);
    is_startup = true;
    connect(this, &CoreDialog::closeStartUp, dialog, &DialogStartScreen::onClose);
    dialog->exec();
    disconnect(this, &CoreDialog::closeStartUp, dialog, &DialogStartScreen::onClose);
    AppState exit_state = dialog->state();
    delete dialog;
    is_startup = false;

    sendExitCode(exit_state);
}

void CoreDialog::dialogPreferences(QWidget *app_window)
{
    DialogPreferences *dialog = new DialogPreferences(app_window);
    dialog->exec();
    AppState exit_state = dialog->state();
    delete dialog;

    sendExitCode(exit_state);
}

void CoreDialog::dialogOpenProject(QWidget *app_window)
{
    qDebug() << __FUNCTION__;
    DialogOpenProject* dialog = new DialogOpenProject(app_window);
    dialog->exec();
    AppState exit_state = dialog->state();
    delete dialog;

    if (is_startup && exit_state == AppState::Cancel)
        return;

    if (is_startup)
        emit closeStartUp(exit_state);
    else
        sendExitCode(exit_state);

}

void CoreDialog::dialogNewProject(QWidget *app_window)
{
    DialogNewProject* dialog = new DialogNewProject(app_window);
    dialog->exec();
    AppState exit_state = dialog->state();
    delete dialog;

    if (is_startup && exit_state == AppState::Cancel)
        return;

    if (is_startup)
        emit closeStartUp(exit_state);
    else
        sendExitCode(exit_state);
}

void CoreDialog::dialogAbout(QWidget *app_window)
{
    DialogAbout *dialog = new DialogAbout(app_window);
    dialog->exec();
    delete dialog;

    sendExitCode(AppState::Cancel);
}

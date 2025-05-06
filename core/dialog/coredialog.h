#ifndef COREDIALOG_H
#define COREDIALOG_H

#include "appstates.h"

#include <QObject>
#include <QWidget>

class CoreDialog : public QObject
{
    Q_OBJECT

private:
    CoreDialog(QObject* parent = nullptr) : QObject{parent}{}; // Prevent construction
    CoreDialog(const CoreDialog&) = delete; // Prevent construction by copying
    CoreDialog& operator=(const CoreDialog&) = delete; // Prevent assignment
    ~CoreDialog(){}; // Prevent unwanted destruction
    static CoreDialog* m_instance;
private:
    bool is_startup = false;
public:
    static CoreDialog* GetInstance(QObject* parent = nullptr);
    static void DeleteInstance();
    AppState start_up_exit_state = AppState::None;

public:
    enum DialogType {
        StartScreen = 1,
        About,
        Preferences,
        Open,
        New
    };

signals:
    void notifyExit();
    void notifyCancel();
    void notifyApply();
    void notifyOpenProject();
    void notifyRestart();
    void notifyUpdate();

private:
    void sendExitCode(const AppState &exit_state);
    void setStartUpExitState(const AppState &exit_state){start_up_exit_state = exit_state;}

public slots:
    void openDialog(const DialogType &dialog_type, QWidget *app_window);

private:
    void dialogStartScreen(QWidget *app_window);
    void dialogPreferences(QWidget *app_window);
    void dialogOpenProject(QWidget *app_window);
    void dialogNewProject(QWidget *app_window);
    void dialogAbout(QWidget *app_window);

signals:
    void closeStartUp(const AppState &exit_state);
};

#endif // COREDIALOG_H

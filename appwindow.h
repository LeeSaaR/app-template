#ifndef APPWINDOW_H
#define APPWINDOW_H

#include "widgetmenupage.h"
#include "appmenubar.h"

#include <QCloseEvent>
#include <QFrame>
#include <QMainWindow>
#include <QProgressBar>
#include <QLabel>

QT_BEGIN_NAMESPACE
namespace Ui { class AppWindow; }
QT_END_NAMESPACE

class AppWindow : public QMainWindow
{
    Q_OBJECT

private:
    Ui::AppWindow *ui;
    QMenuBar* appMenu = nullptr;
private:
    static AppMenuBar *menuBar;
    static WidgetMenuPage *menuPages;
    static QStatusBar *statusBar;
    static QProgressBar *progBar;
    static QLabel *progText;

public:
    QFrame* frameMain  = nullptr;
    QFrame* menuLeft   = nullptr;
    QFrame* menuRight  = nullptr;
    QFrame* menuTop    = nullptr;
    QFrame* menuBottom = nullptr;

public:
    AppWindow(QWidget *parent = nullptr);
    ~AppWindow();

    enum AppExitCode{
        Normal = 0,
        Error = 1,
        Restart = 1337
    };

private:
    static AppWindow* m_instance;
public:
    static AppWindow* get();

private: // Init
    void initApplication();
    void initUiElements();
    void initStatusBar();
private:
    // Methods
    void updateApp();

public:
    void updateMenuPosition();
    QMenuBar *AppMenu();
    static AppMenuBar *MenuBar();
    static WidgetMenuPage *MenuPages();
    static QStatusBar* StatusBar();
    static QProgressBar* ProgBar();
    static QLabel* ProgText();

private:
    void openStartScreen();
    void exitApp();
    void restartApp();

public slots:
    void onExit();
    void onCancel();
    void onApply();
    void onOpenProject();
    void onRestart();
    void onUpdate();

protected:
    // overrides
    void closeEvent(QCloseEvent *event) override;
    void resizeEvent(QResizeEvent* event) override;
signals:
    void projectSelected();
};
#endif // APPWINDOW_H

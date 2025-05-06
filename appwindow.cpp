#include "appwindow.h"
#include "./ui_appwindow.h"

#include <QDebug>
#include "coreinitializer.h"
#include "coredialog.h"
#include <QRegularExpression>
#include <QTextEdit>
#include <QSysInfo>
#include <QSpacerItem>
#include <QGraphicsEffect>
#include "prop.h"
#include "info.h"

AppWindow* AppWindow::m_instance     = nullptr;
AppMenuBar *AppWindow::menuBar       = nullptr;
WidgetMenuPage *AppWindow::menuPages = nullptr;
QStatusBar *AppWindow::statusBar     = nullptr;
QProgressBar *AppWindow::progBar     = nullptr;
QLabel *AppWindow::progText          = nullptr;

AppWindow::AppWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::AppWindow)
{
    ui->setupUi(this);
    m_instance = this;
    Prop::init();
    initApplication();
}

AppWindow::~AppWindow()
{
    if (menuPages) delete menuPages;
    if (menuBar) delete menuBar;
    m_instance = nullptr;
    delete ui;
}

AppWindow *AppWindow::get()
{
    return m_instance;
}

void AppWindow::initApplication()
{
    initUiElements();
    CoreInitializer::init();
    // if (CoreInitializer::isFinished())
    //     openStartScreen();
    Info::msg("Loaded App");
    Info::prog(0);
    Info::text("");
}

void AppWindow::initUiElements()
{
    frameMain  = ui->frame_main;
    menuLeft   = ui->frame_menu_left;
    menuRight  = ui->frame_menu_right;
    menuTop    = ui->frame_menu_top;
    menuBottom = ui->frame_menu_bottom;
    appMenu = ui->menubar;
    menuPages   = new WidgetMenuPage(this);
    menuBar     = new AppMenuBar(this);
    initStatusBar();
}

void AppWindow::initStatusBar()
{
    statusBar   = ui->statusBar;

    progText = new QLabel(statusBar);
    statusBar->addPermanentWidget(progText);

    progBar = new QProgressBar(statusBar);
    progBar->setMaximumWidth(80);
    progBar->setMaximumHeight(8);
    progBar->setRange(0,100);
    progBar->setTextVisible(false);
    statusBar->addPermanentWidget(progBar);

    QFrame* progSpacer = new QFrame(statusBar);
    progSpacer->setMinimumWidth(8);
    progSpacer->setMaximumWidth(8);
    statusBar->addPermanentWidget(progSpacer);
}

void AppWindow::updateApp()
{
    CoreInitializer::updateApp();
}

QMenuBar *AppWindow::AppMenu()
{
    return appMenu;
}

WidgetMenuPage *AppWindow::MenuPages()
{
    return menuPages;
}

QStatusBar *AppWindow::StatusBar()
{
    return statusBar;
}

QProgressBar *AppWindow::ProgBar()
{
    return progBar;
}

QLabel *AppWindow::ProgText()
{
    return progText;
}

AppMenuBar *AppWindow::MenuBar()
{
    return menuBar;
}

void AppWindow::exitApp()
{
    exit(0);
}

void AppWindow::restartApp()
{
    CoreDialog::GetInstance()->DeleteInstance();
    qApp->exit(AppWindow::AppExitCode::Restart);
}

void AppWindow::openStartScreen()
{
    qDebug() << __FUNCTION__;
    CoreDialog* coreDialog = CoreDialog::GetInstance();
    coreDialog->openDialog( CoreDialog::StartScreen, this );
}

void AppWindow::onExit()
{
    exitApp();
}

void AppWindow::onCancel()
{
    return;
}

void AppWindow::onApply()
{
    qDebug() << __FUNCTION__;
    return;
}

void AppWindow::onOpenProject()
{
    qDebug() << __FUNCTION__;
    emit projectSelected();
}

void AppWindow::onRestart()
{
    restartApp();
}

void AppWindow::onUpdate()
{
    updateApp();
}

// overrides
void AppWindow::closeEvent (QCloseEvent *event)
{
    event->ignore();
    exitApp();
}

void AppWindow::resizeEvent(QResizeEvent *event)
{
    QMainWindow::resizeEvent(event);
}

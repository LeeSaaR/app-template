#include "dialogstartscreen.h"
#include "ui_dialogstartscreen.h"

#include "appdata.h"
#include "appimage.h"
#include "apptext.h"
#include "propwgt.h"
#include "coredialog.h"
#include "appconnector.h"
#include "prop.h"

DialogStartScreen::DialogStartScreen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogStartScreen)
{
    ui->setupUi(this);
    init();
}

DialogStartScreen::~DialogStartScreen()
{
    delete ui;
}

void DialogStartScreen::init()
{
    exit_state = AppState::Exit; // Default Start Action
    initWindow();
    initConnections();
}

void DialogStartScreen::initConnections()
{
    connect(ui->btn_new, &QPushButton::clicked, this, &DialogStartScreen::onNew);
    connect(ui->btn_open, &QPushButton::clicked, this, &DialogStartScreen::onOpen);
    connect(ui->btn_exit, &QPushButton::clicked, this, &DialogStartScreen::onExit);
}

void DialogStartScreen::initWindow()
{
    AppData *appData = AppData::GetInstance();
    PropWgt::setWindowSize(this, 800, 600);
    setWindowTitle(appData->appName() + " - " +AppText::title_Startup());
    ui->label_logo->setPixmap(AppImage::logo128());

    ui->btn_new->setText(AppText::btn_new());
    Prop::setWidth(125, ui->btn_new);
    Prop::setHeight(64, ui->btn_new);

    ui->btn_open->setText(AppText::btn_open());
    Prop::setWidth(125, ui->btn_open);
    Prop::setHeight(64, ui->btn_open);

    ui->btn_exit->setText(AppText::btn_exit());
    Prop::setWidth(Prop::btn_ctrl_w, ui->btn_exit);
    Prop::setHeight(Prop::btn_ctrl_h, ui->btn_exit);
}

void DialogStartScreen::handleStartAction()
{
    switch (exit_state) {
    case AppState::Apply:
        exit_state = AppState::Apply;
        close();
        break;
    case AppState::Cancel:
        exit_state = AppState::Cancel;
        return;
        break;

    case AppState::Exit:
        exit_state = AppState::Exit;
        close();
        break;

    default:
        exit_state = AppState::Exit;
        close();
        break;
    }
}

void DialogStartScreen::blockSignalsAppWindow(const bool &block_signal)
{
    AppConnector::connectCoreDialog(!block_signal);

    CoreDialog* coreDialog = CoreDialog::GetInstance();
    if (block_signal) {
        QObject::connect(coreDialog, &CoreDialog::notifyApply, this, &DialogStartScreen::onApply);
        QObject::connect(coreDialog, &CoreDialog::notifyCancel, this, &DialogStartScreen::onCancel);
        QObject::connect(coreDialog, &CoreDialog::notifyExit, this, &DialogStartScreen::onExit);
    }
    else {
        QObject::disconnect(coreDialog, &CoreDialog::notifyApply, this, &DialogStartScreen::onApply);
        QObject::disconnect(coreDialog, &CoreDialog::notifyCancel, this, &DialogStartScreen::onCancel);
        QObject::disconnect(coreDialog, &CoreDialog::notifyExit, this, &DialogStartScreen::onExit);
    }
}

AppState DialogStartScreen::startAction() const
{
    return exit_state;
}

AppState DialogStartScreen::state() const
{
    return exit_state;
}


void DialogStartScreen::enableButtonOpen(bool enable)
{
    ui->btn_open->setEnabled(enable);
}

void DialogStartScreen::onNew()
{
    blockSignalsAppWindow(true);
    CoreDialog* coreDialog = CoreDialog::GetInstance();
    coreDialog->openDialog(CoreDialog::New, this);
    blockSignalsAppWindow(false);

}

void DialogStartScreen::onOpen()
{
    qDebug() << __FUNCTION__;
    blockSignalsAppWindow(true);
    CoreDialog* coreDialog = CoreDialog::GetInstance();
    coreDialog->openDialog(CoreDialog::Open, this);
    blockSignalsAppWindow(false);
}

void DialogStartScreen::onExit()
{
    // EXIT
    exit_state = AppState::Exit;
    close();
}

void DialogStartScreen::onCancel()
{
}

void DialogStartScreen::onApply()
{
    exit_state = AppState::Apply;
    close();
}

void DialogStartScreen::onClose(const AppState& exit_state)
{
    this->exit_state = exit_state;
    close();
}

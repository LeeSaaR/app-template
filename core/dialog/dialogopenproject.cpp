#include "dialogopenproject.h"
#include "ui_dialogopenproject.h"


#include "appdata.h"
#include "apptext.h"
#include "propwgt.h"
#include "propui.h"
#include "prop.h"

DialogOpenProject::DialogOpenProject(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogOpenProject)
{
    ui->setupUi(this);
    init();
}

DialogOpenProject::~DialogOpenProject()
{
    delete ui;
}

void DialogOpenProject::init()
{
    exit_state = AppState::Cancel; // Default Start Action
    initWindow();
    initTexts();
    initConnections();
    initProjectList();
}

void DialogOpenProject::initConnections()
{
    connect(ui->btn_open, &QPushButton::clicked, this, &DialogOpenProject::onOpen);
    connect(ui->btn_exit, &QPushButton::clicked, this, &DialogOpenProject::onExit);
    connect(ui->btn_cancel, &QPushButton::clicked, this, &DialogOpenProject::onCancel);
}

void DialogOpenProject::initProjectList()
{
    project_list = new WidgetProjectList(this);
    ui->frame_content->layout()->addWidget(project_list);
    connect(project_list, &WidgetProjectList::enableOpen, this, &DialogOpenProject::enableButtonOpen);
    enableButtonOpen(false);
}

void DialogOpenProject::initWindow()
{
    PropWgt::setWindowSize(this, 800, 600);
}

void DialogOpenProject::initTexts()
{
    AppData *app_data = AppData::GetInstance();
    PropUi::setFrameHeight(ui->frame_title, PropUi::frame_title_height());
    PropUi::setFramePadding(ui->frame_title, PropUi::frame_title_padding());
    setWindowTitle(app_data->appName() + " - " + AppText::title_OpenProject());
    ui->lbl_title->setText(AppText::title_OpenProject());

    ui->btn_cancel->setText(AppText::btn_cancel());
    Prop::setWidth(Prop::btn_ctrl_w, ui->btn_cancel);
    Prop::setHeight(Prop::btn_ctrl_h, ui->btn_cancel);

    ui->btn_exit->setText(AppText::btn_exit());
    Prop::setWidth(Prop::btn_ctrl_w, ui->btn_exit);
    Prop::setHeight(Prop::btn_ctrl_h, ui->btn_exit);

    ui->btn_open->setText(AppText::btn_open());
    Prop::setWidth(Prop::btn_ctrl_w, ui->btn_open);
    Prop::setHeight(Prop::btn_ctrl_h, ui->btn_open);

}

AppState DialogOpenProject::state() const
{
    return exit_state;
}

void DialogOpenProject::enableButtonOpen(bool enable)
{
    ui->btn_open->setEnabled(enable);
}

void DialogOpenProject::onOpen()
{
    qDebug() << __FUNCTION__;
    if (project_list->noSelection()) return;

    project_list->setOpenProject();
    exit_state = AppState::OpenProject;
    close();
}

void DialogOpenProject::onCancel()
{
    exit_state = AppState::Cancel;
    close();
}

void DialogOpenProject::onExit()
{
    qDebug() << __FUNCTION__;
    exit_state = AppState::Exit;
    close();
}

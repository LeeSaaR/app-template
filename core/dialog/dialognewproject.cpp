#include "dialognewproject.h"
#include "ui_dialognewproject.h"

#include "propui.h"
#include "appdata.h"
#include "apptext.h"
#include "propwgt.h"
#include "prop.h"

DialogNewProject::DialogNewProject(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogNewProject)
{
    ui->setupUi(this);
    init();
}

DialogNewProject::~DialogNewProject()
{
    delete ui;
}

void DialogNewProject::init()
{
    AppData* app_data = AppData::GetInstance();
    exit_state = AppState::Cancel;

    setWindowTitle(app_data->appName() +" - "+ AppText::title_NewProject());
    PropWgt::setWindowSize(this, 800, 600);
    // Buttons

    PropUi::setFrameHeight(ui->frame_title, PropUi::frame_title_height());
    PropUi::setFramePadding(ui->frame_title, PropUi::frame_title_padding());
    ui->lbl_title->setText(AppText::title_NewProject());

    ui->btn_apply->setText(AppText::btn_apply());
    Prop::setWidth(Prop::btn_ctrl_w, ui->btn_apply);
    Prop::setHeight(Prop::btn_ctrl_h, ui->btn_apply);

    ui->btn_back->setText(AppText::btn_back());
    Prop::setWidth(Prop::btn_ctrl_w, ui->btn_back);
    Prop::setHeight(Prop::btn_ctrl_h, ui->btn_back);

    ui->btn_cancel->setText(AppText::btn_cancel());
    Prop::setWidth(Prop::btn_ctrl_w, ui->btn_cancel);
    Prop::setHeight(Prop::btn_ctrl_h, ui->btn_cancel);

    ui->btn_exit->setText(AppText::btn_exit());
    Prop::setWidth(Prop::btn_ctrl_w, ui->btn_exit);
    Prop::setHeight(Prop::btn_ctrl_h, ui->btn_exit);

    ui->btn_next->setText(AppText::btn_next());
    Prop::setWidth(Prop::btn_ctrl_w, ui->btn_next);
    Prop::setHeight(Prop::btn_ctrl_h, ui->btn_next);

    initPagesStack();
}

void DialogNewProject::initPagesStack()
{
    pages = new WidgetProjectNew(this);
    ui->frame_widget_project_new->layout()->addWidget(pages);
    pages->initConnections(ui->btn_exit, ui->btn_cancel, ui->btn_back, ui->btn_next, ui->btn_apply);
    connect(pages, &WidgetProjectNew::enableButtonBack, this, [this](bool enable){ui->btn_back->setEnabled(enable);});
    connect(pages, &WidgetProjectNew::enableButtonNext, this, [this](bool enable){ui->btn_next->setEnabled(enable);});
    connect(pages, &WidgetProjectNew::enableButtonApply, this, [this](bool enable){ui->btn_apply->setEnabled(enable);});
    connect(pages, &WidgetProjectNew::finishedDialog, this, &DialogNewProject::onFinishedDialog);
    // connect(
    //     pages, &WidgetProjectNew::finishedDialog,
    //     this, [this](AppState state){ exit_state = state;close(); }
    // );
    pages->setButtonStates();
    enableNextBackButtons();
}

void DialogNewProject::enableNextBackButtons()
{
    ui->btn_back->setVisible(pages->hasMultiplePages());
    ui->btn_next->setVisible(pages->hasMultiplePages());
}

AppState DialogNewProject::state() const
{
    return exit_state;
}

void DialogNewProject::onFinishedDialog(const AppState &exit_state)
{
    this->exit_state = exit_state;
    close();
}

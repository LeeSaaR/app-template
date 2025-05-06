#include "dialoglettereditor.h"
#include "ui_dialoglettereditor.h"

#include "appdata.h"
#include "apptext.h"
#include "propui.h"
#include "widgetprop.h"
#include <QTabBar>

DialogLetterEditor::DialogLetterEditor(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DialogLetterEditor)
{
    ui->setupUi(this);
    init();
}

DialogLetterEditor::~DialogLetterEditor()
{
    qDebug() << __FUNCTION__;
    if (editor) delete editor;
    delete ui;
}

void DialogLetterEditor::init()
{
    AppData* app_data = AppData::GetInstance();
    exit_state = AppState::Cancel;
    setWindowTitle(app_data->appName() +" - "+ AppText::title_letter_editor());

    // TITLE
    PropUi::setFrameHeight(ui->frame_title, PropUi::frame_title_height());
    PropUi::setFramePadding(ui->frame_title, PropUi::frame_title_padding());
    ui->frame_title->setVisible(true);
    ui->lbl_title->setText(AppText::title_letter_editor());
    // BUTTONS
    ui->frame_buttons->setVisible(true);
    ui->btn_apply->setText(AppText::btn_apply());
    ui->btn_back->setText(AppText::btn_back());
    ui->btn_cancel->setText(AppText::btn_cancel());
    ui->btn_exit->setText(AppText::btn_exit());
    ui->btn_next->setText(AppText::btn_next());

    setWindowFlag(Qt::Dialog, true);
    setWindowFlag(Qt::WindowMaximizeButtonHint, true);
    setWindowFlag(Qt::WindowMinimizeButtonHint, true);

    // has to explicitly set to modal
    setModal(true);
    setWindowModality(Qt::ApplicationModal);
    resize(1920, 1009);
    showMaximized();
    initWidgetLetterEditor();
}

void DialogLetterEditor::initWidgetLetterEditor()
{
    editor = new WidgetLetterEditor(this);
    ui->frame_content->layout()->addWidget(editor);
}


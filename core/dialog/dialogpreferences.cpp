#include "dialogpreferences.h"
#include "./ui_dialogpreferences.h"

#include <QDebug>

#include "convertdata.h"
#include "appdata.h"
#include "appconfiguration.h"
#include "apptext.h"

DialogPreferences::DialogPreferences(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogPreferences)
{
    ui->setupUi(this);
    initDialog();
    qDebug() << windowFlags();
}

DialogPreferences::~DialogPreferences()
{
    delete ui;
}

AppState DialogPreferences::state() const
{
    return exit_state;
}

// Initialize
void DialogPreferences::initDialog()
{
    initUI();
    initConnections();
    initItemController();
    load();
}

void DialogPreferences::initUI()
{
    initUiText();
    ui->btn_save->setText(AppText::btn_save());
    ui->frame_scrollArea->setStyleSheet("QWidget[accessibleName=\"scrollArea\"] {background-color: transparent;}");
}

void DialogPreferences::initUiText()
{
    AppData* appData = AppData::GetInstance();
    setWindowTitle(appData->appName() + " - "+ AppText::action_preferences());
    ui->label_title->setText(AppText::action_preferences());
}

void DialogPreferences::initConnections()
{
    connect(ui->btn_save, &QPushButton::clicked, this, &DialogPreferences::onClickedSave);
}

void DialogPreferences::initItemController()
{
    itemCrtl = new PropItemsController(this);
}

void DialogPreferences::addItemToUserInterface(QWidget *item)
{
    ui->frame_scrollArea->layout()->removeItem(ui->spacer);
    ui->frame_scrollArea->layout()->addWidget(item);
    ui->frame_scrollArea->layout()->addItem(ui->spacer);
}

// private: Methods
void DialogPreferences::loadConfigDataItems()
{
    AppConfiguration* appConfig = AppConfiguration::GetInstance();
    ConfigDataList* data_list = appConfig->list();
    ConfigSectionTop* top;
    foreach (top, data_list->list()) {
        QWidget* item;
        item = itemCrtl->addItemPropSection( ConvertData::seperatePascalCase(top->name()), true);
        addItemToUserInterface(item);

        ConfigSectionSub* sub;
        foreach (sub, top->list()) {
            item = itemCrtl->addItemPropSection( ConvertData::seperatePascalCase(sub->name()));
            addItemToUserInterface(item);
            // if (sub->name() == "FilePaths") item->hide();
            // if (sub->name() == "Language") item->hide();
            if (sub->name() == "Theme") item->hide();

            ConfigData* data;
            foreach (data, sub->list()) {
                item = itemCrtl->addItem(data);
                addItemToUserInterface( item );
                // if (data->name() == "Output Directory") item->hide();
                // if (data->name() == "Default Project Directory") item->hide();
                // if (data->name() == "Language") item->hide();
                if (data->name() == "Theme") item->hide();
            }
        }
    }
}

void DialogPreferences::load()
{
    loadConfigDataItems();
}

void DialogPreferences::save()
{
    AppConfiguration* appConfig = AppConfiguration::GetInstance();
    appConfig->save();
    exit_state = AppState::UpdateWindow;
}


// private slots:
void DialogPreferences::onClickedSave()
{
    save();
    close();
}

void DialogPreferences::closeEvent(QCloseEvent *event)
{
    event->accept();
}

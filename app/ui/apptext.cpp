#include "apptext.h"

#include "appconfiguration.h"

AppText::Language AppText::language = DE;

// ABOUT
QMap<AppText::Language, QString> AppText::m_about_dev{ {DE, "Entwickelt von"},{EN, "Developed by"} };
QMap<AppText::Language, QString> AppText::m_about_framework{ {DE, "Mit C++ und Qt.\nDiese Applikation ist Open Source."}, {EN, "With C++ and Qt.\nThis Application is Open Source."} };

// ACTIONS
QMap<AppText::Language, QString> AppText::m_action_exit{ {DE, "Beenden"},{EN, "Exit"} };
QMap<AppText::Language, QString> AppText::m_action_new{ {DE, "Neu"},{EN, "New"} };
QMap<AppText::Language, QString> AppText::m_action_open{ {DE, "Öffnen"},{EN, "Open"} };
QMap<AppText::Language, QString> AppText::m_action_preferences{ {DE, "Einstellungen"},{EN, "Preferences"} };
QMap<AppText::Language, QString> AppText::m_action_save{ {DE, "Speichern"},{EN, "Save"} };
QMap<AppText::Language, QString> AppText::m_action_save_as{ {DE, "Speichern unter"},{EN, "Save as"} };
QMap<AppText::Language, QString> AppText::m_action_undo{ {DE, "Schritt zurück"},{EN, "Undo"} };
QMap<AppText::Language, QString> AppText::m_action_redo{ {DE, "Schritt vor"},{EN, "Redo"} };
QMap<AppText::Language, QString> AppText::m_action_about{ {DE, "Über"},{EN, "About"} };
QMap<AppText::Language, QString> AppText::m_action_documentation{ {DE, "Dokumentation"},{EN, "Documentation"} };

// MENU
QMap<AppText::Language, QString> AppText::m_menu_menu{ {DE, "Menu"},{EN, "Menu"} };
QMap<AppText::Language, QString> AppText::m_menu_edit{ {DE, "Bearbeiten"},{EN, "Edit"} };
QMap<AppText::Language, QString> AppText::m_menu_project{ {DE, "Projekt"},{EN, "Project"} };
QMap<AppText::Language, QString> AppText::m_menu_help{ {DE, "Hilfe"},{EN, "Help"} };

// TITLES
QMap<AppText::Language, QString> AppText::m_title_open_project{ {DE, "Projekt öffnen"},{EN, "Open Project"} };
QMap<AppText::Language, QString> AppText::m_title_new_project{ {DE, "Neues Projekt"},{EN, "New Project"} };
QMap<AppText::Language, QString> AppText::m_title_startup{ {DE, "Start"},{EN, "Start"} };
QMap<AppText::Language, QString> AppText::m_title_about{ {DE, "Über"},{EN, "About"} };
QMap<AppText::Language, QString> AppText::m_title_letter_editor{ {DE, "Brief Editor"},{EN, "Letter Editor"} };

// BUTTONS
QMap<AppText::Language, QString> AppText::m_btn_apply{ {DE, "anwenden"},{EN, "apply"} };
QMap<AppText::Language, QString> AppText::m_btn_discard{ {DE, "verwerfen"},{EN, "discard"} };
QMap<AppText::Language, QString> AppText::m_btn_back{ {DE, "zurück"},{EN, "back"} };
QMap<AppText::Language, QString> AppText::m_btn_cancel{ {DE, "abbrechen"},{EN, "cancel"} };
QMap<AppText::Language, QString> AppText::m_btn_exit{ {DE, "beenden"},{EN, "exit"} };
QMap<AppText::Language, QString> AppText::m_btn_new{ {DE, "neu"},{EN, "new"} };
QMap<AppText::Language, QString> AppText::m_btn_next{ {DE, "weiter"},{EN, "next"} };
QMap<AppText::Language, QString> AppText::m_btn_open{ {DE, "öffnen"},{EN, "open"} };
QMap<AppText::Language, QString> AppText::m_btn_save{ {DE, "speichern"},{EN, "save"} };
QMap<AppText::Language, QString> AppText::m_btn_ok{ {DE, "ok"},{EN, "ok"} };
QMap<AppText::Language, QString> AppText::m_btn_no{ {DE, "nein"},{EN, "no"} };
QMap<AppText::Language, QString> AppText::m_btn_yes{ {DE, "ja"},{EN, "yes"} };

// LABELS
QMap<AppText::Language, QString> AppText::m_lbl_project_name{ {DE, "Projekt Name"},{EN, "Project Name"} };


void AppText::setLanguage() {
    AppConfiguration* appConfig = AppConfiguration::GetInstance();
    const QString config_data_value = appConfig->getConfigData("Language");
    if (config_data_value == "English") {
        language = EN;
    }
    else if (config_data_value == "Deutsch") {
        language = DE;
    }

}

// ABOUT
QString AppText::about_dev(){ return m_about_dev.value(language); }
QString AppText::about_framework(){ return m_about_framework.value(language); }

// ACTIONS
QString AppText::action_exit(){ return m_action_exit.value(language); }
QString AppText::action_new(){ return m_action_new.value(language); }
QString AppText::action_open(){ return m_action_open.value(language); }
QString AppText::action_preferences(){ return m_action_preferences.value(language); }
QString AppText::action_save(){ return m_action_save.value(language); }
QString AppText::action_save_as(){ return m_action_save_as.value(language); }
QString AppText::action_undo(){ return m_action_undo.value(language); }
QString AppText::action_redo(){ return m_action_redo.value(language); }
QString AppText::action_about(){ return m_action_about.value(language); }
QString AppText::action_documentation(){ return m_action_documentation.value(language); }

// MENU
QString AppText::menu_menu(){ return m_menu_menu.value(language); }
QString AppText::menu_edit(){ return m_menu_edit.value(language); }
QString AppText::menu_project(){ return m_menu_project.value(language); }
QString AppText::menu_help(){ return m_menu_help.value(language); }

// TITLES
QString AppText::title_OpenProject(){ return m_title_open_project.value(language); }
QString AppText::title_NewProject() { return m_title_new_project.value(language); }
QString AppText::title_Startup()    { return m_title_startup.value(language); }
QString AppText::title_about()      { return m_title_about.value(language); }
QString AppText::title_letter_editor()    { return m_title_letter_editor.value(language); }

// BUTTONS
QString AppText::btn_apply()  { return m_btn_apply.value(language); }
QString AppText::btn_discard(){ return m_btn_discard.value(language); }
QString AppText::btn_back()   { return m_btn_back.value(language); }
QString AppText::btn_cancel() { return m_btn_cancel.value(language); }
QString AppText::btn_exit()   { return m_btn_exit.value(language); }
QString AppText::btn_new()    { return m_btn_new.value(language); }
QString AppText::btn_next()   { return m_btn_next.value(language); }
QString AppText::btn_open()   { return m_btn_open.value(language); }
QString AppText::btn_save()   { return m_btn_save.value(language); }
QString AppText::btn_ok()     { return m_btn_ok.value(language); }
QString AppText::btn_no()     { return m_btn_no.value(language); }
QString AppText::btn_yes()    { return m_btn_yes.value(language); }

// LABELS
QString AppText::lbl_project_name()   { return m_lbl_project_name.value(language); }

void AppText::onUpdate()
{
    setLanguage();
}

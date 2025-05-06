#ifndef APPTEXT_H
#define APPTEXT_H

#include <QObject>
#include <QString>
#include <QList>
#include <QMap>

class AppText : public QObject
{
    Q_OBJECT

public:
    enum Language {
        DE = 0,
        EN = 1
    };

private:
    static QMap<Language, QString> m_about_dev;
    static QMap<Language, QString> m_about_framework;

private:
    static QMap<Language, QString> m_action_exit;
    static QMap<Language, QString> m_action_new;
    static QMap<Language, QString> m_action_open;
    static QMap<Language, QString> m_action_preferences;
    static QMap<Language, QString> m_action_save;
    static QMap<Language, QString> m_action_save_as;
    static QMap<Language, QString> m_action_undo;
    static QMap<Language, QString> m_action_redo;
    static QMap<Language, QString> m_action_about;
    static QMap<Language, QString> m_action_documentation;

private:
    static QMap<Language, QString> m_menu_menu;
    static QMap<Language, QString> m_menu_edit;
    static QMap<Language, QString> m_menu_project;
    static QMap<Language, QString> m_menu_help;

private:
    static QMap<Language, QString> m_title_open_project;
    static QMap<Language, QString> m_title_new_project;
    static QMap<Language, QString> m_title_startup;
    static QMap<Language, QString> m_title_about;
    static QMap<Language, QString> m_title_letter_editor;

private:
    static QMap<Language, QString> m_btn_apply;
    static QMap<Language, QString> m_btn_discard;
    static QMap<Language, QString> m_btn_back;
    static QMap<Language, QString> m_btn_cancel;
    static QMap<Language, QString> m_btn_exit;
    static QMap<Language, QString> m_btn_new;
    static QMap<Language, QString> m_btn_next;
    static QMap<Language, QString> m_btn_open;
    static QMap<Language, QString> m_btn_save;
    static QMap<Language, QString> m_btn_ok;
    static QMap<Language, QString> m_btn_no;
    static QMap<Language, QString> m_btn_yes;

private:
    static QMap<Language, QString> m_lbl_project_name;

private:
    AppText() = delete;

public:
    static Language language;
    static void setLanguage();

public:
    static QString about_dev();
    static QString about_framework();

public:
    static QString action_exit();
    static QString action_new();
    static QString action_open();
    static QString action_preferences();
    static QString action_save();
    static QString action_save_as();
    static QString action_undo();
    static QString action_redo();
    static QString action_about();
    static QString action_documentation();

public:
    static QString menu_menu();
    static QString menu_edit();
    static QString menu_project();
    static QString menu_help();

public:
    static QString title_OpenProject();
    static QString title_NewProject();
    static QString title_Startup();
    static QString title_about();
    static QString title_letter_editor();

public:
    static QString btn_apply();
    static QString btn_discard();
    static QString btn_back();
    static QString btn_cancel();
    static QString btn_exit();
    static QString btn_new();
    static QString btn_next();
    static QString btn_open();
    static QString btn_save();
    static QString btn_ok();
    static QString btn_no();
    static QString btn_yes();

public:
    static QString lbl_project_name();

public slots:
    void onUpdate();

};

#endif // APPTEXT_H

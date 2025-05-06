#ifndef APPDATA_H
#define APPDATA_H

#include <QString>
#include <QDir>

class AppData
{
private:
    bool m_is_initialized = false;
    QDir dir;

    const QString m_appName      = "AppTemplate";
    const QString m_vendor_name  = "Your Vendor Name";
    const QString m_dev_name     = "Your Name";
    const QString m_dev_url      = "https://your-url.com";

    // DIRS
    QString m_dir_appdata_user = "";
    QString m_dir_vendor       = m_vendor_name;
    QString m_dir_appdata      = m_dir_vendor+"/"+m_appName;
    QString m_dir_home         = "";
    QString m_dir_docs         = "";
    // App Data Directories
    QString m_dir_temp         = m_dir_appdata+"/tmp";
    QString m_dir_theme        = m_dir_appdata+"/themes";
    QString m_dir_project      = m_dir_appdata+"/projects";
    QString m_dir_data         = m_dir_appdata+"/data";
    QString m_dir_shared       = m_dir_data+"/shared";
    QString m_dir_config       = m_dir_appdata+"/config";
    QString m_dir_struct       = m_dir_appdata+"/struct";
    QString m_dir_template     = m_dir_appdata+"/template";
    // additional directories goes here
    QList<QString> m_create_dirs;

    // additional files goes here
    const QString m_file_config_struct  = "config_struct.json";
    const QString m_file_config         = "config.json";
    const QString m_file_project_struct = "project_file_struct.json";
    const QString m_file_projects       = "projects.json";
    const QString m_file_theme          = "style.qss";
    QString m_filepath_config_struct;
    QString m_filepath_project_struct;
    QString m_filepath_config;
    QString m_filepath_projects;
private:
    const QString m_appFileExtention = ".at";
private:
    AppData();
    ~AppData(){};
protected:
    static AppData * m_instance;
public:
    AppData(AppData &other) = delete; // copy
    void operator=(const AppData &other) = delete; // assign
    static AppData *GetInstance();
public:
    void init();
    bool is_initialized();
private:
    void initAppDataDirectory();
    void initDefault();
    void copyDefaultFiles();
    void copyDefaultFile(const QString &qrc_file_path, const QString &destination_file_path);
    void makeAppDataDirectories();
public:
    QString appFileExtention() const;
    QString appName() const;
    QString appDev() const;
    QString appDevURL() const;
    QString dir_home() const;
    QString dir_docs() const;
    QString dir_app_data() const;
    QString dir_temp() const;
    QString dir_theme() const;
    QString dir_project() const;
    QString dir_data() const;
    QString dir_shared() const;
    QString file_config_struct() const;
    QString file_project_struct() const;
    QString file_projects() const;
    QString file_config() const;
};

#endif // APPDATA_H

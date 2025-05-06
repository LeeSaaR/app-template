#include "appdata.h"

#include "appio.h"

#include <QApplication>
#include <QDebug>
#include <QFile>

AppData *AppData::m_instance = nullptr;

AppData *AppData::GetInstance() {
    if (m_instance == nullptr)
        m_instance = new AppData();

    return m_instance;
}

AppData::AppData(){}

void AppData::init()
{
    initAppDataDirectory();
    m_is_initialized = true;
}

bool AppData::is_initialized()
{
    return m_is_initialized;
}

void AppData::initAppDataDirectory()
{
    dir.cd("C:/Users/"+qgetenv("USERNAME"));
    m_dir_home     = dir.absolutePath();

    m_dir_docs    = m_dir_home+"/Documents";

    dir.cd("C:/Users/"+qgetenv("USERNAME")+"/AppData/Local");
    m_dir_appdata_user = m_dir_home+"/AppData/Local";

    // set directory paths
    m_dir_vendor   = m_dir_appdata_user + "/" + m_dir_vendor;   m_create_dirs.append(m_dir_vendor);
    m_dir_appdata = m_dir_appdata_user + "/" + m_dir_appdata; m_create_dirs.append(m_dir_appdata);
    m_dir_temp     = m_dir_appdata_user + "/" + m_dir_temp;     m_create_dirs.append(m_dir_temp);
    m_dir_theme    = m_dir_appdata_user + "/" + m_dir_theme;    m_create_dirs.append(m_dir_theme);
    m_dir_project  = m_dir_appdata_user + "/" + m_dir_project;  m_create_dirs.append(m_dir_project);
    m_dir_data     = m_dir_appdata_user + "/" + m_dir_data;     m_create_dirs.append(m_dir_data);
    m_dir_shared   = m_dir_appdata_user + "/" + m_dir_shared;   m_create_dirs.append(m_dir_shared);
    m_dir_config   = m_dir_appdata_user + "/" + m_dir_config;   m_create_dirs.append(m_dir_config);
    m_dir_struct   = m_dir_appdata_user + "/" + m_dir_struct;   m_create_dirs.append(m_dir_struct);
    m_dir_template = m_dir_appdata_user + "/" + m_dir_template; m_create_dirs.append(m_dir_template);

    // set app data file paths
    m_filepath_config_struct   = m_dir_struct + "/" + m_file_config_struct;
    m_filepath_project_struct  = m_dir_struct + "/" + m_file_project_struct;
    m_filepath_config          = m_dir_config + "/" + m_file_config;
    m_filepath_projects        = m_dir_appdata + "/" + m_file_projects;

    makeAppDataDirectories();
    copyDefaultFiles();
}

void AppData::copyDefaultFiles()
{
    // GET FILES FROM core.qrc and app.qrc
    QMap<QString, QString> files;
    files[":/default/"+m_file_config_struct]   = m_filepath_config_struct;
    files[":/default/"+m_file_project_struct]  = m_filepath_project_struct;
    files[":/default/"+m_file_config]          = m_filepath_config;
    files[":/default/"+m_file_projects]        = m_filepath_projects;
    files[":/themes/"+m_file_theme]            = m_dir_theme +"/"+ m_file_theme;

    QMapIterator<QString, QString> it(files);
    while (it.hasNext()) {
        it.next();
        copyDefaultFile(it.key(), it.value());
    }
}

void AppData::copyDefaultFile(const QString &qrc_file_path, const QString &destination_file_path)
{
    if (AppIO::fileExists(destination_file_path)) {
        qDebug() << "SKIP: file already exists:" << destination_file_path;
        return;
    }
    QString file_content;
    if (!AppIO::readFile(file_content, qrc_file_path)) return;
    if (!AppIO::writeFile(file_content, destination_file_path)) return;
}

void AppData::makeAppDataDirectories()
{
    for (const QString & dir : std::as_const(m_create_dirs)){
        if(!AppIO::makeDir(dir))
                qDebug() << "SKIP:  dir already exists:" << dir;
    }
}

QString AppData::appFileExtention() const
{
    return m_appFileExtention;
}

QString AppData::appName() const
{
    return m_appName;
}

QString AppData::appDev() const
{
    return m_dev_name;
}

QString AppData::appDevURL() const
{
    return m_dev_url;
}

QString AppData::dir_home() const
{
    return m_dir_home;
}

QString AppData::dir_docs() const
{
    return m_dir_docs;
}

QString AppData::dir_app_data() const
{
    return m_dir_appdata;
}

QString AppData::dir_temp() const
{
    return m_dir_temp;
}

QString AppData::dir_theme() const
{
    return m_dir_theme;
}

QString AppData::dir_project() const
{
    return m_dir_project;
}

QString AppData::dir_shared() const
{
    return m_dir_shared;
}

QString AppData::dir_data() const
{
    return m_dir_data;
}

QString AppData::file_config_struct() const
{
    return m_filepath_config_struct;
}

QString AppData::file_project_struct() const
{
    return m_filepath_project_struct;
}

QString AppData::file_projects() const
{
    return m_filepath_projects;
}

QString AppData::file_config() const
{
    return m_filepath_config;
}

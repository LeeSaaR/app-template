#include "appfiledialog.h"

#include <QDebug>
#include <QFileDialog>
#include "appdata.h"

AppFileDialog::AppFileDialog()
{
    qDebug() << __FUNCTION__;
}

AppFileDialog::~AppFileDialog()
{
    qDebug() << __FUNCTION__;
}

QString AppFileDialog::saveProject(QWidget *parent)
{
    qDebug() << __FUNCTION__;
    qDebug() << "Save Project As...";
    AppData* appData = AppData::GetInstance();

    const QString absoluteFilePath = QFileDialog::getSaveFileName(parent, appData->applicationName()+" - Save Project", QDir::homePath());

    if (absoluteFilePath.isEmpty()) {
        qDebug() << "Warning: No file is set!";
    }
    else {
            qDebug() << "File: " << absoluteFilePath;
    }

    return absoluteFilePath;
}

QString AppFileDialog::openProject(QWidget *parent)
{
    qDebug() << __FUNCTION__;
    qDebug() << "Open Project...";
    AppData* appData = AppData::GetInstance();

    const QString absoluteFilePath = QFileDialog::getOpenFileName(parent, appData->applicationName()+" - Open Project", QDir::homePath());

    if (absoluteFilePath.isEmpty()) {
            qDebug() << "Warning: No file selected!";
    }
    else {
            qDebug() << "File: " << absoluteFilePath;
    }

    return absoluteFilePath;
}

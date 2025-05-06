#ifndef APPFILEDIALOG_H
#define APPFILEDIALOG_H

#include <QWidget>

class AppFileDialog
{
public:
    AppFileDialog();
    ~AppFileDialog();

public:
    static QString saveProject(QWidget* parent);
    static QString openProject(QWidget* parent);
};

#endif // APPFILEDIALOG_H

#include "info.h"

#include "appwindow.h"
#include <QStatusBar>
#include <QLabel>
#include <QProgressBar>

Info::Info() {}

void Info::msg(const QString &text)
{
    AppWindow::StatusBar()->showMessage(text);
}

void Info::prog(const int &val)
{
    AppWindow::ProgBar()->setValue(val);
}

void Info::text(const QString &text)
{
    AppWindow::ProgText()->setText(text);
}

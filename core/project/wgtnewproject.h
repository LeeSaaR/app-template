#ifndef WGTNEWPROJECT_H
#define WGTNEWPROJECT_H

#include <QWidget>
#include <QPushButton>
#include <QStackedWidget>

class WgtNewProject : public QWidget
{
    Q_OBJECT
public:
    explicit WgtNewProject(QWidget *parent = nullptr);
    ~WgtNewProject();

public:
    virtual void transferNewProjectData(){}
};

#endif // WGTNEWPROJECT_H

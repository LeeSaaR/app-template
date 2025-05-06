#include "widgetprojectnew.h"
#include "appinitializer.h"
#include "coreinitializer.h"
#include "ui_widgetprojectnew.h"

#include "projectcreator.h"
#include <QDebug>

WidgetProjectNew::WidgetProjectNew(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WidgetProjectNew)
{
    ui->setupUi(this);
    init();
}

WidgetProjectNew::~WidgetProjectNew()
{
    delete ui;
}

bool WidgetProjectNew::hasPreviousPage()
{
    return currentPage() > 0;
}

bool WidgetProjectNew::hasNextPage()
{
    return currentPage() < lastPage();
}

void WidgetProjectNew::setPage(int index)
{
    pages->setCurrentIndex(index);
    enableButtons();
}

void WidgetProjectNew::previousPage()
{
    setPage(currentPage()-1);
    enableButtons();
}

void WidgetProjectNew::nextPage()
{
    setPage(currentPage()+1);
    enableButtons();
}

int WidgetProjectNew::currentPage()
{
    return pages->currentIndex();
}

int WidgetProjectNew::lastPage()
{
    return pages->count()-1;
}

void WidgetProjectNew::enableBack()
{
    emit enableButtonBack(hasPreviousPage());
}

void WidgetProjectNew::enableNext()
{
    emit enableButtonNext(hasNextPage());
}

void WidgetProjectNew::enableApply()
{
    emit enableButtonApply(currentPage() == lastPage());
}

void WidgetProjectNew::enableButtons()
{
    enableBack();
    enableNext();
    enableApply();
}

void WidgetProjectNew::createNewProject()
{
    // HERE WE TRANSFER THE DATA TO ProjectCreator
    if (wgt_list.isEmpty())
        return;

    for (WgtNewProject *wgt : std::as_const(wgt_list))
        wgt->transferNewProjectData();

    ProjectCreator *project_creator = ProjectCreator::GetInstance();
    project_creator->createProject();
}

void WidgetProjectNew::init()
{
    CoreInitializer::initNewProjectPages(this);
}

void WidgetProjectNew::initConnections(QPushButton* btn_exit, QPushButton* cancel, QPushButton* back, QPushButton* next, QPushButton* apply)
{
    connect(btn_exit, &QPushButton::clicked, this, &WidgetProjectNew::onExit);
    connect(back, &QPushButton::clicked, this, &WidgetProjectNew::onBack);
    connect(next, &QPushButton::clicked, this, &WidgetProjectNew::onNext);
    connect(cancel, &QPushButton::clicked, this, &WidgetProjectNew::onCancel);
    connect(apply, &QPushButton::clicked, this, &WidgetProjectNew::onApply);
}

void WidgetProjectNew::setButtonStates()
{
    enableButtons();
}

bool WidgetProjectNew::hasMultiplePages()
{
    return pages->count() > 1;
}

void WidgetProjectNew::initPages(QList<WgtNewProject *> wgts_derived)
{
    qDebug() << __FUNCTION__;
    pages = ui->stk_wgt_pages;
    if (wgts_derived.isEmpty())
        return;

    wgt_list = wgts_derived;
    for (WgtNewProject *wgt : std::as_const(wgt_list)) {
        addPage(wgt);
    }
    pages->setCurrentIndex(0);
    enableButtons();
}

void WidgetProjectNew::addPage(QWidget* wgt)
{
    pages->insertWidget(lastPage()+1, wgt);
}

void WidgetProjectNew::onBack()
{
    if (!hasPreviousPage()) return;
    previousPage();
}

void WidgetProjectNew::onNext()
{
    if (!hasNextPage()) return;
    nextPage();
}

void WidgetProjectNew::onExit()
{
    emit finishedDialog(AppState::Exit);
}

void WidgetProjectNew::onCancel()
{
    emit finishedDialog(AppState::Cancel);
}

void WidgetProjectNew::onApply()
{
    createNewProject();
    emit finishedDialog(AppState::OpenProject);
}

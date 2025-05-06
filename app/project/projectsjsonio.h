#ifndef PROJECTSJSONIO_H
#define PROJECTSJSONIO_H

#include <QList>

#include "projectfiledata.h"

struct ProjectFile;

class ProjectsJsonIO
{
private:
    ProjectsJsonIO() = delete;

public:
    static void loadProjects(QList<ProjectFileData *> &projects);
    static void saveProjects(QList<ProjectFileData *> &projects);
};

#endif // PROJECTSJSONIO_H

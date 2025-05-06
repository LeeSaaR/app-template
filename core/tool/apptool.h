#ifndef APPTOOL_H
#define APPTOOL_H

#include <QList>

class AppTool
{
private:
    AppTool();

public:
    template< class T >
    static void subtractList(QList<T*> &subtract_list, QList<T*> &target_list) {
        while (!subtract_list.isEmpty()) {
            T* a_instance = subtract_list.last();
            target_list.removeOne(a_instance);
            subtract_list.removeLast();
            delete a_instance;
        }
    };
};

#endif // APPTOOL_H

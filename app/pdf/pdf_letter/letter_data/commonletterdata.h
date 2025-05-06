#ifndef COMMONLETTERDATA_H
#define COMMONLETTERDATA_H

#include "contactdata.h"

#include <QString>
#include <QStringList>

class CommonLetterData
{
private:
    bool m_private = false;
    QString m_institution;
    QString m_gender;
    QString m_title;
    QString m_titleAcademic;
    QString m_nameFirst;
    QString m_nameLast;
    QString m_address1;
    QString m_address2;

public:
    CommonLetterData(){}
    ~CommonLetterData(){}

    enum Name
    {
        // Full         : Max Mustermann
        // Abbreviation : M. Mustermann
        // Formal       : Mustermann
        Full = 0,
        Abbreviation = 1,
        Formal
    };

    bool isPrivate() const {return m_private;}
    bool hasInstitution() const {return !m_institution.isEmpty();}
    bool hasGender() const {return !m_gender.isEmpty();}
    bool hasTitle() const {return !m_title.isEmpty();}
    bool hasTitleAcademic() const {return !m_titleAcademic.isEmpty();}
    bool hasNameFirst() const {return !m_nameFirst.isEmpty();}
    bool hasNameLast() const {return !m_nameLast.isEmpty();}
    bool hasAddress1() const {return !m_address1.isEmpty();}
    bool hasAddress2() const {return !m_address2.isEmpty();}


    QString institution() const { return m_institution; }
    QString gender() const { return m_gender; }
    QString title() const { return m_title; }
    QString titleAcademic() const { return m_titleAcademic; }
    QString nameFirst() const { return m_nameFirst; }
    QString nameLast() const { return m_nameLast; }
    QString address1() const { return m_address1; }
    QString address2() const { return m_address2; }
    QString name(CommonLetterData::Name type, const bool &useTitle = false)
    {
        QStringList name_list;
        switch (type) {
        case Name::Full:
            if (useTitle && hasTitle())
                name_list.append(title());

            if (useTitle && hasTitleAcademic())
                name_list.append(titleAcademic());

            if (hasNameFirst())
                name_list.append(nameFirst());

            name_list.append(nameLast());
            break;
        case Name::Abbreviation:
            if (useTitle && hasTitle())
                name_list.append(title());

            if (useTitle && hasTitleAcademic())
                name_list.append(titleAcademic());

            if (hasNameFirst())
                name_list.append(QString(nameFirst().at(0)) + ".");

            name_list.append(nameLast());
            break;
        case Name::Formal:
            if (hasTitle())
                name_list.append(title());

            if (hasTitleAcademic())
                name_list.append(titleAcademic());

            name_list.append(nameLast());
            break;
        default:
            if (hasNameFirst())
                name_list.append(nameFirst());

            name_list.append(nameLast());
            break;
        }
        return name_list.join(" ");
    }

    void isPrivate(const bool &isPrivate){m_private = isPrivate;}
    void institution(const QString &newValue) { m_institution = newValue; }
    void gender(const QString &newValue) { m_gender = newValue; }
    void title(const QString &newValue) { m_title = newValue; }
    void titleAcademic(const QString &newValue) { m_titleAcademic = newValue; }
    void nameFirst(const QString &newValue) { m_nameFirst = newValue; }
    void nameLast(const QString &newValue) { m_nameLast = newValue; }
    void address1(const QString &newValue) { m_address1 = newValue; }
    void address2(const QString &newValue) { m_address2 = newValue; }

    void address(
        const QString &new_address1,
        const QString &new_address2)
    {
        address1(new_address1);
        address2(new_address2);
    }

    void setName(
        const QString &new_gender,
        const QString &new_title,
        const QString &new_titleAcademic,
        const QString &new_nameFirst,
        const QString &new_nameLast)
    {
        gender(new_gender);
        title(new_nameFirst);
        titleAcademic(new_nameFirst);
        nameLast(new_nameLast);
        nameFirst(new_nameFirst);
    }
};

#endif // COMMONLETTERDATA_H

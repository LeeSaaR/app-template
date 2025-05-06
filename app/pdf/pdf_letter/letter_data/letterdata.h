#ifndef LETTERDATA_H
#define LETTERDATA_H

#include "letteroptions.h"
#include "receiverdata.h"
#include "senderdata.h"

#include <QMap>
#include <QString>
#include <QStringList>

class LetterData
{
private:
    QString m_file_name;
    QString m_document_name;
    QString m_logo;
    QString m_background;
    QString m_date;
    QString m_subject;
    QStringList m_html_pages;
    QStringList m_attachments;
    QMap<QString, QString> m_links;

public:
    LetterData() :
        rec(new ReceiverData()),
        sen(new SenderData()),
        opt(new LetterOptions()){}
    ~LetterData()
    {delete rec; delete sen; delete opt;}

    ReceiverData  *rec; // TODO: Reset Receiver
    SenderData    *sen;
    LetterOptions *opt;

    void initDocument(
        const QString &new_fileName,
        const QString &new_docName)
    {
        fileName(new_fileName);
        docName(new_docName);
    }

    void resetReceiver()
    {
        delete rec;
        rec = new ReceiverData();
    }

    void resetContent()
    {
        m_attachments.clear();
        m_date.clear();
        m_document_name.clear();
        m_file_name.clear();
        m_html_pages.clear();
        m_subject.clear();
    }

    int pageCount() const{ return m_html_pages.size();}
    QStringList attachments() const{return m_attachments;}
    QString backgroundFile() const{ return m_background;}
    QString date() const{ return m_date;}
    QString docName() const{ return m_document_name;}
    QString fileName() const{ return m_file_name+".pdf";}
    QStringList htmlPages() const{return m_html_pages;}
    QString logoFile() const{ return m_logo;}
    QMap<QString, QString> links() const{return m_links;}
    QString subject() const{ return m_subject;}

    void attachments(const QStringList &attachments){m_attachments = attachments;}
    void backgroundFile(const QString &fileName){m_background = fileName;}
    void date(const QString &date){m_date = date;}
    void docName(const QString &docName){m_document_name = docName;}
    void fileName(const QString &fileName){m_file_name = fileName;}
    void htmlPages(const QStringList &htmlPages){m_html_pages = htmlPages;}
    void links(const QMap<QString, QString> &links){m_links = links;}
    void logoFile(const QString &fileName){m_logo = fileName;}
    void subject(const QString &subject){m_subject = subject;}

    bool hasAttachments()const {return !m_attachments.isEmpty();}
    bool hasBackground()const {return !m_background.isEmpty();}
    bool hasDate()const {return !m_date.isEmpty();}
    bool hasDocumentName()const {return !m_document_name.isEmpty();}
    bool hasFileName()const {return !m_file_name.isEmpty();}
    bool hasHtmlPages()const {return !m_html_pages.isEmpty();}
    bool hasLinks()const {return !m_links.isEmpty();}
    bool hasLogo()const {return !m_logo.isEmpty();}
    bool hasSubject()const {return !m_subject.isEmpty();}
};
#endif // LETTERDATA_H

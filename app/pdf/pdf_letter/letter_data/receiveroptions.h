#ifndef RECEIVEROPTIONS_H
#define RECEIVEROPTIONS_H

class ReceiverOptions
{
private:

    bool m_abbreviation   = false;
    bool m_account        = false;
    bool m_confidential   = false;
    bool m_department     = false;
    bool m_direct         = false;
    bool m_reference      = true;
    bool m_represent      = false;
    bool m_title          = true;

public:
    ReceiverOptions(){}
    ~ReceiverOptions(){}


    bool useAbbreviation() const {return m_abbreviation;}
    bool useAccount() const {return m_account;}
    bool useConfidential() const {return m_confidential;}
    bool useDepartment() const {return m_department;}
    bool useDirect() const {return m_direct;}
    bool useReference() const {return m_reference;}
    bool useRepresentative() const {return m_represent;}
    bool useTitle() const {return m_title;}

    void useAbbreviation(const bool &useIt){m_abbreviation = useIt;}
    void useAccount(const bool &useIt){m_account = useIt;}
    void useConfidential(const bool &useIt){m_confidential = useIt;}
    void useDepartment(const bool &useIt){m_department = useIt;}
    void useDirect(const bool &useIt){m_direct = useIt;}
    void useReference(const bool &useIt){m_reference = useIt;}
    void useRepresentative(const bool &useIt){m_represent = useIt;}
    void useTitle(const bool &useIt){m_title = useIt;}
};

#endif // RECEIVEROPTIONS_H

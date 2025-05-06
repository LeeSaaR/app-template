#ifndef PDFWRITER_H
#define PDFWRITER_H

#include <QPdfWriter>
#include <QPainter>
#include <QBrush>
#include <QFont>
#include <QPen>
#include <QMap>
#include <QRegularExpression>

class TableColumns;
struct TableProp;

class PdfWriter
{

private:
    QPdfWriter *q_pdfWriter = nullptr;

public:
    QPainter painter;
    TableColumns* cols = nullptr;

private:
    QString m_document_name = "";
    QString m_file_name     = "";
    int m_dpi               = 300;

    QMap<QString, QBrush> m_brushes;
    QMap<QString, QColor> m_colors;
    QMap<QString, QFont>  m_fonts;
    QMap<QString, QPen>   m_pens;

    QBrush m_current_brush;
    QColor m_current_color;
    QFont m_current_font;
    QPen m_current_pen;
    QString m_current_pen_name;

    QRegularExpression rx_body = QRegularExpression("<body (?)(.*)>(?)");

public:
    int actual_width  = 2480;
    int actual_height = 3508;
    int logo_rect_w  = 886;
    int logo_rect_h  = 591;

    int doc_left   = 0; // left margin
    int doc_right  = 0; // right margin
    int doc_top    = 0; // top margin
    int doc_bottom = 0; // bottom margin

    double m_offset_mm = 3.5;
    double pos_y_mm = 0.0;
    double m_line_height = 45.0;
    double m_table_line_margin = 8.0;

    // without these factors the psoitioning is inaccurate
    double factor_x_PX  = 11.809523809523809523809523809524;
    double factor_y_PX  = 11.811447811447811447811447811448;
    double factor_x_MM  = 0.08467741935483870967741935483871;
    double factor_y_MM  = 0.08466362599771949828962371721779;

public:
    PdfWriter();
    ~PdfWriter();

private:
    void initWriter();
    void resetWriter();
public:
    double getCurrentY() { return pos_y_mm; }
    void setCurrentY(const int &mm) { pos_y_mm = mm; }
private:
    double xPX(const double &mm);
    double yPX(const double &mm);

    double xMM(const int &px);
    double yMM(const int &px);

    double xL(const double &_mm); // position x from left in mm->px
    double xR(const double &_mm); // position x from right in mm->px
    double yT(const double &_mm); // position y from top in mm->px
    double yB(const double &_mm); // position y from Bottom in mm->px

public:
    void paintBeginLandscape();
    void paintBegin();
    void startPdfWriter();
    void startLandscape();
    void paintEndLandscape();
    void paintEnd();

public:
    void initLandscape();
    void drawTextBody(const double &MM_startY, const double &MM_endY, const QString &text);
    void drawText(const double &x, const double &y, const double &x2, const double &y2, const QString &text, Qt::AlignmentFlag options = Qt::AlignLeft);
    void drawLine(const QString &text);
    void drawImage(const double &MM_x, const double &MM_y, const QImage &img);
    void drawLogo(const double &MM_x, const double &MM_y, const QImage &img);
    void drawBackground(const double &MM_x, const double &MM_y, const QImage &img);
    void drawLine(const double &x1, const double &y1, const double &x2, const double &y2);
    void drawHtmlBody(const QString &text, const int &y_pos);
    QString processBodyTag(QString text_html, QFont &font, const int &size, QColor &color) const;

public:
    void initTable(const TableProp &prop);
    void setTableStartPosY(const double &value);
    void drawTableColumn(const int &column_index, const QString &text);
    void drawTableColumnOffset(const int &column_index, const QString &text, const double &offset);
    void drawTableLine(const QString &pen_name);
    void drawTableLineManual(const QString &pen_name, const double& x_end);
    void drawTableLineV(const QString &pen_name, const double &pos_x, const double &pos_yT, const double &pos_yB);
    void tableLineMargin();
    void newLine();

public:
    void addPage();
    void addBrush(const QString &brushName, const QString &colorName);
    void addPen(const QString &penName, const QString &colorName, const int &width);
    void addFont(const QString &fontName, const QString &fontFamily, const bool &bold, const int &pointSize);
    void addColor(const QString &colorName, const QString &hexColor);
    void addColor(const QString &colorName, const int &r, const int &g, const int &b);
    void addColor(const QString &colorName, const int &r, const int &g, const int &b, const int &a);

public:
    void setFileName(const QString &newFileName);
    void setDocumentName(const QString &newDocumentName);
    void setDPI(const int &newDPI);
    void setFont(const QString &fontName, const QString colorName, const int &pt = 0, const bool &bold = false);
    void setBrush(const QString &brushName);
    void setPen(const QString &penName);
    void setLineHeight(const double &line_height_px);
    void offsetPosY(const double &offset_px);

public:
    QStringList brushes() const;
    QStringList pens() const;
    QStringList fonts() const;
    QStringList colors() const;
    QString fileName() const;
    QString documentName() const;
    int dpi() const;
};

struct TableProp {
    QList<double> m_width;
    QList<Qt::AlignmentFlag> m_alignment;
    void add(const double &new_width, const Qt::AlignmentFlag &new_alignment){
        m_width.append(new_width);
        m_alignment.append(new_alignment);
    };

    void clear() {m_width.clear(); m_alignment.clear();}
    const double width(const int &index) const {return m_width.at(index);}
    const Qt::AlignmentFlag alignment(const int &index) const {return m_alignment.at(index);}

    const int size() const {return m_width.size();}
};

class TableColumn
{
public:
    const double start;
    const double width;
    const Qt::AlignmentFlag align;
    const double spacing;
    TableColumn(const double &start, const double &width, Qt::AlignmentFlag align = Qt::AlignRight, const double &spacing = 0.0)
        : start(start), width(width), align(align), spacing(spacing){}
    int endPosition() {return start + width + spacing;};
};

class TableColumns
{
private:
    QMap<int, TableColumn*> cols;
public:
    TableColumns(){}
    ~TableColumns(){qDeleteAll(cols);}
    TableColumn* get(const int &index) {return cols[index];};
    TableColumn* last() {return cols[cols.size()-1];};

    void reset() { qDeleteAll(cols); }

    void add(double &start_col, const double &width, Qt::AlignmentFlag align = Qt::AlignRight, const double &spacing = 0.0) {
        cols[cols.size()] = new TableColumn(start_col, width, align, spacing);
        start_col = start_col + width + spacing; // mind that this is an incremented start_col
    };
    void addLast(double start_col, const double &width, const double &spacing = 0.0) {
        cols[cols.size()] = new TableColumn(start_col, width, Qt::AlignRight, spacing);
    };
    int lastIndex() const {return cols.size()-1;};
    int nextStart() const {
        return cols[lastIndex()]->endPosition();
    }
};

#endif // PDFWRITER_H

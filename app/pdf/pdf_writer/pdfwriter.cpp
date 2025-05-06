#include "pdfwriter.h"

#include <QDebug>
#include <QTextDocument>
#include <QAbstractTextDocumentLayout>
#include <QRegularExpression>

PdfWriter::PdfWriter()
{
    qDebug() << __FUNCTION__;
    initWriter();
}

PdfWriter::~PdfWriter()
{
    qDebug() << __FUNCTION__;
    if (q_pdfWriter) delete q_pdfWriter;
}

void PdfWriter::initWriter()
{
    qDebug() << __FUNCTION__;
    // TODO: CHANGE THE FONT SYSTEM
    // colors
    addColor("white",        255,255,255);
    addColor("grey light",   191,191,191);
    addColor("grey medium",  127,127,127);
    addColor("grey dark",    64,64,64);
    addColor("black",        0,0,0);

    addColor("red",          255,0,0);
    addColor("green",        0,255,0);
    addColor("blue",         0,0,255);

    // brushes
    addBrush("normal", "black");

    // fonts
    addFont("default large", "Ubuntu Thin",  false, 32);
    addFont("default",       "Ubuntu Thin",  false, 11);
    addFont("default bold",  "Ubuntu",       false, 11);
    addFont("default tiny",  "Ubuntu Thin",  false,  7);
    addFont("default footer","Ubuntu Thin",  false,  8);
    addFont("default page",  "Ubuntu Thin",  false,  6);
    addFont("default small", "Ubuntu Thin",  false,  9);
    addFont("default small bold", "Ubuntu",  false,  9);
    addFont("text line",     "Ubuntu",       false,  9);
    addFont("text line thin", "Ubuntu Thin", false,  9);
    addFont("default mono",  "Ubuntu Mono",  false, 11);
    addFont("table bold",    "Ubuntu Bold",   true,  8);
    addFont("table normal",  "Ubuntu",       false,  8);
    addFont("table thin bold", "Ubuntu",      false, 8);
    addFont("table thin",  "Ubuntu Thin",    false,  8);

    // pens
    addPen("default text", "black", 1);
    addPen("marks",  "grey light", 1);
    addPen("footer", "grey light", 2);
    addPen("table thick",  "black", 5);
    addPen("table medium", "grey medium", 2);
    addPen("table thin",   "grey medium", 1);


    doc_left   = xL(25);
    doc_right  = xR(20);
    doc_top    = 0;
    doc_bottom = yB(0);
}


void PdfWriter::resetWriter()
{
    m_file_name.clear();
    m_document_name.clear();
}


double PdfWriter::xPX(const double &mm)
{
    // MM to PX
//    return qRound(mm * factor_x_PX);
    return mm * factor_x_PX;
}

double PdfWriter::yPX(const double &mm)
{
    // MM to PX
//    return qRound(mm * factor_y_PX);
    return mm * factor_y_PX;
}

double PdfWriter::xMM(const int &px)
{
    // PX to MM
    return double(px) * factor_x_MM;
}

double PdfWriter::yMM(const int &px)
{
    // PX to MM
    return double(px) * factor_y_MM;
}

double PdfWriter::xL(const double &_mm)
{
    // position x from left in mm->px
    return xPX(_mm) - xPX(m_offset_mm);
}

double PdfWriter::xR(const double &_mm)
{
    // position x from right in mm->px
    return actual_width - xPX(_mm) - xPX(m_offset_mm);
}

double PdfWriter::yT(const double &_mm)
{
    // position y from top in mm->px
    return yPX(_mm) - yPX(m_offset_mm);
}

double PdfWriter::yB(const double &_mm)
{
    // position y from Bottom in mm->px
    return actual_height - yPX(_mm) - yPX(m_offset_mm);
}

void PdfWriter::paintBeginLandscape()
{
    startLandscape();
    initLandscape();
    painter.begin(q_pdfWriter);
}


void PdfWriter::paintBegin()
{
    qDebug() << __FUNCTION__;
    startPdfWriter();
    painter.begin(q_pdfWriter);
}

void PdfWriter::startPdfWriter()
{
    qDebug() << __FUNCTION__;
    q_pdfWriter = new QPdfWriter( m_file_name );
    q_pdfWriter->setPageSize( QPageSize(QPageSize::A4) );
    q_pdfWriter->setResolution( m_dpi );
    q_pdfWriter->setTitle( m_document_name );
    q_pdfWriter->setPageOrientation(QPageLayout::Portrait);

    int dwPX = q_pdfWriter->width();
    int dhPX = q_pdfWriter->height();

    int dwMM = q_pdfWriter->widthMM();
    int dhMM = q_pdfWriter->heightMM();
    qDebug() << "document PX:" << dwPX << dhPX;
    qDebug() << "document MM:" << dwMM << dhMM;
}

void PdfWriter::startLandscape()
{
    q_pdfWriter = new QPdfWriter( m_file_name );
    q_pdfWriter->setPageSize( QPageSize(QPageSize::A4) );
    q_pdfWriter->setResolution( m_dpi );
    q_pdfWriter->setTitle( m_document_name );
    q_pdfWriter->setPageOrientation(QPageLayout::Landscape);

    int dhPX = q_pdfWriter->width();
    int dwPX = q_pdfWriter->height();

    int dhMM = q_pdfWriter->widthMM();
    int dwMM = q_pdfWriter->heightMM();
    qDebug() << "document PX:" << dwPX << dhPX;
    qDebug() << "document MM:" << dwMM << dhMM;
}

void PdfWriter::paintEndLandscape()
{

}

void PdfWriter::paintEnd()
{
    qDebug() << __FUNCTION__;
    painter.end();
    resetWriter();
    delete q_pdfWriter;
}

void PdfWriter::initLandscape()
{
    qDebug() << __FUNCTION__;
    actual_height = 2480;
    actual_width  = 3508;
    doc_left   = xL(10);
    doc_right  = xR(10);
    doc_top    = 0;
    doc_bottom = yB(0);
}


void PdfWriter::drawTextBody(const double &MM_startY, const double &MM_endY, const QString &text)
{
    double x = doc_left;
    double y = yT(MM_startY);
    double w = doc_right - doc_left;
    double h = yT(MM_endY) - y;

    const QRect rect = QRect(x, y, w, h);
    auto options = Qt::TextWordWrap | Qt::AlignJustify;
    painter.drawText( rect, options, text );
}

void PdfWriter::drawText(const double &x, const double &y, const double &x2, const double &y2, const QString &text, Qt::AlignmentFlag options)
{
    const double _x = xL(x);
    const double _y = yT(y);
    const double _w = xL(x2) - _x;
    const double _h = yT(y2) - _y;

    const QRect rect = QRect(_x, _y, _w, _h);
    painter.drawText( rect, options, text );
    // painter.drawRect( rect );
}

void PdfWriter::drawLine(const QString &text)
{
    double x = doc_left;
    double y = yT(pos_y_mm);
    double w = doc_right - doc_left;
    double h = yT(pos_y_mm) + m_line_height - y;

    const QRect rect = QRect(x, y, w, h);
    auto options = Qt::AlignLeft;
    painter.drawText( rect, options, text );
    newLine();
}

void PdfWriter::drawImage(const double &MM_x, const double &MM_y, const QImage &img)
{
    int x = xL(MM_x);
    int y = yT(MM_y);
    painter.drawImage(x, y, img);

}

void PdfWriter::drawLogo(const double &MM_x, const double &MM_y, const QImage &img)
{
    int x = xL(MM_x);
    int y = yT(MM_y);
    int w = logo_rect_w;
    int h = logo_rect_h;
    QRect rect(x,y,w,h);
    painter.drawImage(rect, img);
    //painter.drawRect(rect);
}

void PdfWriter::drawBackground(const double &MM_x, const double &MM_y, const QImage &img)
{
    int x = xL(MM_x);
    int y = yT(MM_y);
    int w = actual_width;
    int h = actual_height;
    QRect rect(x,y,w,h);
    painter.drawImage(rect, img);
    //painter.drawRect(rect);
}

void PdfWriter::drawLine(const double &x1, const double &y1, const double &x2, const double &y2)
{
    painter.drawLine(xL(x1), yT(y1), xL(x2), yT(y2));
}

void PdfWriter::drawHtmlBody(const QString &text, const int &y_pos)
{
    qDebug() << __FUNCTION__;
    QTextDocument td;
    td.setPageSize(QSize(q_pdfWriter->width(), q_pdfWriter->height()));

    QTextOption textOption;
    textOption.setAlignment(Qt::AlignJustify);
    textOption.setWrapMode(QTextOption::WordWrap);
    td.setDefaultTextOption(textOption);

    const QRectF rect = QRectF(doc_left, yT(y_pos), doc_right-doc_left, yT(260));
    td.setTextWidth(rect.width());

    const QString text_html = processBodyTag(text, m_current_font, 34, m_current_color);

    td.setHtml(text_html);

    painter.translate(rect.topLeft());
    td.drawContents(&painter);
    painter.translate(QPoint(-doc_left, yT(-y_pos+m_offset_mm*2)));
}

QString PdfWriter::processBodyTag(QString text_html, QFont &font, const int &size, QColor &color) const
{
    /*
     * Without set style="color: <color>" in the body tag the text will be invisible.
     * So body tag has to be processed with this method.
     */
    const QString font_family = font.family();
    const QString font_size   = QString::number(size);
    const QString font_color  = "rgb("
                               +QString::number(color.red())+","
                               +QString::number(color.green())+","
                               +QString::number(color.blue())+")";

    const QString rpl_body = "<body style=\"font-family:'"+font_family+"'; font-size:"+font_size+"pt; color: "+font_color+"; font-weight:400; font-style:normal;\">";
    text_html.replace(rx_body, rpl_body);
    return text_html;
}


void PdfWriter::initTable(const TableProp &prop)
{
    if (cols) delete cols;
    double col_spacing = xPX(2);
    double start_col   = doc_left; // where to start the table
    cols = new TableColumns();

    for (int i = 0; i < prop.size(); i++) {
        // mind that start_col is incremented in add()
        cols->add(start_col, xPX( prop.width(i) ), prop.alignment(i), col_spacing);
    }

    // last column
    cols->add(start_col, doc_right - start_col, Qt::AlignRight);
}

void PdfWriter::drawTableColumn(const int &column_index, const QString &text)
{
    double x = cols->get(column_index)->start;
    double y = yT(pos_y_mm);
    double w = cols->get(column_index)->width;
    double h = yT(pos_y_mm) + m_line_height - y;

    const QRect rect = QRect(x, y, w, h);
    auto options = cols->get(column_index)->align;
    painter.drawText( rect, options, text );
    //painter.drawRect( rect );
}

void PdfWriter::drawTableColumnOffset(const int &column_index, const QString &text, const double &offset)
{
    double x = cols->get(column_index)->start;
    double y = yT(pos_y_mm);
    double w = cols->get(column_index)->width;
    double h = yT(pos_y_mm) + m_line_height - y;

    const QRect rect = QRect(x-xPX(1.0)-xPX(offset), y, w, h);
    auto options = cols->get(column_index)->align;
    painter.drawText( rect, options, text );
    //painter.drawRect( rect );
}

void PdfWriter::drawTableLine(const QString &pen_name)
{
    const QString current_pen = m_current_pen_name;
    setPen(pen_name);

    painter.drawLine(
        QPoint(doc_left, yT(pos_y_mm)),
        QPoint(doc_right, yT(pos_y_mm))
    );
    tableLineMargin();
    setPen(current_pen);
}

void PdfWriter::drawTableLineManual(const QString &pen_name, const double &x_end)
{
    const QString current_pen = m_current_pen_name;
    setPen(pen_name);

    painter.drawLine(
        QPoint(doc_left, yT(pos_y_mm)),
        QPoint(doc_left+(xPX(x_end)), yT(pos_y_mm))
        );
    tableLineMargin();
    setPen(current_pen);
}

void PdfWriter::drawTableLineV(const QString &pen_name, const double& pos_x, const double& pos_yT, const double& pos_yB)
{
    const QString current_pen = m_current_pen_name;
    setPen(pen_name);

    painter.drawLine(
        QPoint(xL(pos_x), yT(pos_yT)),
        QPoint(xL(pos_x), yB(pos_yB))
        );
    //tableLineMargin();
    setPen(current_pen);
}

void PdfWriter::setTableStartPosY(const double &value)
{
    pos_y_mm = value;
}

void PdfWriter::tableLineMargin()
{
    pos_y_mm += yMM(m_table_line_margin);
}

void PdfWriter::newLine()
{
    pos_y_mm += yMM(m_line_height);
}



void PdfWriter::addPage()
{
    q_pdfWriter->newPage();
}

void PdfWriter::addBrush(const QString &brushName, const QString &colorName)
{
    QBrush _brush = QBrush();
    _brush.setColor(m_colors[colorName]);
    m_brushes[brushName] = _brush;
}

void PdfWriter::addPen(const QString &penName, const QString &colorName, const int &width)
{
    QPen _pen = QPen();
    _pen.setColor(m_colors[colorName]);
    _pen.setWidth(width);
    m_pens[penName] = _pen;
}

void PdfWriter::addFont(const QString &fontName, const QString &fontFamily, const bool &bold, const int &pointSize)
{
    QFont _font = QFont();
    _font.setFamily(fontFamily);
    _font.setPointSize(pointSize);
    if (bold) _font.setBold(true);
    m_fonts[fontName] = _font;
}

void PdfWriter::addColor(const QString &colorName, const QString &hexColor)
{
    m_colors[colorName] = QColor::fromString(hexColor);
}

void PdfWriter::addColor(const QString &colorName, const int &r, const int &g, const int &b)
{
    m_colors[colorName] = QColor(r, g, b);
}

void PdfWriter::addColor(const QString &colorName, const int &r, const int &g, const int &b, const int &a)
{
    m_colors[colorName] = QColor(r, g, b, a);
}


void PdfWriter::setFileName(const QString &newFileName)
{
    qDebug() << __FUNCTION__;
    m_file_name = newFileName;
}

void PdfWriter::setDocumentName(const QString &newDocumentName)
{
    qDebug() << __FUNCTION__;
    m_document_name = newDocumentName;
}

void PdfWriter::setDPI(const int &newDPI)
{
    qDebug() << __FUNCTION__;
    m_dpi = newDPI;
}

void PdfWriter::setFont(const QString &fontName, const QString penName, const int &pt, const bool &bold)
{
    QFont _font = m_fonts[fontName];
    if (pt > 0)
        _font.setPointSize(pt);
    _font.setBold(bold);
    m_current_font = _font;
    m_current_pen_name = penName;
    painter.setFont(_font);
    painter.setPen(m_pens[penName]/*QPen(m_colors[colorName])*/);
}

void PdfWriter::setBrush(const QString &brushName)
{
    m_current_brush = m_brushes[brushName];
    painter.setBrush(m_brushes[brushName]);
}

void PdfWriter::setPen(const QString &penName)
{
    m_current_pen_name = penName;
    m_current_pen = m_pens[penName];
    painter.setPen(m_pens[penName]);
}

void PdfWriter::setLineHeight(const double &line_height_px)
{
    m_line_height = line_height_px;
}

void PdfWriter::offsetPosY(const double &offset_px)
{
    pos_y_mm += yMM(offset_px);
}


QStringList PdfWriter::brushes() const
{
    return m_brushes.keys();
}

QStringList PdfWriter::pens() const
{
    return m_pens.keys();
}

QStringList PdfWriter::fonts() const
{
    return m_fonts.keys();
}

QStringList PdfWriter::colors() const
{
    return m_colors.keys();
}

QString PdfWriter::fileName() const
{
    return m_file_name;
}

QString PdfWriter::documentName() const
{
    return m_document_name;
}

int PdfWriter::dpi() const
{
    return m_dpi;
}


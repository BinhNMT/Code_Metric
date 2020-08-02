#ifndef XLREPORT_H
#define XLREPORT_H

#include "xlsxdocument.h"
#include "xlsxchartsheet.h"
#include "xlsxcellrange.h"
#include "xlsxchart.h"
#include "xlsxrichstring.h"
#include "xlsxworkbook.h"
using namespace QXlsx;

class XlReport
{
private:
    XlReport();
    QXlsx::Document xlsx;

    // @m_XlReportInstance: pointer to constructor
    static XlReport *m_XlReportInstance;

    // @brief: creating the report excel's file template
    void createReport();

public:
    // @brief: get the instance of XlReport's class (using singleton pattern)
    static XlReport *getXlReportInstance();

    // @brief: fill file name to the report file
    // @cellPosition: Excel report file cell position that be written
    // @content:      The input content that be written to the report file
    void fillFileNameToReport(QString, QString);

    // @brief: fill total Lines os Code to the report file
    // @cellPosition: Excel report file cell position that be written
    // @content:      The input content that be written to the report file
    void fillLocsToReport(QString, QString);

    // @brief: fill Effected Lines of Code to the report file
    // @cellPosition: Excel report file cell position that be written
    // @content:      The input content that be written to the report file
    void fillElocsToReport(QString, QString);

    // @brief: fill total Effort to do to the report file
    // @cellPosition: Excel report file cell position that be written
    // @content:      The input content that be written to the report file
    void fillEffortReport(QString, QString);
    ~XlReport();
};

#endif // XLREPORT_H

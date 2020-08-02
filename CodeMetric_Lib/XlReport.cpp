#include "XlReport.h"

XlReport *XlReport::m_XlReportInstance = nullptr;

XlReport::XlReport()
{
    createReport();
}

XlReport *XlReport::getXlReportInstance()
{
    // Verify whether any XlReport's instance exsited or not
    if (m_XlReportInstance == nullptr)
    {
        m_XlReportInstance = new XlReport();
    }
    return m_XlReportInstance;
}

void XlReport::createReport()
{
    // create Items title
    xlsx.write("A1", "File name");
    xlsx.write("B1", "Total LoCs");
    xlsx.write("C1", "ELoC");
    xlsx.write("D1", "Effort(Manday)");
}

void XlReport::fillFileNameToReport(QString cellPosition, QString content)
{
    // write to custom cell position
    QString columnPosistion = "A";
    xlsx.write(columnPosistion + cellPosition, content);
}

void XlReport::fillLocsToReport(QString cellPosition, QString content)
{
    // write to custom cell position
    QString columnPosistion = "B";
    xlsx.write(columnPosistion + cellPosition, content);
}
void XlReport::fillElocsToReport(QString cellPosition, QString content)
{
    // write to custom cell position
    QString columnPosistion = "C";
    xlsx.write(columnPosistion + cellPosition, content);
}
void XlReport::fillEffortReport(QString cellPosition, QString content)
{
    // write to custom cell position
    QString columnPosistion = "D";
    xlsx.write(columnPosistion + cellPosition, content);
}

XlReport::~XlReport()
{
    xlsx.saveAs("C:\\Users\\acer\\Desktop\\MetricReport.xlsx");
}

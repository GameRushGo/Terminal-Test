#ifndef MANAGEDATA_H
#define MANAGEDATA_H

#include <QString>
#include <QFile>
#include <QDebug>
#include <QSettings>
#include <QObject>
#include <QtCore>

class ManageData
{
public:
    ManageData();
    ~ManageData();
    //管理数据文件路径
    void setDataPath(QString value);
    QString getDataPath();
    //管理EEG脑电程序路径
    void setEEGPath(QString value);
    QString getEEGPath();
    //管理BG大游戏路径
    void setBGPath(QString value);
    QString getBGPath();
    //管理App游戏程序路径
    void setAppPath(QList<QString> &file_path);
    QList<QString> getAppPath();

    //ToSring函数，返回所有数据

private:
    QSettings *pIni;
    QString data_path;
    QString EGG_path;
    QString BG_path;
    QList<QString> app_path;
};

#endif // MANAGEDATA_H

#ifndef CTESTERINFO_H
#define CTESTERINFO_H
#include "qlist.h"
#include "QString"

struct msg{
    char name[20];	    //被测者姓名
    int  age;		//年龄
    char date[30];       //日期
    char type[50];       //实验类型
};

class CTesterInfo
{
public:
    CTesterInfo();
    // 读取测试者信息
    void ReadInfo();

    //信息写入文件
    void WirteInfo();

    //添加新测试者
    void AddInfo(QString name, QString age,QString date, QString type);
    //void DeletInfo();

    QList <msg> info;
    int num;
};

#endif // CTESTERINFO_H

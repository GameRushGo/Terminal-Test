#ifndef CTESTERINFO_H
#define CTESTERINFO_H
#include "qlist.h"
#include "QString"

struct msg{
    int number;
    int group;
    int research;
    char name[20];	    //被测者姓名
    char identity[20];
    char tel[20];
    char department[20];
    char classes[20];
    float  weight;
    float vision;
//    int  age;		//年龄
//    char date[30];       //日期
//    char type[50];       //实验类型
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
    void AddInfo(int group,int research,QString name, QString identity,
                 QString tel, QString department,QString classes, float  weight,float vision);
    //void DeletInfo();

    QList <msg> info;
    int num;
};

#endif // CTESTERINFO_H

#include "ctesterinfo.h"
#include <QSettings>  //读写ini文件。
#include<QDebug>
#include <qfile.h>


CTesterInfo::CTesterInfo()
{
}


//读取被测试人员信息
void CTesterInfo::ReadInfo()
{
    msg tmp;

    FILE *fd = fopen("testerinfo.txt","r");
    if(fd == NULL){
        qDebug() <<"打开文件失败！";
    }else{
        while(fread(&tmp,sizeof(tmp),1,fd)>0){
            //qDebug() <<tmp.name<<tmp.age<<tmp.date<<tmp.type;
            info.push_back(tmp);
        }
    }
    fclose(fd);
}


//写入文件
void CTesterInfo::WirteInfo()
{
    msg tmp;
    int length=0;
    FILE *fd = fopen("testerinfo.txt","w+");
    length=info.size();
    if (length >= 0)	//商品链表有内容才执行
    {
        //通过迭代器取出链表内容，写入文件
        for (QList<msg>::iterator it = info.begin(); it != info.end(); it++)
        {
            tmp.age=it->age;
            memcpy(tmp.name,it->name,20);
            memcpy(tmp.date,it->date,30);
            memcpy(tmp.type,it->type,50);
            fwrite(&tmp,sizeof(tmp),1,fd);
            //qDebug() << "info:" << tmp.name<<tmp.age<<tmp.date<<tmp.type;
        }
    }
    fclose(fd);
}

//添加新被试
void CTesterInfo::AddInfo(QString name, QString age,QString date,QString type)
{
    msg tmp;
    std::string tr;
    if(!name.isEmpty()){
        tmp.age=age.toInt();
        tr=name.toStdString();
        memcpy(tmp.name,tr.data(),20);
        memcpy(tmp.date,date.toLatin1().data(),30);
        tr=type.toStdString();
        memcpy(tmp.type,tr.data(),50);
        qDebug() << "start:" << name<<age<<date<<type;
        qDebug() << "add:" << tmp.name<<tmp.age<<tmp.date<<tmp.type;
        info.push_back(tmp);
    }
}



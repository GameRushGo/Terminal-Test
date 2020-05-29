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
//            qDebug() << "read:" << tmp.number<<tmp.group<<tmp.research<<tmp.name<<tmp.identity<<
//                        tmp.tel<<tmp.department<<tmp.classes<< tmp.weight<<tmp.vision;
            info.push_back(tmp);
        }
    }
    fclose(fd);
}


//写入文件
void CTesterInfo::WirteInfo()
{
    msg tmp;
    int i=1;
    int length=0;
    FILE *fd = fopen("testerinfo.txt","w+");
    length=info.size();
    if (length >= 0)	//商品链表有内容才执行
    {
        //通过迭代器取出链表内容，写入文件
        for (QList<msg>::iterator it = info.begin(); it != info.end(); it++)
        {
            tmp.number=i;
            tmp.group=it->group;
            tmp.research=it->research;
            memcpy(tmp.name,it->name,20);
            memcpy(tmp.identity,it->identity,20);
            memcpy(tmp.tel,it->tel,20);
            memcpy(tmp.department,it->department,20);
            memcpy(tmp.classes,it->classes,20);
            tmp.weight=it->weight;
            tmp.vision=it->vision;
            fwrite(&tmp,sizeof(tmp),1,fd);
            i++;
//            qDebug() << "write:" << tmp.number<<tmp.group<<tmp.research<<tmp.name<<tmp.identity<<
//                        tmp.tel<<tmp.department<<tmp.classes<< tmp.weight<<tmp.vision;
        }
    }
    fclose(fd);
}

//添加新被试
void CTesterInfo::AddInfo(int group,int research,QString name, QString identity,
                          QString tel, QString department,QString classes, float  weight,float vision)
{
    msg tmp;
    int num=0;
    std::string tr;
    if(!name.isEmpty()){
        num+=1;
        tmp.number=num;
        tmp.research=research;
        tmp.group=group;
        tr=name.toStdString();
        memcpy(tmp.name,tr.data(),20);
        memcpy(tmp.identity,identity.toLatin1().data(),20);
        memcpy(tmp.tel,tel.toLatin1().data(),20);
        tr=department.toStdString();
        memcpy(tmp.department,tr.data(),20);
        tr=classes.toStdString();
        memcpy(tmp.classes,tr.data(),20);
        tmp.weight=weight;
        tmp.vision=vision;
//        qDebug() << "add:" << tmp.number<<tmp.group<<tmp.research<<tmp.name<<tmp.identity<<
//                    tmp.tel<<tmp.department<<tmp.classes<< tmp.weight<<tmp.vision;
        info.push_back(tmp);
    }
}



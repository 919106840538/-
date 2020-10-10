#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <iostream>
#include <QString>
#include "set_admin.h"
#include "log_in.h"
#include "in.h"
#include "changeinf.h"
#include "lookfor.h"
#include "remove.h"
#include "vipguanli.h"
#include "vipzhuce.h"
#include "findvip.h"

class admin{
private:

        QString admin_id;           //工号
        QString name;               //姓名
        QString pwd;                //密码
        QString phone;              //手机号

public:

        QString getname(){
            return name;
        }

        void setAdmin_id(const QString &s ) { admin_id=s; }
        void setName(const QString &s) { name=s; }
        void setPwd(const QString &s) { pwd=s; }
        void setPhone(const QString &s) { phone=s; }
        bool isAdmin_id(const QString &s){
            if(admin_id==s)
                return true;
            else
                return false;
        }
        bool isPwd(const QString &s){
            if(pwd==s)
                return true;
            else
                return false;
        }

};

class Date{
    private:
        QString year, month, day;
    public:


        void setYear(const QString &s) { year = s; }
        void setMonth(const QString &s) { month = s; }
        void setDay(const QString &s) { day = s; }
        QString getYear() { return year; }
        QString getMonth() { return month; }
        QString getDay() { return day; }
};

/*
class in_goods{
    private:
        int    goods_id;           //货号
        QString name;               //货物名称
        int    In_num;           //入库数量
        Date   In_date;            //入库日期
        QString unit;               //计量单位
        double P_price;            //进货单价
    public:
        void   setGoods_id(const QString &s) { goods_id= s.toInt(); }
        void   setName(const QString &s) { name = s; }
        void   setIn_num(const QString &s) { In_num = s.toInt(); }
        void   setIn_date(const QString &y,const QString &m,const QString &d) {
            In_date.setYear(y);
            In_date.setMonth(m);
            In_date.setDay(d);
        }
        void   setUnit(const QString &s) { unit = s; }
        void   setP_price(const QString &s) { P_price = s.toDouble(); }
        int    getGoods_id() { return goods_id; }
        QString getName() { return name; }
        int    getIn_num() { return In_num; }
        QString    getIn_date_year() { return In_date.getYear(); }
        QString    getIn_date_month() { return In_date.getMonth(); }
        QString    getIn_date_day() { return In_date.getDay(); }
        QString getUnit() { return unit; }
        double getP_price() { return P_price; }
};


class out_goods{
    private:
        int    goods_id;            //货号
        QString name;                //货物名称
        int    Out_num;             //出库数量
        Date   Out_date;            //出库日期
        double S_price;             //出货单价
    public:
        void   setGoods_id(const QString &s) { goods_id = s.toInt(); }
        void   setName(const QString &s) { cin>>name; }
        void   setOut_num(const QString &s) { Out_num = s.toInt(); }
        void   setOut_date(const QString &y,const QString &m,const QString &d) {
            Out_date.setYear(y);
            Out_date.setMonth(m);
            Out_date.setDay(d);
        }
        void   setS_price(const QString &s) { S_price = s.toDouble(); }
        int    getGoods_id() { return goods_id; }
        QString getName() { return name; }
        int    getOut_num() { return Out_num; }
        QString    getOut_date_year() { return Out_date.getYear(); }
        QString    getOut_date_month() { return Out_date.getMonth(); }
        QString    getOut_date_day() { return Out_date.getDay(); }
        double getS_price() { return S_price; }
};*/

class goods{
    private:
        int    goods_id;          //货号
        QString name;                //商品名称
        double P_price;            //进货单价
        double S_price;             //售货单价
        int total_num=0;            //该货物总数
        int sales_volume=0;         //销量
        QString unit;                //计量单位
    public:
        bool exist = true;
        void   setGoods_id(const QString &s)
        {
            goods_id=s.toInt();
        }
        void   setName(const QString &s)
        {
            name=s;
        }
        void   setP_price(const QString &s)
        {
            P_price = s.toDouble();
        }
        void   setS_price(const QString &s)
        {
            S_price=s.toDouble();
        }
        void   setTotal_num(const QString &s)
        {
            total_num+=s.toInt();
        }
        void   destory(){
            total_num = 0;
        }
        void   setSales_volume(const QString &s)
        {
            sales_volume+=s.toInt();
        }
        void   setUnit(const QString &s)
        {
            unit=s;
        }
        int    getGoods_id()
        {
            return goods_id;
        }
        QString getName()
        {
            return name;
        }
        double getS_price()
        {
            return S_price;
        }
        double getP_price()
        {
            return P_price;
        }
        int    getTotal_num()
        {
            return total_num;
        }
        int    getSales_volume()
        {
            return sales_volume;
        }
        QString getUnit()
        {
            return unit;
        }

};

class vip{
    private:
        QString name;                //姓名
        QString phone;              //手机号
        int money = 0;                  //余额
    public:
        void setmoney(const QString &s)
        {
            money+=s.toInt();
        }
        void   setName(const QString &s)
        {
            name =s;
        }
        void   setPhone(const QString &s)
        {
            phone= s;
        }
        QString getName()
        {
            return name;
        }
        QString getPhone()
        {
            return phone;
        }
};

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

    ~MainWindow();

private slots:
    void on_exit_released();

    void on_set_admin_released();

    void on_log_in_released();
    void zhuce();
    void denlu();
    void ruku();
    void gaijia();
    void chazhao();
    void xiajia();
    void chaxun();

    void on_back_released();

    void on_ingood_released();

    void on_totalgood_released();

    void on_changemes_released();

    void on_findgood_released();

    void on_possesion_released();

    void on_remov_released();

    void on_vip_released();

private:
    double asset=50000;     //资产
    vip VIP[5000];
    int v=0;                //会员人数
    goods good[5000];
    int total = 0;          //仓库中存的货物总数
    vipguanli guanvip;      //会员管理窗口
    vipzhuce setvip;        //会员注册窗口
    findvip chayue;         //余额查询窗口
    REmove removv;          //下架窗口
    lookfor lkfor;          //查找货物窗口
    changeinf chg;          //改价窗口
    in IN;                  //入库窗口
    log_in login;           //登录窗口
    set_admin set_Admin;    //注册窗口
    admin Admin[10],user;
    int ad = 0;         //管理人数量
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

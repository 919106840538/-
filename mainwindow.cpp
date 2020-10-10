#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include <QDebug>
#include <QTimer>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("瀚瀚超市仓库管理系统");
    setStyleSheet("#logmenu{border-image: url(:/new/prefix1/image/超市外部图.jpg);}"
                  "#mainmenu{border-image: url(:/new/prefix1/image/商品全局图.jpg);}"
                  "#back{border-image: url(:/new/prefix1/image/e67b324eae3c964506b73021aa3214ae.jpg);}");
    connect(&set_Admin,&set_admin::zhuce,this,&MainWindow::zhuce);
    connect(&login,&log_in::denlu,this,&MainWindow::denlu);
    connect(&IN,&in::ruku,this,&MainWindow::ruku);
    connect(&chg,&changeinf::gaijia,this,&MainWindow::gaijia);
    connect(&lkfor,&lookfor::chazhao,this,&MainWindow::chazhao);
    connect(&removv,&REmove::xiajia,this,&MainWindow::xiajia);
    connect(&guanvip,&vipguanli::chaxun,this,&MainWindow::chaxun);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::chaxun()
{
    QString s = "姓名：手机号码";
    for(int i = 0;i<v;i++)
    {
        s+="\n"+VIP[i].getName()+"："+VIP[i].getPhone();
    }
    if(s == "姓名：手机号码")
        s = "暂无注册会员";
    QMessageBox *m_box = new QMessageBox(QMessageBox::Information,QString("通知"),s);
    m_box->show();
}
void MainWindow::on_exit_released()
{
    exit(0);
}

void MainWindow::on_set_admin_released()
{
    if(ad<10)
    set_Admin.show();
    else
    {
        QMessageBox *m_box = new QMessageBox(QMessageBox::Information,QString("通知"),QString("管理员人数到达上限（10人）"));
        QTimer::singleShot(2000,m_box,SLOT(accept()));
        m_box->exec();
    }
}

void MainWindow::on_log_in_released()
{
    login.show();
}
void MainWindow::zhuce()
{
    if(ad<10)
    {
    Admin[ad].setAdmin_id(set_Admin.getID());
    qDebug()<<set_Admin.getID();
    Admin[ad].setName(set_Admin.getNAME());
    qDebug()<<set_Admin.getNAME();
    Admin[ad].setPwd(set_Admin.getPASSWORD());
    qDebug()<<set_Admin.getPASSWORD();
    Admin[ad].setPhone(set_Admin.getNUMBER());
    qDebug()<<set_Admin.getNUMBER();
    if(set_Admin.getID()==""||set_Admin.getNAME()==""||set_Admin.getPASSWORD()==""||set_Admin.getNUMBER()=="")
    {
        QMessageBox *m_box = new QMessageBox(QMessageBox::Information,QString("通知"),QString("请完整输入以上信息"));
        QTimer::singleShot(1500,m_box,SLOT(accept()));
        m_box->exec();
    }
    else
    {QMessageBox *m_box = new QMessageBox(QMessageBox::Information,QString("通知"),QString("注册成功"));
        QTimer::singleShot(1500,m_box,SLOT(accept()));
        m_box->exec();
        set_Admin.oon_pushButton_2_released();
        set_Admin.hide();
        ad++;}

    }
}

void MainWindow::denlu()
{
    QString id,pass;
    id = login.getid();
    pass = login.getpass();
    int i = 0;
    bool suc = false,find = true;
    for(;i<ad;i++)
    {
        if(Admin[i].isAdmin_id(id))
        {
            find = false;
            if(Admin[i].isPwd(pass))
            {suc = true;
            break;}
            else
            {
                QMessageBox *m_box = new QMessageBox(QMessageBox::Information,QString("通知"),QString("登陆失败\n密码错误"));
                QTimer::singleShot(2000,m_box,SLOT(accept()));
                m_box->exec();
                login.blankpass();
                break;
            }
        }
    }
    if(suc)
    {
        user = Admin[i];
        QMessageBox *m_box = new QMessageBox(QMessageBox::Information,QString("通知"),QString(user.getname()+"\n很高兴为您服务"));
        QTimer::singleShot(2000,m_box,SLOT(accept()));
        m_box->exec();
        login.oon_pushButton_2_released();
        login.hide();
        //跳转至下一界面
        ui->stackedWidget->setCurrentIndex(1);
    }
    else if (find)
    {
        QMessageBox *m_box = new QMessageBox(QMessageBox::Information,QString("通知"),QString("找不到此用户"));
        QTimer::singleShot(2000,m_box,SLOT(accept()));
        m_box->exec();
        login.oon_pushButton_2_released();
    }
}

void MainWindow::on_back_released()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_ingood_released()
{
    IN.show();
    QMessageBox *m_box = new QMessageBox(QMessageBox::Information,QString("通知"),QString("入库新商品时请输入所有信息\n入库已有商品时只需输入货号，入库数量及进货单价"));
    m_box->show();
}

void MainWindow::ruku()
{
    if(total<5000)
    {
        int i = 0;
        bool find = false;
        QString in_name = IN.getname(), in_unit = IN.getunit(),in_id = IN.getid();
        QString in_price = IN.getprice(), in_amount = IN.getamount(),sprice = IN.getsprice();

        for(;i<total;i++)
        {
            //找到
            if(good[i].getGoods_id() == in_id.toInt())
            {
                find = true;
                break;

            }
        }
        if(find)
        {
            if(!good[i].exist)
                good[i].exist = true;
            good[i].setTotal_num(in_amount);
            qDebug()<<good[total].getSales_volume();
            QMessageBox *m_box = new QMessageBox(QMessageBox::Information,QString("通知"),QString("入库成功\n"
                                                                                                "仓库中的"
                                                                                                +good[i].getName()+
                                                                                                "库存增加"));
            double n=in_amount.toDouble()*in_price.toDouble();
            asset=asset-n;
            QTimer::singleShot(1500,m_box,SLOT(accept()));
            m_box->exec();
            IN.oon_pushButton_2_released();
        }
        else{
            good[total].setGoods_id(in_id);
            good[total].setName(in_name);
            good[total].setTotal_num(in_amount);
            good[total].setUnit(in_unit);
            good[total].setS_price(sprice);
            qDebug()<<good[total].getSales_volume();
            double n=in_amount.toDouble()*in_price.toDouble();
            asset=asset-n;
            QMessageBox *m_box = new QMessageBox(QMessageBox::Information,QString("通知"),QString("入库成功\n"
                                                                                                "仓库中新增"+good[total].getName()+"库存"));
            QTimer::singleShot(1500,m_box,SLOT(accept()));
            m_box->exec();
            total++;
            IN.oon_pushButton_2_released();
        }
    }
    else
    {
        QMessageBox *m_box = new QMessageBox(QMessageBox::Information,QString("通知"),QString("仓库容量到达上限"));
        QTimer::singleShot(1500,m_box,SLOT(accept()));
        m_box->exec();
    }

}

void MainWindow::on_totalgood_released()
{
    QString intotal = " 货号  商品名称    销售单价    数量  销量  计量单位", tmp;
    if(!total)
    {
        intotal ="\n仓库无库存";
    }
    else
    {
        for(int i = 0;i<total;i++)
            if(good[i].exist)
        {
            intotal+="\n"+tmp.setNum(good[i].getGoods_id())+"   "+good[i].getName()+"   ";
            intotal+=tmp.setNum(good[i].getS_price());
            intotal+="  "+tmp.setNum(good[i].getTotal_num())+"   ";
            intotal+=tmp.setNum(good[i].getSales_volume())+"  "+good[i].getUnit();
        }
    }
    if (intotal == " 货号  商品名称    销售单价    数量  销量  计量单位")
        intotal ="\n仓库无库存";
    QMessageBox *m_box = new QMessageBox(QMessageBox::Information,QString("通知"),intotal);
    m_box->show();
}

void MainWindow::on_changemes_released()
{
    chg.show();
}

void MainWindow::gaijia(){
    int i = 0;
    bool find = false;
    QString gai_id = chg.getid(),gai_sprice = chg.getsprice();

    for(;i<total;i++)
    {
        //找到
        if(good[i].getGoods_id() == gai_id.toInt())
            if(good[i].exist)
        {
            find = true;
            break;

        }
    }
    if(find)
    {
        good[i].setS_price(gai_sprice);
        QMessageBox *m_box = new QMessageBox(QMessageBox::Information,QString("通知"),QString("改价成功\n"
                                                                                            "仓库中的"
                                                                                            +good[i].getName()+
                                                                                            "售价变为"+gai_sprice));
        QTimer::singleShot(1500,m_box,SLOT(accept()));
        m_box->exec();
        chg.oon_pushButton_2_released();
    }
    else{
        QMessageBox *m_box = new QMessageBox(QMessageBox::Information,QString("通知"),QString("货号不存在或货品已下架"));
        QTimer::singleShot(1500,m_box,SLOT(accept()));
        m_box->exec();

        chg.oon_pushButton_2_released();
    }
}

void MainWindow::on_findgood_released()
{
    lkfor.show();
    QMessageBox *m_box = new QMessageBox(QMessageBox::Information,QString("通知"),QString("输入货号或者商品名以查找货物信息\n（优先依据货号查找）"));
    m_box->show();
}

void MainWindow::chazhao(){
    QString id = lkfor.getid(),name = lkfor.getname();
    bool find = false;
    if(!id.isEmpty()){
        int fid = id.toInt(),i =0;
        for( ; i<total;i++)
        {
            if(good[i].getGoods_id() == fid)
            {
                find = true;
                break;
            }
        }
        if(find)
        {
            if(good[i].exist)
            {QString intotal = " 货号  商品名称    销售单价    数量  销量  计量单位", tmp;
                intotal+="\n"+tmp.setNum(good[i].getGoods_id())+"   "+good[i].getName()+"   ";
                intotal+=tmp.setNum(good[i].getS_price());
                intotal+="  "+tmp.setNum(good[i].getTotal_num())+"   ";
                intotal+=tmp.setNum(good[i].getSales_volume())+"  "+good[i].getUnit();
                QMessageBox *m_box = new QMessageBox(QMessageBox::Information,QString("通知"),intotal);
                m_box->show();
                lkfor.oon_pushButton_2_released();
            }
            else
            {
                QMessageBox *m_box = new QMessageBox(QMessageBox::Information,QString("通知"),"货品已下架");
                QTimer::singleShot(2500,m_box,SLOT(accept()));
                m_box->exec();
                lkfor.oon_pushButton_2_released();
            }

        }
        else if(name.isEmpty())
        {
            QMessageBox *m_box = new QMessageBox(QMessageBox::Information,QString("通知"),"货号查询失败");
            m_box->show();
            lkfor.oon_pushButton_2_released();
        }
        else{
            i = 0;
            for(; i<total;i++)
            {
                if(good[i].getName() == name)
                {
                    find = true;
                    break;
                }
            }
            if(find)
            {
                if(good[i].exist)
                {QString intotal = " 货号  商品名称    销售单价    数量  销量  计量单位", tmp;
                    intotal+="\n"+tmp.setNum(good[i].getGoods_id())+"   "+good[i].getName()+"   ";
                    intotal+=tmp.setNum(good[i].getS_price());
                    intotal+="  "+tmp.setNum(good[i].getTotal_num())+"   ";
                    intotal+=tmp.setNum(good[i].getSales_volume())+"  "+good[i].getUnit();
                    QMessageBox *m_box = new QMessageBox(QMessageBox::Information,QString("通知"),intotal);
                    m_box->show();
                    lkfor.oon_pushButton_2_released();
                }
                else
                {
                    QMessageBox *m_box = new QMessageBox(QMessageBox::Information,QString("通知"),"货品已下架");
                    QTimer::singleShot(2500,m_box,SLOT(accept()));
                    m_box->exec();
                    lkfor.oon_pushButton_2_released();
                }
            }
            else
            {
                QMessageBox *m_box = new QMessageBox(QMessageBox::Information,QString("通知"),"查询失败");
                m_box->show();
                lkfor.oon_pushButton_2_released();
            }
        }
    }
    else if(name.isEmpty())
    {
        QMessageBox *m_box = new QMessageBox(QMessageBox::Information,QString("通知"),QString("请输入"));
        QTimer::singleShot(1500,m_box,SLOT(accept()));
        m_box->exec();
    }
    else{
        int i = 0;
        for(; i<total;i++)
        {
            if(good[i].getName() == name)
            {
                find = true;
                break;
            }
        }
        if(find)
        {
            if(good[i].exist)
            {QString intotal = " 货号  商品名称    销售单价    数量  销量  计量单位", tmp;
                intotal+="\n"+tmp.setNum(good[i].getGoods_id())+"   "+good[i].getName()+"   ";
                intotal+=tmp.setNum(good[i].getS_price());
                intotal+="  "+tmp.setNum(good[i].getTotal_num())+"   ";
                intotal+=tmp.setNum(good[i].getSales_volume())+"  "+good[i].getUnit();
                QMessageBox *m_box = new QMessageBox(QMessageBox::Information,QString("通知"),intotal);
                m_box->show();
                lkfor.oon_pushButton_2_released();
            }
            else
            {
                QMessageBox *m_box = new QMessageBox(QMessageBox::Information,QString("通知"),"货品已下架");
                QTimer::singleShot(2500,m_box,SLOT(accept()));
                m_box->exec();
                lkfor.oon_pushButton_2_released();
            }
        }
        else
        {
            QMessageBox *m_box = new QMessageBox(QMessageBox::Information,QString("通知"),"查询失败");
            m_box->show();
            lkfor.oon_pushButton_2_released();
        }
    }
}

void MainWindow::on_possesion_released()
{
    QString s;
    QMessageBox *m_box = new QMessageBox(QMessageBox::Information,QString("资产盘点"),"现共有资产"+s.setNum(asset)+"元");
    m_box->show();
}



void MainWindow::on_remov_released()
{
    removv.show();
    QMessageBox *m_box = new QMessageBox(QMessageBox::Information,QString("通知"),QString("输入货号或者商品名以下架对应货物\n（优先依据货号查找）"));
    m_box->show();
}

void MainWindow::xiajia()
{
    QString id = removv.getid(),name = removv.getname();
    bool find = false;
    if(!id.isEmpty())
    {
        int fid = id.toInt(),i =0;
        for( ; i<total;i++)
        {
            if(good[i].getGoods_id() == fid)
            {
                find = true;
                break;
            }
        }
        if(find)
        {
            if(good[i].exist)
            {
                good[i].exist = false;
                QMessageBox *m_box = new QMessageBox(QMessageBox::Information,QString("通知"),"货品"+good[i].getName()+"下架成功");
                QTimer::singleShot(2500,m_box,SLOT(accept()));
                m_box->exec();
                good[i].destory();
                removv.oon_pushButton_2_released();
            }
            else
            {
                QMessageBox *m_box = new QMessageBox(QMessageBox::Information,QString("通知"),"货品已下架");
                QTimer::singleShot(2500,m_box,SLOT(accept()));
                m_box->exec();
                removv.oon_pushButton_2_released();
            }

        }
        else if(name.isEmpty())
        {
            QMessageBox *m_box = new QMessageBox(QMessageBox::Information,QString("通知"),"找不到货物\n无法下架");
            m_box->show();
            removv.oon_pushButton_2_released();
        }
        else{
            i = 0;
            for(; i<total;i++)
            {
                if(good[i].getName() == name)
                {
                    find = true;
                    break;
                }
            }
            if(find)
            {
                if(good[i].exist)
                {
                    good[i].exist = false;
                    QMessageBox *m_box = new QMessageBox(QMessageBox::Information,QString("通知"),"货品"+good[i].getName()+"下架成功");
                    QTimer::singleShot(2500,m_box,SLOT(accept()));
                    m_box->exec();
                    good[i].destory();
                    removv.oon_pushButton_2_released();
                }
                else
                {
                    QMessageBox *m_box = new QMessageBox(QMessageBox::Information,QString("通知"),"货品已下架");
                    QTimer::singleShot(2500,m_box,SLOT(accept()));
                    m_box->exec();
                    removv.oon_pushButton_2_released();
                }
            }
            else
            {
                QMessageBox *m_box = new QMessageBox(QMessageBox::Information,QString("通知"),"找不到货物\n无法下架");
                m_box->show();
                removv.oon_pushButton_2_released();
            }
        }

    }
    else if(name.isEmpty())
    {
        QMessageBox *m_box = new QMessageBox(QMessageBox::Information,QString("通知"),QString("请输入"));
        QTimer::singleShot(1500,m_box,SLOT(accept()));
        m_box->exec();
    }
    else
    {

        int i = 0;
        for(; i<total;i++)
        {
            if(good[i].getName() == name)
            {
                find = true;
                break;
            }
        }
        if(find)
        {
            if(good[i].exist)
            {
                good[i].exist = false;
                QMessageBox *m_box = new QMessageBox(QMessageBox::Information,QString("通知"),"货品"+good[i].getName()+"下架成功");
                QTimer::singleShot(2500,m_box,SLOT(accept()));
                m_box->exec();
                removv.oon_pushButton_2_released();

                good[i].destory();
            }
            else
            {
                QMessageBox *m_box = new QMessageBox(QMessageBox::Information,QString("通知"),"货品已下架");
                QTimer::singleShot(2500,m_box,SLOT(accept()));
                m_box->exec();
                removv.oon_pushButton_2_released();
            }
        }
        else
        {
            QMessageBox *m_box = new QMessageBox(QMessageBox::Information,QString("通知"),"找不到货物\n无法下架");
            removv.oon_pushButton_2_released();
            m_box->show();
        }
    }
}



void MainWindow::on_vip_released()
{
    guanvip.show();
}

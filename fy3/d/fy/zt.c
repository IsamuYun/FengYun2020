#include <ansi.h>
inherit ROOM;
//void kf_same(object who,object me);

string *guanwai = ({//���ﶨ��Ŀ��ܲ�����
"/u/guanwai/chanhouse.c",
"/u/guanwai/citygate.c",
"/u/guanwai/dazhaotemple.c",
"/u/guanwai/grassland0.c",
"/u/guanwai/grassland1.c",
"/u/guanwai/grassland2.c",
"/u/guanwai/grassland3.c",
"/u/guanwai/grassland4.c",
"/u/guanwai/inn.c",
"/u/guanwai/octo1.c",
"/u/guanwai/octo10.c",
"/u/guanwai/octo11.c",
"/u/guanwai/octo12.c",
"/u/guanwai/octo13.c",
"/u/guanwai/octo14.c",
"/u/guanwai/octo15.c",
"/u/guanwai/octo16.c",
"/u/guanwai/octo2.c",
"/u/guanwai/octo3.c",
"/u/guanwai/octo4.c",
"/u/guanwai/octo5.c",
"/u/guanwai/octo6.c",
"/u/guanwai/octo7.c",
"/u/guanwai/octo8.c",
"/u/guanwai/octo9.c",
"/u/guanwai/octostreet.c",
"/u/guanwai/shop.c",
"/u/guanwai/templeyard.c",
"/u/guanwai/templeyard2.c",
"/u/guanwai/templeyard3.c",
"/u/guanwai/topoftower.c",
"/u/guanwai/wallhole.c",
"/u/guanwai/woodhouse.c",
"/d/fy/afa.c",
"/d/fy/ansheng.c",
"/d/fy/baozipu.c",
"/d/fy/bupu.c",
"/d/fy/cheaph.c",
"/d/fy/chjian.c",
"/d/fy/egate.c",
"/d/fy/examp.c",
   });

string *fych = ({//���ﶨ��Ŀ��ܲ�����
"/d/fy/afa.c",
"/d/fy/ansheng.c",
"/d/fy/baozipu.c",
"/d/fy/bupu.c",
"/d/fy/cheaph.c",
"/d/fy/chjian.c",
"/d/fy/egate.c",
"/d/fy/examp.c",
"/d/fy/fqkhotel.c",
"/d/fy/futhur.c",
"/d/fy/fyge.c",
"/d/fy/fysecret.c",
"/d/fy/fysf.c",
"/d/fy/fyyage.c",
"/d/fy/gcang.c",
"/d/fy/ginhall.c",
"/d/fy/gke1.c",
"/d/fy/gke2.c",
"/d/fy/gke3.c",
"/d/fy/gkitchen.c",
"/d/fy/gmoney.c",
"/d/fy/goldlion.c",
"/d/fy/govern.c",
"/d/fy/hall.c",
"/d/fy/hfeng.c",
"/d/fy/hfenglang1.c",
"/d/fy/hiretem.c",
"/d/fy/jbang.c",
"/d/fy/jhuang.c",
"/d/fy/jhuang1.c",
"/d/fy/jijian.c",
"/d/fy/jinqian.c",
"/d/fy/jlong.c",
"/d/fy/jlonglang1.c",
"/d/fy/jsecret.c",
"/d/fy/jssju.c",
"/d/fy/jting.c",
"/d/fy/mailst.c",
"/d/fy/mianhua.c",
"/d/fy/nanbank.c",
"/d/fy/ngate.c",
"/d/fy/poemp.c",
"/d/fy/ponder.c",
"/d/fy/pusheng.c",
"/d/fy/pxhdian.c",
"/d/fy/qcyzdian.c",
"/d/fy/qianyin.c",
"/d/fy/road0.c",
"/d/fy/secret_room.c",
"/d/fy/sgate.c",
"/d/fy/shufang.c",
"/d/fy/sroad1.c",
"/d/fy/sroad2.c",
"/d/fy/stopwin.c",
"/d/fy/tang2.c",
"/d/fy/tang3.c",
"/d/fy/tuji.c",
"/d/fy/wgate.c",
"/d/fy/yangsheng.c",
"/d/fy/yitea2.c",
"/d/fy/yuljade.c",
"/d/fy/zuisheng.c",
"/d/qianjin/corror1.c",
"/d/qianjin/corror2.c",
"/d/qianjin/corror3.c",
"/d/qianjin/eting.c",
"/d/qianjin/garden.c",
"/d/qianjin/garden1.c",
"/d/qianjin/garden2.c",
   });

string *qianjin = ({//���ﶨ��Ŀ��ܲ�����
"/d/qianjin/bamboo_bridge1.c",
"/d/qianjin/bamboo_bridge2.c",
"/d/qianjin/bamboo_bridge3.c",
"/d/qianjin/boat.c",
"/d/qianjin/boat1.c",
"/d/qianjin/boat2.c",
"/d/qianjin/boat3.c",
"/d/qianjin/bridge.c",
"/d/qianjin/bridge1.c",
"/d/qianjin/bridge2.c",
"/d/qianjin/cao.c",
"/d/qianjin/corror.c",
"/d/qianjin/corror1.c",
"/d/qianjin/corror2.c",
"/d/qianjin/corror3.c",
"/d/qianjin/eting.c",
"/d/qianjin/garden.c",
"/d/qianjin/garden1.c",
"/d/qianjin/garden2.c",
"/d/qianjin/grassroom.c",
"/d/qianjin/hehuadang.c",
"/d/qianjin/hehuadang1.c",
"/d/qianjin/hehuadang2.c",
"/d/qianjin/hotel1.c",
"/d/qianjin/hotel2.c",
"/d/qianjin/hua.c",
"/d/qianjin/jinge.c",
"/d/qianjin/jiu.c",
"/d/qianjin/lastbridge.c",
"/d/qianjin/liu.c",
"/d/qianjin/nu.c",
"/d/qianjin/pingfeng.c",
"/d/qianjin/secfloor.c",
"/d/qianjin/secret_room.c",
"/d/qianjin/shui.c",
"/d/qianjin/sr1.c",
"/d/qianjin/sr2.c",
"/d/qianjin/sr3.c",
"/d/qianjin/stairs.c",
"/d/qianjin/stairs2.c",
"/d/qianjin/taban.c",
"/d/qianjin/tading.c",
"/d/qianjin/troom.c",
"/d/qianjin/wting.c",
"/d/qianjin/xue.c",
"/d/qianjin/yue.c",
"/d/qingping/bridge.c",
"/d/qingping/garden.c",
"/d/qingping/gate.c",
"/d/qingping/kitchen.c",
"/d/qingping/liutree.c",
"/d/qingping/midtree.c",
"/d/qingping/neiyuan.c",
   });

string *qingping = ({//���ﶨ��Ŀ��ܲ�����
"/d/qingping/aroad.c",
"/d/qingping/backdoor.c",
"/d/qingping/bedroom1.c",
"/d/qingping/bedroom2.c",
"/d/qingping/bedroom3.c",
"/d/qingping/bridge.c",
"/d/qingping/garden.c",
"/d/qingping/gate.c",
"/d/qingping/kitchen.c",
"/d/qingping/liutree.c",
"/d/qingping/midtree.c",
"/d/qingping/neiyuan.c",
"/d/qingping/northpond.c",
"/d/qingping/northting.c",
"/d/qingping/pond.c",
"/d/qingping/pond1.c",
"/d/qingping/road.c",
"/d/qingping/road2.c",
"/d/qingping/southpond.c",
"/d/qingping/southpond1.c",
"/d/qingping/southting.c",
"/d/qingping/studyroom.c",
"/d/qingping/ting.c",
"/d/qingping/treetop.c",
"/d/qingping/underwater.c",
"/d/qingping/wall.c",
"/d/qingping/wuchang1.c",
"/d/qingping/wuchang2.c",
"/d/qingping/wuchang3.c",
"/d/qingping/xting.c",
"/d/daimiao/peiqing1.c",
"/d/daimiao/peiqing2.c",
"/d/daimiao/peitian.c",
"/d/daimiao/renan.c",
   });

string *daimiao = ({//���ﶨ��Ŀ��ܲ�����
"/d/daimiao/chuxun.c",
"/d/daimiao/daimiao.c",
"/d/daimiao/dongbei.c",
"/d/daimiao/dongyu.c",
"/d/daimiao/hanbai.c",
"/d/daimiao/houqing.c",
"/d/daimiao/houzai.c",
"/d/daimiao/jiaolou1.c",
"/d/daimiao/jiaolou2.c",
"/d/daimiao/jiaolou3.c",
"/d/daimiao/jiaolou4.c",
"/d/daimiao/peiqing1.c",
"/d/daimiao/peiqing2.c",
"/d/daimiao/peitian.c",
"/d/daimiao/renan.c",
"/d/daimiao/tiankuang.c",
"/d/daimiao/tongting.c",
"/d/daimiao/xibei.c",
"/d/daimiao/yaocan.c",
"/d/daimiao/yuhua.c",
"/d/daimiao/zhengyan.c",
"/d/daimiao/zhengyuan.c",
   });

string *palace = ({//���ﶨ��Ŀ��ܲ�����
"/u/palace/bamboo.c",
"/u/palace/bamboo2.c",
"/u/palace/bamboo3.c",
"/u/palace/bao.c",
"/u/palace/black.c",
"/u/palace/black2.c",
"/u/palace/bladem.c",
"/u/palace/bookhouse.c",
"/u/palace/bottom.c",
"/u/palace/bottom1.c",
"/u/palace/bottom2.c",
"/u/palace/bottom3.c",
"/u/palace/bridge.c",
"/u/palace/cliff.c",
"/u/palace/datang.c",
"/u/palace/dating.c",
"/u/palace/entrance.c",
"/u/palace/firehole.c",
"/u/palace/garden.c",
"/u/palace/garden1.c",
"/u/palace/garden2.c",
"/u/palace/garden3.c",
"/u/palace/gate.c",
"/u/palace/ghost.c",
"/u/palace/grass.c",
"/u/palace/holeopen.c",
"/u/palace/holeopen2.c",
"/u/palace/house.c",
"/u/palace/house2.c",
"/u/palace/huding.c",
"/u/palace/interroad.c",
"/u/palace/intersection.c",
"/u/palace/jinghouse.c",
"/u/palace/juhua.c",
"/u/palace/keng.c",
"/u/palace/kengdi.c",
"/u/palace/lighthole.c",
"/u/palace/lighthole1.c",
"/u/palace/lighthole2.c",
"/u/palace/lighthole3.c",
"/u/palace/lighthole4.c",
"/u/palace/lighthole5.c",
"/u/palace/lighthole6.c",
"/u/palace/naibridge.c",
"/u/palace/palace_front.c",
"/u/palace/palace_gate.c",
"/u/palace/palace_palace.c",
"/u/palace/palace_path1.c",
"/u/palace/palace_path2.c",
"/u/palace/palace_path3.c",
"/u/palace/palace_path4.c",
"/u/palace/realhole.c",
"/u/palace/river.c",
"/u/palace/secretpath0.c",
"/u/palace/secretpath1.c",
"/u/palace/secretpath2.c",
"/u/palace/smalllake.c",
"/u/palace/sriver.c",
"/u/palace/stone.c",
"/u/palace/stonelin.c",
"/u/palace/tang.c",
"/u/palace/valley.c",
"/u/palace/white.c",
"/u/palace/whiterock.c",
"/u/palace/windhole.c",
"/u/palace/woods.c",
"/u/palace/yadi.c",
"/u/guanwai/citygate.c",
"/u/guanwai/dazhaotemple.c",
"/u/guanwai/grassland0.c",
"/u/guanwai/grassland1.c",
"/u/guanwai/grassland2.c",
   });


void create()
{
        set("short", "֪���鷿��¥");
        set("long", "
������֪���鷿��¥���������۷ְ�վ��������ѻȵ�������ÿڰڷ�
�Ż������͵�����ͭա���ִ��˸��������ϣ���ɫ������΢��ŭɫ������
��������׽���˷����������и���һ�ң�\n"HIR+"
               ��    ��    ��    ��\n\n"NOR
        );
        set("valid_startroom",1);
        set("no_steal", "1");
        set("no_magic", "1");
        set("no_fight", "1");
        set("exits", ([
"up": __DIR__"yage",
"down": __DIR__"shufang",
        ]));
       set("coor/x",-19);
       set("coor/y",-10);
       set("coor/z",10);

        set("objects", ([
                __DIR__"npc/bao2": 1,
                "/d/fy/npc/governor": 1,
                "/d/fy/npc/yayi": 4,
        ]));
        setup();
}

void init ()
{
        add_action("do_work","work");
        add_action("do_finish","finish");
}

int do_work (string arg)
{
        object ob,obj1;
        int kf_npc,kf_whatnpc,worked_num,lv;
        string kf_name,kf_name1,kf_where,titles;
        object me = this_player();
        string location = "";
                
        if ((int)me->query("kf_jiangli"))
                return notify_fail("����ƽ˵�����񲶴����Ѿ�����Բ���ˣ�\n");

             if (!objectp(present("lin zhongping", environment(me))))
                return notify_fail("��������Ц�����ִ����Ѿ������ˣ�Ҫ��������������������\n");
		if (me->query("level")<45)
				return notify_fail("����ƽҡ��ҡͷ�����������������ʤ�δ�����!\n");
		if (me->query("level")>75)
				return notify_fail("����ƽҡ��ҡͷ����������Ѿ����ʺ�����!\n");
        if (present("ling pai",me)||(int)me->query("kf_working"))
                return notify_fail("����ƽ��ɫһ����������ǰ�ս�����Ĳ�����ȥ���������������أ�\n");
        kf_npc = 1 + random(165);
        kf_whatnpc =1+random(6);
        me->set("kf_whatnpc",kf_whatnpc);
        ob = new(__DIR__"npc/obj/lingpai");        //50
        if(kf_whatnpc==1){obj1 = new(__DIR__"npc/tufei1");}
        if(kf_whatnpc==2){obj1 = new(__DIR__"npc/tufei2");}
        if(kf_whatnpc==3){obj1 = new(__DIR__"npc/tufei3");}
        if(kf_whatnpc==4){obj1 = new(__DIR__"npc/tufei4");}
        if(kf_whatnpc==5){obj1 = new(__DIR__"npc/tufei5");}
        if(kf_whatnpc==6){obj1 = new(__DIR__"npc/tufei6");}
//      kf_same(ob1,me);    
//      ob1->move(ob);
        ob ->move(me);
        me->set_temp("kf_npc",kf_npc);

        if(kf_npc<84)
        {
                kf_where = "���Ƴ���";
                location = fych[random(sizeof(fych))];
                }
        else if(kf_npc<107)
        {
                kf_where = "ǧ��¥����";
                location = qianjin[random(sizeof(qianjin))];
        }
        else if(kf_npc<125)
        {
                kf_where = "�����¸���";
                location = guanwai[random(sizeof(guanwai))];        
        }
        else if(kf_npc<141)
        {
                kf_where = "�����";
                location = daimiao[random(sizeof(daimiao))];
                }
        else if(kf_npc<152)
        {
                kf_where = "�����ȸ���";
                location = palace[random(sizeof(palace))];
                }
        else
        {
                kf_where = "��ƽɽׯ����";
                location = qingping[random(sizeof(qingping))];
        }

        if(kf_whatnpc==1)
        {
                obj1->set("title","ɱ������");
                obj1->set_name("������", ({ "mengmian dadao"}) );
                kf_name = "������";
                kf_name1 = "��·����,ɱ������";
        }
        else if(kf_whatnpc==2)
        { 
                obj1->set("title","̤ѩ�޺�");
                obj1->set_name("��Ӱ��͵", ({ "shen tou"}) );
                kf_name = "��Ӱ��͵"; 
                kf_name1 = "�Ĵ����Բ���";
        }
        else if(kf_whatnpc==3)
        { 
                obj1->set("title","���׼���");
                obj1->set_name("�����", ({ "pei fengxiao"}) );
                kf_name = "���������"; 
                kf_name1 = "����������Ů���޶���";
        }
        else if(kf_whatnpc==4)
        { 
                obj1->set("title","�Ĵ��");
                obj1->set_name("ħ��ϸ��", ({ "mojiao xizuo"}) );
                kf_name = "ħ��ϸ��"; 
                kf_name1 = "�Ĵ��";
        }
        else if(kf_whatnpc==5)
        { 
                obj1->set("title","�Ĵ���ҥ�ƻ�");
                obj1->set_name("���ڼ�ϸ", ({ "jian xi"}) );
                kf_name = "���ڼ�ϸ"; 
                kf_name1 = "�Ĵ���ҥ�ƻ�";
        }
        else if(kf_whatnpc==6)
        { 
                obj1->set("title","�����е�");
                obj1->set_name("������", ({ "shenmi ren"}) );
                kf_name = "������"; 
                kf_name1 = "��ɱ��͢����";
        }

        obj1->set_temp("owner/id",me->query("id"));
        obj1->set_temp("owner/name",me->query("name"));
         obj1->set("level",me->query("level")+10); 
		 lv = obj1->query("level");
		 obj1->set("str",6*lv);
		 obj1->set("cor",6*lv);
		 obj1->set("int",6*lv);
		 obj1->set("spi",6*lv);
		 obj1->set("cps",6*lv);
		 obj1->set("per",6*lv);
		 obj1->set("con",6*lv);
		 obj1->set("kar",6*lv);
		 obj1->set("agi",6*lv);
		 obj1->set("dur",6*lv);
		 obj1->set("fle",6*lv);
		 obj1->set("tol",6*lv);
		 obj1->set("max_kee",me->query("max_kee")*2);
		 obj1->set("eff_kee",obj1->query("max_kee"));
		 obj1->set("kee",obj1->query("max_kee"));
		 obj1->set("max_gin",me->query("max_gin")*2);
		 obj1->set("eff_gin",obj1->query("max_gin"));
		 obj1->set("gin",obj1->query("max_gin"));
		 obj1->set("max_sen",me->query("max_sen")*2);
		 obj1->set("eff_sen",obj1->query("max_sen"));
		 obj1->set("sen",obj1->query("max_sen"));

        obj1->add_temp("apply/armor",lv*10);
        obj1->add_temp("apply/iron-cloth", lv*10);

        me->set_temp("kf_whatnpc",kf_whatnpc);
        me->set_temp("kf_name",kf_name);
        me->set_temp("kf_where",kf_where);
        message_vision (HIY"����ƽһ�ľ���ľŭ�����ݲ����"+kf_name+"��"+kf_where+kf_name1+"��"+me->query("name")+"��ȥ�ư�����������\n"NOR,me);
                obj1->move(location);
                obj1->set("vendetta_mark","tufei");
                me->add("vendetta/tufei",1);
        me->set("kf_working",1);
		if (me->query("linjobauto")-time()>0)
				{
					write("��ʹ�õļ�ϸ���񵤷��ӹ�Ч��.\n");
					me->move(location);
				}
        return 1;
}
int do_finish (string arg)
{
        object ob,silk1,silk2,silk3,goldobj;
        string kf_where,kf_name;
        int kf_whatnpc,kf_exp,kf_qn,gold_num,reb,lv;
        object me = this_player();
        
        if (!objectp(present("lin zhongping", environment(me))))
                return notify_fail("��������Ц�����ִ����Ѿ������ˣ�Ҫ�뽻����������������\n");
        if (!me->query("kf_working"))
                return notify_fail("����ƽ��ɫһ����������ʲôʱ���ɹ�����°���\n");
        if (!(int)me->query_temp("kf_finish"))
                return notify_fail("����ƽ��ɫһ��������������Ĳ�ʹ����δ���ף��㻹����Ŀ�����ң�\n");

        ob= present("ling pai",me);
        if (objectp(ob))
        {
            tell_object(me, "�㹧�������Ľ������ơ�\n" NOR );
                destruct(ob);
        }
        else
        {
                return notify_fail("����ƽ��ɫһ������������������ƶ��Ҷ�ʧ������ʲô�񲶣�\n");
        }        

        kf_whatnpc = me->query_temp("kf_whatnpc");
        kf_name = me->query_temp("kf_name");
        kf_where = me->query_temp("kf_where");
        if(!kf_whatnpc || !kf_name || !kf_where || kf_whatnpc > 6)
        {
                return notify_fail("����ƽ��ɫһ����������ʲôʱ���ɹ�����°���\n");
        }
        
        message_vision (WHT"����ƽ΢΢һЦ����"+me->query("name")+WHT"��"+kf_where+WHT"�ƻ�"+kf_name+WHT"һ�����Ϳ๦�ߣ��Ͽ���ȥ��Ϣ�ɣ�\n"NOR,me);
        reb=me->query("reborned"); // updated by Tiandi 200712031228
        kf_exp = kf_whatnpc*1000+random(2000);
        kf_exp = kf_exp + kf_exp/5*reb;
        kf_qn = kf_whatnpc*300+random(500);
        kf_qn = kf_qn + kf_qn/5*reb;
        gold_num = kf_whatnpc + 10;
        gold_num = gold_num + gold_num/5*reb;
        me->add("combat_exp",kf_exp);
        me->add("potential",kf_qn);
        me->add("kf_worked",1);
        me->set("kf_working",0);
        me->delete_temp("kf_finish");

            goldobj=new("/obj/money/gold");
            goldobj->set_amount(gold_num);
            goldobj->move(me);

        message_vision(HIW "$N�������ˣ�\n"
                + chinese_number(kf_exp) + "��ʵս���飬\n"
                + chinese_number(kf_qn) + "��Ǳ�ܣ�\n"
               + chinese_number(gold_num) + "���ƽ�\n" NOR, me);

        if (me->query("kf_worked")==1800)
        {
                me->set("kainame",9);
                me->add("score",2000);
                message_vision(HIC "$N����������ˣ�\n" NOR,me);
                tell_object(me, "�����ڵ�������" + chinese_number((string)(me->query("score")))+"��\n"NOR);
                if(!me->query("kf_jiangli"))
                {
                        message_vision (WHT"����ƽ΢Ц��˵����"+me->query("name")+"���ƴ󰸣����������������Ѿ��������ϡ�\n���ճ�ּ���£��ش˼ν����ɣ�\n"NOR,me);
                        me->set("kf_jiangli",1);
                        tell_object(me, "����ƽ�����������ң�\n");
                                        silk1 = new("/questobj/big");
                                        silk1->move(me);
                                        silk2 = new("/questobj/big");
                                        silk2->move(me);
                                        silk3 = new("/questobj/big");
                                        silk3->move(me);
                                }
        }    
        else if (me->query("kf_worked")==1300)
        {
                me->set("kainame",8);
                me->add("score",1500);
                message_vision(HIC "$N����������ˣ�\n" NOR,me);
                tell_object(me, "�����ڵ�������" + chinese_number((string)(me->query("score")))+"��\n"NOR);
        }       
        else if (me->query("kf_worked")==800)
        {
                me->set("kainame",7);
                me->add("score",1000);
                message_vision(HIC "$N����������ˣ�\n" NOR,me);
                tell_object(me, "�����ڵ�������" + chinese_number((string)(me->query("score")))+"��\n"NOR);
        }
        else if (me->query("kf_worked")==400)
        {
                me->set("kainame",6);
                me->add("score",800);
                message_vision(HIC "$N����������ˣ�\n" NOR,me);
                tell_object(me, "�����ڵ�������" + chinese_number((string)(me->query("score")))+"��\n"NOR);
        }
        else if (me->query("kf_worked")==200)
        {
                me->set("kainame",5);
                me->add("score",400);
                message_vision(HIC "$N����������ˣ�\n" NOR,me);
                tell_object(me, "�����ڵ�������" + chinese_number((string)(me->query("score")))+"��\n"NOR);
        }
        else if (me->query("kf_worked")==100)
        {
                me->set("kainame",4);
                me->add("score",200);
                message_vision(HIC "$N����������ˣ�\n" NOR,me);
                tell_object(me, "�����ڵ�������" + chinese_number((string)(me->query("score")))+"��\n"NOR);
        }
        else if (me->query("kf_worked")==50)
        {
                me->set("kainame",3);
                me->add("score",100);
                message_vision(HIC "$N����������ˣ�\n" NOR,me);
                tell_object(me, "�����ڵ�������" + chinese_number((string)(me->query("score")))+"��\n"NOR);
        }
        else if (me->query("kf_worked")==20)
        {
                me->set("kainame",2);
                me->add("score",50);
                message_vision(HIC "$N����������ˣ�\n" NOR,me);
                tell_object(me, "�����ڵ�������" + chinese_number((string)(me->query("score")))+"��\n"NOR);
        }
        me->save();
        return 1;
}
int valid_leave (object who, string dir)
{
        if(who->query_condition("kf_stop")<1)
        {
                return ::valid_leave(who, dir);
        }
        else
        {
                message_vision ("$N���������������ܡ�\n",who);
                return notify_fail(WHT"�����������㰴�ڵ��Ϻȵ�����ʵ�㣡\n"NOR);
        }
}


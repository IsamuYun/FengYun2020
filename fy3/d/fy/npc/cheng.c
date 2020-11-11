// Room: /city/ymdongting.c
// YZC 1995/12/04 
// cheng.c ��ҩ��
#include <ansi.h>
inherit NPC;

int ask_job();
int ask_fail();
string *yz_east = ({//���ﶨ��ǿ���Ŀ��ܲ�����
        "/d/taishan/yidao1",
        "/d/quanzhou/qzroad1",
        "/d/quanzhou/qzroad4",
        "/d/fuzhou/fzroad1",
        "/d/fuzhou/kedian",
        "/d/fuzhou/wuyishan3",
        "/d/taishan/taishanjiao",
        "/d/huanghe/huanghe4",
        "/d/huanghe/huanghe_1",
        "/d/huanghe/jingyuan",
        "/d/huanghe/wufosi",
        "/d/huanghe/xueguan",
        });

string *yz_south = ({//���ﶨ��ǿ���Ŀ��ܲ�����
        "/d/wudang/wdroad4",
        "/d/fuzhou/fzroad6",
        "/d/henshan/hsroad1",
        "/d/wudang/wdroad5",
        "/d/wudang/house",
        "/d/wudang/sanbuguan",
        "/d/emei/qsjie1",
        "/d/emei/caopeng",
        "/d/emei/cangjinglou",
        "/d/xiaoyao/muwu3",
        "/d/xiaoyao/muwu2",
        "/d/xiaoyao/shulin2",
        });

string *yz_north = ({//���ﶨ��ǿ���Ŀ��ܲ�����
        "/d/shaolin/hanshui1",
        "/d/shaolin/jiulou2",
        "/d/shaolin/shijie1",
        "/d/shaolin/shijie5",
        "/d/city2/haigang",
        "/d/city2/xiaotan",
        "/d/city2/road2",
        "/d/city2/yihongyu",
        "/d/city2/zhuang4",
        "/d/city2/zhuang9",
        });

string *yz_west = ({//���ﶨ��ǿ���Ŀ��ܲ�����
        "/d/xiangyang/northgate2",
        "/d/xiangyang/hutong2",
        "/d/xiangyang/westjie3",
        "/d/xiangyang/wallw8",
        "/d/xiangyang/shudian",
        "/d/xiangyang/walle7",
        "/d/xiangyang/minju2",
        "/d/city4/road4",
        "/d/city4/clubup",
        "/d/mingjiao/westroad1",
        "/d/mingjiao/westroad2",
        "/d/mingjiao/shanjiao",
        "/d/mingjiao/huangtulu2",
        "/d/mingjiao/mjtianmen",
        });

void create()
{
        set_name("��ҩ��", ({ "cheng yaofa", "cheng" }));
        set("title", "֪��");
        set("gender", "����");
        set("age", 43);
        set("str", 20);
        set("dex", 20);
        set("long", "�����ǳ�ҩ��������֪����\n");
        set("combat_exp", 3000000);
        set("SEN", 0);
        set("attitude", "heroism");

        set_skill("unarmed", 50);
        set_skill("force", 50);
        set_skill("sword", 50);
        set_skill("dodge", 50);
        set_skill("parry", 50);

        set("force", 500); 
        set("max_force", 500);
        set("inquiry", ([
                "job" : (:ask_job():),
                "����" : (: ask_job() :),
                "ʧ��" : (: ask_fail() :),
          ])),

        set("env/important", 1);    

        setup();
        carry_object("/clone/misc/cloth")->wear();
}

int ask_job()
{

        object me = this_player(), ob;
        mapping skl; 
        string *sname, place;
        int i, skill = 0;

        skl = me->query_skills();

        if (me->query("combat_exp") < 100000){
                command("say " + RANK_D->query_respect(me) + "��ı��»�û�е�����,���´�ȥ·;�ն�,�㻹����ʤ�Σ�\n");
                return 1;
        }

        if ( !skl ) {
                tell_object(me, "��ȥѧһЩ�����Ȱɣ�\n");
                return 1;
                }
        sname  = sort_array( keys(skl), (: strcmp :) );
        for(i=0; i<sizeof(skl); i++) 
                if (skl[sname[i]] >= skill && sname[i] != "literate" && sname[i] != "taoism")
                        skill = skl[sname[i]];
                        
        if (skill < 80) skill = 80;
       
        if (me->query("combat_exp") > 3000000) {
                command("say " + RANK_D->query_respect(me) + "���ǹ�֮��������СС������������ܣ�");
                return 1;
        }
        if (me->query("kill_qiangdao") == 1) {
                command("kick " + me->query("id"));
                command("say �Ҳ��Ǹ�������������");
                return 1;
                }
        else {
                command("nod" + me->query("id"));
                command("say " + RANK_D->query_respect(me) + "��Ϊ��ɽ������룬����̫���ˡ�");
                me->set("kill_qiangdao", 1);
                me->set("quest/quest_type", "ɱ");
                me->set("quest/quest", "ǿ��");
                me->set("task_time", time() + 300);
                switch(random(3)) {
                case 0 :
                        ob = new("/u/chen/npc/qiangdao");
                        ob->set("long", "����������ͽ��ר�����Ӫ��������һ�����⣬����������η��\n"
                        "����" + me->query("name") + "(" + me->query("id") + ")" + "��Ŀ�ꡣ\n");
                        ob->set_skill("jiuyang-shengong", skill);
                        ob->set_skill("lingxu-bu", skill);
                        ob->set_skill("sanhua-zhang", skill);
                        ob->set_skill("jinwu-daofa", skill);
                        ob->map_skill("force", "jiuyang-shengong");
                   
                        ob->map_skill("dodge", "lingxu-bu");
                        ob->map_skill("parry", "jinwu-daofa");
                        ob->map_skill("blade","jinwu-daofa");
                        ob->prepare_skill("strike", "sanhua-zhang");
                        ob->set("chat_chance_combat", 100);
                        break;

                default : 
                        ob = new("/u/chen/npc/qiangdao");                   
                        ob->set("long", "�������޵��ӣ�������ɽ��٣������°��Ϲ��ż��ź��룬һ����֪�����Ǹ�аħ���֮����\n"
                        "����" + me->query("name") + "(" + me->query("id") + ")" + "��Ŀ�ꡣ\n");
                        ob->set_skill("zhaixinggong", random(skill));
                        ob->set_skill("huagong-dafa", random(skill));

                        ob->set_skill("unarmed", random(skill));
                        ob->map_skill("force", "huagong-dafa");
                        ob->map_skill("dodge", "zhaixinggong");
                
                        ob->map_skill("parry", "chousui-zhang");
                        ob->map_skill("unarmed","chousui-zhang");
                        ob->prepare_skill("strike", "chousui-zhang");
                        ob->set("chat_chance_combat", 100);
                        break;
                  }

                                 
                switch(random(4)) {
                        case 0 :
                                place = yz_east[random(sizeof(yz_east))];
                                ob->move(place);
                                me->set("quest/place", place);
                                command("tell " + me->query("id") + " ��һ��ǿ�������ݳǶ�Ϊ����������ȥ��������");                           
                                break;
                        case 1 :
                                place = yz_south[random(sizeof(yz_south))];
                                ob->move(place);
                                me->set("quest/place", place);
                                command("tell " + me->query("id") + " ��һ��ǿ�������ݳ���Ϊ����������ȥ��������");                           
                                break;
                        case 2 :
                                place = yz_north[random(sizeof(yz_north))];
                                ob->move(place);
                                me->set("quest/place", place);
                                command("tell " + me->query("id") + " ��һ��ǿ�������ݳǱ�Ϊ����������ȥ��������");                           
                                break;
                        default :
                                place = yz_west[random(sizeof(yz_west))];
                                ob->move(place);

                                me->set("quest/place", place);
                                command("tell " + me->query("id") + " ��һ��ǿ�������ݳ���Ϊ����������ȥ��������");                           
                }               
                ob->set_temp("owner/id",me->query("id"));
                ob->set("combat_exp", me->query("combat_exp"));
                ob->set("max_force", me->query("max_force"));
                ob->set("eff_kee", me->query("max_kee") * 2);
                ob->set("max_kee", me->query("max_kee") * 2);
                ob->set("kee", me->query("max_kee") * 2);
                ob->set_skill("dodge", skill);
                ob->set_skill("force", skill);
                ob->set_skill("parry", skill);

                ob->set("force_factor", random(10));   
                return 1;
                }
        return 1;
}

int ask_fail()
{
        object me = this_player();
        
        if (me->query("kill_qiangdao") == 1) {
                command("haha");
                command("say ��������Ҳ�����ͼ���񣬶����Ϸ򵱳��������ˡ�");
                command("chat " + me->query("name") + "�����Դ���ʹǿ��Σ��һ������������������ʮ��������⣡");
                me->move("/d/city/yamen");
                me->add("kee",-300);
                call_out("delete", 300);
                return 1;
                }
        else return 0;
}

int delete()
{
        this_player()->delete("kill_qiangdao");
        return 1;
}

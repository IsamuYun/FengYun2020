#include <ansi.h>
inherit NPC;
inherit F_MASTER;
int ask_job();
int ask_fail();
int ask_me();
string *yz_west = ({//���ﶨ��Ŀ��ܲ�����
        "/u/guanwai/octostreet",
        "/u/resort/smallroad4",
        "/u/ghost/lroad3",
        "/u/quicksand/mroad2",
        "/u/guanwai/octo7",
        "/u/resort/front_yard",
        "/u/quicksand/sandroad",
            "/u/resort/front_yard",
              "/u/resort/bookhouse",
              "/d/shaolin/tianwang",
              "/d/shaolin/qianfe",
              "/d/shaolin/cj",
              "/u/yihua/houyuan",
   });

string *yz_south = ({//���ﶨ��Ŀ��ܲ�����
        "/d/fy/sroad1",
        "/d/manglin/groupn2",
        "/d/fy/sroad2",
        "/d/wanmei/playground",
        "/d/dali/sroad2",
        "/d/qianjin/corror1",
        "/d/dali/quan1",
        "/d/wanmei/cleft",
        "/d/wanmei/right",
              "/d/wudujiao/dt",
              "/d/wudujiao/mroom",
             "/d/manglin/groups2",
        "/d/qianjin/secfloor",
        "/d/wanmei/backyard",
        });

string *yz_north = ({//���ﶨ��Ŀ��ܲ�����
        "/d/tieflag/road",
        "/d/laowu/town1",
        "/d/laowu/street",
        "/d/laowu/street3",
        "/u/taoguan/road1",
        "/u/taoguan/lake1",
        "/u/taoguan/kitchen",
        "/d/qianfo/fangsheng",
        "/d/qianfo/changlang",
        "/d/qianfo/fudi",
              "/d/baihuagu/mroom",
              "/d/shenshui/gong",
        });

string *yz_east = ({//���ﶨ����ܲ�����
        "/u/wudang/road1",
        "/d/tieflag/troad1",
        "/d/bat/shushi",
        "/d/tieflag/troad3",
        "/u/palace/intersection",
        "/u/palace/smalllake",
        "/u/palace/interroad",
        "/u/palace/keng",
        "/u/palace/garden3",
        "/u/palace/house2",
        "/u/palace/gate",
        "/u/palace/tang",
        "/u/chuenyu/dustyroad0",
        "/u/chuenyu/dustyroad2",
        "/u/chuenyu/smallyard",
       "/d/wanmei/rightcave",
 });
void create()
{
        set_name("������", ({ "master yin", "master","yin" }) );
        set("long",
                "���Ƴ�����ߵĹ٣����������ϵ�Ȩ��\n");
	set("nickname", RED"һƷ�ղ�"NOR);
        set("attitude", "heroism");
	set("student_title","��Ա");
	create_family("��͢",6,"��Ա");
	set("vendetta_mark", "authority");
        set("str", 27);
        set("cor", 26);
        set("cps", 25);
	set("agi",25);
	set("int",30);
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: perform_action, "unarmed.yuhuan" :),
        }) );
         set("inquiry", ([
                "job" : (:ask_job():),
                "����" :  "\n�κ���ֻҪ����(join chaoting)���Ϳ���Ϊ��͢������\n",
                "work" :  "\n�κ���ֻҪ����(join chaoting)���Ϳ���Ϊ��͢������\n",
                "����" : (: ask_job() :),
                "ʧ��" : (: ask_fail() :),
                   ]));
    set("combat_exp", 90000000);
	set_temp("apply/damage",500);
        set_skill("unarmed", 200);
        set_skill("sword",120);
        set_skill("force",100);
        set_skill("parry", 120);
        set_skill("dodge", 110);
	set_skill("changquan",200);
        set_skill("feixian-steps",80);
        set_skill("feixian-sword",100);
        set_skill("jingyiforce",80);
        set_skill("move", 100);
        set_skill("literate",150);
	set_skill("leadership",200);
	set_skill("strategy",200);
	map_skill("unarmed","changquan");
	map_skill("dodge","feixian-steps");
	map_skill("force","jingyiforce");
	map_skill("sword","feixian-sword");
        setup();

        carry_object(__DIR__"obj/guanfu")->wear();
}

void attempt_apprentice(object me)
{
	if( !me->query("class"))
	{
	command("smile");
	command("say �ܺã���͢��������֮ʱ��Ŭ���ɣ�\n");
        command("recruit " + me->query("id") );
	}
	else
	command("say ��͢����Ҫ�����ֲ������ģ���������֮�ˣ�\n");
}

void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "official");
		ob->set("vendetta_mark", "authority");

}
void re_rank(object student)
{
        int exp;
        exp = (int) student->query("combat_exp");
        if( exp <= 32000 ) {
                student->set("title","��͢��Ʒ֥���");
                return ;
        } else if ( exp <= 64000 ) {
                student->set("title","��͢��Ʒ��");
                return ;
        } else if ( exp <= 128000 ) {
                student->set("title","��͢��Ʒ��");
                return ;
        } else if ( exp <= 256000 ) {
                student->set("title","��͢��Ʒ��");
                return ;
        } else if ( exp <= 512000 ) {
                student->set("title","��͢��Ʒ��");
                return ;
        } else if ( exp <= 1024000 ) {
                student->set("title","��͢��Ʒ��");
                return ;
        } else if ( exp <= 1536000 ) {
                student->set("title","��͢һƷ��");
                return ;
        } else if ( exp <= 2304000 ) {
                student->set("title","��͢�ղ��");
                return ;
        } else if ( exp <= 3456000 ) {
                student->set("title","��͢����ͳ��");
                return ;
        } else if ( exp <= 5187000 ) {
                student->set("title","��͢������ͳ��");
                return ;
        } else if ( exp <= 26244000 ) {
                student->set("title","��Զ����");
                return ;
        } else
                student->set("title","�����󽫾�");
                return ;

}
int ask_job()
{

        object me = this_player(), ob;
        mapping skl; 
        string *sname, place;
        int i, skill = 0;

        skl = me->query_skills();

                if(this_player()->query("killhyr") > 6000)
                {
                        command("say ��Ϊ��͢���Ĺ����Ѿ��ǳ������ˣ�ȥ������������ս�Ե�����ɣ�");
                        return 1;       
                }
  
        if (me->query("gongxian") > 35000 && me->query("class") == "dali"){
                command("say " + RANK_D->query_respect(me) + "���Ѿ���Ϊ��ү�����ٲ��Ҳ�ǲ��\n");
                return 1;
        }
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
                        
        if (skill < 50) skill = 50;
        if (skill > 100) skill = 100;
       
        if (me->query("combat_exp") > 5000000) {
                command("say " + RANK_D->query_respect(me) + "���ǹ�֮���������������ܣ�");
                return 1;
        }
        if (me->query("kill_qiangdao") == 1) {
                command("kick " + me->query("id"));
                command("say �Ҳ��Ǹ�������������");
                return 1;
                }
        else {
                command("nod" + me->query("id"));
                command("say " + RANK_D->query_respect(me) + "������Ϊ��͢��������̫���ˡ�");
                me->set("kill_qiangdao", 1);
                me->set("quest/quest_type", "ɱ");
                me->set("quest/quest", "ǿ��");
                me->set("task_time", time() + 300);
                switch(random(3)) {
                case 0 :
                        ob = new("/d/xgchen/npc/qiangdao");
                        ob->set("long", "���Ǳ���͢������С�٣�����ר������Ӫ��������һ�����⣬����������η��\n"
                        "����" + me->query("name") + "(" + me->query("id") + ")" + "��Ŀ�ꡣ\n");
                        ob->set_skill("jingyiforce", skill);
                        ob->set_skill("feixian-steps", skill);
                                             ob->set_skill("move", skill);
                       ob->set_skill("parry", skill);
			     ob->set_skill("dodge", skill);
                                              ob->set("chat_chance_combat", 10);
                                     break;

                default : 
                        ob = new("/d/xgchen/npc/qiangdao");                   
                        ob->set("long", "�������ڵ��ӣ������°��Ϲ��ż��ź��룬һ����֪�����Ǹ�аħ���֮����\n"
                        "����" + me->query("name") + "(" + me->query("id") + ")" + "��Ŀ�ꡣ\n");
                        ob->set_skill("jingyiforce", skill);
                        ob->set_skill("feixian-steps", skill);
                                            ob->set_skill("move", skill);
                    	    ob->set_skill("parry", skill);
                                          ob->set_skill("sword", skill);

                                     ob->set("chat_chance_combat", 10);
                         break;

                  }

                                 
                switch(random(4)) {
                        case 0 :
                                place = yz_east[random(sizeof(yz_east))];
                                ob->move(place);
                                me->set("quest/place", place);
                                command("whisper " + me->query("id") + " һ�����������͵�˱��ٵ����ͣ�\n����ƳǶ���������,��ȥ����ɱ����");                           
                                break;
                        case 1 :
                                place = yz_south[random(sizeof(yz_south))];
                                ob->move(place);
                                me->set("quest/place", place);
                                command("whisper " + me->query("id") + " һ�����������͵�˱��ٵĹ�ӡ��\n����Ƴ��ϱ�������,��ȥ����ɱ����");                           
                                break;
                        case 2 :
                                place = yz_north[random(sizeof(yz_north))];
                                ob->move(place);
                                me->set("quest/place", place);
                                command("whisper " + me->query("id") + " һ�����������͵�˱��ٵ����ƣ�\n����ƳǱ���������,��ȥ����ɱ����");                           
                                break;
                        default :
                                place = yz_west[random(sizeof(yz_west))];
                                ob->move(place);

                                me->set("quest/place", place);
                                command("whisper " + me->query("id") + " һ�����������͵�˱��ٵİ���\n����Ƴ�����������,��ȥ����ɱ����");                           
                }               
                ob->set_temp("owner/id",me->query("id"));
                ob->set("combat_exp", me->query("combat_exp"));
                ob->set("eff_kee", me->query("max_kee") * 8);
                ob->set("max_kee", me->query("max_kee") * 8);
                ob->set("kee", me->query("max_kee") * 8);
                ob->set("eff_gin", me->query("max_gin") * 8);
                ob->set("max_gin", me->query("max_gin") * 8);
                ob->set("gin", me->query("max_gin") * 8);
                            ob->set("eff_sen", me->query("max_sen") * 8);
                ob->set("max_kee", me->query("max_sen") * 8);
                ob->set("sen", me->query("sen") * 8);
                ob->set("force", me->query("force") * 2);
                            ob->set_skill("dodge", skill);
                ob->set_skill("force", skill);
                ob->set_skill("parry", skill);
                ob->set("force_factor", random(100));   
                return 1;
                }
        return 1;
}

int ask_fail()
{
        object me = this_player();
        if (me->query("kill_qiangdao") == 1) {
                command("heng");
                command("say ��������ô��,���ٵ����������ˡ�");
                command("qst " + me->query("name") + "�����Դ��������������ʮ��������⣡");
                me->move("/d/fy/wcloud2");
                me->add("kee",-300);
                call_out("delete", 1);
                return 1;
                }
        else return 0;
}

int delete()
{
        this_player()->delete("kill_qiangdao");
        return 1;
}
void init()
{       
        object ob; 
        mapping myfam; 
        ob = this_player();
        ::init();
        add_action("do_join", "join");

        if (interactive(ob = this_player()) &&                 (int)ob->query_condition("killer")) {
                remove_call_out("kill_ob");
                call_out("kill_ob", 1, ob);
        }
}
int do_join(string arg)
{
   object ob ;
   ob = this_player () ;
   if( !arg || arg!="chaoting" )
        return notify_fail("��Ҫ����ʲô��֯��\n"); 
   if(ob->query("kaifengfu")) 
        {
        message_vision(HIC "������˵�������Ѿ��ǲ����ˡ�\n" NOR,this_player());
        return 1;
        }
   if (ob->query("combat_exp")<500000)
        {

        message_vision(HIC "��������$Nҡͷ�������ʵս����̫�͡�\n" NOR,this_player());
        return 1;
        }
    ob->set("kaifengfu",1);
    ob->set("kainame",1);
    command("tell "+this_player()->query("id")+" ������������Ǹ�ʵϰ������.\n");
    ob->add("score",100);
    message_vision(HIC "$N����������ˣ�\n" NOR,ob);
    tell_object(ob, "�����ڵ�������" + chinese_number((string)(ob->query("score")))+"��\n"NOR);
    return 1;   
}


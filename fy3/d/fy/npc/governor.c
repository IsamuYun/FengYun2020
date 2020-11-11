#include <ansi.h>
inherit NPC;
inherit F_MASTER;
int ask_job();
int ask_fail();
int ask_money();
string *yz_west = ({//���ﶨ��Ŀ��ܲ�����
        "/u/guanwai/octostreet",
        "/u/resort/smallroad4",
        "/u/ghost/lroad3",
        "/u/quicksand/mroad2",
        "/u/guanwai/octo7",
        "/u/resort/front_yard",
        "/u/quicksand/sandroad",
			"/u/quicksand/desert4",
			"/u/quicksand/desert5",
			"/u/quicksand/desert3",
			"/u/quicksand/desert2",
            "/u/resort/front_yard",
              "/u/resort/bookhouse",
              "/d/shaolin/tianwang",
              "/d/shaolin/qianfe",
              "/d/shaolin/cj",
   });

string *yz_south = ({//���ﶨ��Ŀ��ܲ�����
        "/d/fy/sroad1",
        "/d/manglin/groupn2",
        "/d/fy/sroad2",
        "/d/wanmei/playground",
        "/d/qianjin/corror1",
        "/d/wanmei/cleft",
        "/d/wanmei/right",
             "/d/manglin/groups2",
        "/d/qianjin/secfloor",
        "/d/wanmei/backyard",
		"d/manglin/groupe2",
			"d/manglin/groupe3",
			"d/manglin/groupe4",
		 "/d/fy/pusheng",
        });

string *yz_north = ({//���ﶨ��Ŀ��ܲ�����
        "/d/tieflag/road",
		"/d/shenshui/midao3",
		"/d/shenshui/midao5",
        "/d/laowu/town1",
        "/d/laowu/street",
        "/d/laowu/street3",
        "/u/taoguan/road1",
        "/u/taoguan/lake1",
        "/u/taoguan/kitchen",
        "/d/qianfo/fangsheng",
        "/d/qianfo/changlang",
        "/d/qianfo/fudi",
              "/d/shenshui/gong",
        });

string *yz_east = ({//���ﶨ����ܲ�����
        "/u/wudang/road1",
        "/d/tieflag/troad1",
        "/d/bat/shushi",
        "/d/tieflag/troad3",
		"/d/tieflag/rock0",
		"/d/tieflag/cloudinn",
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
	set("class","official");
        set("attitude", "heroism");
	set("student_title","��Ա");
	create_family("��͢",6,"��Ա");
	set("vendetta_mark", "authority");
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: perform_action, "unarmed.yuhuan" :),
        }) );
         set("inquiry", ([
                "job" : (:ask_job():),
                "����" : (: ask_job() :),
                "ٺ»" : (: ask_money() :),
                "ʧ��" : (: ask_fail() :),
                   ]));
    set("combat_exp", 90000000);
	set("no_arrest",1);
	set_temp("apply/damage",500);
        set_skill("unarmed", 1000);
        set_skill("force",500);
        set_skill("parry", 500);
        set_skill("dodge", 500);
        set_skill("changquan",1000);
        set_skill("jingxinforce",1000);
        set_skill("move", 500);
       set_skill("danei-sword",1000);
       set_skill("liuyun-steps",1000);
       set_skill("sword",500);
            set_skill("literate",500);
	set_skill("leadership",1000);
	set_skill("strategy",1000);
	map_skill("unarmed","changquan");	
	map_skill("dodge","liuyun-steps");
	map_skill("force","jingxinforce");
	map_skill("sword","danei-sword");

        setup();

        carry_object(__DIR__"obj/guanfu")->wear();
}

void attempt_apprentice(object me)
{
	if( me->query("class"))
	{
	command("stare");
	command("say ���Ѿ����Լ��������ˣ�\n");
	}
	else if( me->query("national") == "����" )
	{
	command("smile");
	command("say �ܺã���͢��������֮ʱ��Ŭ���ɣ�\n");
            command("recruit " + me->query("id") );
	}
	else
	command("say ��ֻ͢�պ���֮�ˣ�\n");
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
        exp = (int) student->query("level");
        if( exp <= 10 ) {
                student->set("title","��͢��Ʒ֥���");
                return ;
        } else if ( exp <= 20 ) {
                student->set("title","��͢��Ʒ��");
                return ;
        } else if ( exp <= 29 ) {
                student->set("title","��͢��Ʒ��");
                return ;
        } else if ( exp <= 37 ) {
                student->set("title","��͢��Ʒ��");
                return ;
        } else if ( exp <= 44 ) {
                student->set("title","��͢��Ʒ��");
                return ;
        } else if ( exp <= 50 ) {
                student->set("title","��͢��Ʒ��");
                return ;
        } else if ( exp <= 55 ) {
                student->set("title","��͢һƷ��");
                return ;
        } else if ( exp <= 65 ) {
                student->set("title","��͢�ղ��");
                return ;
        } else if ( exp <= 75 ) {
                student->set("title","��͢����ͳ��");
                return ;
        } else if ( exp <= 80 ) {
                student->set("title","��͢������ͳ��");
                return ;
        } else if ( exp <= 95 ) {
                student->set("title","��Զ����");
                return ;
        } else
                student->set("title","�����󽫾�");
                return ;

}

int ask_money()
{
	mapping quest ;
	int lv;
	object me,money;
	me = this_player();
	lv = me->query("level");
	if(  me->query("class") !="official" )
	{
		command("say ֻ�г�͢��Ա�ſ�����ȡٺ»��\n");
		return 1;
	}
	if( ((int) me->query("lastctmoney")+60*10080) >  time() )
	{
		write("��ȡٺ»�ļ��ʱ�䲻���������졣\n");
		return 1;
	}
	if(  me->query("score") <  (lv*50) )
	{
		write("�������ڽ����е����ۻ�������\n");
		return 1;
	}
	me->add("score",- lv*10);
 	money = new("/obj/money/gold");
	money->set_amount(lv*10);
	money->move(me);
	me->set("lastctmoney",time());
	command("say ���ǳ�͢���ݽ�����������۶��������������ٺ»"+chinese_number(lv*10)+"���ƽ����ټ���Ϊ��͢����");
	return 1;
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
  
        if (me->query("level") < 20){
                command("say " + RANK_D->query_respect(me) + "��ı��»�û�е�����,���´�ȥ·;�ն�,�㻹����ʤ�Σ�\n");
                return 1;
        }
        if (me->query("level") > 50){
                command("say " + RANK_D->query_respect(me) + "���Ѿ����ʺ�������С�����ˣ�\n");
                return 1;
        }


        if ( !skl ) {
                tell_object(me, "��ȥѧһЩ�����Ȱɣ�\n");
                return 1;
                }

//by tiandi job NPC��SKILLΪ��ҵ�LEVEL��10��
 /*       sname  = sort_array( keys(skl), (: strcmp :) );
        for(i=0; i<sizeof(skl); i++) 
                if (skl[sname[i]] >= skill && sname[i] != "literate" && sname[i] != "taoism")
                        skill = skl[sname[i]];
                        
        if (skill < 50) skill = 50;
        if (skill > 100) skill = 100;
*/
 skill = me->query("level")*10;      
        if (me->query("level") > 50) {
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
                        ob = new("/job/npc/qiangdao");
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
                        ob = new("/job/npc/qiangdao");                   
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
                                command("whisper " + me->query("id") + " һ�����������͵�˱��ٵ����ͣ�\n����ƳǶ��ߵ�"+place->query("short")+"������,��ȥ����ɱ����");                           
                                break;
                        case 1 :
                                place = yz_south[random(sizeof(yz_south))];
                                ob->move(place);
                                me->set("quest/place", place);
                                command("whisper " + me->query("id") + " һ�����������͵�˱��ٵĹ�ӡ��\n����Ƴ��ϱߵ�"+place->query("short")+"������,��ȥ����ɱ����");                           
                                break;
                        case 2 :
                                place = yz_north[random(sizeof(yz_north))];
                                ob->move(place);
                                me->set("quest/place", place);
                                command("whisper " + me->query("id") + " һ�����������͵�˱��ٵ����ƣ�\n����ƳǱ��ߵ�"+place->query("short")+"������,��ȥ����ɱ����");                           
                                break;
                        default :
                                place = yz_west[random(sizeof(yz_west))];
                                ob->move(place);

                                me->set("quest/place", place);
                                command("whisper " + me->query("id") + " һ�����������͵�˱��ٵİ���\n����Ƴ����ߵ�"+place->query("short")+"������,��ȥ����ɱ����");                           
                }               
                ob->set_temp("owner/id",me->query("id"));
                ob->set("level", me->query("level"));
                ob->set("eff_kee", me->query("max_kee") *2);
                ob->set("max_kee", me->query("max_kee") *2);
                ob->set("kee", me->query("max_kee") *2);
                ob->set("eff_gin", me->query("max_gin") *2);
                ob->set("max_gin", me->query("max_gin") *2);
                ob->set("gin", me->query("max_gin") *2);
                ob->set("eff_sen", me->query("max_sen")*2 );
                ob->set("max_kee", me->query("max_sen") *2);
                ob->set("sen", me->query("sen") *2);
                ob->set("force", me->query("force") * 2);
                ob->set("force_factor", random(100));   
				if (me->query("heiyirenauto")-time()>0)
				{
					write("��ʹ�õĺ��������񵤷��ӹ�Ч��.\n");
					me->move(place);
				}
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
                me->delete("kill_qiangdao");
				me->start_busy(5);
				return 1;
                }
        else return 0;
}


inherit NPC;
#include <ansi.h>

string *npc = ({
"�Ϲ�ʮһ��",
"�Ϲ�ʮ����",
"�Ϲ�ʮ����",
"����",
"������",
"��һ��",
"Ҷ�³�",
"�Ϲٽ��",
"������",
"���˷�",
"���촸",
"���Ŵ�ѩ",
"������",
"������",
"�����",
"ԭ����",
"�����",
"������",
"������",
"ʯ����",
"����",
"̫����",
"������",
"���ӣ",
"����",
"����ü",
"��ʮһ��",
"�����",
"����Ϫ",
"��ң��",
"�˹���ʦ",
"�δ�",
"����",
"�ĺ�",
"��ˮ����",
"������",
"�����",
"����ѩ",
"���ڻ�̫",
"����",
"������",
"����",
"ѩ���",
"ʯ��",
   });

void create()
{
      set_name("����", ({ "meng", "cha meng" }) );
      set("title", HIY "��ʨ��" NOR);
      set("gender", "����" );
      set("age", 42);
      set("skill_public",1);
      create_family("�����׼�", 21, "����");

      set("long",
                "��ʨ�Ʋ����������׼ҵ��ӣ��˲��������ˬ���ҹ㽻���ѣ�
������������̵ģ�ֻҪΪ�ھֳ����������ͿϽ̣�\n"
                );
	set("inquiry", ([ "����" : "����ھ�����̫�࣬�������ֲ�������Ը��Э�����𣿣�quest��" 
	  ]));

       set("chat_chance", 1);
       set("chat_msg", ({
                "����˵����������ھ����ⲻ��\n",
        }) );        
        set("attitude", "peaceful");
        set_skill("unarmed", 60);
        set_skill("changquan", 50);
        set_skill("literate", 60);
        set_skill("force", 70);
        set_skill("dodge",60);
        set_skill("parry",50);
        map_skill("unarmed", "changquan");
        set("combat_exp", 190000);
        setup();
        carry_object(__DIR__"obj/jinzhuang")->wear();
}
void init()
{
        add_action("give_quest", "quest");
}

int give_quest(string arg)
{
	mapping quest ;
	object me,room,qiangdao;
	int j, combatexp, timep,gold ;
	string file,location,*roomlines;
	me = this_player();

	if((int) me->is_ghost())
	{
		write("��겻��Ҫ����\n");
		return 1;
	}
	if (me->query("level")<10)
	{
		write("���ڻ�����Ҫһ��ʵ���������ģ�Ŀǰ���ʵ���������ʸ�\n");
		return 1;
	}
//	if ((me->query("hubiaojob") - 100) > me->query("TASK"))
//	{
//		write("Ŀǰ��Ļ���������ɴ����Ѿ��ﵽ���ޡ�\n");
//		return 1;
//	}
	if( ((int) me->query("lasthbtime")+60*5) >  time() )
	{
		write("���λ�������ļ��ʱ�䲻����������ӡ�\n");
		return 1;
	}
	if( ! me->query("hubiao") )
	{
		combatexp = me->query("level");
		gold = combatexp;
		write("���͵��������һ��ڣ�̫���ˣ��������ܵð�Ѻ���˰ɡ�\n");
		write("���͵���������Ŀǰ�ĵȼ�������Ҫ����"+chinese_number(gold)+"���ƽ�\n");
		me->set_temp("yajinok",1);
		return 1;
	}
	if( me->query("hubiao") )
	{
		write("���͵����㵽���ڻ�û����ɻ����������Ѻ����û���ˣ�\n");
		me->delete("hubiao");
		me->delete("no_fly");
		return 1;
	}
	else
	{
		write("���͵���û�к��ʵ�����\n");
		return 1;
	}
}

int accept_object(object who, object ob)
{
	int val,gold,combatexp;
	object bag;
	val = ob->value();
	combatexp = who->query("level");
	gold = combatexp;

            if (val/10000 >= gold)
	{
		if (!who->query_temp("yajinok"))
		 {
			tell_object(who,"���͵�������Ե�޹ʸ��Ҷ�������\n");
			return 0;
		}
		else
		{
		who->delete_temp("yajinok");
		who->set("lasthbtime", (int) time());
		who->set("hubiao",npc[random(sizeof(npc))]);
		who->set("no_fly",1);
		who->apply_condition("biaojob",99);
       		tell_object(who,"����˵�������������͸���"+who->query("hubiao")+"���İ������鷳�������͹�ȥ��\n" NOR);
		bag = new("/obj/bag");
		bag->move(who);
		bag->set("long","һ���͸�"+who->query("hubiao")+"�İ�����Ū���˿�Ҫ�⳥�ġ�����ָ��NPC����finish <id>���������\n");
		return 1;
		}
	}
	else
	{
		tell_object(who,"���͵�����Щ��������Ѻ��ô��\n");
		return 0;
	}
}
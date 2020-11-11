inherit NPC;
#include <ansi.h>
void create()
{
        set_name(HIB"ŷ����" NOR, ({ "ouyangdang" }) );
        set("gender", "����");
        set("age", 46);
        set("long",
                "    �����ݹ���ᾡ�˫ȧ͹�����������ű��ʲ������Ŵ�磬������������
�ü�Ϊ����ĸ��̴�֣�ģ�����飬ȴ���Ǹմӵ����ӳ����Ķ����\n");
        set("attitude", "friendly");
  set("reward_npc", 1);
        set("difficulty", 80); 

        set("no_arrest",1);
        set("chat_chance", 1);
        set("chat_msg", ({
                "ŷ���������е��ʱ����Ļ���ֱ�죮������\n",
        }) );

        set("score", -50000);
        
        set_skill("move", 220);
       set_skill("dodge",220);
        set_skill("unarmed", 200);
        set_skill("force", 220);
        set_skill("iron-cloth", 200);
        set_skill("jin-gang", 200);
        set_skill("tigerstrike", 230);
        set_temp("apply/damage",1000);
        map_skill("iron-cloth", "jin-gang");
        map_skill("unarmed", "tigerstrike");

        create_family("eren", 1, "��ʦ��");
        set("title", HIC "ƴ��ռ����" NOR);
        setup();
        carry_object("/tongji/obj/zhangben");

}

void init()
{
        object ob;
        
        ::init();

        ob = this_player();

        if (userp(ob) && interactive(ob) && ob->query("tongji") && query_temp("owner/id") == ob->query("id"))
        {
                command("heihei");
                command("say ʮ�������Ҳ��ץ���ðɣ��Ҿͳ�ȫ���㣡\n");
        this_object()->kill_ob(ob);
        ob->kill_ob(this_object());
        }
        else 
        {
        call_out("leave",300);
        }

}

void leave()
{        
        if (!this_object()->is_fighting()) 
        {
        	command("rumor "+this_object()->query("name")+"���ض��˹�ȥ�ˡ�");
            destruct(this_object());
        }
        else
        {
        	call_out("leave",20);
        }
}

void die()
{
	object me = this_object()->query_temp("last_damage_from");
    if (!objectp(me))
    {
        ::die();
        return;
    }
    // ���������������ڵ�ɱ�ģ�Ҫ�����ת��
    if (!userp(me))
        me = find_player(geteuid(me));
//		message("vision", name() + "���ˡ�\n" NOR, environment(), this_object() );
		message_vision(this_object()->query("name")+"���ˡ�\n",me);
        destruct(this_object());
}

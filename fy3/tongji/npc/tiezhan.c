inherit NPC;
#include <ansi.h>
void create()
{
        set_name(HIG "��ս" NOR, ({ "tiezhan" }) );
        set("no_arrest",1);
        set("gender", "����");
  set("reward_npc", 1);
        set("difficulty", 80); 

        set("age", 79);
        set("long",
                "    ��������Ҳ��̫�ߣ����Ҳֻ�����������߳ߣ���������������Ҳ��������ߣ�һ����
�������Ƿ��ģ�������һ���ʯͷ������ͷ����ó��棬ͷ��������һ�ƣ�����Ҳ����
��ʮ���ͷ��������������Ѱ��һͷ�ҷ���ͷ���������ӣ���������ͷ����Ҳ�ֲ�
��ʲô�Ǻ��ӣ�ʲô��ͷ���ˣ�������ͣ��������Ҷ��Ҳ�����ԶԶ��ȥ�����˾�����
һ���ʯ���϶���һͷ��⬣�������һͷ��ʲô����ѹ�ñ����ε���ʨ��\n");
        set("attitude", "friendly");
        set("chat_chance", 1);
        set("chat_msg", ({
                "��ս��������������ҾͶ��ˣ�������\n",
        }) );

        set("score", -50000);
        
        set_skill("move", 220);
        set_skill("parry",250);
        set_skill("lianxin-blade", 200);
       set_skill("dodge",220);
        set_skill("unarmed", 200);
        set_skill("force", 250);
        set_skill("iron-cloth", 220);
        set_skill("jin-gang", 230);
        set_skill("blade", 200);
        set_temp("apply/damage",1000);
        map_skill("iron-cloth", "jin-gang");
       map_skill("blade", "lianxin-blade");
        map_skill("parry", "lianxin-blade");

        create_family("eren", 1, "��ʦ��");
        set("title", HIR "��ʨ" NOR);
        setup();
        carry_object("/tongji/obj/blade")->wield();

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
//        object ob = find_object("/tongji/npc/zhuge.c");
        
        if (!this_object()->is_fighting()) 
        {
//        	if(ob && ob->query_temp("gtongji")>0)
//        	{
//        		ob->add_temp("gtongji",-1);	
//        	}
        	command("rumor "+this_object()->query("name")+"���ض��˹�ȥ�ˡ�");
            destruct(this_object());
        }
        else
        {
        	call_out("leave",10);
        }
}

void die()
{
	object obj;
        object me = this_object()->query_temp("last_damage_from");
//        object ob = find_object("/tongji/npc/zhuge.c");
//        object ob = this_object()->query_temp("owner");
//        if(ob && ob->query_temp("gtongji")>0)
//        {
//        	ob->add_temp("gtongji",-1);	
//        }

    if (!objectp(me))
    {
        ::die();
        write("\nлл��Ϊ����Ⱥ�ڳ���һ�󺦣�\n\n");
        return;
    }
    // ���������������ڵ�ɱ�ģ�Ҫ�����ת��
    if (!userp(me))
        me = find_player(geteuid(me));
//		message("vision", name() + "���ˡ�\n" NOR, environment(), this_object() );
		message_vision(this_object()->query("name")+"���ˡ�\n",me);
        if (me->query("tongji") && this_object()->query_temp("owner/id") == me->query("id")) 
        {
	        message_vision("\n$N������ͷ�������Լ��Ļ��У�\n\n",me);
	        obj=new("/tongji/obj/tou2");
	        obj->set_temp("owner/id",me->query("id"));
	        obj->move(me);
        }
        else 
        {
			message_vision("\nлл��Ϊ����Ⱥ�ڳ���һ�󺦣�\n\n",me);
		}

        me->add("MKS", 1);

        destruct(this_object());
}
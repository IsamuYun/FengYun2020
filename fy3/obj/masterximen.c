// servant.c

inherit NPC;
inherit F_MASTER;
#include <ansi.h>
int test_array();
void create()
{
        int cox;
        cox=30000+random(30000);
        set_name("���Ŵ�ѩ", ({ "master ximen", "ximen", "master" }) );
        set("title", "��÷ׯ��");
        set("gender", "����");
        set("age", 34);
        set("long",
"���Ŵ�ѩ���ǵ�����������֮һ�������Ѿ������ˣ��޽����ľ��磮��\n"
               ); 

        set("attitude", "peaceful");
        set("hit_always_on", 1);
        set("no_parry", 1);
        set("combat_exp", 100000000);
        set("agi",25);
        set("int",40);
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "sword.hunranyijian" :),
                (: perform_action, "dodge.feitiantui" :),
                (: exert_function, "powerup" :),
                (: exert_function, "recover" :),
                (: test_array :),
                (: test_array :),
                (: test_array :),
                (: test_array :),
                (: test_array :),
                 HIR"���Ŵ�ѩ����Ķ���Ҷ�³�,������̬����û���������ϳ��ֹ���\n"NOR
        }) );
        set("str", 30);
        set("int", 30);
        set("cor", 300);
        set("cps", 30);
        set("con", 30);
              set("force_factor", 300);
        set("force", 4000);
        set("max_force", 2200);
        set("max_gin",999999);
        set("max_sen",999999);
        set("kee",cox);
              set("eff_kee",cox);
             set_skill("force", 100);
        set_skill("unarmed", 100);
        set_skill("sword", 150);
        set_skill("parry", 100);
        set_skill("dodge", 80);
        set_skill("throwing", 50);
	 set_skill("move", 150);

        set_skill("doomforce", 100);
        set_skill("doomstrike", 100);
        set_skill("doomsteps", 90);
	 set_skill("doomsword",120);

        map_skill("force", "doomforce");
        map_skill("unarmed", "doomstrike");
        map_skill("sword", "doomsword");
        map_skill("dodge", "doomsteps");



        setup();

        carry_object("/d/wanmei/npc/obj/xuejian")->wield();
        carry_object("/d/wanmei/npc/obj/cloth")->wear();
}

void killed_enemy(object who)
{
        command("say Ҷ���¡��ǣ������֮��,ֻ�Ǵ����֮�ģ�������������,���ң�\n");
}

void die()
{
        object ob;
        ob=new("/obj/guardleader");
        command("chat �����Ŵ�ѩ���հ���Ҷ�³�֮��,�ķ��ڷ���\n");
        message_vision("���Ŵ�ѩ���쳤Ц,����һ�������������,��ʧ�����ˣ�\n", this_object());
        ob->ccommand("chat Ҷ�³�ʤ��");
        destruct(this_object());
}

int test_array()
{
          message_vision(HIC"���Ŵ�ѩ����Ӧս��\n"NOR, this_object());
}


// referee.c

inherit NPC;
#include <ansi.h>;
void create()
{
        set_name("��ƽ��", ({ "gongping zi", "zi", "referee" }) );
        set("gender", "����");
        set("age", 35);
        set("long",
                "����һλ�ɷ���ǵ�������ˣ����������ķ����Ժ�������������˽��\n");
        set("combat_exp",60000);
        set("shen_type", 1);
        set_temp("kf_tufei",60);
              set("attitude", "friendly");
         set("inquiry", ([
"������": "��������𣿣�answer��\n",
        ]) );
        set("apply/attack", 50);
        set("apply/defense", 50);

        set("max_kee", 800);
        set("max_gin", 800);
        set("max_sen", 800);
        set("max_force", 800);

        set_skill("force", 80);
        set_skill("unarmed", 80);
        set_skill("sword",80);
        set_skill("parry",80);
        set_skill("dodge", 80);

        setup();

        carry_object("/obj/cloth")->wear();
        carry_object("/obj/weapon/sword")->wield();
}
 void init()
{
add_action("do_answer","answer");
}
int do_answer(string arg)
{
object me;
        object room;
        me = this_player();
        if( !me->query("family/family_name") )          return notify_fail("��û�аݹ�ʦ����ȥ�μӱ��䣿\n");
if(arg == "��" ) {
command("say �ã���ȥ�ɣ�\n");
        message_vision("$N���Ź�ƽ�ӵĺ��棬�������俴̨��\n", me);
                me->move("/d/fy/biwufang");
                me->set("biwuid",1);
//room = load_object("/d/fy/biwufang");
//                if(room) me->move(room);

                 }
}




// garrison.c

#include <ansi.h>

inherit NPC;

void create()
{
        set_name("������", ({ "lang", "langhuzi" }) );
        set("long",
"�������������ķ��Ĵ��ϰ壮\n");
        set("attitude", "heroism");
	set("title", HIB "�����ķ����ϰ�" NOR);
        set("str", 27);
        set("cor", 26);
	set("age",33);
        set("cps", 25);
	set("per", 30);
        set("combat_exp", 100000);
        set("chat_chance", 1);
        set("chat_msg", ({
"������̾������ɲ�Ʊ���ϼ͵�����ݣ�����ħ�����ǲ���ֻ����������\n",
        }) );

        set_skill("unarmed", 170);
        set_skill("sword", 170);
        set_skill("parry", 170);
        set_skill("dodge", 170);
        set_skill("move", 100);

        set_temp("apply/attack", 70);
        set_temp("apply/defense", 70);
        set_temp("apply/damage", 30);
        set_temp("apply/armor", 70);
        set_temp("apply/move", 100);

        setup();

        carry_object(__DIR__"obj/yincloth")->wear();
}

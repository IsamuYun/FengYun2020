// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
void create()
{
        set_name("����", ({ "shaolin monk", "monk"}) );
        create_family("������", 20, "����");
        set("gender", "����" );
        set("age",random(20)+ 32);
	set("nickname","��ɮ");
        set("long", "����������ר���о������书��Ѱ���ƽ���ɾ��еĺ��У�\n");
	set("vendetta_mark","shaolin");
        set("combat_exp", random(1000000)+100000);
        set("attitude", "friendly");
        set_skill("staff", 5+random(100));
	set_skill("xingyi-stick",random(100)+20);
	set_skill("move",400);
	set_skill("force",200);
	map_skill("staff", "xingyi-stick");
	set("force",100);
        set("max_force",100);
	set("force_factor",10);
        set("chat_chance", 10);
        set("chat_msg", ({
                name()+"̾�������ģ���������ħ������ʽ�����Ǻ���������\n",
                name()+"Ц����Ҳ��֪�����񺯣�����ü������ڽ���
���㣡���ɽ���书һ�����в���ʮ��������\n",
                name()+"����������Ů��Ҳ������ˣ�\n",
		name()+"�е������ڱ����ҳ������ˣ�\n"
        }) );
	setup();
	carry_object(__DIR__"obj/monk_cloth")->wear();
}


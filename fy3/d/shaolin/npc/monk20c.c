// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
void create()
{
        set_name("��ɮ", ({ "shaolin monk", "monk"}) );
        create_family("������", 17, "����");
        set("gender", "����" );
        set("age",random(30)+ 62);
	set("nickname","��ͨ����");
        set("long", "����������ר���о������书��Ѱ���ƽ���ɾ��еĺ��У�\n");
	set("vendetta_mark","shaolin");
        set("combat_exp", random(1000000)+1000000);
        set("attitude", "friendly");
        set_skill("unarmed", 200+random(100));
	set_skill("move",400);
	set_skill("force",200);
	set("force",100);
        set("max_force",100);
	set("force_factor",10);
        set("chat_chance", 10);
        set("chat_msg", ({
                name()+"̾����������������\n",
                name()+"Ц�������뿴��������ţ�\n",
                name()+"�������㿴Ҳû���ã�����츳������\n",
		name()+"���������Ѿ���ʮ����û����¥һ���ˣ�\n"
        }) );
	setup();
	carry_object(__DIR__"obj/monk_cloth")->wear();
}


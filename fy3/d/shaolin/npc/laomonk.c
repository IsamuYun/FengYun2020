// teacher.c

inherit NPC;

void create()
{
	set_name("�Ϻ���", ({ "old monk", "monk" }) );
	set("gender", "����" );
    set("reward_npc", 1);
    set("difficulty", 50); 

	set("age", 62);
	set("skill_public",1);
        set("vendetta_mark","shaolin");
	set("int", 30);
        create_family("������", 18, "��ɮ");
	set("long",
		"ר�����и����书����ɮ\n"
		);
       set("chat_chance", 5);
        set("chat_msg", ({
                name()+"���׿�˼������ħ�ʣ�һ�Բ�������\n",
                name()+"ͻȻ������ͷ���૵�����Ҳ����Ҳ������\n",
                name()+"��Ҫ�ӱ�������֮�ϣ���ͻȻͣ��������\n",

        }) );

	set("attitude", "peaceful");
	set_skill("unarmed", 70);
	set_skill("dabei-strike", 60);
	set_skill("force", 80);
	set_skill("xiaochengforce", 75);
	map_skill("unarmed", "dabei-strike");
	map_skill("force", "xiaochengforce");
	set("combat_exp", 9000000);
	setup();
}

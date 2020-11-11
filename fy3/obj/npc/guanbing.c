// guanbing.c
// ��̣���ɽ��ѧ  �����ᣨMicro��----Micro_Liang@Hotmail.Com		1997.6

#include <ansi.h>

inherit NPC;

#define SET_SKILL	100			// ��������书��ֵ����������Զ����ɾ���
#define SET_SEN		10			// ����������ֵ

void create()
{
	int n;

        set_name("����", ({ "bing ding", "bing" }) );

        set("long", @LONG
���Ǹ�ר�Ÿ����س��ŵı�����
LONG
	);

        set("attitude", "heroism");
        set("vendetta_mark", "authority");
	set("gender", "����" );
	set("age", 30);

	set("str", 30);				// ����		
	set("cps", 30);				// ����
	set("cor", 30);				// ��ʶ		
	set("per", 26);				// ��ò
	set("con", 30);				// ����

        set("combat_exp", SET_SKILL * SET_SKILL * SET_SKILL / 10 * ( 10 + random( 10 ) ) / 10);
	set("SEN", SET_SEN);

        set("env/wimpy", 30);			//

	n = SET_SKILL + random(10) - 5;		set_skill("unarmed", (n <= 0) ? 1 : n); 
	n = SET_SKILL + random(10) - 5;		set_skill("parry",   (n <= 0) ? 1 : n);
	n = SET_SKILL + random(10) - 5;		set_skill("dodge",   (n <= 0) ? 1 : n);

        set("chat_chance_combat", 15);
        set("chat_msg_combat", ({
                "�ٱ��ȵ�������������������־͸���\n",
                "�ٱ��ȵ����󵨵��񾹸Ҿܲ������ˣ����ˣ�\n"
        }) );

        setup();
        
	carry_object("/obj/cloth/tou-kui")->wear();	// װ��
	carry_object("/obj/cloth/binding-cloth")->wear();
	carry_object("/obj/cloth/boots")->wear();
	
	carry_object("/obj/weapon/longsword")->wield();
}

void init()
{       
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 0, ob);
        }
}

void greeting(object ob)
{
        if( !ob || !present(ob, environment(this_object())) ) return;
        if(!ob->query("kill_flag") )	return;
	command("kill "+ob->query("id") );
}

#include <ansi.h>
inherit NPC;
inherit F_VENDOR;
string ask_me();
void create()
{
        set_name("������", ({ "shiye chen", "shiye","chen" }) );
        set("long",
                "��������ʦү�����𷢷ų�͢ٺ»��\n");
    set("reward_npc", 1);
    set("difficulty", 170); 

	set("nickname", WHT"һƷʦү"NOR);
        set("attitude", "heroism");
	set("student_title","��Ա");
	create_family("��͢",6,"��Ա");
        set("str", 27);
        set("cor", 26);
        	  set_temp("kf_tufei",51);
        set("pursuer", 1);
set("cps", 25);
	set("agi",25);
	set("int",30);
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: perform_action, "unarmed.yuhuan" :),
        }) );
         set("inquiry", ([
                "ٺ»" : (: ask_me :),
                   ]));
    set("combat_exp", 90000000);
	set_temp("apply/damage",500);
        set_skill("unarmed", 200);
        set_skill("sword",120);
        set_skill("force",100);
        set_skill("parry", 120);
        set_skill("dodge", 110);
	set_skill("changquan",200);
        set_skill("feixian-steps",80);
        set_skill("feixian-sword",100);
        set_skill("jingyiforce",80);
        set_skill("move", 100);
        set_skill("literate",150);
	set_skill("leadership",200);
	set_skill("strategy",200);
	map_skill("unarmed","changquan");
	map_skill("dodge","feixian-steps");
	map_skill("force","jingyiforce");
	map_skill("sword","feixian-sword");
        setup();

        carry_object(__DIR__"obj/guanfu")->wear();
}
string ask_me()
{
	object ob;
        if (this_player()->query("combat_exp") < 800000 )
                return RANK_D->query_respect(this_player()) + 
                "��Ĺ�ְ̫�ͣ�������ٺ»��";
        if (this_player()->query("class") != "official" )
		return RANK_D->query_respect(this_player()) + 
		"�㲻�ǳ�͢���٣�������ٺ»��";
        if (this_player()->query("fenglu")!=this_player()->query("age"))
		return RANK_D->query_respect(this_player()) + 
		"�㻹û�е�ʱ����ٺ»ѽ��";
        if (this_player()->query("fengluover") == this_player()->query("age"))
		return RANK_D->query_respect(this_player()) + 
		"�㲻���Ѿ�����ٺ»��";
	ob = new("/d/fy/obj/fenglu");
	ob->move(this_player());
        this_player()->set("fengluover",this_player()->query("age")); 
        this_player()->delete("fenglu_open"); 
            message_vision(HIW"$N���һ���������͵�ٺ»����\n",this_player());

	return "�ðɣ�ϣ�������Ϊ��͢Ч��!";

}



inherit NPC;
void create()
{
        set_name("Ҷ��", ({ "ye kai" ,"ye" ,"kai"}) );
        set("gender", "����");
    set("reward_npc", 1);
    set("difficulty", 250); 

        set("age", 24);
        set("long","һ���۾����������ˣ���ָϸ����Ƥ�����塣\n"); 
        set("title", "����һ���������˽�");
        set("nickname", "����������");
	set("attitude", "friendly");
        set("combat_exp", 10000000);
        set("eff_gin", 100000);
        set("eff_kee", 100000);
        set("eff_sen", 100000);
        set("max_gin", 100000);
        set("max_kee", 100000);
        set("max_sen", 100000);
        set("gin", 100000);
        set("kee", 100000);
        set("sen", 100000);
	set("str", 30);
	set("cor", 30);
	set("courage", 1000);
	set("int", 30);
	set("per", 30);
	set("cps", 30);
	set("max_force" , 15000);
	set("force" , 15000);
	set("force_factor" , 3);
	set("score" , 200000);
        set("chat_chance", 3);
        set("chat_msg", ({
                "Ҷ��̾����������������Ь�׵Ĵ󶴡�\n",
		"Ҷ�������Ҵ������Ǿ��˵ģ��Ӳ����ˡ�\n"
        }) );
        create_family("����һ��", 3, "�˽�");
        set_skill("literate", 200);
        set_skill("dodge", 200);
        set_skill("force", 40);
        set_skill("throwing", 300);
        set_skill("feidao", 220);
        set_skill("parry", 200);
	set_skill("move", 200);
        map_skill("throwing", "feidao");
        setup();

}

object offensive_target(object me)
{
        int sz;
        object *enemy;

        enemy = me->query_enemy();
        if( !enemy || !arrayp(enemy) ) return 0;

        sz = sizeof(enemy);
        if( sz > 4 ) sz = 4;

        if( sz > 0 ) return enemy[random(sz)];
        else return 0;
}
void heart_beat()
{
object feidao;
object target;
if(!query_temp("weapon") && is_fighting())
{
	feidao = new("/d/fy/npc/obj/xlfd_knife");
	feidao->move(this_object());
	command("wield flying blade");
        target = offensive_target(this_object());
        if(target)
        (CLASS_D("traveller") + "/feidao/xiaoli-feidao")->kill_him(this_object(),target);
	WEAPON_D->throw_weapon(this_object(),target,feidao,0);
	return;
}
else
return ::heart_beat();
}

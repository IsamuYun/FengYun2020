//TIE@FY3`
inherit NPC;
void create()
{
        set_name("������", ({ "luliu" }) );
        set("gender", "����" );
        set("age", 53);
        set("long", "һ���������ˣ��뷢���Ѿ����ˣ�����ȴ����ͦ�ı�ֱ���۾������Ĺ�âԶ��
���滹���ˡ�\n");
        set("combat_exp", 7000000);
        set("str", 27);
        set("force", 200);
        set("max_force", 200);
        set("force_factor", 90);
        set("chat_chance", 10);
        set("chat_msg", ({
"��������������֮�����������ġ�\n",
                (: random_move :),
                (: random_move :),
                (: random_move :),
        }) );
	set_skill("throwing",10);
	set_skill("feidao",10);
	map_skill("throwing","feidao");
        setup();
        carry_object(__DIR__"obj/greencloth")->wear();
	carry_object(__DIR__"obj/7inch")->wield();
}
int heal_up()
{
	if(!query_temp("right_hand")) carry_object(__DIR__"obj/7inch")->wield();
	return ::heal_up() + 1;

}

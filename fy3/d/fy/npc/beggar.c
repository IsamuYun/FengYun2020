// TIE@FY3
inherit NPC;
void create()
{
        set_name("����ؤ", ({ "old beggar" }) );
        set("gender", "����" );
        set("age", 53);
        set("long", "һ��������˪֮ɫ������ؤ��\n");
        set("combat_exp", 100);
	create_family("ؤ��", 12, "����");
	set("title","ؤ��һ������");
        set("str", 27);
        set("force", 200);
		  set_temp("kf_tufei",3);
        set("pursuer", 1);
set_skill("begging",random(100)+10);
        set("max_force", 200);
        set("force_factor", 2);
        setup();
        set("chat_chance", 15);
        set("chat_msg", ({
                "����ؤ˵�������ĵĴ�ү�ġ� ����Ҫ���ļ���Ǯ�ɡ�\n",
                "����ؤ˵�������ĵĴ�ү�ġ� ����Ҫ���ļ���Ǯ�ɡ�\n",
                "����ؤ˵�������ĵĴ�ү�ġ� ����Ҫ���ļ���Ǯ�ɡ�\n",
                "����ؤ˵�������ĵĴ�ү�ġ� ����Ҫ���ļ���Ǯ�ɡ�\n",
                (: random_move :),
        }) );
        carry_object(__DIR__"obj/old_book");
        carry_object("/questobj/obj/shuijing");
}

int accept_object(object me, object obj)
{
        command("smile");
        command("say ��л��λ" + RANK_D->query_respect(me) + 
"��������һ�����кñ��ģ�");
        return 1;
}

int accept_fight(object me)
{
        command("say " + RANK_D->query_respect(me) + 
"������С������뿪��\n");
        return 0;
}
 
void init()
{
	        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }

}
void greeting(object ob)
{
command("beg silver from "+ob->query("id"));
}

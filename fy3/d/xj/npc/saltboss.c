// fatman.c

inherit NPC;

void create()
{
        set_name("�", ({ "lee" }) );
        set("gender", "����" );
        set("age", 39);
        set("long", "�½������������ϰ壬�˼Ҷ�����Ϊ�����ϴ�.\n");

        set("combat_exp", 100000);
        set("attitude", "heroism");
        set_skill("unarmed", 100);
        set_skill("shuaijiao", 100);
	map_skill("unarmed", "shuaijiao");
        set("chat_chance", 15);
        set("chat_msg", ({
		"�����ȱ���ӻ�ô������װ�Σ�work����һ��һ�����ӣ�\n",
		"�ָ���㣺��͵������ɻ\n"
        }) );
	setup();
        carry_object("/obj/cloth")->wear();
        
}

void init()
{
        ::init();
        add_action("do_work", "work");

}
int do_work(string arg)
{
        object ob;
        object me;
        me = this_player();
if(me->is_busy()) return notify_fail("��Ķ�����û����ɣ����ܹ�����\n");
message_vision("$N����װ����һ���Σ�����Ҳ�۵�Ҫ��\n",me);
me->add("gin",-30);
me->add("sen",-30);
ob = new("/obj/money/silver");
ob->move(me);
message_vision("���Ц����������$N˵��������Ĺ�Ǯ��\n", me);
me->start_busy(1);
return 1;
}

inherit NPC;
int direct();
void create()
{
        set_name("������", ({ "wurong" }) );
        set("gender", "Ů��" );
        set("age", 22);
	set("str",40);
        set("long",
                "һ��ȫ����۵�Ů���ӣ���\n");
	set("combat_exp", 5000000);
        set("chat_chance", 2);
        set("chat_msg", ({
                "������ָ�ż���������㣮������Ĳ����ߣ�����\n",
		"�����ݺߵ�����ԭһ��죬����İ��ң���\n",
        }) );
        set("inquiry", ([
                "ʯ����" : (: direct :),
                "master guanyin" : (: direct :)

        ]));


        set("attitude", "friendly");
        setup();
        carry_object(__DIR__"obj/bcloth")->wear();

}

int direct()
{
	object me;
	object room;
	me = this_player();
	message_vision("$N��$n��Цһ�����������ʦ����
���Ҿͳ�ȫ�㣡��\n",this_object(),me);
	room = load_object("/d/guanyin/mirror");
	message_vision("$N����һ�ɣ������˲����ˣ�\n",me);
	me->move(room);	
        if(!me->query("m_success/�ɼ�ʯ����"))
        {
                me->set("m_success/�ɼ�ʯ����",1);
                me->add("score",50);

        }

	return 1;
}

// TIE@FY3

inherit NPC;
void create()
{
        string *name = ({"ɽ����","�˹�����","����","ӡ��","��ɽ��","������","��ɽ","̩��"});
        set_name(name[random(sizeof(name))]+"�ĺ���", ({ "shaolin monk", "monk"}) );
        set("gender", "����");
        set("age", random(90)+10);
        set("long",
                "һ�������ֵ����º��С�\n");
	set("combat_exp", 5+random(5000000));
        set("chat_chance", 5);
        set("chat_msg", ({
        	name()+"̾�������ֲ���Ϊ������ͥѽ����\n",
		name()+"�����ҿ�����Ҳ�������������ߣ�\n",
                name()+"����˵������λС�ܣ���������Σ�\n",
        }) );

        set("attitude", "friendly");
        setup();
        carry_object("/obj/cloth")->wear();

}

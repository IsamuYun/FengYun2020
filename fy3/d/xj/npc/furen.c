inherit NPC;
void create()
{
        set_name("˫���缦צ���ϸ�", ({ "old woman", "ugly old woman"}) );
        set("gender", "Ů��");
        set("per", 6);
        set("age", 69);
        set("long",
"��������ɴ�ۣ�������������ס�ˣ�ֻ¶��һ˫�缦צ���֡�
ȫ���ڲ�ͣ�س鴤�ţ�����\n"
               ); 

        set("attitude", "heroism");
        set("combat_exp", 1000000);
        set("chat_chance", 10);
        set("chat_msg", ({
                "�ϸ������������Ϊʲô��������˭����Ū�����ڵĵز�����ask old woman about whom��\n",
        }) );
        set_skill("unarmed", 121);
        set_skill("dodge", 109);
        set_skill("sword", 127);
        set_skill("parry", 103);
	set_skill("move", 155);
        setup();
        set("inquiry", ([
                "whom" : "�����������Ǹ������������ˣ���",
                        ]) );
	carry_object(__DIR__"obj/robe")->wear();
}

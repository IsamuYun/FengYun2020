// chuenyu.c

inherit NPC;

string kill_passenger(object who);

void create()
{
        set_name("���ڻ�̫", ({ "chunyu" }) );
        set("gender", "����" );
    set("reward_npc", 1);
    set("difficulty", 30); 

        set("title", "���ڱ���");
        set("age", 47);
        set("str", 27);
        set("int", 12);
        set("per", 10);
	set("max_kee", 2000);
        set("long", @LONG
���ڻ�̫��ǿ����������ʱ��ҽ��ᣬ�޶�����������
�Զ��磬û��Ը����Ϊͽ�������������������ټ�֮������
��һ��
LONG
);
        set("attitude", "killer");

        set("combat_exp", 10000);
        set("bellicosity", 3000 );
        set("chat_chance", 50);
        set("chat_msg", ({
"���ڻ�̫�ȵ���߾���㾹�һ���ү�ĺ��£�\n",
         }) );
        set_skill("unarmed", 60);
        set_skill("whip", 30);
        set_skill("dodge", 40);
        set_skill("parry", 30);
        set_skill("snowwhip", 80);
        set_skill("bai-quan", 20);
        set_skill("pyrobat-steps", 300);
        map_skill("whip", "snowwhip");
        map_skill("unarmed","bai-quan");
        map_skill("dodge", "pyrobat-steps");
        set("score", 100);

        setup();

        add_money("gold", 10); 
        carry_object(__DIR__"obj/chwhip")->wield();
}
void init()
{
        object ob;
        ::init();
        if( interactive(ob = this_player()) ) {
        message_vision("���ڻ�̫�ȵ���߾���㾹�һ���ү�ĺ��£�\n",ob);
                kill_ob(ob);
        }
}


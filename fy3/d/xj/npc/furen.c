inherit NPC;
void create()
{
        set_name("双手如鸡爪的老妇", ({ "old woman", "ugly old woman"}) );
        set("gender", "女性");
        set("per", 6);
        set("age", 69);
        set("long",
"此人身穿黑纱袍，将整个脸都遮住了，只露出一双如鸡爪的手。
全身在不停地抽搐着．．．\n"
               ); 

        set("attitude", "heroism");
        set("combat_exp", 1000000);
        set("chat_chance", 10);
        set("chat_msg", ({
                "老妇盯着你道：你为什么不问我是谁把我弄到现在的地步？（ask old woman about whom）\n",
        }) );
        set_skill("unarmed", 121);
        set_skill("dodge", 109);
        set_skill("sword", 127);
        set_skill("parry", 103);
	set_skill("move", 155);
        setup();
        set("inquiry", ([
                "whom" : "他，他就是那个＂不带刀的人＂！",
                        ]) );
	carry_object(__DIR__"obj/robe")->wear();
}

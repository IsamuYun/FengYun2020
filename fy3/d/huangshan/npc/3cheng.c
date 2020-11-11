//TIE@FY3`
inherit NPC;
void create()
{
        set_name("轩辕三成", ({ "san cheng" }) );
    set("reward_npc", 1);
    set("difficulty", 50); 

        set("gender", "男性" );
        set("age", 53);
        set("long", "一个很可怕的人物，武功高绝，行踪诡秘，无论黑白两道的交易，
只要被他知道，就要抽三成，若有人不肯答应，不出三天，就会尸骨无存。\n");
        set("combat_exp", 4000000);
        set("str", 27);
        set("force", 200);
	set("attitude", "friendly");
        set("max_force", 200);
        set("force_factor", 20);
        set("chat_chance", 10);
        set("chat_msg", ({
"轩辕三成围着你转了一圈：最近你好象又有交易了？\n",
"轩辕三成笑道：这个萧十一郎真不量力，还要抽我七成！\n",
                (: random_move :),
                (: random_move :),
                (: random_move :),
        }) );
        set("inquiry", ([
                "萧十一郎" : "哦，我也正在找他。\n",
		"xiao 11" : "哦，我也正在找他。\n",
        ]) );
        setup();
        carry_object("/obj/cloth")->wear();
}

int accept_object(object me, object obj)
{
        command("grin");
        command("say 这位" + RANK_D->query_respect(me) + 
"，这就够了三成了吗？");
        return 1;
}

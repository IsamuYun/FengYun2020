// xgchen edit for 2001

inherit NPC;
#include <ansi.h>
int ask_pei();
int test_dart();
void create()
{
	set_name("查猛", ({ "meng", "cha meng" }) );
	set("title", HIY "金狮掌" NOR);
	set("gender", "男性" );
	set("age", 42);
	set("skill_public",1);
      set("inquiry",  ([
		"mission" : (: test_dart :),
		"护镖" : (: test_dart :),
                 "失败" : (:ask_pei:),       ]) );       
	set("int", 30);
        create_family("少林俗家", 21, "弟子");
	set("long",
		"金狮掌查猛是少林俗家弟子，人不但性情豪爽，且广交朋友．
		 凡是想向他求教的，只要为镖局出点力，他就肯教．\n"
		);
       set("chat_chance", 50);
       set("chat_msg", ({
                " 查猛说道：这个月镖局生意不错\n",
        }) );        
	set("attitude", "peaceful");
	set_skill("unarmed", 60);
	set_skill("changquan", 50);
	set_skill("literate", 60);
	set_skill("force", 70);
	set_skill("dodge",60);
	set_skill("parry",50);
	map_skill("unarmed", "changquan");
	set("combat_exp", 190000);
	setup();
	carry_object(__DIR__"obj/jinzhuang")->wear();
}
void init()
{
        ::init();
        add_action("do_accept", "accept");
}

int recognize_apprentice(object ob)
{
        if(ob->query("quest/ybover")){
                say("查猛说道：你．．你好象没为镖局出过力了....\n");
                return 0;
        }

        return 1;
}
int test_dart()
{
	object me;
	
	me=this_player();
        if (this_player()->query("vendetta/authority")>0)
   {            
                command("say 这位"+RANK_D->query_respect(this_player())+"好象你的品格不好，我怎么放心！");
                        return 1;    
       }
        if (is_busy())
       {
                command("say 这位"+RANK_D->query_respect(this_player())+"慢慢来，不要急！");
                        return 1;    
       }
        if (query("marks/gived") > 1 )
	{
		command("say 我们镖局现在没有你要护的镖。");
		return 1;
	}
          this_player()->set_temp("quest/answer",1);
        start_busy(random(10));
	command("say 现在南宫钱庄有一笔金锭需要运到沉香镇，你可愿意协助我们？(accept mission)");
	return 1;
}
int do_accept(string arg)
{    
	object ob,cart,biaotou;
	object me,*team;
	int i;	
	if (arg != "mission") return 0;
	me=this_player();
	team=me->query_team();
	if (sizeof(team)==0) team=({me});
	for (i=0;i<sizeof(team);i++)
	{
		if (team[i]->query("combat_exp")<1500000)
		{
			command("say 护镖路途危险，我看这位"+RANK_D->query_respect(team[i])+"似乎不宜！");
			return 1;
                }
        if (this_player()->query("combat_exp")>10000000)
                {
                        command("say 我看这位"+RANK_D->query_respect(team[i])+"本领太高了，运镖似乎不宜！");
                        return 1;
               }
                if (!intp(team[i]->query("deposit")) || team[i]->query("deposit")<1000000)
		{
			command("say 护镖是危险的事，我看"+RANK_D->query_respect(team[i])+"没有赔偿能力。");
			return 1;
		}
	}
	
	if (sizeof(team) != 0 && (team[0]!=me)) 
			return notify_fail("say 只有队伍首领才能提出接镖。\n");
        if (this_player()->query("quest/yunbiao"))
        return notify_fail("查猛说道: 你已经接过镖了，怎么还不去完成？\n");
        if (this_player()->query_temp("quest/answer")<1)
        return notify_fail("查猛说道: 你要回答什么事情？\n");
        if (this_player()->query("vendetta/authority")>0)
        return notify_fail("查猛说道: 你已经是官府要的土匪，怎么给你任务呢。\n");
        if (query("marks/gived") > 1 )
        return notify_fail("查猛说道: 镖已经被别人接了，等下次吧。\n");
        if (is_busy())
        return notify_fail("查猛说道: 我现在很忙，请等会。\n");
        add("marks/gived",1);
        this_player()->delete("quest/ybpei");
        this_player()->set_temp("quest/biao_b",1);
	command("say 好吧。跟着李镖头走吧。");
	command("say 丢镖可是要赔双份的，一路小心。");
	command("rumor 金狮镖局的镖队已经出发了。");
	
	biaotou=new(__DIR__"biaotou");
        me->set("quest/yunbiao",1);
        biaotou->move(environment(me));
        biaotou->set_temp("owner/id", me->query("id"));
        biaotou->set("combat_exp", me->query("combat_exp"));
        biaotou->set("max_sen",me->query("sen") * 5);
        biaotou->set("max_gin",me->query("gin") * 3);
        biaotou->set("max_kee",me->query("kee") * 4);
        biaotou->set("eff_sen", me->query("sen") * 3); 
        biaotou->set("eff_gin",me->query("gin") * 3);
        biaotou->set("eff_kee", me->query("kee") * 4); 
        biaotou->set("sen", me->query("sen") * 3); 
        biaotou->set("gin", me->query("gin") * 3); 
        biaotou->set("kee", me->query("kee") * 4); 
        biaotou->set("eff_force",me->query("force"));
        biaotou->set("max_force",me->query("force"));
        biaotou->set("force",me->query("force"));
        biaotou->set_skill("dodge",me->query_skill("dodge"));
        biaotou->set_skill("iron-cloth",me->query_skill("iron-cloth")/3*2);
        biaotou->set_skill("changquan",me->query_skill("unarmed"));
        biaotou->map_skill("unarmed", "chuanquan");
        biaotou->move(environment());
	
    for(i=0;i<sizeof(team);i++)
       	team[i]->set_temp("protecting",cart);
    	
    me->set_temp("protecting",cart);
    me->set_leader(biaotou);
    me->delete_temp("quest/answer");
        start_busy(random(40));
    return 1;
}
int ask_pei()
{
        object me = this_player();
        int kar, dot, balance;
        kar = me->query("kar");
        dot = (random(50)+50)* 10000;
        balance = me->query("deposit");
        
        if (balance < dot || this_player()->query("quest/ybpei")) {
                command("?");
                command("say 你需要赔偿吗？你需要用" + chinese_number(dot / 10000) + "两黄金来赔偿我们的损失吗？");
                }
        else {
                me->add("deposit",-dot);
                command("nod");
                command("say 好的，我会在你帐上扣"+chinese_number(dot / 10000)+"两黄金，你回去等消息吧！");
                me->delete("quest/yunbiao");
                me->add("quest/ybpei",1);
                }
        return 1;
}
void reset()
{
delete("marks/gived");
}                  

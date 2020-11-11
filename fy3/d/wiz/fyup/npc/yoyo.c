// by Tiandi for reborned user
inherit NPC;
#include <ansi.h>
void create()
{
	set_name("悠悠凉", ({ "yoyo" }) );
	set("gender", "女性" );
	set("age", 23);
        set("title","被亲弟弟嫌弃菜手艺的可怜姐姐");
	set("long", "一个手艺很好却被世人误会的大厨师。\n");
   	set("per", 160);
	set("combat_exp",200000000 );
	set("attitude", "friendly");
	set("chat_chance", 1);
	set_skill("sword",500);
	set_skill("iron-cloth",500);
	set_skill("yiqiforce",500);

         map_skill("iron-cloth","yiqiforce");
	set_skill("fallingstar-sword",500);
         map_skill("sword","fallingstar-sword");
	set("max_force", 15000);
          set("max_kee", 555000);
        set("max_sen", 255000);
         set("max_gin", 255000);
         set("max_mana", 15000);
         set("max_atman", 15000);
         set("force", 15000);
         set("atman", 15000);
         set("mana", 15000);
          set("force_factor", 500);
	set("marry","fengsh");
	set("marryname","风四海");

	set("marks/kuaihuo",1);
	set("TASK",3000);
	set("chat_chance_combat", 50 );
	set("chat_msg", ({   "悠悠凉道：弟弟~~你在哪?姐姐新设计的菜,快来尝尝！\n",
			   "悠悠凉愤慨地说道：这死小子,又跑哪去了,好不容易做完了菜,又让他溜了。\n",
				}) );
	set("chat_msg_combat", ({"悠悠凉怒道：敢在我的地盘闹事，不想活了！看香蕉皮！\n",
				  (: perform_action, "sword.onheart" :),
				 "悠悠凉一边打一边叫.....该死的小偷，想偷吃我给弟弟做的菜..找打~~~！\n", 
				    (: perform_action, "sword.tianyaliuxing" :),
				 
				}) );
				
	set("inquiry", (["香蕉" : "我弟弟最喜欢吃拔丝香蕉了，我每天都要烧给他吃。",   
		          "重生" : "玩家重生后可以到我这里来提升(upmax_hp)相应的精气神。" ,
		        "烧菜" : "今天又研制了一种新的菜,以香蕉,糖水,大蒜,巧克力为原料,味道一定不错。" ,
		     "弟弟" : "那死小子又不知道跑哪去了,难道我做的菜那么吓人么。" ,
               "奖励":"只要把我那不听话的弟弟带回来，姐姐会给你很多奖励哦~",
			"双效丹":"每完成一百个使命可以到我这里拿取(getreward)奖励一颗双效丹",
				]));

	setup();
       	 carry_object("/d/fy/npc/obj/leafsword")->wield();

}
void init()
{
	add_action("do_upgrade", "upmax_hp");
	add_action("do_change", "getreward");
}
int do_change()
{
	object me,dan;
	int a,b;
	me = this_player();
	a = me->query("TASK");
	b = me->query("TASKREWARD");
	if (a - b > 99) 
	{
		a = a -100;
		dan = new("/obj/food/double");
		dan ->move(me);
		me->add("TASKREWARD",100);
		write("你从悠悠凉那里获得了一颗双效丹。\n");
		message("system",HIY "\n【快乐风云】使命奖励："+me->query("name")+"由于勤奋努力地完成风云使命，获得悠悠凉的赏识，特赠一颗双效丹以示鼓励！\n" NOR,users());
	}
	else
		write("你目前完成的使命数还不够。\n");
	return 1;
}
int do_upgrade()
{
	object me;
	int reb,rebb;
	mapping my;

	me = this_player();
	reb = me->query("reborned"); 
	rebb = me->query("rebb");
	if (!reb)  
	{
		message_vision("$N对着$n说道："+RANK_D->query_respect(me)+"你还没有重生过吧，别来耍姐姐了！\n",this_object(), me);    
         	  	return 1;  
	}
	if (rebb < reb)
	 {
	 	message_vision("$N说道：既然你已经重生过了，那姐姐我就帮你提升一下各项能力吧！\n",this_object(), me);    
		me->set("rebb",reb);
		me->save();
                message("system",HIC "\n【快乐风云】重生奖励："+me->query("name")+"由于重生，体质发生了变化，因此经脉骨骼的上限得到了提升了。\n" NOR,users());
		return 1;
	}
	else
		message_vision("$N说道：$n是不是已经来过了，我怎么感觉这么眼熟呢！\n",this_object(), me);    
	return 1;
}
void die()
{
        int gin,kee,sen;
        gin =(int)query("max_gin");
        kee =(int)query("max_kee");
        sen =(int)query("max_sen");
        set("eff_kee",kee);set("kee",kee);
        set("eff_gin",gin);set("gin",gin);
        set("eff_sen",sen);set("sen",sen);
    message_vision("$N从怀里拿出一枚十全大补丸往嘴里一放，顿时整个人又恢复到了最佳状态。\n",this_object());
        return ;

}



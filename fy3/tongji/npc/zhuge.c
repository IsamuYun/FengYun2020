inherit NPC;
#include <ansi.h>
int random_action();
void create()
{
        set_name(HIB "诸葛先生" NOR, ({ "zhu ge" }) );

        set("gender", "男性");
  set("reward_npc", 1);
        set("difficulty", 80); 

        set("age", 62);
        set("long",
                "    诸葛先生是六扇门里的最高统帅，是传说中罪恶的克星，乃是当今天子
的智囊，武功深不可测。诸葛先生不问世事已久，这次出山是为了......\n");
        set("attitude", "peaceful");
     //   set("skill_public",1);
        set("str", 26000);
        set("cor", 30);
        set("int", 24);
        set("cps", 30);
        set("per", 50);



        set("chat_chance", 1);
        set("chat_msg", ({
                (: random_action :)
        }) );

        set("mana", 4000000);
        set("max_mana", 800000);
        set("atman", 4000000);
        set("max_atman", 800000);
        set("force", 4000000);
        set("max_force", 800000);
        set("force_factor", 2000);

        set("combat_exp", 200000000);
        set("score", 0);
        set_skill("magic",200);
        set_skill("spells",200);
        set_skill("literate",200);
        set_skill("move",200);
        set_skill("dodge",200);
        set_skill("unarmed", 200);
        set_skill("force", 200);
        set_skill("iron-cloth", 200);
        set_skill("yiqiforce", 100);
        set_skill("dagger",200);

        set_temp("apply/attack",300);
        set_temp("apply/damage",30000);

        map_skill("iron-cloth", "yiqiforce");
        map_skill("force", "yiqiforce");
        map_skill("unarmed", "yiqiforce");

        create_family("六扇门", 1, "统帅");
        set("title", HIR "军师" NOR);
        set("class", "official");
        setup();
}

int accept_fight(object me)
{       object who=this_player();
        command("say 老身久不动手，武艺早已生疏，怎是" + RANK_D->query_respect(who)+ "的对手？");
        return 0;
}


void init()
{
        add_action("give_tongji", "tongji");
}


int accept_object(object who, object ob)
{
       object silk,silk2,goldobj;
        string sure,weap;
       int  exp, pot, score,c1,val,goldnum,reb,doubletime,doubletype;
        mapping tongji;
       tongji = who->query("tongji");
        reb = who->query("reborned");  // update by Tiandi 200712030945

        val=ob->value();
        weap=HIY"惩恶扬善"NOR;
        if((string)ob->query("id")=="sword" || (string)ob->query("id")=="blade") c1=1;
       if(who->query("m_success/通缉") && c1 && weap == (string)ob->query("name"))
        {command("say 谢谢" + RANK_D->query_respect(who)+ "了!只是那人武功太高,只怕有兵刃亦无济于事,以老朽的功夫,
竟连一招都没能接下,唉....." + RANK_D->query_respect(who)+ "神功盖世,或许可以替老朽雪此一招败于敌手之耻,
也免敌人笑我大国无人.....唉.....那人武功之高,乃老朽平生仅见," + RANK_D->query_respect(who)+ "千万小心了,
那人在老屋以北的我国与罗刹国交界之处,长相丑陋,手拿一铁器,呈直角状," + RANK_D->query_respect(who)+ "
务必小心此物,此物发射之极亮光芒,伤人于无形.....老朽就败于此光之下,唉....吉人自
有天象," + RANK_D->query_respect(who)+ "就此去吧,也许这通古斯之迷就此破解也未可知!!
另外,老朽这身功夫,或者有" + RANK_D->query_respect(who)+ "所需要的,老朽当倾囊相授!\n");
        who->set("m_success/UFO",1);

         return 1;
        }

		if (val && val >2000 && who->query("tongji"))
        {
                who->set("tongji", 0 );
                tell_object(who,"诸葛先生说道：这也太难为你了，这个通缉任务就算了吧．．\n");

           if (reb) {
                 who->add("score",-1);
               }
         else {
               who->add("score",-2);
             }
                        
                return 1;
        }


     if(!(tongji =  who->query("tongji")))
        {
        	tell_object(who,"诸葛先生说道：你没有申请通缉十大恶人。\n");
         	return 0;
        }
        sure ="m_success/"+tongji["tongji"];
        if(!(ob->query("id") == "tou"))
        {
         tell_object(who,"诸葛先生说道：这不是我想要的。\n");
          return 0;
        }
        if ((string)ob->query("name") != (tongji["tongji"]+"的人头") ||
        	ob->query_temp("owner/id") != who->query("id"))
        {
         tell_object(who,"诸葛先生说道：这不是我想要的。我没收了！\n");
          return 1;
        }
        
        goldnum = 50+random(100);
		doubletime = who->query("doubletime");
		doubletype = (int)who->query("doubletype");
		reb = who->query("reborned");
        exp = who->query("level");
		exp = 5000+exp*20;
		exp = exp + exp/5*reb;
		if (doubletime - time() > 0)
			exp = exp*(doubletype+1);
		pot = exp / 5;
		score = 1;


        message_vision(HIW "$N被奖励了：\n"
                + chinese_number(exp) + "点实战经验，\n"
                + chinese_number(pot) + "点潜能，\n"
               + chinese_number(score) + "点评价，\n" NOR, who);
        who->add("combat_exp", exp);
        who->add("potential", pot);
        who->add("score", score);
	    goldobj=new("/obj/money/silver");
	    goldobj->set_amount(goldnum);
	    goldobj->move(who);

		who->add("ftongji",1);
		who->set("tongji_time", (int) time());
		who->set("tongji",0);
		
		if(who->query("m_success/通缉") || who->query(sure))
		{
			return 1;	
		}
				
		command("say 这位" + RANK_D->query_respect(who)+ "，你杀了十大恶人之一的"+tongji["tongji"]+"？\n
			真是百姓之福啊！\n");
	//	silk = new("/tongji/obj/jp");
 //silk->move(who);
// tell_object(who,"诸葛给你一个"+silk->query("name")+"。\n");
 // silk->move(this_object());
//    command("give xzhang to " + who->query("id"));
		who->add("TTQUEST",1);
		who->set(sure,1);

	    if ( who->query("m_success/李大嘴") && who->query("m_success/杜杀") 
	        		&& who->query("m_success/屠娇娇") && who->query("m_success/阴九幽")
	        		&& who->query("m_success/欧阳丁当") && who->query("m_success/萧咪咪")
	        		&& who->query("m_success/铁战") && who->query("m_success/白开心")
	        		&& who->query("m_success/哈哈儿") && who->query("m_success/轩辕三光"))
	    {
	        command("say 这位" + RANK_D->query_respect(who)+ "，你竟然将危害武林的十大恶人全部诛灭？\n
	        	真是英雄盖世，这番为国为民的胸襟更是令人钦佩！这个也给你吧！\n");
		    silk2 = new("/tongji/obj/jp1");
		    silk2->move(this_object());
		    command("give jianb to " + who->query("id"));
		    who->set("title",HIR"盖"+HIC"世"+HIM"英"+HIW"豪"NOR);
		    who->set("m_success/通缉",1);
	message("system",HIC "\n【快乐风云】谜题任务："+who->query("name")+"解开了相关谜题，获得了"HIY"【盖世英豪】"HIC"的称号。\n" NOR,users());

	    }
		
		return 1;
}



int give_tongji(string arg)
{
        mapping tongji;
        object obj0,obj1,obj2,room1;
        string file,location,*roomlines,objid,output;
        object me;
        int j, combatexp,lv,i;
        string tag ="1";
        me = this_player();
       
//		if(query_temp("gtongji") >= 10)
//		{
//               write("已经有十个恶人逍遥在外，等会儿再来申请吧．\n");
//                return 1;			
//		}

		if( ((int) me->query("tongji_time")) >  time() )
        {
        tell_object(me,"\n你刚刚才申请的通缉任务，等会儿再来申请吧！\n");
                return 1;
        }

         if((int)me->query("ftongji") > 5000)
        {
        tell_object(me,"\n你的通缉历程已经非常完满了，去接受其它更有挑战性的任务吧！\n");
                return 1;
        }

         if((int)me->query("level") < 35)
        {
        tell_object(me,"\n你武艺虽然不错1，但还不足以对付十大恶人，谢谢您的好意！\n");
               return 1;
        }

          if((int)me->query("level") > 80)
        {
        tell_object(me,"\n你已经达到化外先天之境，十大恶人不需要劳烦您出手了！\n");
                return 1;
        }

        if((int) me->is_ghost())
        {
                write("还是先照顾好您自己吧．\n");
                return 1;
        }
//        if(me->query("m_success/通缉"))
//        {       write("谢谢您的好意！十大恶人已经全部伏法，天下又可以平静一段日子了。\n");
//                return 1;
//        }

		j=2000;
		lv = me->query("level");
		for(i=0;i<lv;i++)
		j=j+j/9;
		 if((int) me->query("combat_exp") > j)
        {
                write("你的经验超过了你的升级经验，请先升级．\n");
                return 1;
        }

      if((tongji =  me->query("tongji")))
        {
        tell_object(me,"\n你已经参与了通缉『"+tongji["tongji"]+"』的任务,加油啊!\n");
        return 1;
        }
        
        file = read_file("/tongji/dynamic_location");
        roomlines = explode(file,"\n"); 
        location = roomlines[random(sizeof(roomlines))];

                if( catch(load_object(location)) || !load_object(location) )
                {
                        write("通缉恶人出现异常，请稍后片刻再重新申请。\n");
                        return 1;               
                }

tongji = TONGJI_D(tag)->query_tongji();

        tell_object(me,"好极了,朝廷正在全力围剿『"+tongji["tongji"]+"』你这就去吧,提『"+tongji["tongji"]+"』的头回来,朝廷重重有赏。\n" NOR);
        me->set("tongji", tongji);


                switch(tongji["tongji"]){
                        case "李大嘴":
                                obj1=new("/tongji/npc/lidazui");
                                objid=obj1->query("id");
                                obj1->set_name(HIR "李大嘴" NOR, ({ "lidazui" }) );
                                break;
                        case "杜杀":
                                obj1=new("/tongji/npc/dusha");
                                objid=obj1->query("id");
                                obj1->set_name(HIR"杜杀" NOR, ({ "dusha" }) );
                                break;
                        case "屠娇娇":
                                obj1=new("/tongji/npc/tujiao");
                                objid=obj1->query("id");
                                obj1->set_name(HIY "屠娇娇" NOR, ({ "tujiaojiao" }) );
                                break;
                        case "阴九幽":
                                obj1=new("/tongji/npc/yinjiuyou");
                                objid=obj1->query("id");
                                obj1->set_name(HIW"阴九幽" NOR, ({ "yinjiuyou" }) );
                                break;
                        case "白开心":
                                obj1=new("/tongji/npc/baikaixin");
                                objid=obj1->query("id");
                                obj1->set_name(HIW "白开心" NOR, ({ "baikaixin" }) );
                                break;
                        case "铁战":
                                obj1=new("/tongji/npc/tiezhan");
                                objid=obj1->query("id");
                                obj1->set_name(HIG "铁战" NOR, ({ "tiezhan" }) );
                                break;
                        case "萧咪咪":
                                obj1=new("/tongji/npc/xiaomimi");
                                objid=obj1->query("id");
                                obj1->set_name(HIC"萧咪咪" NOR, ({ "xiaomimi" }) );
                                break;
                        case "哈哈儿":
                                obj1=new("/tongji/npc/hahaer");
                                objid=obj1->query("id");
                                obj1->set_name(HIG"哈哈儿" NOR, ({ "hahaer" }) );
                                break;
                        case "欧阳丁当":
                                obj1=new("/tongji/npc/ouyangding");
                                objid=obj1->query("id");
                                obj1->set_name(HIB"欧阳丁" NOR, ({ "ouyangding" }) );
                                obj2=new("/tongji/npc/ouyangdang");
								obj2->set_name(HIB"欧阳当" NOR, ({ "ouyangdang" }) );
                                break;
                        case "轩辕三光":
                                obj1=new("/tongji/npc/sanguang");
                                objid=obj1->query("id");
                                obj1->set_name(HIM"轩辕三光" NOR, ({ "sanguang" }) );
                                break;
                        }

//        obj1->set_temp("owner", this_object());
         obj1->set_temp("owner/id",me->query("id"));
         obj1->set("level",me->query("level")+10); 
		 lv = obj1->query("level");
		 obj1->set("str",6*lv);
		 obj1->set("cor",6*lv);
		 obj1->set("int",6*lv);
		 obj1->set("spi",6*lv);
		 obj1->set("cps",6*lv);
		 obj1->set("per",6*lv);
		 obj1->set("con",6*lv);
		 obj1->set("kar",6*lv);
		 obj1->set("agi",6*lv);
		 obj1->set("dur",6*lv);
		 obj1->set("fle",6*lv);
		 obj1->set("tol",6*lv);
		 obj1->set("max_kee",me->query("max_kee")*2);
		 obj1->set("eff_kee",obj1->query("max_kee"));
		 obj1->set("kee",obj1->query("max_kee"));
		 obj1->set("max_gin",me->query("max_gin")*2);
		 obj1->set("eff_gin",obj1->query("max_gin"));
		 obj1->set("gin",obj1->query("max_gin"));
		 obj1->set("max_sen",me->query("max_sen")*2);
		 obj1->set("eff_sen",obj1->query("max_sen"));
		 obj1->set("sen",obj1->query("max_sen"));

		obj1->move(location);
        if(obj2)
        {
         obj2->set_temp("owner/id",me->query("id"));
         obj2->set("level",me->query("level")+10); 
		 lv = obj2->query("level");
		 obj2->set("str",6*lv);
		 obj2->set("cor",6*lv);
		 obj2->set("int",6*lv);
		 obj2->set("spi",6*lv);
		 obj2->set("cps",6*lv);
		 obj2->set("per",6*lv);
		 obj2->set("con",6*lv);
		 obj2->set("kar",6*lv);
		 obj2->set("agi",6*lv);
		 obj2->set("dur",6*lv);
		 obj2->set("fle",6*lv);
		 obj2->set("tol",6*lv);
		 obj2->set("max_kee",me->query("max_kee")*2);
		 obj2->set("eff_kee",obj2->query("max_kee"));
		 obj2->set("kee",obj2->query("max_kee"));
		 obj2->set("max_gin",me->query("max_gin")*2);
		 obj2->set("eff_gin",obj2->query("max_gin"));
		 obj2->set("gin",obj2->query("max_gin"));
		 obj2->set("max_sen",me->query("max_sen")*2);
		 obj2->set("eff_sen",obj2->query("max_sen"));
		 obj2->set("sen",obj2->query("max_sen"));
        	obj2->add_team_member(obj1);
        }

//        room1 = load_object(location);
//        if(room1)
//        {
//	        room1->set("no_beg",1);
//	        room1->set("no_sheet",1);
//	        room1->set("no_magic",1);
//        }
		me->set("tongji_time", (int) time()+360);
		me->save();

	output = TASK_D->locate_obj(this_object(),objid);
	if(output=="")
		output = "暂时确定不了十大恶人的大概位置。\n";
	write(output);
//	add_temp("gtongji",1);
		if (me->query("tongjiauto")-time()>0)
				{
					write("你使用的通缉任务丹发挥功效了.\n");
					me->move(location);
				}
		return 1;
}
int random_action(){
switch(random(4)){
        case 0:
          
      command("say 朝廷缉拿十大恶人,请诸位武林同道加以援手.");
                break;
        case 1:
                command("say 协助朝廷缉拿十大恶人．．．．");
                break;
        case 2:
      command("say 本站点的论坛地址为http://club.xilu.com/happyfy3，欢迎前来留下您的笔墨。");
                break;

        case 3:
                command("say 我竟然连一招都．．．．唉．．．．,好厉害的功夫．．．．");
                break;}
     return 1;
}


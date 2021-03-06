//小孩.c
//根据一个前辈的宠物系统更改的 小孩子系统
//by xgchen@fy
#include <ansi.h>
#include <combat.h>
#define PET_MARKING "/d/fy/fqkhotel"
inherit NPC;

static int last_age_set;

void create()
{
        set_name("婴儿", ({ "baby" }) );
        set("race", "人类");
        set("age",0);
        set("str",10);
        set("cor",10);
        set("int",10);
        set("spi",0);
        set("cps",10);  
        set("per",10);
        set("con",10);
        set("agi",10);
        set("dur",10);
        set("fle",10);
    set("go_free",1);
    set("can_carry",1);
        set("tol",10);
        set("max_kee",300);
        set("max_gin",300);
        set("max_sen",300);
        set("long", "一个小婴儿。\n");
        set("owner","R");
        set("limbs", ({ "头部", "身体", "前心", "後背","双脚" }) );
        set("verbs", ({ "bite", "claw" }) );
        set("obedience",60);
        set("combat_exp",1000);
        set("deathstamp",1);
        setup();
}
string query_save_file()
{
        string id;

        id = query("owner");
        if( !stringp(id) ) return 0;
        return sprintf(DATA_DIR "user/%c/%s/%s", id[0],id, id+".pet");
}

int save()
{
        string file;
        int gin, kee, sen;

        gin = (int) query("max_gin");
        kee = (int) query("max_kee");
        sen = (int) query("max_sen");
        set("eff_kee",kee);
        set("eff_gin",gin);
            set("eff_sen",sen);
        set("kee",kee);
        set("gin",gin);
        set("sen",sen);

        if( stringp(file = this_object()->query_save_file()) ) {
                assure_file(file+ __SAVE_EXTENSION__);
                return save_object(file);
        }
        return 0;
}
int restore()
{
        string file;

        if( stringp(file = this_object()->query_save_file()) )
            return restore_object(file);
        return 0;
}

//食量随年龄增长而增加。
int max_food_capacity() { return 10+10*query("age"); }
int max_water_capacity() { return 10+10*query("age"); }

void die()
{       
        int i;
        object owner, *enemy;
        int gin,kee,sen,exp;
        exp = (int) query("combat_exp");
        gin = (int) query("max_gin");
        kee = (int) query("max_kee");
        sen = (int) query("max_sen");
        if(!environment()->query("no_death_penalty")){
          set("deathstamp",time());
          set("combat_exp",exp/10 * 9);
        }
        set("eff_kee",kee);
        set("eff_gin",gin);
        set("eff_sen",sen);
        set("kee",kee);
        set("gin",gin);
        set("sen",sen);
        if(objectp(owner=query("possessed")))
        {
                enemy = query_enemy();
        i = sizeof(enemy);
        while(i--) {
                if( enemy[i] && living(enemy[i]) ) {
                        owner->kill_ob(enemy[i]);
                }
        }

        }

        save(); 
        ::die();
}

//会长大。
void update_age()
{

        if( !last_age_set ) last_age_set = time();
        add("mud_age", time() - last_age_set);
        last_age_set = time();
        set("age", (int)query("mud_age") / 172800);
}


int heal_up()
{
        object owner=this_object()->query("possessed");
 //同样长年龄。
        update_age();
        if(!objectp(owner))
        {
        save();
        message_vision("$N去玩去了，不见了。\n",this_object());
        destruct(this_object());
        return 1;
        }
        //长期不喂养，训练度降低。
        //加个随机是必须的，可以解释为可以忍耐饥饿，但主要是为了防止信息泛滥。
        if((query("food")<2||query("water")<2)&&!random(5))
        {
        if(environment()==owner->environment()) 
        message_vision("$N在$n不知道是饿了还是渴了。\n",this_object(),owner);
           add("ask_food",1);
           if(query("ask_food")>5)
    if(random(100)>query("obedience"))
    {
        add("obedience",-1);
         if(environment()==owner->environment())        
         message_vision("$N以幽怨的眼光看了看$n。\n",this_object(),owner);
        }
         }
        set_heart_beat(1);
        return ::heal_up() ;
        
  }
void init()
{
        if(this_player() == query("possessed"))
        {
        add_action("do_order","order");
        add_action("do_modify","modify");
        add_action("do_gongji","gongji");
        add_action("do_teach","teach");
        add_action("do_shape","shape");
    add_action("do_weiyang","weiyang");
    add_action("do_mai","mai");
        }

}

//喂养。
int do_weiyang(string arg)
  {
object me,ob,food;
if(!arg||arg=="")
return notify_fail("命令格式:weiyang <食物或水的id>\n");
ob=this_object();
me=ob->query("possessed");
if(me!=this_player())
{
command("yawn "+this_player()->query("id"));
return 1;
  }

if(!(food=present(arg,ob)))
{
if(!(food=present(arg,me)))
return notify_fail("你身上没有"+arg+"这样东西。\n");
if(!food->is_food()&&!food->is_liquid()||!food->query("babyeat"))
return notify_fail("这东西既不能给婴儿用，你想要"+name()+"的命呀？\n");
if(food->move(ob))
message_vision("$N把$n放到"+name()+"的身边。\n",me,food);
else return notify_fail(name()+"现在不想吃东西。\n");
 }
if(food->is_food())
{
if(ob->query("food")>=ob->max_food_capacity())
return notify_fail(name()+"已经吃的够饱了，你要撑死它呀？\n");
command("eat "+arg);
message_vision("$N耐心的喂$n吃了一些"+food->name()+"。\n",me,ob);
return 1;
}

else if(food->is_liquid())
{
if(ob->query("water")>=ob->max_water_capacity())
return notify_fail(name()+"已经喝了太多东西了，你要撑死它呀？\n");
command("drink "+arg);
message_vision("$N耐心的喂$n喝了一点"+food->query("liquid/name")+"。\n",me,ob);
return 1;
}
else return notify_fail("这东西既不能吃又不能喝，你想要"+name()+"的命呀？\n");

 }

int do_order(string arg)
{
       int i;
        int obedience;
       string arg1;
        object me = this_player();
        me->add("sen",-5);
        obedience = query("obedience");
        if(random(100) > obedience )
        {
        command("emote 很不情愿的样子。");
        return 1;
   }            
   if(!arg||arg=="")
   {
   command("emote 疑惑地看着"+me->query("name")+"。\n");
   return 1;    
        }
  //禁止使用的命令。
      if( strsrch(arg, "follow") != -1 ||
          strsrch(arg, "apprentice") != -1 ||
          strsrch(arg, "promote") != -1 ||
          strsrch(arg, "recruit") != -1 )
         {   
            command( "emote " + arg);
            return 1;
        }

//处理公共频道。
//暂时无法在公共频道使用emote.
      if( strsrch(arg, "fy ") != -1 ||
          strsrch(arg, "chat ") != -1 )
         {   
            command(arg);
            return 1;
        }

        i = strlen(arg);
       while(i--) {
                if(is_chinese(arg[i..<0]) ) {
            command( "emote " + arg);
            return 1;
                }
        }                       
        command(arg);
        return 1;
}

int do_modify(string arg)
{
        string item, msg;
        object me = this_player();
        if(!arg || sscanf(arg,"%s %s",item,msg) != 2)
        return notify_fail("命令格式: modify 款项 内容\n");
        if(item == "flee")
        {
                set("env/wimpy", atoi(msg));
                write("ＯＫ\n");
                save();
                return 1;
        }
                
                if(CHINESE_D->check_control(msg))
                return notify_fail("描述不可有控制符！\n");
        me->add("sen",-10);
        msg = replace_string(msg, "$BLK$", BLK);
        msg = replace_string(msg, "$RED$", RED);
        msg = replace_string(msg, "$GRN$", GRN);
        msg = replace_string(msg, "$YEL$", YEL);
        msg = replace_string(msg, "$BLU$", BLU);
        msg = replace_string(msg, "$MAG$", MAG);
        msg = replace_string(msg, "$BNK$", BLINK);
        msg = replace_string(msg, "$CYN$", CYN);
        msg = replace_string(msg, "$WHT$", WHT);
        msg = replace_string(msg, "$HIR$", HIR);
        msg = replace_string(msg, "$HIG$", HIG);
        msg = replace_string(msg, "$HIY$", HIY);
        msg = replace_string(msg, "$HIB$", HIB);
        msg = replace_string(msg, "$HIM$", HIM);
        msg = replace_string(msg, "$HIC$", HIC);
        msg = replace_string(msg, "$HIW$", HIW);
        msg = replace_string(msg, "$NOR$", NOR);
        msg += NOR;
        switch(item)
        {
        case "desc":
                if(CHINESE_D->check_length(msg) > 150)
                return notify_fail("描述太长！\n"); 
                set("long",msg+"\n");
                write("ＯＫ\n");
                save();
                return 1;
        case "nickname" :
                if(CHINESE_D->check_length(msg) > 60)
                return notify_fail("描述太长！\n");
                set("nickname",msg);
                write("ＯＫ\n");
                save();
                return 1;
        case "name" :
                if(CHINESE_D->check_length(msg) > 30)
                return notify_fail("描述太长！\n");
                set("name",msg);
                write("ＯＫ\n");
                save();
                return 1;

        case "title" :
                if(CHINESE_D->check_length(msg) > 40)
                return notify_fail("描述太长！\n");
                set("title",msg);
                write("ＯＫ\n");
                save();
                return 1;
        case "arrive_msg" :
                if(CHINESE_D->check_length(msg) > 40)
                return notify_fail("描述太长！\n");
                set("arrive_msg",msg);
                write("ＯＫ\n");
                save();
                return 1;
        case "leave_msg" :
                if(CHINESE_D->check_length(msg) > 40)
                return notify_fail("描述太长！\n");
                set("leave_msg",msg);
                write("ＯＫ\n");
                save();
                return 1;

        }
        return notify_fail("你要修改什么？\n");

}
int do_gongji(string arg)
{
        object me,obj;
        me = this_player();
        if( environment(me)->query("no_fight") )
                return notify_fail("这里不准战斗。\n");

        if( !arg )
                return notify_fail("你想杀谁？\n");

        if(!objectp(obj = present(arg, environment(me))))
                return notify_fail("这里没有这个人。\n");

        if( !obj->is_character() || obj->is_corpse() )
                return notify_fail("看清楚一点，那并不是活物。\n");
        message_vision(
        sprintf("$N对$n一指，对%s命令道：＂上！＂\n",this_object()->name()),me,obj);
    me->add("sen",-5);
        add("sen",-10);
       if(random(100) > query("obedience") )
        command("emote 很不情愿地哼了一声。");
        else
        kill_ob(obj);
        return 1;
        
}

int do_teach(string arg)
{
        object me;
        int gin_cost,amount;
        int myskill, itskill;
        me = this_player();
        if(!myskill = me->query_skill(arg,1))
        return notify_fail("这项技能你好象还不会呢！\n");
//能学的技能。
        if( arg != "unarmed" && arg != "move" && arg != "dodge"&& arg != "changquan"
     && arg != "parry" && arg != "iron-cloth" && arg != "leadership"
     && arg != "dormancy" && arg != "incarnation" && arg != "literate"
     && arg != "chanting"    )
        return notify_fail("它学不会这项技能的！\n");
        itskill = query_skill(arg,1);
        if(myskill <= itskill)
        return notify_fail(name()+"以嘲笑的目光望着你。\n");
        if((int)me->query("potential")-(int)me->query("learned_points") < 1)
        return notify_fail("你的潜能不够！\n");
        gin_cost = 3;
        if((int)me->query("gin") < gin_cost)
        return notify_fail("你显然太累了没有办法教！\n");
        me->receive_damage("gin",gin_cost);
        amount = (int)me->query_int() * (int)query_int()*3/100;
        message_vision(sprintf("$N不厌其烦地教$n「%s」。\n",to_chinese(arg)),me,this_object());
        me->add("potential",-1);
       if(random(100) > query("obedience") )
        command("emote 很不情愿地哼了一声。");
        else {
        improve_skill(arg,amount);
        message_vision(sprintf("$N似乎真的学会了一些「%s」！\n",to_chinese(arg)),this_object());
    }
    return 1;

}

string status_color(int current, int max)
{
        int percent;

        if( max>0 ) percent = current * 100 / max;
        else percent = 100;
        if( percent > 100 ) return HIC;
        if( percent >= 90 ) return HIG;
        if( percent >= 60 ) return HIY;
        if( percent >= 30 ) return YEL;
        if( percent >= 10 ) return HIR;
        return RED;
}
//显示状态。
int do_shape(string arg)
{       mapping my;
        string shape;
        int at_pt,pa_pt,do_pt;
        my = query_entire_dbase();
        printf("精：%s%3d/ %3d %s(%3d%%)"NOR"  气：%s%3d/ %3d %s(%3d%%)"NOR"  神：%s%3d/ %3d %s(%3d%%)\n"+NOR,
                status_color(my["gin"], my["eff_gin"]), my["gin"],my["eff_gin"],
                status_color(my["eff_gin"], my["max_gin"]),     my["eff_gin"] * 100 / my["max_gin"],
                status_color(my["kee"], my["eff_kee"]), my["kee"], my["eff_kee"],
                status_color(my["eff_kee"], my["max_kee"]),     my["eff_kee"] * 100 / my["max_kee"],
                status_color(my["sen"], my["eff_sen"]), my["sen"], my["eff_sen"],
                status_color(my["eff_sen"], my["max_sen"]),     my["eff_sen"] * 100 / my["max_sen"]
        );              
        printf("主人： %s\t\t经验： %d\t\t杀气： %d\n",
        my["owner"], my["combat_exp"],my["bellicosity"]
        );
        printf("才智： %d\t\t体质： %d\t\t体态： %d\n",
        query_int(), query_con(),query_per()
        );
        printf("凶性： %d\t\t力量： %d\t\t耐力： %d\n",
        query_cor(), query_str(),query_fle()
        );
        printf("速度： %d\t\t个性： %d\t\t定性： %d\n",
        query_agi(), query_tol(),query_dur()
        );
        printf("食物： %d\t\t饮水： %d\t\t年龄： %d\n",
        my["food"], my["water"],my["age"]
        );
        at_pt= COMBAT_D->skill_power(this_object(), "unarmed", SKILL_USAGE_ATTACK);
        pa_pt= COMBAT_D->skill_power(this_object(), "unarmed", SKILL_USAGE_DEFENSE);
        do_pt= COMBAT_D->skill_power(this_object(), "dodge", SKILL_USAGE_DEFENSE);
        printf("攻击力： %d\t\t\t\t防御力： %d\n\n",
        at_pt+1, pa_pt/2+do_pt/2+1
        );
        printf("/cmds/usr/skills"->pet_skill(this_object()));
        return 1;
}
void unconcious()
{
 save();
}

//added by lion@hero
//to make fun,let pet can buy sth for it's owner
int accept_object(object who, object ob)
{
 if(who==this_object()->query("possessed"))
return 1;
}

int do_mai(string arg)
{
   int i,value,flag;
   object *inv;
   object ob,me;
   value=0;
   ob = this_object();
   me=ob->query("possessed");
   if(!me||!userp(me))
   return notify_fail(name()+"以不屑的眼光看了看你。\n");
   if(!arg||arg=="")
   return notify_fail("命令格式:mai <物品id>，这里的物品只能是在凤求凰客栈出售的物品。\n");
   inv=all_inventory(ob);
   for(i=0;i<sizeof(inv);i++)
  {
    if(inv[i]->is_money())
    value +=inv[i]->value();
   }
   if(!value)
   return notify_fail(name()+"身上一分钱都没有呢，你不是难为人吗？\n");
   if(value<100)
   return notify_fail(name()+"对你无奈的耸了耸肩，似乎在说：巧妇难为无米之炊呀。\n");
   message_vision("$N似乎接受了$n的什么命令，一转眼就不见了。\n",ob,me);
//买东西的商店。
   ob->move(PET_MARKING);
   call_out("buy_for_owner",10+random(20),arg);
   return 1;
 }

void buy_for_owner(string arg)
{
object ob,owner,obj;
command("buy "+arg+" from waiter");
ob = this_object();     
obj = present(arg,ob);
if(!obj)
message_vision("$N想来替主人买点什么，但似乎没买到。\n",ob);
else 
message_vision("$N从店小二那里买了一个$n,然后一转眼就不见了。\n",ob,obj);
owner = ob->query("possessed");
if(!objectp(owner))
  {
        save();
    destruct(this_object());    
        }
if(!objectp(environment(owner)))
  {
        save();
    destruct(this_object());    
        }
if(!(ob->move(environment(owner))))
   {
        tell_object(owner,name()+"迷路了，你快去凤求凰客栈领它回来吧。\n");
        return;
    }
obj = present(arg,ob);
if(!obj)
 {
command("sorry "+owner->query("id"));
tell_object(owner,name()+"似乎没有完成你交给它的任务。\n");
return;
 }
command("give "+arg+" to "+owner->query("id"));
message_vision("$N买来一个"+obj->name()+"交给$n，$n感到十分高兴。\n",ob,owner);
return;

}
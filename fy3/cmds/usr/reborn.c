// reborn.c
// yiru@hero
// 重生，请慎重使用此命令。
#include <ansi.h>

inherit F_CLEAN_UP;

int reborn_skill(object ob);
int reborn_attrib(object ob);

string *revive_loc= ({
  "/d/fy/church",
  "/u/guanwai/tower",
});

int main(object me, string arg)
{
	if ( me->query("level") < 101 )
	{
		write(HIY"波也波罗蜜!!!!!\n\n你的等级太低，还无法重生！\n\n\n"NOR);
		return 1;
	}

	if( me->query("reborned") > 5 )
	{
		write(HIY"波也波罗蜜!!!!!\n\n你已经不能再次重生了！\n\n\n"NOR);
		return 1;		
	}
	
	write(HIC"请输入口令：\n"NOR);
	input_to("check_password", 1, me, 1);
	return 1;
}

void check_password(string passwd, object me, int flag)
{
    object link_ob;
    string old_pass;

    link_ob = me->query_temp("link_ob");
    old_pass = link_ob->query("password");

    if ( crypt(passwd, old_pass) != old_pass )
    {
        write(HIM"口令不对。\n"NOR);
        return;
    }

    reborn_skill(me);
    reborn_attrib(me);

    log_file("static/reborn",
      sprintf("%s rebornd once on %s\n",
        me->name_id(), ctime(time()) ) );

    return ;
}

int reborn_skill(object ob)
{
    mapping skills;
    string *sk;
   
	skills = ob->query_skills();
	if (!sizeof(skills))
	{
	    return 1;
	}
	
	sk = keys(skills);
	foreach ( string sname in sk )
	{
		//保留literate的级别
	    if ( sname == "literate" ) continue;
            if ( sname == "incarnation" ) continue;          
	    //其他最高300
	    if ( skills[sname] >= 300 )
	    {
	    	ob->set_skill(sname, 300 );
	    }
        else
	    {
	    	ob->delete_skill(sname);
	    }
	}

    return 1;
}

int reborn_attrib(object ob)
{
object silk;

string *attribs = ({ "tol", "cps", "cor", "con", "per",
      "kar", "str", "fle", "dur", "agi" }); // "int" "spi" 除外

    //清楚判师
	ob->delete("betrayer");
   //回归百姓
    ob->delete("class");
    ob->delete("family");
    ob->set("title", "普通百姓-转世");

    foreach (string attrib in attribs)
    {
        if ( ob->query(attrib) >= 60 )
        {
        	ob->set(attrib, 60);
        }
        else
        {
        	ob->set(attrib, 6);
        }
    }

    ob->set("combat_exp", 1000000);
    ob->set("potential",0);
    ob->set("learned_points",0);
    ob->set("pot_deposit",0);
    ob->set("score", 3000);
    ob->set("used_gift_points",0);
    ob->set("bellicosity", 0);
    ob->set("mud_age", 0);
  ob->set("eatdans", 0);
  ob->set("eatxpd", 0);
  ob->set("eatwqd", 0);
ob->set("alibaoo_over", 0);
ob->set("tiejob",0);



 ob->set("killhyr", 0);
 ob->set("jiebiao", 0);
 ob->set("ftongji", 0);
 ob->set("get_lin_end", 0);
 ob->set("succ_letter_num", 0);
 ob->set("TASK", 0);
 ob->set("bigtasks", 0);
 ob->set("kf_worked", 0);
ob->set("age_modify",0);
ob->set("kf_jiangli",0);
 
	ob->set("max_mana", 0);
	ob->set("max_force", 0);
	ob->set("max_atman", 0);
	ob->set("mana", 0);
	ob->set("force", 0);
	ob->set("atman", 0);

    UPDATE_D->check_user(ob);
    ob->delete("vendetta");
    ob->delete("vendetta_mark");

	ob->set("deposit", 1000000);
	message("system",HIY "\n【系统消息】:"+HIR "忽然间，狂风大作，一道耀眼的红色火光从天而降，天上仿佛落下火雨，瞬间点燃了地面的草木森林,你思绪缥缈，意识竟被导入神的领域。"+ob->name()
    	+"在"+environment(ob)->query("short")+"坐化了。\n" NOR,users());
	message("system",HIY "\n【系统消息】:"+HIG "恭喜"+ob->name()+"重新转世！\n" NOR,users());
	ob->unconcious();
    ob->move(revive_loc[random(sizeof(revive_loc))]);
	ob->set("startroom", base_name(environment(ob)));

	message("vision",
          "你忽然发现前面多了一个人影，不过那人影又好像已经在那里\n"
          "很久了，只是你一直没发觉。\n", environment(ob), ob);

    ob->add("reborned", 1);
silk = new("/obj/prize/f_p");
silk->move(ob);
       
    ob->save();
    return 1;
}

int help(object me)
{
    write(@HELP
指令格式 :
    reborn

保留：
    可以保留技能最大300级（读书和修仙除外）,低于300不保留。基本属性最大60点，才智和灵性除外。
    结婚记录保留,但要玩家重生5次后才可以和另一方相互学习。
    民族保留，神兵保留，大理贡献保留。
清除：
    清除已拜师标志，变为普通百姓。
    清除潜能，清除已存潜能，
    经验减少至1M。

可获得：
    大还丹一个。进宝山杀妖探宝的机会（这个正在增加）
    
    
其他奖励：
 对敌伤害和对伤害的吸收都增加为原来×（1+reborned),
 论做TASK还是quest等，和sc命令里某几个任务，在你的奖励基础上乘以下列值：
 原来的奖励×（1+reborned/5)
 增加2个重生后才能拜的新门派,提高普通百姓才能拜帮派威力.

限制：
重生5次。

HELP);
    return 1;
}

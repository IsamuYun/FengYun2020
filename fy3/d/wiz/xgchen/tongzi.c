#include <ansi.h>
#include <localtime.h>
inherit NPC;
inherit F_VENDOR;
string ask_me();
string ask_zxlw();
string ask_zxlwb();
//string ask_yuandangift();
string ask_zxlwc();
string ask_zxlwd();
string ask_zxlwf();



void create()
{
        set_name(NOR"运财童子"NOR, ({ "tongzi" }) );
        set("long",
                "他是神仙派下来的运财童子。\n");
         set("str", 45);
        set("cor", 45);
        set("title", NOR"观音座下"NOR);
        set("cps", 45);
        set("agi",45);
        set("int",45);
       set("chat_chance", 80);
        set("chat_msg", ({
                "运财童子道：有在线礼物了！[Ask tongzi about all] \n",
                "本站论坛地址为[http://club.xilu.com/happyfy3]。 \n",
                                    }) );

       set("attitude","friendly");
                 set("inquiry", ([
                "新手红包" : (: ask_me :),
                "在线礼物" : (: ask_zxlw :),
             //    "元旦礼物" : (: ask_yuandangift :),
                "在线礼物八十级" : (: ask_zxlwb :),
                "在线礼物一百二十级" : (: ask_zxlwc :),
                "在线礼物一百五十级" : (: ask_zxlwd :),
                "在线礼物一百八十级" : (: ask_zxlwf :),
             


        ]) );
set("combat_exp", 100000000);
            set("chat_chance", 2);
            set_skill("unarmed", 1000);
            set("force", 10000);
            set("max_kee", 1000000);
            set("kee", 1000000);
        set("force_factor", 1500);
    setup();
}
string ask_me()
{
	object ob;

        if ( (int)this_player()->query("hongbao_over") == 22 )
		return RANK_D->query_respect(this_player()) + 
		"不是给你红包了吗?想乱占便宜呀！";
        if ( (int)this_player()->query("hongbao_over") == 1 )
		return RANK_D->query_respect(this_player()) + 
		"你不是已经开过红包了吗?想乱占便宜呀！";
        ob = new("/d/wiz/xgchen/hb.c");
     ob->set("player_id",this_player()->query("id"));
	ob->move(this_player());
        this_player()->set("hongbao_over",22);
            message_vision("$N获得一个沉甸甸的红包。\n",this_player());

        return "希望你努力成为一代大侠。。。。";

}
string ask_zxlw()
{
	object ob;

   
   if ( (int)this_player()->query_skill("idle-force", 1) < 50) 
                return RANK_D->query_respect(this_player()) + 
                "你的发呆神功太差了,再努力提高一下吧，50级、80级、120级、150级、180级各有不同的礼物领取。";
   
    if ( (int)this_player()->query("jine_over") == 22 )
		return RANK_D->query_respect(this_player()) + 
		"不是给你金鹅了吗?想乱占便宜呀！";
        if ( (int)this_player()->query("jine_over") == 1 )
		return RANK_D->query_respect(this_player()) + 
		"你不是得到金鹅了吗?想乱占便宜呀！";
        ob = new("/obj/prize/u_goose.c");
     ob->set("player_id",this_player()->query("id"));
	 ob->move(this_player());
        this_player()->set("jine_over",22);
            message_vision("一只金光闪闪的金鹅飞进$N怀里,忽然不见了。\n",this_player());

        return HIY"一只金光闪闪的金鹅!它可以带来好运!可是退出游戏后将不复存在!"NOR;

}

string ask_zxlwb()
{
	object ob;

   
   if ( (int)this_player()->query_skill("idle-force", 1) < 80) 
                return RANK_D->query_respect(this_player()) + 
                "你的发呆神功太差了,再努力提高一下吧，50级、80级、120级、150级、180级各有不同的礼物领取。";
   
    if ( (int)this_player()->query("jineb_over") == 80 )
		return RANK_D->query_respect(this_player()) + 
		"不是给你金凤凰了吗?想乱占便宜呀！";
        if ( (int)this_player()->query("jineb_over") == 1 )
		return RANK_D->query_respect(this_player()) + 
		"你不是得到金凤凰了吗?想乱占便宜呀！";
        ob = new("/obj/prize/fenghuang.c");
     ob->set("player_id",this_player()->query("id"));
	 ob->move(this_player());
        this_player()->set("jineb_over",80);
            message_vision("一只金光闪闪的金凤凰飞进$N怀里,忽然不见了。\n",this_player());

        return HIY"一只金光闪闪的金凤凰!它可以带来好运!可是退出游戏后将不复存在!"NOR;

}

string ask_zxlwc()
{
	object ob;

   
   if ( (int)this_player()->query_skill("idle-force", 1) < 120) 
                return RANK_D->query_respect(this_player()) + 
                "你的发呆神功太差了,再努力提高一下吧，50级、80级、120级、150级、180级各有不同的礼物领取。";
   
    if ( (int)this_player()->query("jinec_over") == 33 )
		return RANK_D->query_respect(this_player()) + 
		"不是给你金麒麟了吗?想乱占便宜呀！";
        if ( (int)this_player()->query("jinec_over") == 1 )
		return RANK_D->query_respect(this_player()) + 
		"你不是得到金麒麟了吗?想乱占便宜呀！";
        ob = new("/obj/prize/qilin.c");
     ob->set("player_id",this_player()->query("id"));
	 ob->move(this_player());
        this_player()->set("jinec_over",33);
            message_vision("一只金光闪闪的金麒麟飞进$N怀里,忽然不见了。\n",this_player());

        return HIY"一只金光闪闪的金麒麟!它可以带来好运!可是退出游戏后将不复存在!"NOR;

}


string ask_zxlwd()
{
	object ob;

   
   if ( (int)this_player()->query_skill("idle-force", 1) < 150) 
                return RANK_D->query_respect(this_player()) + 
                "你的发呆神功太差了,再努力提高一下吧，50级、80级、120级、150级、180级各有不同的礼物领取。";
   
    if ( (int)this_player()->query("jined_over") == 15 )
		return RANK_D->query_respect(this_player()) + 
		"不是给你金鹏了吗?想乱占便宜呀！";
        if ( (int)this_player()->query("jined_over") == 15 )
		return RANK_D->query_respect(this_player()) + 
		"你不是得到金鹏了吗?想乱占便宜呀！";
        ob = new("/obj/prize/jinpeng.c");
     ob->set("player_id",this_player()->query("id"));
	 ob->move(this_player());
        this_player()->set("jined_over",15);
            message_vision("一只金光闪闪的金鹏飞进$N怀里,忽然不见了。\n",this_player());

        return HIY"一只金光闪闪的金鹏它可以带来好运!可是退出游戏后将不复存在!"NOR;

}


string ask_zxlwf()
{
	object ob;

   
   if ( (int)this_player()->query_skill("idle-force", 1) < 180) 
                return RANK_D->query_respect(this_player()) + 
                "你的发呆神功太差了,再努力提高一下吧，50级、80级、120级、150级、180级各有不同的礼物领取。";
   
    if ( (int)this_player()->query("jinef_over") == 18 )
		return RANK_D->query_respect(this_player()) + 
		"不是给你金龙了吗?想乱占便宜呀！";
        if ( (int)this_player()->query("jinef_over") == 18 )
		return RANK_D->query_respect(this_player()) + 
		"你不是得到金龙了吗?想乱占便宜呀！";
        ob = new("/obj/prize/dragon.c");
     ob->set("player_id",this_player()->query("id"));
	 ob->move(this_player());
        this_player()->set("jinef_over",18);
            message_vision("一只金光闪闪的金龙飞进$N怀里,忽然不见了。\n",this_player());

        return HIY"一只金光闪闪的金龙它可以带来好运!可是退出游戏后将不复存在!"NOR;

}
/*
string ask_yuandangift()
{
        string e_time, week, month, year;
        string c_week, c_year, c_month, c_time;
        int day, hour, minute, second;
        object gift;
        string *month_name = ({"Jan","Feb","Mar","Apr","May","Jun","Jul",
                "Aug","Sep","Oct","Nov","Dec"});
        string *week_name = ({"Mon","Tue","Wed","Thu","Fri","Sat","Sun"});
        if(this_player()->query("yuandangift")>2007)
                   return "你怎么这么贪心啊！\n";
        if ( stringp((string)localtime(time()) ) )
                e_time = (string)localtime(time());
        else e_time = ctime(time());
        sscanf(e_time,"%s %s %d %d:%d:%d %s", week, month, day, hour, minute, second, year);
        c_month = chinese_number(member_array(month, month_name) + 1);
        if(c_month+"月"+chinese_number(day) != "一月一")
                    return "今天是"+c_month+"月"+chinese_number(day)+"日，不是节假日，所以没有礼物发放。\n";

        this_player()->set("yuandangift",2008);
        gift = new("/d/wiz/tiandi/obj/hongbao");
        gift->move(this_player());
        message_vision("$N对着$n说道：谢谢你支持本站并祝你元旦快乐。说完从包里拿出一个红包塞给了$n。\n",this_object(),this_player());
        return "来拿元旦礼物的人还真是多啊。\n";
}
*/


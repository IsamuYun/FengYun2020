//by tiandi，每次修改一下时间即可，也可以做数组的定义，懒。以下两个标签需要每次加1。

#include <ansi.h>
#include <localtime.h>
#define GIFTDATE "十月一"
#define GIFTREASON "国庆日"
inherit NPC;
inherit F_VENDOR;
string ask_yuandangift();
string ask_when();

void create()
{
        set_name(NOR"礼物使者"NOR, ({ "gifter" }) );
        set("long",
                "他是快乐风云的礼物使者，逢年过节的都会发放礼物哦。\n");
         set("str", 45);
        set("cor", 45);
        set("title", NOR"快乐风云"NOR);
        set("cps", 45);
        set("agi",45);
        set("per",105);
       set("attitude","friendly");
                 set("inquiry", ([
                 "节日礼物" : (: ask_yuandangift :),
	     "发放时间" : (: ask_when :),
	  "节日详细":GIFTDATE+"日是"+GIFTREASON+"。",
        ]) );
set("combat_exp", 1);
    setup();
}
string ask_yuandangift()
{
        string e_time, week, month, year;
        string c_week, c_year, c_month, c_time;
        int day, hour, minute, second;
        object gift;
        string *month_name = ({"Jan","Feb","Mar","Apr","May","Jun","Jul",
                "Aug","Sep","Oct","Nov","Dec"});
        string *week_name = ({"Mon","Tue","Wed","Thu","Fri","Sat","Sun"});
	   if(this_player()->query("level") < 10)          // limtied exp >400k
                   return "你的等级太低，先去再练练回头再来拿吧！\n";

        if(this_player()->query("getgiftno")>4)          // EVERY TIME CHANGE THIS VALUE +1
                   return "你怎么这么贪心啊！\n";
        if ( stringp((string)localtime(time()) ) )
                e_time = (string)localtime(time());
        else e_time = ctime(time());
        sscanf(e_time,"%s %s %d %d:%d:%d %s", week, month, day, hour, minute, second, year);
        c_month = chinese_number(member_array(month, month_name) + 1);
        if(c_month+"月"+chinese_number(day) != GIFTDATE)
                    return "今天是"+c_month+"月"+chinese_number(day)+"日，不是节假日，所以没有礼物发放。\n";

        this_player()->set("getgiftno",5);        //EVERY TIME ADD 1
        gift = new("/d/wiz/tiandi/obj/hongbao");
        gift->move(this_player());
        gift->set_temp("giftowner",this_player()->query("name"));
//message_vision(gift->query_temp("giftowner")+"\n",this_player());
        message_vision("$N对着$n说道：谢谢你支持本站并祝你节日快乐。说完从包里拿出一个红包塞给了$n。\n",this_object(),this_player());
        return "来拿节日礼物的人还真是多啊。\n";
}
string ask_when()
{
	 message_vision("$N对着$n说道：下一次发放礼物的时间为"+GIFTDATE+"日。\n",this_object(),this_player());
	 return "记得来拿哦，过了日子可就没有了。\n";
}


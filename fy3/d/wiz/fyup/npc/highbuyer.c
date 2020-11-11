inherit NPC;
#include <ansi.h>
string doing();
string *item = ({
"香油酥",
"大饼",
"麻饼",
"金翠角",
"云丝卷",
"成仙卷",
"麦芽黄",
"金香圈",
"逸君仙丹",
"黑糊糊的东西",
"五皇丹",
"墨成丹",
"朝天神丹",
"金香玉丹",
"返生丹",
"雀香仙丹",
"翎玉仙丹",
"灵泉圣丹",
"月牙刀",
HIW"白苗刀"NOR,
MAG"夜月魔刀"NOR,
HIG"柳叶刀"NOR,
RED"泣血刀"NOR,
YEL"如觉刀"NOR,
CYN"青龙堰月刀"NOR,
HIY"晓月斩风"NOR,
HIR"火云怒刃"NOR,
HIC "邪神霸刀"NOR,
"明剑",
HIW"紫玉剑"NOR,
MAG"潇湘剑"NOR,
HIG"无花碎剑"NOR,
RED"红云剑"NOR,
YEL"冷月"NOR,
CYN"藏风"NOR,
HIY"五月开天"NOR,
HIR"落雪有痕"NOR,
HIC "鳞水碧波"NOR,
"八角禅杖",
HIW"黏虚禅杖"NOR,
MAG"丞相杖"NOR,
HIG"天月禅杖"NOR,
	RED"无风杖"NOR,
	YEL"算命"NOR,
	CYN"化光"NOR,
	HIY"漫天风雪"NOR,
	HIR"无花无心"NOR,
	HIC "乾坤无量"NOR,
	"铁爪拳套",
	HIW"虎爪拳套"NOR,
	 MAG"钢铁拳套"NOR,
	 HIG"翔龙刃"NOR,
	 RED"鬼手"NOR,
	YEL"霹雳拳套"NOR,
	CYN"凤凰刃"NOR,
	HIY"阎王索命"NOR,
	HIR"碎石断山"NOR,
	HIC "缘定江山"NOR,
	 "傲云衫",
	 HIW"轻云和服"NOR,
	MAG"狂沙劲衫"NOR,
	HIG"叶纹袄"NOR,
	 RED"夜隐甲"NOR,
	 YEL"天璇轻衣"NOR,
	CYN"瑜玉战铠"NOR,
	 HIY"麒麟战甲"NOR,
	 HIR"玄皿魔袍"NOR,
	 HIC "修罗披风"NOR,
	 "麻布头巾",
	HIW"厚棉头巾"NOR,
	 MAG"无边帽"NOR,
	HIG"锦绣帽"NOR,
	 RED"向阳帽"NOR,
	YEL"黔首皮帽"NOR,
	CYN"零花箍"NOR,
	HIY"神皮帽"NOR,
	 HIR"凤羽冠"NOR,
	HIC "龙麟冠"NOR,
	 "护身项链",
	 HIW"双色彩链"NOR,
	 MAG"玫瑰链"NOR,
	HIG"神木珠"NOR,
	RED"笑傲江湖"NOR,
	 YEL"漂渺法珠"NOR,
	 CYN"灵月仙舞"NOR,
	HIY"碧水铃"NOR,
	 HIR"乾坤镜"NOR,
	HIC "祥云之风"NOR,
	"羊皮靴",
	 HIW"牛皮靴"NOR,
	 MAG"神步鞋"NOR,
	 HIG"神行跨龙"NOR,
	RED"侠客靴"NOR,
	YEL"追日靴"NOR,
	 CYN"战月神履"NOR,
	 HIY"龙虎战履"NOR,
	 HIR"踏雪无痕"NOR,
	HIC "凌空虚渡"NOR,
	 "铁戒",
	  HIW"梅花戒"NOR,
	MAG"如痴戒指"NOR,
	HIG"虎戒"NOR,
	RED"梦灭戒指"NOR,
	 YEL"绝情戒"NOR,
	CYN"霹雳雷霆"NOR,
	 HIY"道道"NOR,
	HIR"七彩飞石"NOR,
	 HIC "龙神戒指"NOR,
	"细腰带",
	HIW"粗腰带"NOR,
	MAG"麻布腰带"NOR,
	 HIG"蛇皮腰带"NOR,
	RED"白鹿腰带"NOR,
	  YEL"虎皮腰带"NOR,
	 CYN"摄魂布"NOR,
	 HIY"帝王腰带"NOR,
	HIR"蛮山带"NOR,
	HIC "幻云仙带"NOR,
	 "铁盾",
	 HIW"钢盾"NOR,
	MAG"玄铁盾"NOR,
	 HIG"大名盾"NOR,
	 RED"蛇蜥盾"NOR,
	  YEL"珊瑚盾"NOR,
	 CYN"天云战盾"NOR,
	HIY"幽灵盾"NOR,
	 HIR"蓝岚盾"NOR,
	 HIC "元成霸盾"NOR,
	 "钢铁护腕",
	 HIW"勇者护腕"NOR,
	 MAG"天青刺"NOR,
	HIG"苗峰护腕"NOR,
	RED"百战神风"NOR,
	 YEL"美人护腕"NOR,
	 CYN"喧天柄"NOR,
	HIY"魉单"NOR,
	  HIR"侠骨道风护腕"NOR,
	HIC "侠骨柔风护腕"NOR,
   });

void create()
{
	set_name(HIY "马老板" NOR, ({ "ma", "boss ma" }) );

	set("gender", "男性");
	set("age", 35);
	set("long",
		"神出鬼没的商人，通常以高于市价的价格收购某样东西．\n");
	set("attitude", "peaceful");
	set("str", 100);
	set("per", 130);
	set("int", 100);
	set("cps", 30);
	set("canbuy",10);
	set("buywhat","无");
	set("combat_exp", 1300000);
	set("inquiry", ([ "收购商品" : (: doing :)
	  ]));

          set("title", HIC"高价收购商"NOR);
	setup();
}
void init()
{
		if (!this_object()->query_temp("markd"))
		{
		set("buywhat",item[random(sizeof(item))]);
		set_temp("markd",1);
		command("chat 现在开始高价收购"+query("buywhat")+"，本人只在"+environment(this_object())->query("short")+"停留五分钟。");
      	remove_call_out("leave");
        call_out("leave",300);

		}
}
int accept_object(object who, object ob)
{
        object gift,gold,me;
		
        int  val, extra, reb,ti,doubletime,doubletype;
	string test,file,*name;
	mapping quest;
	me = this_object();

        if( me ->query("canbuy") < 1)
	{
        tell_object(who,"马老板说道：我已经收到十样了，朋友你来晚了。\n");
	return 0;
	}
        if( (string)ob->query("name") != me->query("buywhat"))
        {
        tell_object(who,"马老板说道：这好像。。。不是我想要的东西吧。\n");
        return 0;
        }
	if( ob->is_character())
        {
        tell_object(who,"马老板说道：朋友，你这算什么意思。\n");
        return 0;
        }
        else
        {
		val = me->query("canbuy")*50;
        tell_object(who,"马老板说道：恭喜你，你是第"+(int)(11-query("canbuy"))+"位来交物品的，奖励你"+val+"两金子。\n");
    me->add("canbuy",-1);
	who->add("buyjob",1);
	//by tiandi 08.1.30修正，删除已经交掉的自造物品
	if (ob->query("selfmaking"))
	{
	seteuid(ROOT_UID);
	rm(base_name(ob) + ".o");
	rm(base_name(ob) + ".c");
	ob->move(environment(who));
	destruct(ob);
	seteuid(getuid());
	}
	gold = new("/obj/money/gold");
	gold ->set_amount(val);
	doubletime = who->query("doubletime");
	doubletype = (int)who->query("doubletype");
	if (doubletime - time() > 0){
		gold ->set_amount((doubletype+1)*val);
	  	tell_object(who,HIW"你被奖励了" +
		chinese_number((doubletype+1)*val) + "两黄金。\n" NOR);
		}
	else
			{
		tell_object(who,HIW"你被奖励了：\n" +
		chinese_number(val) + "两黄金。\n" NOR);
			}
	gold->move(who);
		}
    return 1;
}
void leave()
{
        object ob = this_object();
			command("chat 今天就到这里了，我要回去赶货了。");
	        message_vision(HIC "马老板走了。\n" NOR,this_object());
            destruct(this_object());     
}
string doing()
{
	object me = this_object();
	int val;
	val = me->query("canbuy")*25;
	return "下一个"+query("buywhat")+"我以"+chinese_number(val)+"两黄金的价格来收购。";
	
}
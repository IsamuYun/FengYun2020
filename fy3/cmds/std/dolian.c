// dolian.c written by Tiandi
#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me)
{
        object obj,ob1,ob2,ob3,ob4,ob5;
        string name;
        int i,tili,lv,tili_cost,exp;

        exp = (int)me->query("lifedoctor_exp") ;
        if (!exp) exp =0;
        lv = (int)me->query("lifedoctor");
        if(lv < 1)
           return notify_fail("什麽？\n");
        name = me->query("name");
        tili = (int)me->query("lifetili");
        tili_cost = 120 - lv;
		tili_cost = tili_cost /10*(10-me->query("save_for_doctor"));
        if( me->is_busy() )
           return notify_fail("你上一个动作还没有完成！\n");
        if( environment(me)->query("no_cook") )
           return notify_fail("这里无法进行炼丹。\n");
       
        if( me->is_fighting() )
           return notify_fail("战斗中炼丹？想死啊！\n");

        if( me->query("lifetili") < tili_cost )
           return notify_fail("活力不够。\n");
        ob1 = present("pilosulae",me);
        if (!ob1) return notify_fail("缺少杞子。\n");
        ob2 = present("dioscoreae",me);
        if (!ob2) return notify_fail("缺少淮山。\n");
        ob3 = present("codonopsis",me);
        if (!ob3) return notify_fail("缺少党参。\n");
        ob4 = present("astragalt",me);
        if (!ob4) return notify_fail("缺少北芪。\n");
        ob5 = present("lycii",me);
        if (!ob5) return notify_fail("缺少当归。\n");
        me->set("lifetili",tili - tili_cost );

        if( ob1 && ob2 && ob3 && ob4 && ob5  ) {
           message_vision("$N将一些中药放入丹鼎中，左手运起一股掌风，朝火苗处打去，火候顿时恰到好处，接着只见$N盘腿而\n坐，双手合成十字，口中不停地默默念起一段咒语，一道金光射入丹鼎，低沉的轰鸣声渐渐响起！\n\n",me);
           destruct(ob1);
           destruct(ob2);
           destruct(ob3);
           destruct(ob4);
           destruct(ob5);
           call_out("give_yao",5,me,lv,exp,name);
           me->start_busy(5);
           return 1;
        }
}

private void give_yao(object me,int lv,int exp,string name)
{
        object obj;
        switch( random((lv+1))%10 ) {
        case 0:
        message_vision("$N小心翼翼地打开丹鼎，结果发现了一堆黑糊糊的东西。\n", me);
        obj=new("/obj/food/dan0");
        obj->set("long","一堆由"+ name +"亲手炼丹而来的黑糊糊的东西，这东西能吃吗，还是赶紧扔了吧。\n");
        obj->move(me);
        break;
        case 1:
        message_vision("刹那间，丹鼎亮起耀眼的金光，将四周照得一片通明，在满天剑光宝气的映衬下，所有的人和物仿佛都变成了绚烂夺目的灯花。\n",me);
        obj=new("/obj/food/dan1");
        obj->set("long","一颗由"+ name +"亲手炼丹而来的五皇丹。据说食用之后可以恢复少量内力。\n");
        obj->move(me);
        me->set("lifedoctor_exp",exp+1);
        break;
        case 2:
        message_vision("刹那间，丹鼎亮起耀眼的金光，将四周照得一片通明，在满天剑光宝气的映衬下，所有的人和物仿佛都变成了绚烂夺目的灯花。\n",me);
        obj=new("/obj/food/dan2");
        obj->set("long","一颗由"+ name +"亲手炼丹而来的墨成丹。据说食用之后可以恢复少量法力。\n");
        obj->move(me);
        me->set("lifedoctor_exp",exp+1);
        break;
        case 3:
        message_vision("刹那间，丹鼎亮起耀眼的金光，将四周照得一片通明，在满天剑光宝气的映衬下，所有的人和物仿佛都变成了绚烂夺目的灯花。\n",me);
        message_vision("$N小心翼翼地打开丹鼎，结果发现了一颗"HIM + "朝天神丹" + NOR"，$N大喜，连忙把丹药揣入怀中。\n", me);
        obj=new("/obj/food/dan3");
        obj->set("long","一颗由"+ name +"亲手炼丹而来的朝天神丹。据说食用之后可以恢复适量内力。\n");
        obj->move(me);
        me->set("lifedoctor_exp",exp+2);
        break;
        case 4:
        message_vision("刹那间，丹鼎亮起耀眼的金光，将四周照得一片通明，在满天剑光宝气的映衬下，所有的人和物仿佛都变成了绚烂夺目的灯花。\n",me);
        message_vision("$N小心翼翼地打开丹鼎，结果发现了一颗"HIM + "金香玉丹" + NOR"，$N大喜，连忙把丹药揣入怀中。\n", me);
        obj=new("/obj/food/dan4");
        obj->set("long","一颗由"+ name +"亲手炼丹而来的金香玉丹。据说食用之后可以恢复适量法力。\n");
        obj->move(me);
        me->set("lifedoctor_exp",exp+2);
        break;
        case 5:
        message_vision("丹鼎在隆隆声中越来越大，很快，一座七米多高的大鼎炉矗立在丹台上。金光渐渐淡去，红光\n闪动间，热浪阵阵涌出，丹台被一股巨大的热流包裹起来。\n",me);
        message_vision("$N小心翼翼地打开丹鼎，结果发现了一颗"HIM + "雀香仙丹" + NOR"，$N大喜，连忙把丹药揣入怀中。\n", me);
        obj=new("/obj/food/dan5");
        obj->set("long","一颗由"+ name +"亲手炼丹而来的雀香仙丹。据说食用之后可以恢复大部分消耗的内力。\n");
        obj->move(me);
        me->set("lifedoctor_exp",exp+3);
        break;
        case 6:
        message_vision("丹鼎在隆隆声中越来越大，很快，一座七米多高的大鼎炉矗立在丹台上。金光渐渐淡去，红光\n闪动间，热浪阵阵涌出，丹台被一股巨大的热流包裹起来。\n",me);
        message_vision("$N小心翼翼地打开丹鼎，结果发现了一颗"HIM + "逸君仙丹" + NOR"，$N大喜，连忙把丹药揣入怀中。\n", me);
        obj=new("/obj/food/dan6");
        obj->set("long","一颗由"+ name +"亲手炼丹而来的逸君仙丹。据说食用之后可以恢复大部分消耗的法力。\n");
        obj->move(me);
        me->set("lifedoctor_exp",exp+3);
        break;
        case 7:
        message_vision("丹鼎在隆隆声中越来越大，很快，一座七米多高的大鼎炉矗立在丹台上。金光渐渐淡去，红光\n闪动间，热浪阵阵涌出，丹台被一股巨大的热流包裹起来。\n",me);
        message_vision("$N小心翼翼地打开丹鼎，结果发现了一颗"HIM + "翎玉仙丹" + NOR"，$N大喜，连忙把丹药揣入怀中。\n", me);
        obj=new("/obj/food/dan7");
        obj->set("long","一颗由"+ name +"亲手炼丹而来的翎玉仙丹。据说食用之后可以恢复大量消耗的内力。\n");
        obj->move(me);
        me->set("lifedoctor_exp",exp+4);
        break;
        case 8:
        message_vision("丹鼎开始缩小，大约缩小到一半时，文丹之火稳定下来，$N长出了一口气，他已经完全控制了丹鼎的本源之火。\n咆哮炙热的罡风笔直地从洞口喷出，并伴随着隐隐的霹雳声，周围的热流就像沸腾的钢水一般。\n",me);
        message_vision("$N小心翼翼地打开丹鼎，结果发现了一颗"HIM + "灵泉圣丹" + NOR"，$N大喜，连忙把丹药揣入怀中。\n", me);
        obj=new("/obj/food/dan8");
        obj->set("long","一颗由"+ name +"亲手炼丹而来的灵泉圣丹。据说食用之后可以恢复大量消耗的法力。\n");
        obj->move(me);
        me->set("lifedoctor_exp",exp+4);
        break;
		case 9:
        message_vision("丹鼎在隆隆声中越来越大，很快，一座七米多高的大鼎炉矗立在丹台上。金光渐渐淡去，红光\n闪动间，热浪阵阵涌出，丹台被一股巨大的热流包裹起来。\n",me);
        message_vision("$N小心翼翼地打开丹鼎，结果发现了一颗"HIM + "返生丹" + NOR"，$N大喜，连忙把丹药揣入怀中。\n", me);
        obj=new("/obj/food/dan9");
        obj->set("long","一颗由"+ name +"亲手炼丹而来的返生丹。据说食用之后可以使人恢复部分活力。\n");
        obj->move(me);
        me->set("lifedoctor_exp",exp+5);
        break;
        default:
        message_vision("$N小心翼翼地打开丹鼎，结果发现了一堆黑糊糊的东西。\n", me);
        break;
        }
        exp = (int)me->query("lifedoctor_exp") ;
		if (lv == 20)
		{
	        me->set("lifedoctor_exp",0);
		}
        if (exp > lv*lv*16) {
        me->set("lifedoctor_exp",0);
        me->set("lifedoctor",lv+1);
        write(HIW"你的炼丹技巧进步了！\n"NOR);
		if (me->query("lifedoctor")==20)
			message("system",HIC "\n【快乐风云】谜题任务："+me->query("name")+"由于在炼丹技巧上的成就，获得了"HIY"【医死人不偿命】"HIC"的称号。\n" NOR,users());
			me->add("score",10000);
			write(HIW"你的评价增加了一万点！\n"NOR);
        }
        me->start_busy(5);
}

int help(object me)
{
        write(@HELP
指令格式 : dolian 

这个指令可以让你利用自己的炼丹技巧做一些丹药.

HELP
    );
        return 1;
}

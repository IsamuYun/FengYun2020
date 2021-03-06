#include <ansi.h>
#define TIME_TICK ((time()-890000000)*60)
#define TIME_TICK1 ((time()-900000000)*60)
// TIME_TICE1 also use in move.c look.c
static int current_day_phase;
mapping *day_phase;

string *weather_msg = ({
        "天空中万里无云",
        "几朵淡淡的云彩妆点著清朗的天空",
        "白云在天空中飘来飘去",
        "厚厚的云层堆积在天边",
        "天空中乌云密布",
});

mapping *read_table(string file);
void init_day_phase();

void create()
{
        day_phase = read_table("/adm/etc/nature/day_phase");
        init_day_phase();
}

void init_day_phase()
{
        mixed *local;
        int i, t;

        // Get minutes of today.
        local = localtime(TIME_TICK1);
        t = local[2] * 60 + local[1];           // hour * 60 + minutes

        // Find the day phase for now.
        for( i=0; i < sizeof(day_phase); i++)
                if( t >= day_phase[i]["length"] )
                        t -= (int)day_phase[i]["length"];
                else
                        break;

        current_day_phase = (i==0? sizeof(day_phase)-1: i - 1);

        // Since in our time scale, 1 minute == 1 second in RL, so we don't need
        // any conversion before using this number as call_out dalay, if you
        // changed the time scale, be sure to convert it.

        call_out("update_day_phase",
      (int)day_phase[(current_day_phase+1) % sizeof(day_phase)]["length"] - t);
}

void update_day_phase()
{
        remove_call_out("update_day_phase");

        current_day_phase = (++current_day_phase) % sizeof(day_phase);
        switch (day_phase[current_day_phase]["outcolor"])
        {
              case "BLK":
                   message("channel:chat", HIG"〖风云天空〗"BLK + day_phase[current_day_phase]["time_msg"] + "\n"NOR, users());
                   break;
              case "RED":
                   message("channel:chat", HIG"〖风云天空〗"RED + day_phase[current_day_phase]["time_msg"] + "\n"NOR, users());
                   break;
              case "HIR":
                   message("channel:chat", HIG"〖风云天空〗"HIR + day_phase[current_day_phase]["time_msg"] + "\n"NOR, users());
                   break;
              case "GRN":
                   message("channel:chat", HIG"〖风云天空〗"GRN + day_phase[current_day_phase]["time_msg"] + "\n"NOR, users());
                   break;
              case "HIG":
                   message("channel:chat", HIG"〖风云天空〗"HIG + day_phase[current_day_phase]["time_msg"] + "\n"NOR, users());
                   break;
              case "YEL":
                   message("channel:chat", HIG"〖风云天空〗"YEL + day_phase[current_day_phase]["time_msg"] + "\n"NOR, users());
                   break;
              case "HIY":
                   message("channel:chat", HIG"〖风云天空〗"HIY + day_phase[current_day_phase]["time_msg"] + "\n"NOR, users());
                   break;
              case "BLU":
                   message("channel:chat", HIG"〖风云天空〗"BLU + day_phase[current_day_phase]["time_msg"] + "\n"NOR, users());
                   break;
              case "HIB":
                   message("channel:chat", HIG"〖风云天空〗"HIB + day_phase[current_day_phase]["time_msg"] + "\n"NOR, users());
                   break;
              case "MAG":
                   message("channel:chat", HIG"〖风云天空〗"MAG + day_phase[current_day_phase]["time_msg"] + "\n"NOR, users());
                   break;
              case "HIM":
                   message("channel:chat", HIG"〖风云天空〗"HIM + day_phase[current_day_phase]["time_msg"] + "\n"NOR, users());
                   break;
              case "CYN":
                   message("channel:chat", HIG"〖风云天空〗"CYN + day_phase[current_day_phase]["time_msg"] + "\n"NOR, users());
                   break;
              case "HIC":
                   message("channel:chat", HIG"〖风云天空〗"HIC + day_phase[current_day_phase]["time_msg"] + "\n"NOR, users());
                   break;
              case "WHT":
                   message("channel:chat", HIG"〖风云天空〗"WHT + day_phase[current_day_phase]["time_msg"] + "\n"NOR, users());
                   break;
              case "HIW":
                   message("channel:chat", HIG"〖风云天空〗"HIW + day_phase[current_day_phase]["time_msg"] + "\n"NOR, users());
                   break;
              default:
                   message("channel:chat", HIG"〖风云天空〗"HIG + day_phase[current_day_phase]["time_msg"] + "\n"NOR, users());
                   break;
        }
//        message("outdoor:vision", day_phase[current_day_phase]["time_msg"] + "\n", users());
        if( !undefinedp(day_phase[current_day_phase]["event_fun"]) )
            call_other(this_object(), day_phase[current_day_phase]["event_fun"]);

        call_out("update_day_phase", day_phase[current_day_phase]["length"]);
}
void event_midnight()
{
	object badguy;
	object room;
	if(!random(10))
	{
        	if(objectp(room=load_object("/d/fy/fysquare")) && 
		objectp(badguy = new("/d/fy/npc/badguy")))
		badguy->move(room);
		badguy->ccommand("chat 月黑杀人，风高放火！");
		badguy = new("/d/fy/npc/badguy");
		badguy->move(room);
                badguy = new("/d/fy/npc/badguy");
                badguy->move(room);
	}
        if(!random(10))
        {
                if(objectp(room=load_object("/d/chenxiang/cxcenter")) && 
                objectp(badguy = new("/d/fy/npc/badguy")))
                badguy->move(room);
                badguy->ccommand("chat 月黑杀人，风高放火！");
                badguy = new("/d/fy/npc/badguy");
                badguy->move(room);
        }
        if(!random(10))
        {
                if(objectp(room=load_object("/u/guanwai/octo4")) && 
                objectp(badguy = new("/d/fy/npc/badguy")))
                badguy->move(room);
                badguy->ccommand("chat 月黑杀人，风高放火！");
                badguy = new("/d/fy/npc/badguy");
                badguy->move(room);

        }
/*        if(!random(10))
        {
                if(objectp(room=load_object("/d/dali/dalicenter")) && 
                objectp(badguy = new("/d/fy/npc/badguy")))
                badguy->move(room);
                badguy->ccommand("chat 月黑杀人，风高放火！");
                badguy = new("/d/fy/npc/badguy");
                badguy->move(room);
                badguy = new("/d/fy/npc/badguy");
                badguy->move(room);
        }*/
}
void event_sunrise()
{
	object *ob_list;
	int i;
	ob_list = children("/d/fy/npc/badguy");
                for(i=0; i<sizeof(ob_list); i++) 
		if(environment(ob_list[i]))
		{
		message_vision("$N叫道：天晓也，扯乎！\n",ob_list[i]);
			destruct(ob_list[i]);
                }
}
void event_dawn()
{
        object room;
	room = find_object("/d/qianjin/qianjin.c");
        if( !room) room = load_object("/d/qianjin/qianjin.c");
        if(room)
        room->set("enter_permission", 0);
        return;
}
// This is called everyday evening by update_day_phase, defined in the
// "event_fun" field in /adm/etc/nature/day_phase
void event_evening()
{
        object room,npc;
        string file,location,*roomlines;

	room = find_object("/d/qianjin/qianjin.c");
        if( !room) room = load_object("/d/qianjin/qianjin.c");
        if( room )
        room->set("enter_permission", 1);

		npc = new("/d/wiz/fyup/npc/japanese");
		file = read_file("/tongji/dynamic_location");
        roomlines = explode(file,"\n"); 
        location = roomlines[random(sizeof(roomlines))];
        if( catch(load_object(location)) || !load_object(location) )   
	{
			CHANNEL_D->do_channel( npc,"rumor", "据说东瀛人来到了中土后碰上了黑衣蒙面高手直接被K.O回去了。。\n" NOR);
			return ;
	}
		npc->move(location);
		CHANNEL_D->do_channel( npc,"sys", sprintf(WHT "东瀛人来到了("HIC"%s" WHT ")。\n" NOR,location));
		CHANNEL_D->do_channel( npc,"rumor", "据说东瀛人来到了中土的"+environment(npc)->query("short")+"附近。\n" NOR);
        return;

}
void event_noon()
{
        object *ob;
        int i, skill,con,con1,con2,con3;
        string get_month,ill,msg;
        get_month = CHINESE_D->chinese_month(TIME_TICK1);
        switch(get_month)
        {
                case "三":
                case "四":
                case "五":
                     ill = "ill_kesou";
                     msg = HIG + "忽然喉头一阵痕痒，你感觉似乎要咳嗽了。\n" + NOR;
                     break;
                case "六":
                case "七":
                case "八":
                     ill = "ill_zhongshu";
                     msg = HIG+"突然你胸臆之间一阵翻腾，你中暑了。\n" + NOR;
                     break;
                case "九":
                case "十":
                case "十一":
                     ill = "ill_shanghan";
                     msg = HIG+"陡的你打了个冷战，头昏沉沉的，你得伤寒病了。\n"+NOR;
                     break;
                case "十二":
                case "一":
                case "二":
                     ill = "ill_dongshang";
                     msg = HIG+"你肢体末端一阵僵直，看来你被冻伤了。\n"+NOR;
                     break;
        }
        if(random(2))
        {
                ill = "ill_fashao";msg = HIG+"你偶感风寒，竟而发起烧来。\n"+NOR;
        }
        ob = users();
        for(i=0; i<sizeof(ob); i++)
        {
               if(ob[i]->query("env/prompt")=="time")tell_object(ob[i], "");
                          if( !environment(ob[i]) ) continue;
                if( !environment(ob[i])->query("outdoors") ) continue;
                if( ob[i]->query("age")==14 ) continue;
                con1 = ob[i]->query("kee");
                con2 = ob[i]->query("max_kee");
                (int)con = con1/con2*50;//形成第一个生病判断条件
                con3 = ob[i]->query("force");
                con2 = ob[i]->query("max_force");
                if( con2 == 0) con2 = 1;
                (int)con1 = con3/con2*50;//形成第二个生病判断条件
                if(random(con)+random(50)+random(con1)<25)
                {
                        ob[i]->apply_condition(ill, 10);
                        tell_object(ob[i], msg);
                }
        }
}

string outdoor_room_description()
{
        return WHT"   〖风云天空〗 " + day_phase[current_day_phase]["desc_msg"] + "。\n"NOR;
}
string outdoor_room_outcolor()
{
        return day_phase[current_day_phase]["outcolor"];
}

string game_time()
{
        return CHINESE_D->chinese_date(TIME_TICK1);
}

mapping *read_table(string file)
{
        string *line, *field, *format;
        mapping *data;
        int i, rn, fn;

        line = explode(read_file(file), "\n");
        data = ({});
        for(i=0; i<sizeof(line); i++) {
                if( line[i]=="" || line[i][0]=='#' ) continue;
                if( !pointerp(field) ) {
                        field = explode( line[i], ":" );
                        continue;
                }
                if( !pointerp(format) ) {
                        format = explode( line[i], ":" );
                        continue;
                }
                break;
        }

        for( rn = 0, fn = 0; i<sizeof(line); i++) {
                if( line[i]=="" || line[i][0]=='#' ) continue;
                if( !fn ) data += ({ allocate_mapping(sizeof(field)) });
                sscanf( line[i], format[fn], data[rn][field[fn]] );
                fn = (++fn) % sizeof(field);
                if( !fn ) ++rn;
        }
        return data;
}

mapping *query_day_phase() { return day_phase; }

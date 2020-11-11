#include <ansi.h>
#define TIME_TICK (time())
static int current_day_phase;
mapping *day_phase;

string *weather_msg = ({
        "�������������",
	"���䵭�����Ʋ�ױ�������ʵ����",
	"�����������Ʈ��Ʈȥ",
	"�����Ʋ�ѻ������",
	"����������ܲ�",
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
	local = localtime(TIME_TICK);
	t = local[2] * 60 + local[1];
	for( i=0; i < sizeof(day_phase); i++)
		if( t >= day_phase[i]["length"] )
			t -= (int)day_phase[i]["length"];
		else	break;
	current_day_phase = (i==0? sizeof(day_phase)-1: i - 1);
	call_out("update_day_phase",
    (int)day_phase[(current_day_phase+1) % sizeof(day_phase)]["length"] - t);
}

void update_day_phase()
{
	remove_call_out("update_day_phase");
	current_day_phase = (++current_day_phase) % sizeof(day_phase);
        message("outdoor:vision", day_phase[current_day_phase]["time_msg"] + "\n", users());
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
		badguy->ccommand("chat �º�ɱ�ˣ���߷Ż�");
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
                badguy->ccommand("chat �º�ɱ�ˣ���߷Ż�");
                badguy = new("/d/fy/npc/badguy");
                badguy->move(room);
        }
        if(!random(10))
        {
                if(objectp(room=load_object("/u/guanwai/octo4")) && 
                objectp(badguy = new("/d/fy/npc/badguy")))
                badguy->move(room);
                badguy->ccommand("chat �º�ɱ�ˣ���߷Ż�");
                badguy = new("/d/fy/npc/badguy");
                badguy->move(room);
                badguy = new("/d/fy/npc/badguy");
                badguy->move(room);
        }
        if(!random(10))
        {
                if(objectp(room=load_object("/d/dali/dalicenter")) && 
                objectp(badguy = new("/d/fy/npc/badguy")))
                badguy->move(room);
                badguy->ccommand("chat �º�ɱ�ˣ���߷Ż�");
                badguy = new("/d/fy/npc/badguy");
                badguy->move(room);
                badguy = new("/d/fy/npc/badguy");
                badguy->move(room);
        }
}

void event_sunrise()
{
	object *ob_list;
	int i;
	ob_list = children("/d/fy/npc/badguy");
                for(i=0; i<sizeof(ob_list); i++) 
		if(environment(ob_list[i]))
		{
		message_vision("$N�е�������Ҳ��������\n",ob_list[i]);
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

void event_evening()
{
        object room;
        object tongji;
        tongji = new("/tongji/npc/zhuge");
     tongji->ccommand("chat ��ͥ�����ؽ���ʮ����ˣ�����Ӣ���붦��������");
        destruct(tongji);
	room = find_object("/d/qianjin/qianjin.c");
        if( !room) room = load_object("/d/qianjin/qianjin.c");
        if( room )
        room->set("enter_permission", 1);
        return;
}

void event_noon()
{
	object *ob;
	int i, skill;
	ob = users();
	for(i=0; i<sizeof(ob); i++) {
		if( !environment(ob[i]) ) continue;
		if( !environment(ob[i])->query("outdoors") ) continue;
		if( !ob[i]->query("mana") ) continue;
		if( !(skill = ob[i]->query_skill("spells", 1) )) {
    tell_object(ob[i], "�����һ����ѣ��������һ�����������ϱ��������ˡ�\n");
			ob[i]->set("mana", 0);
			ob[i]->receive_damage("sen", 0);
		} else if( skill < 25 ) {
		tell_object(ob[i], "����ʱ�̣��������ķ�����ʼ��ʧ�ˡ�\n");
		ob[i]->set("mana", (int)ob[i]->query("mana") * skill / 25 );
		}
	}
}

string outdoor_room_description()
{
	return "    " + day_phase[current_day_phase]["desc_msg"] + "��\n";
}

string game_time()
{
	return CHINESE_D->chinese_date(TIME_TICK);
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

// story:songdai.c

#include <ansi.h>

string give_gift();

private mixed *story = ({
        "ɽ����ʮ�����ֵܣ���˵�����Ļ����ﲻ����",
        "��̫�ɣ��ǰ������������в����书��ǿ֮�ˣ�����ȥ����",
        "ɽ����ʮ������Ҳ�Ǹ����⣬�����������ɵ���ȥ̽��̽������û�и��֡�",
        "��̫�ɣ������Ƚ�����һ�㡣",
        "ɽ����ʮ�������˰���ȥ��������̽��һ�����ָ��ֵķֲ������",
        "�ǣ�",

        (: give_gift :)
});

void create()
{
        seteuid(getuid());
}

mixed query_story_message(int step)
{
        return step < sizeof(story) ? story[step] : 0;
}

string give_gift()
{
        object npc;
        string file,location,*roomlines;

		npc = new("/d/wiz/fyup/npc/japanese");
		file = read_file("/tongji/dynamic_location");
        roomlines = explode(file,"\n"); 
        location = roomlines[random(sizeof(roomlines))];
        if( catch(load_object(location)) || !load_object(location) )   
			return HIM "��˵����������������������˺�����ֱ�ӱ�K.O��ȥ�ˡ�\n"NOR;               
		npc->move(location);
		CHANNEL_D->do_channel( npc,"sys", sprintf(WHT "�����������("HIC"%s" WHT ")��\n" NOR,location));
        return HIM "��˵�����������������"+environment(npc)->query("short")+"������\n" NOR;
}
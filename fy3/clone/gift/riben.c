// story:songdai.c

#include <ansi.h>

string give_gift();

private mixed *story = ({
        "山本五十六：兄弟，听说中土的花姑娘不错啊。",
        "龟太郎：是啊，不过中土有不少武功高强之人，不敢去啊。",
        "山本五十六：这也是个问题，不如我们先派点人去探查探查哪里没有高手。",
        "龟太郎：这样比较稳妥一点。",
        "山本五十六：来人啊，去中土给我探查一下武林高手的分布情况。",
        "是！",

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
			return HIM "据说东瀛人来到了中土后碰上了黑衣人直接被K.O回去了。\n"NOR;               
		npc->move(location);
		CHANNEL_D->do_channel( npc,"sys", sprintf(WHT "东瀛人来到了("HIC"%s" WHT ")。\n" NOR,location));
        return HIM "据说东瀛人来到了中土的"+environment(npc)->query("short")+"附近。\n" NOR;
}
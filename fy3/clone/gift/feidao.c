// story:feidao

#include <ansi.h>

int give_gift();

private mixed *story = ({
        "一日，阿飞见李寻欢，厅内。",
        "阿飞：大哥，听说你的小李飞刀，例无虚发是否真有其事？",
        "李寻欢回答：江湖上朋友抬爱给取了个这么一个绰号，事实上怎么可能呢？",
        "李寻欢随手拿出一柄飞刀，往外一扔，对着阿飞说道：",
        "你看，这一刀，能打中人么？",
		"啊～～～～",
		(: give_gift :),
        "远处传来一阵尖叫。",
		"阿飞飞奔了出去，片刻又回到大厅。",
        "李寻欢疑惑地道：怎么回事？",
        "阿飞：大哥你的飞刀果真是例无虚发啊!刚一路人被你的飞刀射中了。",
        "李寻欢：。。。。。。",

});

void create()
{
        seteuid(getuid());
}

mixed query_story_message(int step)
{
        return step < sizeof(story) ? story[step] : 0;
}

int give_gift()
{
        object *players,ob;
		players = users();
		ob = players[random(sizeof(players))];
		if (ob)
		{
			if (!wizardp(ob)){
			message_vision("只见远处飞来一把飞刀，刀背正巧打在了$N的脑袋上。\n",ob);
			ob->unconcious();
			}
			else
			{
			message_vision("只见远处飞来一把飞刀，刀背正巧打在了$N的脑袋上。$N眼前冒出好多星星！气得$N破口大骂。\n",ob);
			}
		}
        return 1;
}

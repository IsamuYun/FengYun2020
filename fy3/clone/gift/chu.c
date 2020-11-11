// story:chu

#include <ansi.h>

string give_gift();

private mixed *story = ({
        "蓉蓉：楚大哥，我们来玩木头人的游戏吧。",
        "楚留香想了一想：也好，反正闲来无事。",
        "蓉蓉：那楚大哥，你先扮作木头人吧。",
        "楚留香回答：好。",
        "蓉蓉：游戏开始，你不准动喔～。",
        "楚留香：恩",
        "蓉蓉：也不需讲话",
        "楚留香：。。。。",
        "蓉蓉回头道：红袖，甜儿把准备的石头拿出来。",
        "只见红袖和甜儿从屋内走了出来，手中捧着不少大大小小的石头。",
        "三人嘿嘿一笑，拿起石头就朝楚留香扔去。",
        "楚留香一见三人脸儿，暗叫一声：又中了三个小鬼的计！连忙险险避开。",
		"啊呀～～，蓉蓉道：这下坏了，恐怕要砸到路人了。。。",
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
        STORY_D->give_gift("/d/wiz/fyup/obj/qh4", 1,
                           HIM "\n“啪”的一声一块强化石掉到你面前。\n\n" NOR);
        return HIM "听说路人甲险些被石头砸中。\n" NOR;
}

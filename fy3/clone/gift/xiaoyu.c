// story:nanji.c

#include <ansi.h>

int give_gift();

private mixed *story = ({
        "小鱼儿：无缺，你又在练功了。",
        "花无缺：是啊，最近搞到不少锻造的册子，闲着无聊想自己造两把兵器玩玩。",
        "小鱼儿：是嘛，我也来看看。",
        "花无缺：来，一起研究一下，你看看这本。",
		"花无缺随手把书扔向小鱼儿。",
        "小鱼儿：啊!!!",
        "花无缺：。。。。。。",
        "小鱼儿：你扔这么大力干吗，都扔到崖下去了。",
	        (: give_gift :),
        "花无缺：算了算了，一本书而已，我这里有的是。",
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
	int i;
	i = random(12);
	switch(i){
	case 0:
        STORY_D->give_gift("/obj/weapons/swordbook4", 1,HIM "\n“啪”的一声一本书掉到你面前。\n\n" NOR);
		break;
	case 1:
        STORY_D->give_gift("/obj/weapons/bladebook4", 1,HIM "\n“啪”的一声一本书掉到你面前。\n\n" NOR);
		break;
	case 2:
        STORY_D->give_gift("/obj/weapons/staffbook4", 1,HIM "\n“啪”的一声一本书掉到你面前。\n\n" NOR);
		break;
	case 3:
        STORY_D->give_gift("/obj/weapons/ringbook4", 1,HIM "\n“啪”的一声一本书掉到你面前。\n\n" NOR);
		break;
	case 4:
        STORY_D->give_gift("/obj/armors/headbook4", 1,HIM "\n“啪”的一声一本书掉到你面前。\n\n" NOR);
		break;
	case 5:
        STORY_D->give_gift("/obj/armors/clothbook4", 1,HIM "\n“啪”的一声一本书掉到你面前。\n\n" NOR);
		break;
	case 6:
        STORY_D->give_gift("/obj/armors/neckbook4", 1,HIM "\n“啪”的一声一本书掉到你面前。\n\n" NOR);
		break;
	case 7:
        STORY_D->give_gift("/obj/armors/fingerbook4", 1,HIM "\n“啪”的一声一本书掉到你面前。\n\n" NOR);
		break;
	case 8:
        STORY_D->give_gift("/obj/armors/waistbook4", 1,HIM "\n“啪”的一声一本书掉到你面前。\n\n" NOR);
		break;
	case 9:
        STORY_D->give_gift("/obj/armors/wristsbook4", 1,HIM "\n“啪”的一声一本书掉到你面前。\n\n" NOR);
		break;
	case 10:
        STORY_D->give_gift("/obj/armors/bootsbook4", 1,HIM "\n“啪”的一声一本书掉到你面前。\n\n" NOR);
		break;
	case 11:
        STORY_D->give_gift("/obj/armors/shieldbook4", 1,HIM "\n“啪”的一声一本书掉到你面前。\n\n" NOR);
		break;
	default:
		break;
	}
        return 0;
}

// story:nanji.c

#include <ansi.h>

int give_gift();

private mixed *story = ({
        "С�������ȱ�������������ˡ�",
        "����ȱ���ǰ�������㵽���ٶ���Ĳ��ӣ������������Լ������ѱ������档",
        "С����������Ҳ��������",
        "����ȱ������һ���о�һ�£��㿴���Ȿ��",
		"����ȱ���ְ�������С�����",
        "С�������!!!",
        "����ȱ��������������",
        "С�����������ô�������𣬶��ӵ�����ȥ�ˡ�",
	        (: give_gift :),

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
        STORY_D->give_gift("/obj/weapons/swordbook4", 1,HIM "\n��ž����һ��һ�����������ǰ��\n\n" NOR);
		break;
	case 1:
        STORY_D->give_gift("/obj/weapons/bladebook4", 1,HIM "\n��ž����һ��һ�����������ǰ��\n\n" NOR);
		break;
	case 2:
        STORY_D->give_gift("/obj/weapons/staffbook4", 1,HIM "\n��ž����һ��һ�����������ǰ��\n\n" NOR);
		break;
	case 3:
        STORY_D->give_gift("/obj/weapons/ringbook4", 1,HIM "\n��ž����һ��һ�����������ǰ��\n\n" NOR);
		break;
	case 4:
        STORY_D->give_gift("/obj/armors/headbook4", 1,HIM "\n��ž����һ��һ�����������ǰ��\n\n" NOR);
		break;
	case 5:
        STORY_D->give_gift("/obj/armors/clothbook4", 1,HIM "\n��ž����һ��һ�����������ǰ��\n\n" NOR);
		break;
	case 6:
        STORY_D->give_gift("/obj/armors/neckbook4", 1,HIM "\n��ž����һ��һ�����������ǰ��\n\n" NOR);
		break;
	case 7:
        STORY_D->give_gift("/obj/armors/fingerbook4", 1,HIM "\n��ž����һ��һ�����������ǰ��\n\n" NOR);
		break;
	case 8:
        STORY_D->give_gift("/obj/armors/waistbook4", 1,HIM "\n��ž����һ��һ�����������ǰ��\n\n" NOR);
		break;
	case 9:
        STORY_D->give_gift("/obj/armors/wristsbook4", 1,HIM "\n��ž����һ��һ�����������ǰ��\n\n" NOR);
		break;
	case 10:
        STORY_D->give_gift("/obj/armors/bootsbook4", 1,HIM "\n��ž����һ��һ�����������ǰ��\n\n" NOR);
		break;
	case 11:
        STORY_D->give_gift("/obj/armors/shieldbook4", 1,HIM "\n��ž����һ��һ�����������ǰ��\n\n" NOR);
		break;
	default:
		break;
	}
        return 0;
}
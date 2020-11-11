// story:zhengxi 征西

#include <ansi.h>

string give_gift();

private mixed *story = ({
        "陆小凤唱着：我得意的笑，我得以的笑～～",
        "花满楼在旁看不懂了，问：小凤，你高兴个啥？",
        "陆小凤：昨天我把灵犀一指练到了第九重境界了。",
        "花满楼：那真是可喜可贺了。",
        "陆小凤：嘿嘿。今天中饭我请客。",
        "花满楼：好啊，我去叫上老叶和西门。",
        "饭桌上。。。。。。",
        "陆小凤：来来来～～大家都别客气，来喝完鸡段汤～～",
        "叶孤城：这汤还真不错啊，我再来一碗。",
        "西门吹雪：这小子还真是不客气啊。",
        "叶孤城：干吗！你有意见不成。",
        "陆小凤：啊呀，汤怎么洒了。",
        "花满楼：哟，老叶把汤罐碰倒了！",
        "西门吹雪：嘿，让你再猴急。。。",
        "叶孤城：饿。。。真不好意思啊。",
        "陆小凤：算了，一碗汤么，小二，再给我上一份汤！",
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
        STORY_D->give_gift("/obj/food/cj9", 1,
                           HIM "\n“啪”的一声一只山参鸡段掉到你面前。\n\n" NOR);
        return 0;
}

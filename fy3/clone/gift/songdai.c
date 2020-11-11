// story:songdai.c

#include <ansi.h>

int give_gift();

private mixed *story = ({
        "萧十一郎：哎！连兄，你怎么还在练功啊？",
        "连城璧：萧兄弟，你难道已经练完了不成？",
        "萧十一郎：是啊，我早就练完了。",
        "连城璧惊讶地问道：怎么可能这么快呢。",
        "萧十一郎：嘿嘿，我这可有神丹啊。",
        "萧十一郎摸出一颗药丸在连城璧面前摆了摆。",
        "连城璧眼睛瞪的老大：这是什么？",
        "萧十一郎嘿嘿的笑，回答：七昌丹。",
        "连城璧惊讶地道：哪搞来的？",
        "萧十一郎：别问那么多，给你一颗就是了。",
        "连城璧喜道：萧兄弟真够朋友。啊，没接住。。。",
        "萧十一郎：。。。",
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

int give_gift()
{
        STORY_D->give_gift("/clone/gift/yao", 1,
                           HIM "\n“啪”的一声一颗药丸掉到你面前。\n\n" NOR);
        return 1;
}
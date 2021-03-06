
// newsd.c

#include <ansi.h>

#pragma optimize
#pragma save_binary

inherit F_SAVE;
inherit F_DBASE;

// 最多一千条新闻
#define MAX_NEWS_CAPACITY       1000

// 门派更新优先级
int     last_update_day = 0;
mapping family_priority = ([ ]);

void create()
{
        seteuid(getuid());
        restore();
        set_heart_beat(300);
}

// 心跳函数：每天增大所有门派的更新优先级
void prompt_user(object me)
{
        int num;
        int total;
        mapping *notes;
        int last_read_time;

        last_read_time = me->query("last_read_news");
        if (! last_read_time)
        {
                tell_object(me, HIG "\n欢迎您进入" + MUD_NAME +
                                HIG "，今后请使用" HIY " news " HIG
                                "命令查阅发布的新闻信息。\n" NOR);
                me->set("last_read_news", time());
                return;
        }

        notes = query("notes");

        if (! pointerp(notes) || ! sizeof(notes))
                return;

        num = sizeof(notes);
        total = 0;
        while (num--)
                if (notes[num]["time"] > last_read_time)
                        total++;
                else
                        break;

        if (! total)
                tell_object(me, "\n你目前没有未曾阅读过的新闻。\n");
        else
                tell_object(me, sprintf(WHT "\n你目前一共有 " HIY "%d" NOR
                                        WHT " 条新闻还没有阅读，请使用 "
                                        HIY "news" NOR WHT " 命令阅读。\n" NOR, total));

        // 开始定时通知
        if (previous_object() == find_object(LOGIN_D))
                me->start_call_out(bind((: call_other, __FILE__, "auto_notice", me :), me), 10 + random(10));
}

// show all the news's title
// raw = 1: only show the non-read news
void show_news(object me, int raw)
{
        mapping *notes;
        int i, last_time_read;
        string msg;

        notes = query("notes");
        if (! pointerp(notes) || ! sizeof(notes))
        {
                tell_object(me, "目前没有任何新闻。\n");
                return;
        }

         msg = "目前泥潭中的最新消息如下。\n"
              WHT "-------------------------------------------------------------------------------\n" NOR;
        last_time_read = me->query("last_read_news");
        i = sizeof(notes);
        while (i--)
        {
                if (raw && (notes[i]["time"] <= last_time_read))
                        break;

                msg += sprintf("%s[%3d]" NOR " %-" +
                               "s %s (%s)\n",
                               (notes[i]["time"] > last_time_read ? HIY : ""),
                               i + 1, notes[i]["title"],
                               notes[i]["author"], ctime(notes[i]["time"])[0..15]);
        }

        if (i == sizeof(notes) - 1)
        {
                tell_object(me, "目前没有任何未读过的新闻。\n");
                return;
        }

        msg += WHT "-------------------------------------------------------------------------------\n" NOR;
        me->start_more(msg);
}
void auto_notice(object me)
{
        int num;
        mapping *notes;
        string msg;
        int last_read_time;

        if (! objectp(me))
                return;

        last_read_time = me->query("last_read_news");
        notes = query("notes");

        if (! pointerp(notes) || ! sizeof(notes))
                return;

        num = sizeof(notes) - 1;
        if (notes[num]["time"] <= last_read_time)
                return;

        // some news need read, start next call out
        me->start_call_out(bind((: call_other, __FILE__, "auto_notice", me :), me), 30 + random(30));

        if (! living(me) || me->query_temp("block_msg/all"))
                return;

        while (num-- > 0)
        {
                if (notes[num]["time"] <= last_read_time)
                {
                        num++;
                        break;
                }

                // contine to find next
        }

        if (num < 0) num = 0;

        switch (random(5))
        {
        case 0:
                msg = HIM "一阵烟雾过后，新闻精灵出现在你的面前，手里"
                      "捏着一张破破烂烂的纸头，对你宣读起来。\n" NOR;
                break;
        case 1:
                msg = HIM "地上突然开了一个裂缝，冒出一个鬼鬼祟祟的新"
                      "闻精灵，对着你就喋喋不休的罗嗦起来。\n" NOR;
                break;
        case 2:
                msg = HIM "你忽然听见有人喊你，你回头一看，原来是新闻"
                      "精灵满头大汗的跑了过来，\n" NOR;
                break;
        case 3:
                msg = HIM "你刚打了一个哈欠，忽然前面冒出一股烟雾，散"
                      "去以后只见一个新闻精灵懒洋洋的看着你，口中念念有词。\n" NOR;
                break;
        default:
                msg = HIM "“啪啦”一声，新闻精灵狼狈不堪的摔在地上，"
                      "你连忙将他扶起。\n" NOR;
                break;
        }

        msg += HIG "新闻精灵告诉你来自神界的最新消息：\n" NOR;
        tell_object(me, msg);
        me->start_more(sprintf("[%d] %-" + 
                               "s %s (%s)\n----------------------------------------------------------------------\n",
                               num + 1, notes[num]["title"], notes[num]["author"],
                               ctime(notes[num]["time"])[0..9]) + notes[num]["msg"]);

        // Keep track which post we were reading last time.
        if (notes[num]["time"] > (int)last_read_time)
                me->set("last_read_news", notes[num]["time"]);
        tell_object(me, HIM "新闻精灵说完后，消失在一阵烟雾之中。\n" NOR);
}

string query_save_file() { return DATA_DIR "newsd"; }

// newsd.c

#include <ansi.h>

#pragma optimize
#pragma save_binary

inherit F_SAVE;
inherit F_DBASE;

// ���һǧ������
#define MAX_NEWS_CAPACITY       1000

// ���ɸ������ȼ�
int     last_update_day = 0;
mapping family_priority = ([ ]);

void create()
{
        seteuid(getuid());
        restore();
        set_heart_beat(300);
}

// ����������ÿ�������������ɵĸ������ȼ�
void prompt_user(object me)
{
        int num;
        int total;
        mapping *notes;
        int last_read_time;

        last_read_time = me->query("last_read_news");
        if (! last_read_time)
        {
                tell_object(me, HIG "\n��ӭ������" + MUD_NAME +
                                HIG "�������ʹ��" HIY " news " HIG
                                "������ķ�����������Ϣ��\n" NOR);
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
                tell_object(me, "\n��Ŀǰû��δ���Ķ��������š�\n");
        else
                tell_object(me, sprintf(WHT "\n��Ŀǰһ���� " HIY "%d" NOR
                                        WHT " �����Ż�û���Ķ�����ʹ�� "
                                        HIY "news" NOR WHT " �����Ķ���\n" NOR, total));

        // ��ʼ��ʱ֪ͨ
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
                tell_object(me, "Ŀǰû���κ����š�\n");
                return;
        }

         msg = "Ŀǰ��̶�е�������Ϣ���¡�\n"
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
                tell_object(me, "Ŀǰû���κ�δ���������š�\n");
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
                msg = HIM "һ������������ž�������������ǰ������"
                      "����һ���������õ�ֽͷ����������������\n" NOR;
                break;
        case 1:
                msg = HIM "����ͻȻ����һ���ѷ죬ð��һ������������"
                      "�ž��飬��������ੲ��ݵ�����������\n" NOR;
                break;
        case 2:
                msg = HIM "���Ȼ�������˺��㣬���ͷһ����ԭ��������"
                      "������ͷ�󺹵����˹�����\n" NOR;
                break;
        case 3:
                msg = HIM "��մ���һ����Ƿ����Ȼǰ��ð��һ������ɢ"
                      "ȥ�Ժ�ֻ��һ�����ž���������Ŀ����㣬���������дʡ�\n" NOR;
                break;
        default:
                msg = HIM "��ž����һ�������ž����Ǳ�������ˤ�ڵ��ϣ�"
                      "����æ��������\n" NOR;
                break;
        }

        msg += HIG "���ž����������������������Ϣ��\n" NOR;
        tell_object(me, msg);
        me->start_more(sprintf("[%d] %-" + 
                               "s %s (%s)\n----------------------------------------------------------------------\n",
                               num + 1, notes[num]["title"], notes[num]["author"],
                               ctime(notes[num]["time"])[0..9]) + notes[num]["msg"]);

        // Keep track which post we were reading last time.
        if (notes[num]["time"] > (int)last_read_time)
                me->set("last_read_news", notes[num]["time"]);
        tell_object(me, HIM "���ž���˵�����ʧ��һ������֮�С�\n" NOR);
}

string query_save_file() { return DATA_DIR "newsd"; }
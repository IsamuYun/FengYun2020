// story:caishen ����

#include <ansi.h>

int give_gift(string money, int amount, string name);

private mixed *story = ({
        "��С������·��ꡣ",
        "�������·��",
        "С����ƾʲô��",
        "����񣺷ϻ���ƾ�ұ�����Ǯ��",
        "С������������ͭ�壬�������˳�ȥ���ߺߵ�������",
        (: give_gift, "coin", random(3)+1, "ͭ��" :),
        "�����һ����Ц������һЩ�������˳�ȥ��",
        (: give_gift, "silver", random(3)+1, "����" :),
        "С�������˰��죬�ͳ�һЩ�ƽ�ҧҧ�����˳�ȥ����������ѽ��",
        (: give_gift, "gold", random(3)+1, "�ƽ�" :),
        "�����ǺǴ�Ц������������Ʊ����ƮƮ�ķ��˳�ȥ��",
        (: give_gift, "thousand-cash", 1 + random(3), "��Ʊ" :),
        "С����������ɫ������������Ǯ��������Ǯ������·������·��",
});

void create()
{
        seteuid(getuid());
}

mixed query_story_message(int step)
{
        return step < sizeof(story) ? story[step] : 0;
}

int give_gift(string money, int amount, string name)
{
        STORY_D->give_gift("/obj/money/" + money, amount,
                           HIM "\n��ž����һ��һЩ" + name + "��������ǰ��\n\n" NOR);
        return 1;
}

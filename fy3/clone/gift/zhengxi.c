// story:zhengxi ����

#include <ansi.h>

string give_gift();

private mixed *story = ({
        "½С�ﳪ�ţ��ҵ����Ц���ҵ��Ե�Ц����",
        "����¥���Կ������ˣ��ʣ�С�����˸�ɶ��",
        "½С������Ұ���Ϭһָ�����˵ھ��ؾ����ˡ�",
        "����¥�������ǿ�ϲ�ɺ��ˡ�",
        "½С��ٺ١������з�����͡�",
        "����¥���ð�����ȥ������Ҷ�����š�",
        "�����ϡ�����������",
        "½С�������������Ҷ�������������꼦��������",
        "Ҷ�³ǣ��������治������������һ�롣",
        "���Ŵ�ѩ����С�ӻ����ǲ���������",
        "Ҷ�³ǣ���������������ɡ�",
        "½С���ѽ������ô���ˡ�",
        "����¥��Ӵ����Ҷ�����������ˣ�",
        "���Ŵ�ѩ���٣������ٺＱ������",
        "Ҷ�³ǣ����������治����˼����",
        "½С����ˣ�һ����ô��С�����ٸ�����һ������",
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
                           HIM "\n��ž����һ��һֻɽ�μ��ε�������ǰ��\n\n" NOR);
        return 0;
}
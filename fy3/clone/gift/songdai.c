// story:songdai.c

#include <ansi.h>

int give_gift();

private mixed *story = ({
        "��ʮһ�ɣ��������֣�����ô������������",
        "����赣����ֵܣ����ѵ��Ѿ������˲��ɣ�",
        "��ʮһ�ɣ��ǰ�������������ˡ�",
        "����赾��ȵ��ʵ�����ô������ô���ء�",
        "��ʮһ�ɣ��ٺ٣���������񵤰���",
        "��ʮһ������һ��ҩ�����������ǰ���˰ڡ�",
        "������۾��ɵ��ϴ�����ʲô��",
        "��ʮһ�ɺٺٵ�Ц���ش��߲�����",
        "����赾��ȵص����ĸ����ģ�",
        "��ʮһ�ɣ�������ô�࣬����һ�ž����ˡ�",
        "�����ϲ�������ֵ��湻���ѡ�����û��ס������",
        "��ʮһ�ɣ�������",
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
                           HIM "\n��ž����һ��һ��ҩ���������ǰ��\n\n" NOR);
        return 1;
}
// story:laojun ����

#include <ansi.h>

int give_gift();

private mixed *story = ({
        "��Բ֮ҹ���Ͻ�֮�ߡ�",
        "Ҷ�³ǣ����ţ�����ô�����ν������ڵ�ʲô��",
        "���Ŵ�ѩ����Ҷ������Ͳ����ˣ���аν�����",
        "Ҷ�³ǣ��ν��������������ٻ����ˣ����ɣ����ҿ�������ĺ��촵ѩ�����������ҵ�������ɸ�ʤһ�",
        "���Ŵ�ѩ������аɣ��ҵĽ������ҵ����У���ʱ��ؿ��Գ�����",
        "Ҷ�³ǣ��ߣ���֪����Ķ�����һ���������������졫�⡫�ɡ��ɡ�",
        "������������������������",
        "���Ŵ�ѩ�����򣤡����������������ˣ��β�������",
		"���Ŵ�ѩ�������ذ����ϵĽ��������ʳ�Ҷ�³���ȥ",
        "����̫���ˣ�Ҷ�³����㲻����ֻ���Խ�������",
        "������ײ��ð���𻨣�ֻ����������һ�������Ŵ�ѩ���ǰѽ����ϵ����ӵ���һ�š�",
        "���Ŵ�ѩ����ս���Ұ��ˣ����ն����ٴα��ԡ�˵��ͷҲ���ص����ˡ�",
		"Ҷ�³Ǽ���ղŵ�������ӣ����˿��������ǿ���ͨ��ʯͷ������һ��Ҳ��ʧ��Բ��֮�¡�",
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
        STORY_D->give_gift("/obj/weapons/banzhi4", 1,
                           HIM "\n��ž����һ��һ�鶫����������ǰ��\n\n" NOR);
        return 1;
}
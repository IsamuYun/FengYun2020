// story:feidao

#include <ansi.h>

int give_gift();

private mixed *story = ({
        "һ�գ����ɼ���Ѱ�������ڡ�",
        "���ɣ���磬��˵���С��ɵ��������鷢�Ƿ��������£�",
        "��Ѱ���ش𣺽���������̧����ȡ�˸���ôһ���ºţ���ʵ����ô�����أ�",
        "��Ѱ�������ó�һ���ɵ�������һ�ӣ����Ű���˵����",
        "�㿴����һ�����ܴ�����ô��",
		"����������",
		(: give_gift :),
        "Զ������һ���С�",
		"���ɷɱ��˳�ȥ��Ƭ���ֻص�������",
        "��Ѱ���ɻ�ص�����ô���£�",
        "���ɣ������ķɵ������������鷢��!��һ·�˱���ķɵ������ˡ�",
        "��Ѱ����������������",

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
        object *players,ob;
		players = users();
		ob = players[random(sizeof(players))];
		if (ob)
		{
			if (!wizardp(ob)){
			message_vision("ֻ��Զ������һ�ѷɵ����������ɴ�����$N���Դ��ϡ�\n",ob);
			ob->unconcious();
			}
			else
			{
			message_vision("ֻ��Զ������һ�ѷɵ����������ɴ�����$N���Դ��ϡ�$N��ǰð���ö����ǣ�����$N�ƿڴ��\n",ob);
			}
		}
        return 1;
}

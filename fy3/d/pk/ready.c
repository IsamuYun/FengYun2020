#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "����׼����");
        set("long", @LONG
����ں����ģ����ϻ���һЩճ����Ѫ���Ĳ�����żȻҲ���õ���
�˵ĳ������ֵ�ʲô�ġ�������Ž��������ţ�����ɢ����һ����Ѫ��
����ζ�������и�������(shelf),����С��ʹ�ã�ʮ�������Ѿ��򿪵�!.
LONG
        );
        set("exits", ([
                "1" : __DIR__"turen1",
                "2" : __DIR__"turen2",
                "3" : __DIR__"turen3",
                "4" : __DIR__"turen4",
                "5" : __DIR__"turen5",
                "6" : __DIR__"turen6",
                "7" : __DIR__"turen7",
                "8" : __DIR__"turen8",
                "9" : __DIR__"turen9",
               "10" : __DIR__"turen10",
               "11" : __DIR__"turen11",
               "12" : __DIR__"turen12",
        ]));
	set("item_desc", ([
                "shelf" : 
"\n
һ��������ͷ�ı����ܣ����ᶼ����ò���ˡ�
���ϰ�����: 
                 �ֵ�(blade)    ����(sword)
                 ����(staff)    ����(whip)
                 ����(hammer)   ��ָ(jiezi)
                 ����(throwing) �̱�(dagger)
                 ��˿����(armor)

�μӱ������԰���Ҫ�������ȡ(take)ʹ�á�
                                ֣�ݷ�����ʦ�� ����
\n"

]));
        set("objects", ([  "/d/pk/npc/wu1" : 1,   ]) );
        set("no_fight",1);
        set("no_magic",1);
        set("no_dazuo",1);
        setup();
}
int valid_leave(object me, string dir)
{
        if (me->query_temp("pkok")!=1)
                return notify_fail("����ʹ�ߺȵ�������վס��û��ɱ��֤�����ܽ�ȥ��\n");
        return ::valid_leave(me,dir);
}
void init()
{
        add_action("do_take","take");
}
int do_take(string arg)
{
        object obj,ob;
        ob = this_player();
        if( !arg || arg=="" )
        {
                message_vision("$Nվ�ڱ�����ǰ����û���Ҫʲô������\n", ob);
                return 1;
        }
        switch (arg)
        {
                case "sword":
                        obj = new("/obj/weapon/sword");
                        obj -> move(ob);
                        message_vision("$N�ӱ�������ȡ��һ�ڳ�����\n",ob);
                        break;
                case "blade":
                        obj = new("/obj/weapon/blade");
                        obj -> move(ob);
                        message_vision("$N�ӱ�������ȡ��һ�ڸֵ���\n",ob);
                        break;
                case "staff":
                        obj = new("/obj/weapon/staff");
                        obj -> move(ob);
                        message_vision("$N�ӱ�������ȡ��һ�˸��ȡ�\n",ob);
                        break;
                case "whip":
                        obj = new("/obj/weapon/whip");
                        obj -> move(ob);
                        message_vision("$N�ӱ�������ȡ��һ�����ޡ�\n",ob);
                        break;
                        obj = new("/obj/weapon/hammer");
                        obj -> move(ob);
                        message_vision("$N�ӱ�������ȡ��һ��������\n",ob);
                        break;
                case "throwing":
                        obj = new("/obj/weapon/dart");
                        obj -> move(ob);
                        message_vision("$N�ӱ�������ȡ��һ�ѷ��ڡ�\n",ob);
                        break;
                case "dagger":
                        obj = new("/obj/weapon/dagger");
                        obj -> move(ob);
                        message_vision("$N�ӱ�������ȡ��һ��ذ�ס�\n",ob);
                        break;
                case "armor":
                        obj = new("/obj/baojia");
                        obj -> move(ob);
                        message_vision("$N�ӱ�������ȡ��һ�����ס�\n",ob);
                        break;
                case "jiezi":
                        obj = new("/obj/weapon/glove");
                        obj -> move(ob);
                        message_vision("$N�ӱ�������ȡ��һ����ָ��\n",ob);
                        break;
                default:
                        message_vision("$Nվ�ڱ�����ǰ����û���Ҫʲô������\n", ob);
        }
        return 1;
}

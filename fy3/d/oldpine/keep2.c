// Room: /d/oldpine/keep2.c

#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "����կ");
        set("long", @LONG
����Ӧ��������կ�ˣ���ȻΧ�������ǽ����ľͷ��ɵģ�������
ϸһ�����������Ҫ��λ�ö����˲���ɳ��ʯ�ѣ�������Ȼ���������
�ĺõط����������óȻ�Ӵ��ſڹ��������϶���Դ���ģ���կ����
��������ߣ�����Խ��һ��ľ׮֮����Ǵ�����
LONG
        );
        
        set("exits", ([ /* sizeof() == 2 */
                "west" : __DIR__"keep15",
                "east" : __DIR__"keep3",
        ]));
        set("objects", ([
//                __DIR__"npc/bandit_guard" : 2,
//                __DIR__"npc/bandit_leader" : 1
        ]) );

        set("coor/x",-210);
	set("coor/y",-350);
	set("coor/z",90);
	setup();
}

int valid_leave(object me, string exit)
{
        int i;
        object ob;

        if( exit != "east"
        ||      !query("exits/west") )
                return 1;

        message("vision",
                HIY "�������������м���������У����Ź��ϣ����Ź��ϣ�һ��Ҳ�������������ߣ�\n" NOR
                        "�������䡹��һ����ͨ������Ĵ����Ѿ���һ���ʯ�����ˡ�\n",
                this_object() );
        delete("exits/west");
        if( ob = find_object(__DIR__"keep15") )
                ob->delete("exits/east");
	if(!me->query("m_success/����կ"))
        {
                me->set("m_success/����կ",1);
                me->add("score",100);
	message("system",HIC "\n�����ַ��ơ���������"+me->query("name")+"�⿪��������⣬�����"HIY"����������կ��"HIC"�ĳƺš�\n" NOR,users());

        }
        i = 5;
        while(i--) {
                ob = new(__DIR__"npc/bandit_guard");
                ob->move(this_object());
                ob->kill_ob(me);
        }
        return 1;
}

void reset()
{
        object ob;

        ::reset();
        set("exits/west", __DIR__"keep15" );
        if( ob = find_object(__DIR__"keep15") )
                ob->set("exits/east", __DIR__"keep2");
        
}

void pipe_notify()
{
        object ob;

        message("vision",
                "������һ�����������̽ʶ�������ס�ſڵĴ�ʯ�����ر��ƿ��ˡ�\n",
                this_object() );
        set("exits/west", __DIR__"keep15" );
        if( ob = find_object(__DIR__"keep15") )
                ob->set("exits/east", __DIR__"keep2");
}

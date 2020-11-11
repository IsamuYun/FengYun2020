#include <globals.h>
inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
��һ�ε��������һ����������������ģ������������������Ҳ
�����⡣�޴��ޱȵı������滷ɽ����Ϊ��֧����Ϊ��������Χ��ɽѩ
ӳ�������͸��˵�����Ĺ��졣
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"baiyang",
]));
	set("frozen",30);
	set("no_pk",1);
	set("no_spells",1);
	set("no_magic",1);
        set("outdoors", "xinjiang");
        set("coor/x",-1120);
	set("coor/y",1010);
	set("coor/z",0);
        set("item_desc", ([
                "����": "��Χ�ű��������ֿ������ֱ������ƺ����ŹŹ֣����������룩������\n",
        ]) );
	setup();
}

void init()
{
	add_action("do_pour", "pour");
	add_action("do_break", "break");
}

int do_pour(string arg)
{
	object me;
	object con;
	me = this_player();
	if(!arg) return 0;
	if(!objectp(con=present(arg, me)))
	return 0;
	if(!con->query("liquid"))
	return 0;
	if(!con->query("liquid/remaining"))
	return notify_fail( con->name() + "�ǿյġ�\n");
	con->add("liquid/remaining", -1);
	message_vision("$N����" + con->name() + "����һЩ" +
	con->query("liquid/name")  + "�ں����ϡ�\n",me);
	if(con->query("liquid/name") == "��ˮ")
	{
	tell_object(me,"�����ոջ�����һ������ֶ����ˣ���\n");
	}
	if(con->query("liquid/name") == "��ˮ")
	{
	tell_object(me,"��ֵúܣ�����һ����ˮ�Ϳ�ʼ�ⶳ�ˣ���\n");
	add("frozen",-1);
	}
	if( query("frozen") <= 0 )
	{
	tell_object(me,"�������ڻ�����һ��С��������\n");
	if(!query("exits/southwest"))
		set("exits/southwest",__DIR__"gela");
	call_out("close_path",5);		
	}
	return 1;
}

int do_break(string arg)
{
	object me;
	me = this_player();

	if(!arg || arg!="����") return notify_fail("��Ҫ��ʲô��\n");

	if (me->query("force")<1000) return notify_fail("������������ˣ�\n");
	me->add("force",-50);
	
	message_vision("$N����һ�ƣ����صػ��ڱ����ϣ�ɲ�Ǽ��м��ɣ������ϵ��Ѻ۸����ˣ�\n",me);
	if( query("frozen") > 15 ) add("frozen",-1);
	return 1;
}


void close_path()
{
        if( !query("exits/south") ) return;
        message("vision",
"Ʈ������ˮ��գ�ۼ䶳�ɱ��飬�����ط�ס�˶��ڣ���\n",
                this_object() );
                delete("exits/south");
		set("frozen",10+random(5));
}

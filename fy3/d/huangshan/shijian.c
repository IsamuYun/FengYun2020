// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "�Խ�ʯ");
        set("long", @LONG
һ��޴��ʯͷ��stone�����´�·�У��м�һ�ۣ�����룬�ഫ����һ
�Ŵ���ʦ�Խ�֮��������ǧ�࣬����������һ�ѿ���������ʯ�Ľ�
����Ϊ������񽣡�����ϧ��ʦ�������㲶������ഫ��ɽ��®����
�����ഫ�ı��Ǵ˽���
LONG
        );
        set("exits", ([ 
  "north"  : __DIR__"zuishi",
]));
        set("item_desc", ([
                "stone": "һ��޴��ʯͷ���м�һ�ۣ��ѷ���ƺ���һ
�����������⡣���ƺ�Ҳ������������һ�ԣ�test�����������\n"
        ]) );
        set("outdoors", "huangshan");
	set("coor/x",-550);
	set("coor/y",-530);
	set("coor/z",10);
	setup();
}
void init()
{
add_action("do_test","test");
}
int do_test(string arg)
{
object me,weapon;
if(!arg ) return notify_fail("��Ҫ��һ�������ϵ�����������\n");
me=this_player();
if(!(weapon = present(arg,me))) return notify_fail("�������ƺ�û������������\n");
if(!weapon->query("weapon_prop")) return notify_fail(weapon->name()+"�ƺ�������һ��������\n");
if(!weapon->query("equipped")) return notify_fail("�㲢û�н�"+weapon->name()+"�������С�\n");
message_vision("$N�þ�ȫ���������е�"+weapon->name()+"�������ʯ��ȥ��������\n",me);
weapon->unequip();
weapon->set("weapon_prop",0);
weapon->save();
me->reset_action();
message_vision("ֻ������������һ����$N���е�"+weapon->name()+"Ӧ�����ϣ�\n",me);
weapon->set("name","�ϵ���" + weapon->query("name"));
weapon->set("value",0);
if(random(500))
tell_object(this_object(),"��ʯ�ϵ��Ѻ��ƺ�������һЩ��\n");
else
{
tell_object(this_object(),"һ�������Ķ�����ʯ���е��˳�����\n");
weapon = new(__DIR__"obj/banzhi5");
weapon->move(this_object());
}
me->start_busy(2);
return 1;
}

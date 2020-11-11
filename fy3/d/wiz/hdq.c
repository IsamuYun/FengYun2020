inherit ROOM;
#include <ansi.h>
#include <room.h>
void create()
{
        set("short", HIY"��"HIM"��"HIC"Ȫ"NOR);
        set("long", @LONG
��ǰ�����������ľ���Զ��Ⱥɽ���������������Բԣ��ʻ���أ������ʵ�
�ڻ�����裬�·������ɾ����ʻ��м���һ���ܴ��Ȫ�ۣ�������Ȫӿ������������
���㣬�����Ŀ�������Ȫˮ�ڲ�Զ�����һ��С������˵����ȥ������֮��Ч���м�
��С������ˮ����ˮ����������Ц��������Ҳ�����ԣ������𣩡�
LONG
        );
        set("exits", ([
                  "east" : "/d/chenxiang/chenxiang3",
        ]));
        set("resource/water",1);
        set("liquid/name","����Ȫˮ");
        set("liquid/type", "alcohol");
        set("liquid/drunk_apply",3);
        set("objects", ([
//                __DIR__"npc/beauty": 3,
//                __DIR__"npc/boy": 2,
          ]) );
        set("no_magic", 1);
        set("coor/x",-620);
        set("coor/y",-800);
        set("coor/z",80);
        set("coor/x",-620);
	set("coor/y",-800);
	set("coor/z",80);
	setup();
}

void init()
{
        add_action("do_jump", "jump");
        add_action("do_fillwater", "fillwater");
}

int do_jump()
{
        object me;
        int wait;
        me = this_player();
        if (me->query_temp("hdqwashing")) {
                tell_object(me,"���Ѿ���Ȫˮ���ˣ�\n");
                return 1;
        }
        wait = random( 40 - (int)(me->query("con"))) ;
        if ( wait <= 10) wait = 11;
        message_vision("$N����һ���������\n",me);
        tell_object(me,HIC"�峺�ĺ�ˮ��Χ���㣬����е�ȫ���ޱȵ���̩����\n"NOR);
        me->set_temp("hdqwashing",1);
        call_out("curehimup", wait, me);
return 1;
}

void curehimup(object me)
{
        int gin,kee,sen;
        if(!me) return;
        gin=(int)me->query("max_gin");
        kee=(int)me->query("max_kee");
        sen=(int)me->query("max_sen");
if( me && environment(me) == this_object())
        {
        message_vision(HIG"$N"HIG"����������Ȫ�ߣ���ǰ�����˲ʵ�����ľ���$N"HIG"�ľ�����ȫ�õ��˻ָ�����\n"NOR, me);
        me->set("eff_gin",gin);
        me->set("eff_kee",kee);
        me->set("eff_sen",sen);
        me->set("gin", gin);
        me->set("kee", kee);
        me->set("sen", sen);
}
me->delete_temp("hdqwashing");
return;
}

int do_fillwater(string arg)
{
        object *list, ob;
        int i, can_fillwater;
        string dir;
        if( !arg || arg=="" ) return 0;
        if( arg=="skin" || arg=="wineskin" ) {
                list = all_inventory(this_player());
                i = sizeof(list);
                can_fillwater = 0;
                while (i--) {
                  if (((string)list[i]->query("liquid/type") == "alcohol")
 || ((string)list[i]->query("liquid/type") == "water")         ) {
                        ob = list[i];
                        can_fillwater = 1;
                        ob->set("liquid", ([
                                "type": "water",
                                "name": "����Ȫˮ",
                                "remaining": 15,
                                "drunk_apply": 6,
                        ]) );
                        write("���ں���Ȫ��װ�����峺�ĺ���Ȫˮ�� \n");
                        return 1;
                   }
                }
                if (can_fillwater ==0) {
                        write("��û��װˮ�Ķ�����....\n");
                        return 1;
                }
        }
        else {
                write("��Ҫ��ʲô�������ˮ��\n");
        }
        return 1;
}

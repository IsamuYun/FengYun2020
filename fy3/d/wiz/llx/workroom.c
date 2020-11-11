//d/wiz/llx/workroom.c

#include <ansi.h>
void test_me(object me);
inherit ROOM;

void create()
{
        set("short",HIW"����������"NOR);
        set("long", @LONG
���ڵĵƹ����ͣ�����о����ǳ����ʣ������﹤����һ������÷ǳ��
�⡣������������������������������������˿��Կ���������һЩ������ϸ���ϡ�
���ӵ��м���һ�Ź���̨�����������ǽ����һ����ܣ����Ϸ���ͨ����ʦ�����
�Ĵ��š�¥���������Ĳ��Լ䣬¥����������˽�˷��䣬û�о���ͬ���벻Ҫȥ��
����о������ҿ���"ע������"(paizi)��
LONG);
        set("exits", ([
        "down" :__DIR__"test",
        "up" :__DIR__"mishi",
        "southeast" : "/d/wiz/jobroom",
        "out" :"/d/fy/fysquare",
]));
        set("objects", ([ 
                __DIR__"obj/paizi" : 1,
                __DIR__"obj/table" : 1,
                __DIR__"obj/shelf" : 1,
        ]));
        set("no_beg",1);
        set("no_stearl",1);
        set("no_magic",1);
        set("no_huanlong",1);
        set("no_burn",1);
	set("no_death_penalty",1);
        
        set("coor/x",-500);
        set("coor/y",-500);
        set("coor/z",-500);
        setup();
}

void init()
{
        add_action("do_get", "get");
        add_action("do_qiurao", "qiurao");
}

void reset()
{
        object          *inv;
        object          con, item;
        int             i;      

        ::reset();
        con = present("table", this_object());
        inv = all_inventory(con);
        if( sizeof(inv) ==0) {
                item = new(__DIR__"obj/book",1);
                item->move(con);
                item = new(__DIR__"myobj/wuyoucha",2);
                item->move(con);
                item = new(__DIR__"myobj/xuejia",2);
                item->move(con);
        }
        con = present("book shelf", this_object());
        inv = all_inventory(con);
        if( sizeof(inv) ==0) {
                item = new(__DIR__"obj/dangan");
                item->move(con);
        }
}
int do_get(string arg)
{
        string          obj, from;
        object          me, shelf, table, target, taro;

        if(sscanf(arg, "%s from %s", obj, from)==2 ) {
                if(obj == "all") {
                        write("һ����̫�ණ���ᱻ�������ֵġ�\n");
                        return 1;
                }
                table =  present("table",this_object());
                shelf =  present("shelf",this_object());
                target =  present(from,this_object());
                me = this_player();
                if(target == table || target == shelf) {
                        taro =  present(obj, target);
                        if(!wizardp(me) && random(10) > 2) {
                                message_vision("$N��û��ע���ʱ�򣬹����������˵�ʲô���Ž����\n", me);
                                me->set_temp("llx_marks/͵��", 1); 
                        }
                }
        }
        return 0;
}

int do_qiurao()
{
        int i;
        object *inv, me;
        me = this_player();
        message_vision(YEL"$N�ϻ̳ϿֵĹ��ڵ��ϣ�ʹ�������˵��: ���Ǳ���������ɵ��!���Ǳ���������ɵ��!\n\n" + "Ӣ���������ߴ����͵ı���ͳ���ǣ������Ұɣ�����Ҳ������!\n\n"NOR,me);
        message_vision(BLU "һ��������ɭɭ��˵�����ðɣ����߰ɣ�����Ҫ�������еĶ������£�\n\n" NOR, me);
        inv = all_inventory(me);
        for(i=0; i<sizeof(inv); i++) {
                destruct(inv[i]);
                message("vision", RED "һ�������" + me->name() + "��ȫ���㷢������ʲô��û���ˡ�\n" NOR, environment(me));
                me->set_temp("llx_marks/͵��", 0); 
                }
        return 0;
}

int valid_leave(object me,string dir)
{
        object obj, man1, man2, man3;
        obj = this_object();
                
        if(dir == "up" && !wizardp(me))
        {
        message_vision(RED"��һ�����ε����Ͻ�$N��ס�ˣ�
        һ�������������˵�����㲻�������������ȥ��\n"NOR,me);
        return notify_fail("");
        }
        if( userp(me) && me->query_temp("llx_marks/͵��"))
        {
                message_vision("���ƺ����������ߡ�\n", me);
                man1 = present("wguard", obj);
                man2 = present("gguard", obj);
                man3 = present("rguard", obj);
                if (!objectp(man1)) {
         message_vision(BLU"һ����Ӱ����ͷ��һ�����£�ѹ�ȵ��㼸����������������\n"NOR, me);
         man1 = new(__DIR__"npc/npc");
         man1->move(obj);
                        if (!objectp(man2)) {
         message_vision(BLU"һ����Ӱ����ͷ��һ�����£�ѹ�ȵ��㼸����������������\n"NOR, me);
         man1 = new(__DIR__"npc/npc1");
         man1->move(obj);
                                if (!objectp(man3)) {
         message_vision(BLU"һ����Ӱ����ͷ��һ�����£�ѹ�ȵ��㼸����������������\n"NOR, me);
         man1 = new(__DIR__"npc/npc2");
         man1->move(obj);
                message_vision(HIR"���һ�θо�������������ô������\n"NOR,me);
        	me->set_temp("llx_marks/͵��",0);
		return notify_fail("");
                        }
                        }
                }
                
        }
        return 1;
}

//xgchen@zzfy

inherit ROOM;
void create ()
{
        set ("short", "���俴̨");
        set ("long", @LONG
����֣�ݷ��Ƶı��䳡�Ŀ�̨����̨����һ���ŵ�ľ�����ʡ�������
����һ�ɸߵı���̨��һ�б�������㶼�ܿ��÷ǳ���������ﻹ�ṩ
��ѵ���ʳ��

                [47m���������������������������������� [0m
                [47m��                              �� [0m
                [47m�� [30m ��  ��  ��  ��  ��  ��  ��[32m  �� [0m
                [47m��                              �� [0m
                [47m���������������������������������� [0m

        [47m���������� [0m                               [47m���������� [0m
        [47m��      �� [0m                               [47m��      �� [0m
        [47m��  [30m��[32m  �� [0m                               [47m��  [30mȭ [32m �� [0m
        [47m��      �� [0m                               [47m��      �� [0m
        [47m��  [30m��[32m  �� [0m  ������֣�ݷ��Ƶı��䳡��̨�� [47m��  [30m�� [32m �� [0m
        [47m��      �� [0m                               [47m��      �� [0m
        [47m��  [30m��[32m  �� [0m  ������Կ�������ı�����̨�� [47m��  [30m�� [32m �� [0m
        [47m��      �� [0m                               [47m��      �� [0m
        [47m��  [30m��[32m  �� [0m  ��̨�������һ���ܴ�Ķ����� [47m��  [30mɽ [32m �� [0m
        [47m��      �� [0m                               [47m��      �� [0m
        [47m��  [30m��[32m  �� [0m                               [47m��  [30m�� [32m �� [0m
        [47m��      �� [0m                               [47m��      �� [0m
        [47m��  [30m��[32m  �� [0m                               [47m��  [30m�� [32m �� [0m
        [47m��      �� [0m                               [47m��      �� [0m
        [47m���������� [0m                               [47m���������� [0m
[0m
LONG);
        set("no_fight",1);
        set("no_exert",1);
        set("no_magic",1);
        set("no_clean_up",1);
        set("watch_fight_room2",1);
        set("exits", ([
                "up"   : __DIR__"biwutai",
                "down"   : __DIR__"biwufang",
        ]));
        setup();
}

void init()
{
        add_action ("do_work","perform");
        add_action ("do_work","exert");
        add_action ("do_work","dazuo");
}

int do_work()
{
        write("���ﲻ��ʹ�����ָ�\n");
        return 1;
}

int valid_leave(object me, string dir)
{
        object tai=load_object(__DIR__"biwutai");
        object *inv=all_inventory(tai);
        object ob, where;
        int i=sizeof(inv);


        if ( !wizardp(me) && dir=="up" ) {
                if(i>=3)
                        return notify_fail("����̨���Ѿ�������ѡ�֣������ڲ�����̨��\n");
        }
        return ::valid_leave(me, dir);
}

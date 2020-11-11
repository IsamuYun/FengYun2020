// glass.c

inherit EQUIP;

void create()
{
        set_name("ս����̽����", ({ "detector", "glass", "device" }) );
        set_weight(300);
        set("unit", "��");
        set("long",
                "�������ԡ������项��ս����̽�����������������̽��(detect)����\n"
                "�ĵȼ���\n");
        set("value", 50000);
        set("type", "misc");
        set("apply", ([
                "ͷ��": 0,
        ]) );
}

void init()
{
        add_action("do_detect", "detect");
}

int do_detect(string arg)
{
        object ob;
        int sen, sk, exp;
        string skill;

        if( arg ) ob = present(arg, environment(this_player()));
        else ob = this_player()->query_opponent();

        if( !ob ) return notify_fail("��Ҫ̽��˭�ĵȼ���\n");

        printf("̽������ʾ%s�ĵȼ��ǣ�%d\n",
                ob->query("name"), 
                ob->query("level"));

        return 1;
}


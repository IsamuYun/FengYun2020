inherit ITEM;

void create()
{
        set_name("����̨", ({ "table", "����̨",}) );
        set_weight(500);
        set_max_encumbrance(8000);
        set("no_get", 1);
        set("no_shown", 1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("prep", "on");
                set("unit", "��");
                set("long", "һ���ѽ��Ƶ����ӡ��������һЩ�й�Mud��̷�����鼮������\n");
                set("value", 1);
        }
}

int is_container()
{
return 1;
}

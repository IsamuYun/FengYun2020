// writted by Tiandi
inherit ITEM;
void create()
{
        set_name("�ں����Ķ���", ({ "dan"}) );
        set_weight(1);
        if( clonep() )
           set_default_object(__FILE__);
        else {
           set("long","һ�Ѻں����Ķ���������������ʧ�ܵĲ��\n");
           set("unit", "��");
           set("value", 0);
        }
        setup();
}

inherit ITEM;

void create()
{
        set_name("�һ���", ({ "petal" , "�һ���"}) );
        set_weight(1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "Ƭ");
                set("long", "�ۺ�ɫ���һ����ϻ����ż���¶�� . \n");
                set("value", 1);
        }
}



inherit ITEM;

void create()
{
        set_name("���ͷ", ({ "fish bone" , "���ͷ"}) );
        set_weight(5);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ�����Եĸɸɾ��������ͷ�� \n");
                set("value", 1);
        }
}



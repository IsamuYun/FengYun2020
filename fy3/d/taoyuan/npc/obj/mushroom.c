inherit ITEM;

void create()
{
        set_name("Ģ��", ({ "mushroom" , "Ģ��"}) );
        set_weight(5);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "�װ����ֵ�Ģ���� \n");
                set("value", 1);
        }
}


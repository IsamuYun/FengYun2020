// toxinbook.c

inherit ITEM;

void create()
{
        set_name("����", ({ "duanyan" }));
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",
                        "����һ���к���ī֭��������̨��\n");
                set("value", 200);
                set("material", "paper");
        }
}

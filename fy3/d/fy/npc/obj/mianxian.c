inherit ITEM;
void create()
{
    set_name("ϸ����", ({ "mianxian" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "��");
             set("value", 100); 
            set("material", "paper");
            set("long", "һ��������ϸ���ߡ�\n");
          }

    setup();
}


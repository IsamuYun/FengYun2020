inherit ITEM;
void create()
{
    set_name("ʥҩ", ({ "yao" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "��");
             set("value", 100000); 
            set("material", "paper");
            set("long", "һ��ʥҩ�����ɻ����ˣ���׹ǡ����ǽ�����ʿ����������鵤��\n");
          }

    setup();
}
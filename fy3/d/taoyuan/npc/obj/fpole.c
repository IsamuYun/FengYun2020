
inherit ITEM;

void create()
{
	set_name("�����", ({ "fish pole" , "pole", "�����"}) );
	set_weight(150);
        set_max_encumbrance(1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("prep", "on");
		set("long", "һ������֦���ɵĵ���ˣ����滹�к������ŵ��һ����Ե�ʮ����ӱ���¡� \n");
		set("value", 150);
	}
}

void init()
{
        add_action("do_use", "fishing");
}

int do_use(string arg)
{
//        if( arg != "fish pole" ) return 0;

        tell_object(this_player(),"���ͳ�һ��" + this_object()->name() + "��\n");
        environment(this_player())->fish_notify(this_object(), 0);

        return 1;
}

int is_container() { return 1; }


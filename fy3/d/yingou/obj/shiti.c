inherit ITEM;

void create()
{
	set_name("ʬ��", ({ "shiti" }));
	set_weight(80000+random(300000));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
             set("for_ok",1);
		set("long",
			"���˰��һ���ϰ������ͽ��ʬ�壬��֪��Ϊʲô����������\n");
		set("value", 0);
	}
}

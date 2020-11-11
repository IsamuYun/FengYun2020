// magic_seal.c

inherit ITEM;

void create()
{
	set_name("����", ({"seal"}) );
	set_weight(5);
	set("long",
		"����һ�Ż��õķ��䡣\n");
	set("unit", "��");
        set("value", 0);
call_out("do_unuse", 1800);

	set("unused", 0);
}
void do_unuse()
{
	set("unused", 1);
}

int unequip()
{
	set("equipped", 0);
	return 1;
}

void init()
{
	add_action("do_attach", "attach");
	add_action("do_write", "write");
	add_action("do_burn", "burn");
}

int do_write(string arg)
{
        object obj, tarobj;
        string sheet, target;

	if(query("unused"))
	{
		return notify_fail("���ŷ����Ѿ�ʧЧ�ˣ�\n");
	}

	if( !arg || sscanf(arg, "%s on %s", target, sheet)!=2 )
		return notify_fail("ָ���ʽ��write <����> on <����>\n");

	if( !objectp(obj = present(sheet, this_player()))) 
           return notify_fail("��Ҫʹ�����ŷ��䣿\n");

	tarobj = find_living(target);
	if( !tarobj || wizardp(tarobj)) {
	   message_vision("$N��" + target + "д��$n�ϡ�\n", this_player(), obj);
	   obj->set("long",
		"����һ��" + obj->name() + "������д�ţ�" + target + "������Ѫ�֣�\n");
        }
        else {
	   message_vision("$N��" + tarobj->name() + "д��$n�ϡ�\n", this_player(), obj);
	   obj->set("long",
		"����һ��" + obj->name() + "������д�ţ�" + tarobj->name() + "������Ѫ�֣�\n");
        }
        obj->set("targetname", target);
        return 1;
}
int do_burn(string arg)
{
	string sheet, dest;
	object ob, sobj;
	function f;

	if(query("unused"))
	{
		return notify_fail("���ŷ����Ѿ�ʧЧ�ˣ�\n");
	}

	if( !arg || sscanf(arg, "%s", sheet)!=1 )
		return notify_fail("ָ���ʽ��burn <����>\n");

	if( !objectp(sobj = present(sheet, this_player()))) 
           return notify_fail("��Ҫʹ�����ŷ��䣿\n");

	if( !functionp(f = sobj->query("burn_func", 1)) )
		return notify_fail("���ŷ��������ա�\n");
//	if( this_player()->is_busy())
//		return notify_fail("������û�ա�\n");
	this_player()->start_busy(1);
	if( evaluate(f, sobj) ) {
		destruct(sobj);
		return 1;
	} else 
		return 0;
}

int do_attach(string arg)
{
	string sheet, dest;
	object ob, sobj;
	function f;

	if(query("unused"))
	{
		return notify_fail("���ŷ����Ѿ�ʧЧ�ˣ�\n");
	}

	if( !arg || sscanf(arg, "%s to %s", sheet, dest)!=2 )
		return notify_fail("ָ���ʽ��attach <����> to <Ŀ��>\n");

	if( !objectp(sobj = present(sheet, this_player()))) 
           return notify_fail("��Ҫʹ�����ŷ��䣿\n");

	ob = present(dest, this_player());
	if( !ob ) ob = present(dest, environment(this_player()));
	if( !ob ) return notify_fail("��Ҫ��ʲ�ᶫ��ʹ�����ŷ��䣿\n");

	if( !functionp(f = sobj->query("attach_func", 1)) )
		return notify_fail("���ŷ�����������\n");

	if( evaluate(f, sobj, ob) ) {
		if( ob!=this_player() )
			message_vision("$N�ó�һ��" + name() + "��$nһ����\n", this_player(), ob);
		if( ob && ob->is_character() ) {
			sobj->move(ob);
			sobj->set("equipped", "sealed");
			sobj->set("no_drop", "�����������ܶ����������� detach��\n");
		} else destruct(sobj);
		return 1;
	} else 
		return 0;
}

// whosepet.c  by tiandi for check the owner of pet.   somebody use the pet name as npc name.
inherit F_CLEAN_UP;
int main(object me, string arg)
{
string name;
        object ob;
        me = this_player();
        if( !arg || sscanf(arg, "%s", name) != 1 )
                return notify_fail("ָ���ʽ: whosepet <id>\n");
        if( !objectp(ob = present(name, environment(me))))
                return notify_fail("�Ҳ���" + name + "��\n");
          write(ob->query("name")+"��"+ob->query("owner")+"�ġ�\n");
return 1;
}
int help(object me)
{
	write(@Help
 ָ���ʽ: whosepet <id>
��Щ��Ҹ��Լ��ĳ���ȡһЩNPC�����֣����һЩ�������BUG��
���������ó��������ĸ���ҡ�
Help
        );
        return 1;
}

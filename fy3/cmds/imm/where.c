// where.c
// 06-14-95
inherit F_CLEAN_UP;
object find_player(string target)
{
        int i;
        object *str;
        str=users();
        for (i=0;i<sizeof(str);i++)
                if (str[i]->query("id")==target)
                        return str[i];
        return 0;
}
int main(object me, string str)
{
        object ob, where, *ob_list;
        int i;
        if (!str)
                return notify_fail("ָ���ʽ��where <�������>\n"); 
        ob = find_player(str);
        if( !ob ) ob = find_living(str);
        if( !ob || !me->visible(ob)) {
                str = resolve_path(me->query("cwd"), str);
                ob_list = children(str);
                for(i=0; i<sizeof(ob_list); i++) {
                        if( !ob = environment(ob_list[i]) ) continue;
                }
                return notify_fail("����˲�֪��������Ү...\n");
        }
        if (!ob) return notify_fail("����û�����.\n");
        where = environment(ob);
        if (!where) return notify_fail("����˲�֪��������Ү...\n");
        printf("\n���ó�ˮ��������һ����Ŷ��%s(%s)������...\n\n",
                (string)ob->name(),
                (string)ob->query("id"));
        "/cmds/std/look.c"->look_room(me,where);
        return 1;
}
int help(object me)
{
        write(@HELP
ָ���ʽ: where <��ҵ� ID>
���ָ����������֪���Ŀǰ���ڵ�λ��.
HELP
        );
        return 1;
}
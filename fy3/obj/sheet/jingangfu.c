// yiru@hero 2000.8.6

// ��շ�

inherit SHEET;

#include <ansi.h>

void create()
{
    set_name(YEL "��շ�" NOR, ({ "jin-gang sheet", "sheet"}) );
    set_weight(5);
    set("unit", "��");
    set("level", 5);
    set("value", 0);
    setup();
}

int burn_function()
{
    object ob, me = this_player();
    int lvl, bonus;

    if(undefinedp(query("targetname")))
        set("targetname",this_object());

    ob = query("targetname");
    if(!objectp(ob))
    {
        write("������writeָ���Ҫ��������д�����ϡ�\n");
        return 1;
    }

        if((int)ob->query_temp("jingangfu") > 0)
        {
                message_vision("$N�Ѿ��ܵ���շ��ı����ˣ�\n",ob);
                return 1;       
        }

    bonus = me->query("atman_factor");
    if( bonus < 1 ){
        write("����ʹ�� enchant ����ָ����������������\n");
        return 1;
    }
    if( me->query("atman")<me->query("atman_factor") ){
        write("������������ˣ�\n");
        return 1;
    }
    me->add("atman", -me->query("atman_factor") );

    message_vision("$N����һ��$n��$n��������������\n",me,this_object());

    lvl = query("level")+bonus;
        if(ob->query("family/family_name")!="��ɽ����")
        {
                lvl = lvl/5;
        }
    ob->add_temp("apply/iron-cloth", lvl/3);
    ob->add_temp("apply/extra_fle", lvl/8);
    ob->add_temp("jingangfu", lvl);

    ob->start_call_out( (: call_other, __FILE__, "do_back", ob, lvl, this_object() :), lvl/6);

    // ��call_out�ĺ�����δִ�У�����destruct
    set("no_get",1);
    move(VOID_OB);
    return 1;
}
 
void do_back(object ob, int lvl, object sheet)
{
    message_vision(HIY"����$N�Ľ�շ�ʧЧ�ˣ�\n"NOR,ob);
    ob->add_temp("apply/iron-cloth", -lvl/3);
    ob->add_temp("apply/extra_fle", -lvl/8);
    ob->add_temp("jingangfu",-lvl);
    destruct(sheet);
}


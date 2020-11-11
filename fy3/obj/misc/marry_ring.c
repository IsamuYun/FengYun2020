// marry_ring.c - ����ָ

#include <ansi.h>
#include <mudlib.h>
#include <armor.h>

inherit FINGER;

int do_coupletalk(string arg, int emote);

void create()
{
        set_name( HIY "����ָ" NOR, ({"marry ring", "ring"}) );
        set_weight(400);
        set( "no_get", 1);
	set( "no_put", 1 );
        set( "no_drop", "��Ľ���ָ���ܶ���,ֻ��ȥ����ׯ�����Լ��\n");
        set( "long", @LONG
����һö����ָ�������ʹ���������
[36m
coupletalk ( ct )	�Ͱ��¶Ի���

֧�����ct, ct#, ct*
[2;37;0m
LONG
	);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "ö");
                set("material", "gold");
		set("armor_type", "finger");
                set("armor_prop/armor", 10);
		set("armor_prop/defense", 10);
	        set("wear_msg", "$N��$n�ó���С�ĵش�����ָ�ϡ�\n");
	        set("remove_msg", "$N��$nС�ĵش���ָ��ժ�����źá�\n");
        }
}

string couplename( object ob ) {
	if( ob ) {
		if( (string)ob->query("gender") == "Ů��" ) return "����" + ob->name(1);
		if( (string)ob->query("gender") == "����" ) return "�ɷ�" + ob->name(1);
		return "�ɰ���" + ob->name(1);
	}
}

void init()
{
        object me, couple_ob;

	me = this_player();
	if( me->query("marry") ) {
	        couple_ob = find_player( me->query("marry") );
                    if (couple_ob && environment(couple_ob) ){
                 if ( couple_ob->query("marry")!=me->query("id") ){
                    tell_object(me,HIY "��İ����Ѿ�����Ͷ̥��,�����Ե...\n"+NOR);
                  me->delete("marry");
                  destruct(this_object());
                  return;
                }
        	 	write( HIM "\n���" + couplename( couple_ob ) + "Ҳ�������ȥ����....\n" NOR);
                	tell_object(couple_ob , sprintf( HIM "\n���%s��������ȥ����....\n" NOR, couplename( me ) ));
	        }
	        set("name", HIC + me->query("id") + HIY "��" HIC + me->query("marry") 
			+ HIY "�Ľ���ָ" NOR );
	}

        add_action("do_coupletalk_0", "ct");
        add_action("do_coupletalk_1", "ct*");
        add_action("do_coupletalk_2", "ct#");
}

int do_coupletalk_0(string arg) { return do_coupletalk( arg, 0 ); }

int do_coupletalk_1(string arg) { return do_coupletalk( arg, 1 ); }

int do_coupletalk_2(string arg) { return do_coupletalk( arg, 2 ); }

int do_coupletalk(string arg, int emote)
{
        object me, couple_ob;
        int i;

        me = this_player();

        if ( !stringp(me->query("marry")) )
                return notify_fail("��û�а��¡�\n");

        couple_ob = find_player( me->query("marry") );
        if( !couple_ob )
                return  notify_fail("��İ��������޷������㣬�����Ѿ��뿪��Ϸ�ˡ�\n");

        if ((string)couple_ob->query("gender") == "����") 
                return  notify_fail("��ԭ���İ����Ѿ�����̫�࣬�㻹�ǰ������˰ɡ�\n");

        if ( !arg ) {
                write( MAG "���������������İ����ˡ�\n" NOR);
                tell_room(environment(me), CYN + (string)me->name() + "��������������Լ��İ���" 
			+ (string)couple_ob->name() + "��\n" + NOR, ({me, couple_ob}));
                tell_object(couple_ob, sprintf(HIM "%s����������������ˡ�\n"NOR, couplename( me ) ) ); 

                return 1;
        }
	
        if (!stringp(arg) || arg == "" || arg == " ") arg = "...";

        // Support of channel emote
        if( emote ) {
                string vb, emote_arg;

                if( sscanf(arg, "%s %s", vb, emote_arg) != 2 ) {
                        vb = arg;
                        emote_arg = "";
                }
                arg = EMOTE_D->do_emote(me, vb, emote_arg, 1, me->name());

		// If out support of channel emote and still send this message
        	if (!arg && emote == 2)
                 	arg = me->name() + vb + "\n";

                // If not Support of channel emote ruturn
        	if (! arg) return 0;

		arg = replace_string( arg, me->name(), couplename( me ) );

        	tell_object( me, MAG + replace_string( arg, couplename( me ), "��" ) + NOR );
        	tell_object( couple_ob, HIM + arg + NOR );
        }
	else {
	        write(sprintf(MAG "���%s˵��%s\n" NOR, couplename( couple_ob ), arg ));
        	tell_object(couple_ob, sprintf(HIM "%s����˵��%s\n" NOR, couplename( me ), arg ));
	}

        return 1;
}


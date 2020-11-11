// marry_ring.c - ½á»é½äÖ¸

#include <ansi.h>
#include <mudlib.h>
#include <armor.h>

inherit FINGER;

int do_coupletalk(string arg, int emote);

void create()
{
        set_name( HIY "½á»é½äÖ¸" NOR, ({"marry ring", "ring"}) );
        set_weight(400);
        set( "no_get", 1);
	set( "no_put", 1 );
        set( "no_drop", "ÄãµÄ½á»é½äÖ¸²»ÄÜ¶ªÆú,Ö»ÄÜÈ¥ºìÄï×¯½â³ý»éÔ¼¡£\n");
        set( "long", @LONG
ÕâÊÇÒ»Ã¶½á»é½äÖ¸¡£Äã¿ÉÒÔÊ¹ÓÃÒÔÏÂÃüÁî£º
[36m
coupletalk ( ct )	ºÍ°éÂÂ¶Ô»°¡£

Ö§³ÖÃüÁî£ºct, ct#, ct*
[2;37;0m
LONG
	);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "Ã¶");
                set("material", "gold");
		set("armor_type", "finger");
                set("armor_prop/armor", 10);
		set("armor_prop/defense", 10);
	        set("wear_msg", "$N½«$nÄÃ³öÀ´Ð¡ÐÄµØ´÷ÔÚÊÖÖ¸ÉÏ¡£\n");
	        set("remove_msg", "$N½«$nÐ¡ÐÄµØ´ÓÊÖÖ¸ÉÏÕªÏÂÀ´·ÅºÃ¡£\n");
        }
}

string couplename( object ob ) {
	if( ob ) {
		if( (string)ob->query("gender") == "Å®ÐÔ" ) return "·òÈË" + ob->name(1);
		if( (string)ob->query("gender") == "ÄÐÐÔ" ) return "ÕÉ·ò" + ob->name(1);
		return "¾É°éÂÂ" + ob->name(1);
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
                    tell_object(me,HIY "ÄãµÄ°éÂÂÒÑ¾­ÖØÐÂÍ¶Ì¥ÁË,Èç¹ûÓÐÔµ...\n"+NOR);
                  me->delete("marry");
                  destruct(this_object());
                  return;
                }
        	 	write( HIM "\nÄãµÄ" + couplename( couple_ob ) + "Ò²ÔÚÕâÀï£¬¿ìÈ¥ÕÒÀ²....\n" NOR);
                	tell_object(couple_ob , sprintf( HIM "\nÄãµÄ%sÀ´À²£¬¿ìÈ¥½ÓÀ²....\n" NOR, couplename( me ) ));
	        }
	        set("name", HIC + me->query("id") + HIY "ºÍ" HIC + me->query("marry") 
			+ HIY "µÄ½á»é½äÖ¸" NOR );
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
                return notify_fail("ÄãÃ»ÓÐ°éÂÂ¡£\n");

        couple_ob = find_player( me->query("marry") );
        if( !couple_ob )
                return  notify_fail("ÄãµÄ°éÂÂÏÖÔÚÎÞ·¨Ìý¼ûÄã£¬»òÕßÒÑ¾­Àë¿ªÓÎÏ·ÁË¡£\n");

        if ((string)couple_ob->query("gender") == "ÎÞÐÔ") 
                return  notify_fail("ÄãÔ­À´µÄ°éÂÂÒÑ¾­×öÁËÌ«¼à£¬Äã»¹ÊÇ°ÑËûÍüÁË°É¡£\n");

        if ( !arg ) {
                write( MAG "ÄãÓÖÉîÇéµØÏëÄîÄãµÄ°®ÂÂÁË¡£\n" NOR);
                tell_room(environment(me), CYN + (string)me->name() + "ÓÖÔÚÉîÇéµØÏëÄî×Ô¼ºµÄ°®ÂÂ" 
			+ (string)couple_ob->name() + "¡£\n" + NOR, ({me, couple_ob}));
                tell_object(couple_ob, sprintf(HIM "%sÓÖÔÚÉîÇéµØÏëÄîÄãÁË¡£\n"NOR, couplename( me ) ) ); 

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

        	tell_object( me, MAG + replace_string( arg, couplename( me ), "Äã" ) + NOR );
        	tell_object( couple_ob, HIM + arg + NOR );
        }
	else {
	        write(sprintf(MAG "Äã¶Ô%sËµ£º%s\n" NOR, couplename( couple_ob ), arg ));
        	tell_object(couple_ob, sprintf(HIM "%s¶ÔÄãËµ£º%s\n" NOR, couplename( me ), arg ));
	}

        return 1;
}


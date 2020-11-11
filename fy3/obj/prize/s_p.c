// black_vest.c

#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("С����", ({ "dan" }) );
	set_weight(1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","���Ƶڶ��Ľ�Ʒ �÷���boost\n");
		set("unit", "��");
		set("value", 4000000);
		set("no_drop",1);
	}
	setup();
}

int query_autoload() { return 1; }
void init()
{
  if(this_player()==environment())
  add_action("boost_skill","boost");
}

int boost_skill()
{
        object ob, *list, couple_ob;
	string f_ski, s_ski, t_ski;
	int f_lvl= 0, s_lvl = 0, t_lvl=0;
        mapping skl, lrn, map;
        string *sname, *mapped,target,cardname;
        int i, marry_flag;
	ob = this_player();
        skl = ob->query_skills();
        if(!sizeof(skl)) {
                write( "��Ŀǰ��û��ѧ���κμ��ܡ�\n");
                return 1;
        }
        sname  = sort_array( keys(skl), (: strcmp :) );

        map = ob->query_skill_map();
        if( mapp(map) ) mapped = values(map);
        if( !mapped ) mapped = ({});

        lrn = ob->query_learned();
        if( !mapp(lrn) ) lrn = ([]);

       for(i=0; i<sizeof(skl); i++) {
		if(skl[sname[i]] >= f_lvl) 
		{
			s_lvl = f_lvl;
			s_ski = f_ski;
			f_lvl = skl[sname[i]];
			f_ski = sname[i];
		}
	else if( skl[sname[i]] >= s_lvl)
		{
			s_lvl = skl[sname[i]];
                        s_ski = sname[i];
		}
					}
	if(!s_ski) s_ski = f_ski;
	ob->set_skill(s_ski, (int)s_lvl+1);
message_vision("$N��"+to_chinese(s_ski)+"��ǿ�ˡ�\n", this_player());
destruct(this_object());
return 1;
}

#include <dbase.h>
#include <login.h>
#include <ansi.h>
int prevent_learn(object me, string skill)
{
	mapping 	my_family, family;
        int 		betrayer, mylvl, lvl;

	lvl = this_object()->query_skill(skill, 1);
	mylvl = me->query_skill(skill, 1);
        if( betrayer = me->query("betrayer") ) {
                if( mylvl >= lvl - betrayer * 20 ) {
			message_vision("$N��ɫ���ƺ���$n����ʮ�����Σ�\nҲ��������$p��ǰ����ʦ�ŵ�����\n...��\n", this_object(), me );
                        command("say �� .... \nʦ���ܽ���Ķ����ˣ����������Լ����ɡ�");
                        return 1;
                }
        }

        if( !me->is_apprentice_of(this_object())) {
		if( !mapp(my_family = me->query("family")) ) 
			return 0;
		if( !mapp(family = this_object()->query("family")) ) 
			return 0;
		if((my_family["family_name"] == family["family_name"]) ) {
                	command("hmm");
                	command("pat " + me->query("id"));
                	command("say ��Ȼ����ͬ�ţ������㲢���ҵĵ��ӣ��㻹��ȥ����ʦ��ѧ��....");
                	return 1;
		}
        }

        return 0;
}

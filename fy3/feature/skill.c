// skill.c

#include <ansi.h>
#include <dbase.h>

mapping skills;
mapping learned;
mapping skill_map;

mapping query_skills() { return skills; }
mapping query_learned() { return learned; }

void set_skill(string skill, int val)
{
	if( !find_object(SKILL_D(skill))
	&&	file_size(SKILL_D(skill)+".c") < 0 )
		error("F_SKILL: No such skill (" + skill + ")\n");

	if( !mapp(skills) ) skills = ([ skill: val ]);
	else skills[skill] = val;
}

int delete_skill(string skill)
{
	if( !mapp(skills) ) return 0;
	if(undefinedp(skills[skill])) return 0;
	if( mapp(skills) ) map_delete(skills, skill);
	if( mapp(learned) ) map_delete(learned, skill);
	if( mapp(skill_map) )
	{
		int i;
		string *name;
		name = keys(skill_map);
		for(i=0;i<sizeof(name);i++)
		if(name[i]==skill || skill_map[name[i]] == skill)
		map_delete(skill_map, name[i]);
	}
	return undefinedp(skills[skill]);
}

// This function 'map' a skill <skill> to another skill <mapped_to>.
// If 2nd argument not given, cancel the mapped skill <skill>.
varargs void map_skill(string skill, string mapped_to)
{
	if( !mapped_to && mapp(skill_map) ) {
		map_delete(skill_map, skill);
		return;
	}

	if( !find_object(SKILL_D(skill))
	&&	file_size(SKILL_D(skill)+".c") < 0 )
		error("F_SKILL: No such skill (" + skill + ")\n");

	if( !mapp(skills) || undefinedp(skills[mapped_to]) )
		return;
		
	if( !mapp(skill_map) ) skill_map = ([ skill: mapped_to ]);
	else skill_map[skill] = mapped_to;
}

string query_skill_mapped(string skill)
{
	if( mapp(skill_map) && !undefinedp(skill_map[skill]) )
		return skill_map[skill];
	return 0;
}
varargs int query_skill(string skill, int raw)
{
	if( !raw ) {
		int s , level;
		//by tiandi ���combatd�޸����ɼ��㷽ʽ������Ҫ����apply
		//s = query_temp("apply/" + skill);
		s = 0;
		if( mapp(skills) ) {
			s += skills[skill] / 2;
			if( mapp(skill_map) )
			{
		 if( skill_map[skill])
		 level = (int) (SKILL_D(skill_map[skill])->effective_level())  ;
		 else
		 level = 0;
				s += skills[skill_map[skill]] * level / 10 ;
			}
		}
		return s;
	}
	if( mapp(skills) && !undefinedp(skills[skill]) ) return skills[skill];
	return 0;
}

mapping query_skill_map()
{
	return skill_map;
}

int skill_death_penalty()
{
	string *sk;
	int i,j;
	if( !mapp(skills) ) return 0;
	i = 0;
	sk = keys(skills);
	if(sizeof(sk) <=0 ) return 0;
        for(j = 0; j<sizeof(sk); j++) 
	if( skills[sk[j]] > skills[sk[i]]) i=j;
			skills[sk[i]]--;
			if( skills[sk[i]]<=0 ) map_delete(skills, sk[i]);
	skill_map = 0;
	return 1;
}
varargs int query_skill_eff_lvl(string skill)
{
        int level;
if(mapp(skills)){
level = (int) (SKILL_D(skill)->effective_level())  ;
// for baisc skills where effecitive_level() undefined
if( level == 0) level = 5;
return skills[skill] * level /10;
}
return 0;
}

varargs void improve_skill(string skill, int amount, int weak_mode)
{
	int spi;
	if( !find_object(SKILL_D(skill))
	&&	file_size(SKILL_D(skill)+".c") < 0 )
		error("F_SKILL: No such skill (" + skill + ")\n");

	if( !weak_mode || !userp(this_object()) ) {
		if( !mapp(skills) ) skills = ([]);
//		if( undefinedp(skills[skill]) ) skills[skill] = 0;
	}

	// Give learning penalty to those learning too much skills.
	spi = this_object()->query_spi();
	if( sizeof(skills) > spi )
		amount /= sizeof(skills) - spi;

	if( amount <= 0 ) amount = 1;

	if( !mapp(learned) ) learned = ([ skill : amount ]);
	else (int)learned[skill] += amount;
//	put a upper limit here so that we can implment research_skill
	if(learned[skill] > (skills[skill] + 1) * (skills[skill] + 1))
	learned[skill] = (skills[skill] + 1) * (skills[skill] + 1) +1;
	if( (!weak_mode || !userp(this_object()))
	&&	learned[skill] > (skills[skill] + 1) * (skills[skill] + 1) ) {
		skills[skill]= skills[skill]+1;

		learned[skill] = 0;
		tell_object(this_object(), HIC "��ġ�" + to_chinese(skill) + "�������ˣ�\n" NOR);
		SKILL_D(skill)->skill_improved(this_object());
	}
}

varargs void decrease_skill(string skill, int amount, int weak_mode)
{
        int spi;
        if( !find_object(SKILL_D(skill))
        &&      file_size(SKILL_D(skill)+".c") < 0 )
                error("F_SKILL: No such skill (" + skill + ")\n");

        if( !weak_mode || !userp(this_object()) ) {
                if( !mapp(skills) ) skills = ([]);
        }
	if( weak_mode )
	{
		if( mapp(learned) ) {
		
			if (((int)learned[skill] - amount ) > 0 )
			 (int)learned[skill] -= amount;
				else learned[skill] = 0;
			}
	}
	else
	{
                skills[skill]= skills[skill]-1;
                learned[skill] = 0;
		if( skills[skill] <= 0 ) skills[skill] = 0;
                tell_object(this_object(), HIC "��ġ�" + to_chinese(skill) + "���˲��ˣ�\n" NOR);
                SKILL_D(skill)->skill_decreased(this_object());
	}
}
void research_skill(string skill, int amount)
{
    int spi;
	//int weak_mode;
    if ( !find_object(SKILL_D(skill))
        && file_size(SKILL_D(skill)+".c") < 0 ) {
        error("F_SKILL: No such skill (" + skill + ")\n");
	}

    if ( !mapp(skills) ) {
		skills = ([]);
	}
    // Give learning penalty to those learning too much skills.
    spi = this_object()->query_spi();
    if ( sizeof(learned) > spi ) {
        amount -= sizeof(learned) - spi;
	}

    if ( amount <= 0 ) {
		amount = 0;
	}

    if ( !mapp(learned) ) {
		learned = ([ skill : amount ]);
	}
    else {
		(int)learned[skill] += amount;
	}
    
	if (learned[skill] > 2 * (skills[skill] + 1) * (skills[skill] + 1) )
        {
            skills[skill] = skills[skill] + 1;
            learned[skill] = 0;
                
            this_object()->add("score", -skills[skill]);	
                
            tell_object(this_object(), HIC "��ġ�" + to_chinese(skill) + "�������ˣ�\n" NOR);
            SKILL_D(skill)->skill_improved(this_object());
    }
}

//by xgchen@fy
#include <ansi.h>
inherit F_CLEAN_UP;
#define DEATH_PERIOD 1200
int main(object me, string arg)
{
        object pet;
        object *ob_list;
        int i;
        string id,name;
        string file;
        if(me->is_busy()) return notify_fail("你现在不可以吹口哨。\n");
        if(me->is_ghost()) return notify_fail("你现在不可以吹口哨。\n");
        write("你轻轻地吹了声口哨．．．\n");
        file = me->query_save_file();
        file += ".pet.o";
        ob_list = children("/obj/pet");
        for(i=0; i<sizeof(ob_list); i++) 
                if(ob_list[i]->query("possessed") == me)
                        pet = ob_list[i];
        if(!pet && file_size(file) > 0 )
        {
                seteuid(getuid());
                pet = new("/obj/pet");
                pet->set("owner",me->query("id"));
                pet->restore();
				if (pet->query("kee")<0) pet->set("kee",1);
				if (pet->query("max_kee")<0) pet->set("max_kee",1);
				if (pet->query("eff_kee")<0) pet->set("eff_kee",1);
				if (pet->query("sen")<0) pet->set("sen",1);
				if (pet->query("max_sen")<0) pet->set("max_sen",1);
				if (pet->query("eff_sen")<0) pet->set("eff_sen",1);
				if (pet->query("gin")<0) pet->set("gin",1);
				if (pet->query("max_gin")<0) pet->set("max_gin",1);
				if (pet->query("eff_gin")<0) pet->set("eff_gin",1);
                id = pet->query("id");
                name = pet->query("name");
                pet->set("id",id);
				pet->set("is_pet",1);
                pet->set_name(name,({id}));
                pet->set("possessed",me);
                pet->setup();

        }
        me->add("sen",-50);

        if(pet && environment(pet) != environment(me) 
        && time() - (int)pet->query("deathstamp") > 60
        && !pet->is_fighting()  )
        {
        pet->move(environment(me));
        pet->reset_action();
		pet->add("obedience",-1);
		if (pet->query("obedience")<0)
		pet->set("obedience",0);
		if(pet->query("shouming") <1 && pet->query("is_pet")) 
			{
			tell_object(me,"你的宠物已经没有寿命了。\n");
			destruct(pet);
			return 1;
			}

		pet->add("shouming",-1);
        message_vision("$N不知从哪里窜到$n面前．\n",pet,me);    

		
// let pet be our protector
        if(me->is_fighting())
        {
        object *enemy;
        enemy = me->query_enemy();
        i = sizeof(enemy);
        while(i--) {
                if( enemy[i] && living(enemy[i]) ) {
                        pet->kill_ob(enemy[i]);
                        if( userp(enemy[i]) ) enemy[i]->fight_ob(pet);
                        else enemy[i]->kill_ob(pet);
                                                    }
                    }
    //by tiandi pet出战并不remove自身的killer    me->remove_all_killer();
        }
       
        pet->set_leader(me);
		me->set_temp("petalready",pet);
        }
        else
           if(pet) 
        {pet->save();
		if (pet->query("shouming")>0 )
			 message_vision("$N一闪就不见了。\n",pet);
		else
			 tell_object(me,"你的宠物已经没有寿命了。\n");
		me->delete_temp("petalready");
        destruct(pet);
        }
        return 1;
}
int help(object me)
{
        write(@HELP
指令格式 : whistle <宠物名>

详解请看帮助文件《宠物篇》:help pet.txt
HELP
        );
        return 1;
}


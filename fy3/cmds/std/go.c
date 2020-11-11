// go.c
#include <ansi.h>
inherit F_CLEAN_UP;
mapping default_dirs = ([
        "north":                "��",
        "south":                "��",
        "east":                 "��",
        "west":                 "��",
        "northup":              "����",
        "southup":              "�ϱ�",
        "eastup":               "����",
        "westup":               "����",
        "northdown":    "����",
        "southdown":    "�ϱ�",
        "eastdown":             "����",
        "westdown":             "����",
        "northeast":    "����",
        "northwest":    "����",
        "southeast":    "����",

        "southwest":    "����",
        "up":                   "��",
        "down":                 "��",
        "out":                  "��",
]);

void create() { seteuid(getuid()); }
int drop_things(object me)
{
        int i,max;
        object *inv;
        object env;
        env = environment(me);
        max = me->query_max_encumbrance();
        inv = all_inventory(me);
        for(i=0;i<sizeof(inv);i++){
                if(inv[i]->query("equipped")) continue;
                if(inv[i]->query("owner")) continue;
                if(random(max) < inv[i]->weight())
                {

                        tell_object(env,"�ڻ����У�");
                        me->ccommand("drop "+inv[i]->query("id"));
                }
                
        }                               

}
int check_flee(object me, string arg) 
{
   mapping      my, your;
   object       *enemy;
   int          fp, bp, i;

   i = me->query("combat_exp");
   if ( (random(i) < 300) && userp(me) ) return 1;
   enemy = me->query_enemy();
   for(i=0; i<sizeof(enemy); i++) {
      if( objectp(enemy[i]) && environment(enemy[i])== environment(me) && living(enemy[i])) { 
         fp = COMBAT_D->skill_power(me, "move", 3);
         if(fp<1) fp = 1;

         bp = COMBAT_D->skill_power(enemy[i], "move", 3);
         if(bp<1) bp = 1;
         if(random(fp*2+bp) > fp*2 || me->query("hubiao")) {
            message_vision(YEL "$N��" + arg + "��ȥ��\n" NOR, me);
            message_vision(RED "$N��Ӱһ����������$n����ǰ��\n" NOR, enemy[i], me);
            return 0;
         }
      }
   }
   return 1;
}


int main(object me, string arg)
{
        string dest, mout, min, dir, blk;
        object env, obj, blocker;
	mixed old_target;
        mapping exit;
        mapping block;


        if( !arg ) return notify_fail("��Ҫ���ĸ������ߣ�\n");

        if( me->over_encumbranced() )
                return notify_fail("��ĸ��ɹ��أ��������á�\n");
        if( me->query_temp("guardfor") )
                return notify_fail("������ػ���·�ڣ������ƶ���\n");
        if( me->is_busy() )
                return notify_fail("������æ�úܣ������ƶ���\n");
	// add by tiandi
        if( me->query_temp("in_trade") )
                return notify_fail("���������ڰ�̯������̯(exit)�ɡ�\n");


        env = environment(me);
        if(!env) return notify_fail("������Ҳȥ���ˡ�\n");

        if( !mapp(exit = env->query("exits")) || undefinedp(exit[arg]) ) {
                if( query_verb()=="go")
                        return notify_fail("�������û�г�·��\n");
                else
                        return 0;
     }
           if(this_player()->query("combat_exp")>1000000)
   {
        if( mapp(block = env->query("guarded/"))&& blk=block[arg]) {
       blocker = env->query("guarded/" + dir);
if (present(blk, env)&&  living(blocker) )
                return notify_fail("��������·���˸���ס�� ��\n");  

       }
}
        if ( old_target = me->query_temp("guardfor") )
        {
                if(objectp(old_target))
                {
                        if( living(old_target) )
                        tell_object(me,"���������"+old_target->name()+"��\n");
                        else
                        tell_object(me,"�㲻�����"+old_target->name()+"����ֱ���ˡ�\n");
                }
                else 
                tell_object( me, "�㲻����ס������"+default_dirs[old_target]+"�ķ����뿪�����\n" );
                me->delete_temp("guardfor");
        }

        dest = exit[arg];

        if( !(obj = find_object(dest)) )
                call_other(dest, "???");
        if( !(obj = find_object(dest)) )
                return notify_fail("�޷��ƶ���\n");

        if( !env->valid_leave(me, arg) ) return 0;

        if( !undefinedp(default_dirs[arg]) )
                dir = default_dirs[arg];
        else
                dir = arg;

        if( me->is_fighting() ) {
                if(check_flee(me, dir) == 0) {
                        return notify_fail("�㱻���˻�����\n");
                } 

                drop_things(me);
                mout = "��" + dir + "��Ķ����ˡ�\n";
                min = "����ײײ�����˹�����ģ����Щ�Ǳ���\n";
               
        } else {
// Let's add this messages here to make go and come more interesting...
                if( mout = me->query("leave_msg"))
                mout = "��" + dir + mout +" ��\n";
                else mout = "��" + dir + "�뿪��\n";
                if( min = me->query("arrive_msg"))
                min = min + " ��\n";
                else
                min = "���˹�����\n";
        }
        if (!userp(me) && obj->query("NONPC"))
                        return notify_fail("�㲻��ȥ���\n");
      if (!userp(me) && obj->query("no_fight"))
                        return notify_fail("�㲻��ȥ���\n");
        else
        if(obj->valid_enter(me))
                        return notify_fail("�㲻��ȥ���˵�˽լ��\n");
        if(!me->is_ghost())

        message( "vision", me->name() + mout, environment(me), ({me}) );
        if( me->move(obj) ) {
                me->remove_all_enemy();
                if(!me->is_ghost())
                message( "vision", me->name() + min, environment(me), ({me}) );
                me->set_temp("pending", 0);
                all_inventory(env)->follow_me(me, arg);
                return 1;
        }

        return 0;
}

void do_flee(object me)
{
        mapping exits;
        string *directions;

        if( !environment(me) || !living(me) ) return;
        exits = environment(me)->query("exits");

        if( !mapp(exits) || !sizeof(exits) ) return;
        directions = keys(exits);
        tell_object(me, "�������һ���������...\n");
        main(me, directions[random(sizeof(directions))]);
}

int help(object me)
{
        write(@HELP
ָ���ʽ : go <����>
 
������ָ���ķ����ƶ���
 
HELP
    );
    return 1;
}

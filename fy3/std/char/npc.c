// npc.c
//edit by 2002-2-9 xgchen@fy 
#include <command.h>

inherit CHARACTER;
inherit F_CLEAN_UP;
#include <ansi.h> 

object carry_object(string file)
{
        object ob;

        if( !objectp(ob = new(file)) ) return 0;
        ob->move(this_object());
        return ob;
}

object add_money(string type, int amount)
{
        object ob;

        ob = carry_object("/obj/money/" + type);
        if( !ob ) return 0;
        ob->set_amount(amount);
}

int accept_fight(object who)
{
        string att;

        att = query("attitude");

        if( is_fighting() )     switch(att) {
                case "heroism":
                        command("say 哼！出招吧！\n");
                        break;
                default:
                        command("say 想倚多为胜，这不是欺人太甚吗！\n");
                        return 0;
        }

        if( (int)query("gin") * 100 / (int)query("max_gin") >= 90
        &&      (int)query("kee") * 100 / (int)query("max_kee") >= 90
        &&      (int)query("sen") * 100 / (int)query("max_sen") >= 90 ) {
                switch(att) {
                        case "friendly":
                                command("say " + RANK_D->query_self(this_object())
                                        + "怎麽可能是" + RANK_D->query_respect(who)
                                        + "的对手？\n");
                                return 0;
                        case "aggressive":
                        case "killer":
                                command("say 哼！出招吧！\n");
                                break;
                        default:
                                if( !is_fighting() )
                                        command("say 既然" + RANK_D->query_respect(who)
                                                + "赐教，" + RANK_D->query_self(this_object())
                                                + "只好奉陪。\n");
                }
                return 1;
        } else
                return 0;
}

// This function is called by the reset() of the room that creates this
// npc. When this function is called, it means the room demand the npc
// to return its startroom.
int return_home(object home)
{
        // Are we at home already?
        if( !environment()
        ||      environment()==home )
                return 1;

        // Are we able to leave?
        if( !living(this_object())
        ||      is_fighting()
        ||      !mapp(environment()->query("exits")) ) return 0;

        // Leave for home now.
        message("vision", this_object()->name() + "急急忙忙地离开了。\n",
                environment(), this_object());
        return move(home);
}

// This is the chat function dispatcher. If you use function type chat
// message, you can either define your own functions or use the default
// ones.
int intellgent_behavor()
{
        int enc,max;
        object *inv;
        command("get all");
        return 1;
}
int chat()
{
        string *msg;
        int chance, rnd;
	int message_size = 0;

        if( !environment() ) return 0;
        if( query_temp("is_unconcious") ) return 0;
        if(query("intellgent")) intellgent_behavor();
        if( !chance = (int)query(is_fighting()? "chat_chance_combat": "chat_chance") )
                return 0;

        if( arrayp(msg = query(is_fighting()? "chat_msg_combat": "chat_msg"))) {
                if( random(100) < chance ) {
                        message_size = sizeof(msg);
			if (message_size > 0) {
			  rnd = random(message_size - 1);
                          if ( stringp(msg[rnd]) )
                                say(msg[rnd]);
                          else if( functionp(msg[rnd]) )
                                return evaluate(msg[rnd]);
			}
                }
                return 1;
        }
}

// Default chat function: Let the npc random move to another room.
int random_move()
{
        mapping exits;
        string *dirs;

        if( !mapp(exits = environment()->query("exits")) ) return 0;
        dirs = keys(exits);
        command("go " + dirs[random(sizeof(dirs))]);
        return 1;
}

// Default chat function: Let the npc cast his/her enabled spells
void cast_spell(string spell)
{
        string spell_skill;

        if( stringp(spell_skill = query_skill_mapped("spells")))
                SKILL_D(spell_skill)->cast_spell(this_object(), spell );
}

// Default chat function: Let the npc exert his/her enabled force
int exert_function(string func)
{
        string force_skill;

        if( stringp(force_skill = query_skill_mapped("force")))
                SKILL_D(force_skill)->exert_function(this_object(), func);
}

// Default chat function: Let the npc perform special action with 
// his/her enabled martial art
int perform_action(string action)
{
        object weapon;
        string martial_skill, act;

        if( sscanf(action, "%s.%s", martial_skill, act) != 2 )
                return 0;
        martial_skill = query_skill_mapped(martial_skill);
        if( stringp(martial_skill) )
                return SKILL_D(martial_skill)->perform_action(this_object(), act);           
}
/*      add reward for first time kills a npc.. 
        on the npc need to set("reward_npc", 1) and set("difficulty", lvl);
        
        current plan is to set difficulty between 1-40,
        difficulty=1 is roughly the reward of 1 task
        so the criteria of NPC setting are:
        1-5:　feel free to give it to any NPC you like, it's just a task or 2,
                However, suggest NPC exp>500k at least.
        5-15: some strong or fun NPCs, weak masters such as jinwuming,
        15-30: 
        30-40: reserved for tough NPC masters only. The reward is huge so be careful here
                example: Master shangguan=30, Huang=40 -- Silencer @Fy4 
*/ 
void die(){
        object killer, owner;
        string location;
        int difficulty, difficulty2;     
        
        if (this_object()->query_temp("last_damage_from")) {
        
                killer = this_object()->query_temp("last_damage_from");
           if(owner=killer->query("possessed"))    killer = owner; 
                if (killer->query("level")>this_object()->query("level")) {     
                        if(this_object()->query("reward_npc")){
                                if(!killer->query("m_killer/" + this_object()->query("name"))&& !this_object()->is_ghost()) {
                                        killer->set("m_killer/" + this_object()->query("name"),1);
                                        difficulty = this_object()->query("difficulty");
                                        if(!difficulty) difficulty = 1;
                                        location = environment(this_object())->query("short");
                                        this_object()->master_reward(this_object(),killer,location,difficulty);
                                }
                        }
                }    
                if(this_object()->query("dungeon_npc")=="eren2" && !this_object()->is_ghost()){
                        difficulty2 = this_object()->query("dungeon_difficulty");
                        if(!difficulty2) difficulty2 = 1;
                        this_object()->dungeon_reward(this_object(),killer,difficulty2);
                //      dungeon_reward() is defined in /std/char/smart_npc.c 
                }
        }
        ::die();
} 
void master_reward(object victim, object killer, string location, int difficulty)
{
        object money_reward;
        int i, pot, combat_exp, score;
        string reward_msg,kill_msg;    
        string *kill_type = ({ "击杀", "刺杀", "搏杀", "击毙","狙杀","砍杀","劈杀",
                                "巧杀", "拼杀", "斩杀", "怒杀", });
        reward_msg="";
        
        kill_msg= kill_type[random(11)];
        
           
                pot = difficulty*40;
                combat_exp = difficulty*150;
                score = difficulty*4;
        
                killer->add("potential",pot);
                killer->add("combat_exp", combat_exp);
                killer->add("score", score);
   if(killer->query("env/savemymoney"))
                killer->add("deposit",difficulty*30000);
        else
        {
                money_reward = new("/obj/money/gold");
                money_reward->set_amount(3*difficulty);
                money_reward ->move(killer);
        }
        
   set("channel_id", "江湖传闻");
CHANNEL_D->do_channel(this_object(), "fy", 
sprintf(HIY"%s，%s于%s"+HIY"%s"+HIY"%s。", NATURE_D->game_time(),
                        killer->query("name"), location, kill_msg, this_object()->name()) );  
        reward_msg +=HIW+"你成功地杀死了一个风云天骄，你被奖励了：\n\t\t" +
        chinese_number(combat_exp) + "点实战经验\n\t\t"+
        chinese_number(pot) + "点潜能\n\t\t" +
        chinese_number(score) + "点评价\n\t\t" + 
        chinese_number(difficulty*3) + "两黄金\n" + NOR;
                
        tell_object(killer,reward_msg); 
         
}     




#include <ansi.h>
#define CHAMPION_FILE "/obj/npc/champion.o"
inherit NPC;
void loadall(object me);
void changeshape(object winner);
int brag();
void create()
{
        string info,name,id,file;
        set_name( "盟主" , ({ "numberone" }) );
        set("chat_chance", 1);
        set("chat_msg", ({
                (: brag :),
        }) );
        setup();
        info = read_file(CHAMPION_FILE);
        if( info && sscanf(info,"%s %s %s",file,id,name) == 3)
        {
                restore_object(file);
        set_name( name , ({ id }) );
        delete("env");
        set("attitude", "aggressive");
        reset_action();
        delete_temp("already_loaded");
        loadall(this_object());
        set("title", HIR "武林盟主" NOR);
        }
        setup();        
                
}
void lose_enemy(object winner)
{
        call_out("changeshape",2,winner);
        return;
}
void changeshape( object winner)
{
        string winner_file;
        string name,id;
        if(!stringp(winner_file = winner->query_save_file()))
        return;
        CHANNEL_D->do_channel(this_object(), "chat",
        sprintf( "%s从现在开始是我们新的盟主了！！ \n",
        winner->name(1)));
        seteuid(ROOT_UID);
        write_file(CHAMPION_FILE,sprintf("%s %s %s",
        winner_file,winner->query("id"),winner->query("name")),1);
        seteuid(getuid());
        restore_object(winner_file);
        name = winner->query("name");
        id = winner->query("id");
        set_name( name , ({ id }) );
        delete("env");
        set("attitude", "aggressive");
        set("chat_chance", 1);
        set("chat_msg", ({
                (: brag :)
        }) );
        reset_action();
        delete_temp("already_loaded");
        loadall(this_object()); 
        set("title", HIR "武林盟主" NOR);       
        return ;
}

void loadall(object me)
{
        int MAX = 3;
        string name,id, *created;
        int i,j;
        object thing, *inv;
        inv = all_inventory(me);
                for(i=0; i<sizeof(inv); i++)
                {
                        destruct(inv[i]);
                }

        id = me->query("id");
        created = get_dir(DATA_DIR + "login/" + id[0..0] + "/" + id + "/");
        for(j=0; (j<sizeof(created) && j < (MAX+1) ); j++)
        if( sscanf(created[j], "%s.c", name) == 1 )
                {
        thing = new( DATA_DIR + "login/" + id[0..0] + "/" + id +
        "/" + name + ".c");
                        if(thing->move(me)) 
                        {
                        thing->wield();
                        thing->wear();
                        } 
                }
        me->reset_action();
        me->set_temp("already_loaded",1);
}
void init()
{
        if(!query_temp("already_loaded"))
                loadall(this_object());
        return;
}
int accept_fight(object me)
{
        return 1;
}
int brag(){
switch(random(4)){
        case 0:
          
      command("chat 武林盟主,号令天下，谁敢不从！");
                break;
        case 1:
                command("chat 水随天去流无际,人别此境挥情泪。。。。");
                break;
        case 2:
                command("haha");
                break;

        case 3:
                command("chat 大批西域手到来中原！请武林有志到本人处商讨对策。");
                break;}
     return 1;
}


/*
int brag()
{
        CHANNEL_D->do_channel(this_object(), "chat",
        "我就是你们的武林总盟主！不服的来试试！\n");
        return 1;
}
*/
void die()
{
        object ob;

        if( !ob = query_temp("last_damage_from") )
                ob = this_player(1);

        if( !ob ) return;

        changeshape(ob);
        return;
}



#include <ansi.h>

inherit NPC;

#include <dirtyword.h>

void punish(object);

void create()
{
        set_name("钟馗", ({"zhong kui", "zhongkui"}));
        set("gender", "男性" );
        set("age", 30);
        set("per", 5);//no rongmao description.

        set("long", "无人不知的抓鬼大仙，你碰上他准是你干了什么坏事。\n");
        set("class", "taoist");
        set("combat_exp", 3000000);
        set("attitude", "peaceful");
        set_skill("unarmed", 250);
        set_skill("dodge", 250);
        set_skill("parry", 250);
        set_skill("blade", 250);
        set_skill("force", 250);   
        set_skill("literate", 280);
        set_skill("spells", 250);
        set("max_kee", 1500);
        set("max_sen", 1400);
        set("force", 4000);
        set("max_force", 2400);
        set("mana", 6000);
        set("max_mana", 3000);   
        set("force_factor", 120);
        set("mana_factor", 150);
        setup();
        if( clonep() ) CHANNEL_D->register_relay_channel("rumor");
        if( clonep() ) CHANNEL_D->register_relay_channel("chat");
        if( clonep() ) CHANNEL_D->register_relay_channel("wiz");
        if( clonep() ) CHANNEL_D->register_relay_channel("new");
        if( clonep() ) CHANNEL_D->register_relay_channel("fy");
        if( clonep() ) CHANNEL_D->register_relay_channel("party");

}

void relay_channel(object ob, string channel, string msg)
{

        int i;
        if( !userp(ob) || (channel == "sys") ) return;

        for(i=0; i<sizeof(msg_d); i++)
        {
            if( strsrch(msg, msg_d[i]) >= 0)
                   {
                    call_out("punish",3,ob);
                    return;
                    }
        }
}

void punish(object ob)
{
        CHANNEL_D->do_channel(this_object(), "chat", sprintf("忽听钟馗一声怒喝：%s ，这次你可跑不了了。",ob->query("name")));
        message_vision(HIC"空中飞下一根绳子，一下就套住$N的脖子。\n"NOR+CYN"$N伸长舌头、翻着白眼地被拖走了。\n"NOR, ob);
        ob->move(environment(this_object()));
        command("say 老老实实地给我待着。");
        message_vision(CYN"说着，绳子一松，$N被扔在地上。\n"NOR, ob);
}




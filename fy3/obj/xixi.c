
#include <ansi.h>

inherit NPC;

#include <dirtyword.h>

void punish(object);

void create()
{
        set_name("��ظ", ({"zhong kui", "zhongkui"}));
        set("gender", "����" );
        set("age", 30);
        set("per", 5);//no rongmao description.

        set("long", "���˲�֪��ץ����ɣ���������׼�������ʲô���¡�\n");
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
        CHANNEL_D->do_channel(this_object(), "chat", sprintf("������ظһ��ŭ�ȣ�%s ���������ܲ����ˡ�",ob->query("name")));
        message_vision(HIC"���з���һ�����ӣ�һ�¾���ס$N�Ĳ��ӡ�\n"NOR+CYN"$N�쳤��ͷ�����Ű��۵ر������ˡ�\n"NOR, ob);
        ob->move(environment(this_object()));
        command("say ����ʵʵ�ظ��Ҵ��š�");
        message_vision(CYN"˵�ţ�����һ�ɣ�$N�����ڵ��ϡ�\n"NOR, ob);
}




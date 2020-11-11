inherit NPC;
#include <ansi.h>
void create()
{
        set_name("��Ħ", ({ "master damo", "master","damo"}) );
        set("vendetta_mark","shaolin");
        set("gender", "����" );
        set("title", "����ʼ��" );
    set("reward_npc", 1);
    set("difficulty", 300); 

        set("age", 150);
        set("agi",30);
        set("per", 35);
        set("int",200);
        set("str",500);
        set("attitude","friendly");
        set("max_force", 15000);
        set("force", 15000);
        set("long",
"����ʼ�棡\n"
        );
        create_family("������", 1, "ʼ��");
        set("combat_exp", 130000000);
        set_temp("apply/damage",2000);
        set_skill("move", 200);
        set_skill("dodge", 200);
        set_skill("force", 200);
        set_skill("axe", 200);
        set_skill("dagger", 200);
        set_skill("iron-cloth", 200);
        set_skill("perception", 200);
        set_skill("throwing", 200);
        set_skill("herb", 200);
        set_skill("spear", 200);
        set_skill("literate", 220);
        set_skill("unarmed",200);
        set_skill("puti-steps",200);
        set_skill("dabei-strike",200);
        set_skill("buddhism",200);
        set_skill("chanting",200);
        set_skill("xiaochengforce",200);
        set_skill("staff",200);
        set_skill("parry",200);
        set_skill("fumostaff",200);
        set_skill("blade",200);
        set_skill("sword",200);
        set_skill("damo-sword",200);
        set_skill("whip",200);
        set_skill("tianlongwhip",200);
        set_skill("suiyuan-sword",200);
        set_skill("lianxin-blade",200);
        set_skill("xingyi-stick",200);
        set_skill("dachengforce", 200);
        set_skill("liuxing-hammer", 200);
        set_skill("hammer", 200);
        set_skill("wuche-axe", 200);
        set_skill("duanhun-spear", 200);
        set_skill("yiyangzhi", 200);
        set_skill("yijinjing", 200);
       map_skill("sword","suiyuan-sword");
        map_skill("staff","xingyi-stick");
        map_skill("parry","lianxin-blade");
        map_skill("dodge", "puti-steps");
        map_skill("force", "yijinjing");
        map_skill("unarmed", "dabei-strike");
        map_skill("blade","lianxin-blade");
        setup();
        carry_object(__DIR__"obj/monk_cloth")->wear();
}
void attempt_apprentice(object ob)
{
        if(ob->query("class")!="shaolin")
        {
                 message_vision("$NЦ����������ʹӺ�ȥ������\n",
        this_object());
        return;
        }
        if((int) ob->query("force_factor") < 100)
        {
         message_vision("$NЦ�����书��̫���ˣ�����\n",
        this_object());
        return;
        }
    if ( random(250) || random((int)ob->query("kar")) <  25 )
        {
        message_vision("$N˵����������ȥ֮��............\n",
        this_object());
                return;
        }
         if ( !ob->query("m_success/�±�����"))
        {
        message_vision("$N����������˵��������Ϊ��������������\n",
        this_object());
                return;
               }
        if(!ob->query_temp("won_master_yi"))    
                {
        message_vision("$N˵�������ǵķ�������ô���أ�\n",
        this_object());
                return;
        }
         if(!ob->query("juexue"))        
                {
        message_vision("$N˵��������������������������\n",
        this_object());
                return;
        }
      command("sigh");
        command("say �ܺã�" + RANK_D->query_respect(ob) + 
"��Ȼ������Ե�����ľ�����Ϊͽ��ϣ�����������֡�\n");
        command("recruit " + ob->query("id") );
    }
void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "shaolin");
}
void re_rank(object student)
{
                student->set("title","�����»��³���");
                return ;
}
int is_ghost() { return 1; }

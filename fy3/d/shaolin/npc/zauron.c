inherit NPC;
#include <ansi.h>
 

void create()
{
        set_name("����", ({ "lianrong" }) );
        set("gender", "Ů��" );
        set("age",18);
        set("long", @TEXT
������ʮ��Ư����ȫ����㣬�����̲�ס���������ۣ���������
���ŵ����������������ŵĶ�������ӯ�Ĳ���������Ŷ!
TEXT
);
       set("class", "dancer");
       set("combat_exp", 200000);
        set_skill("unarmed",70);
        set_skill("dodge", 80);
        set_skill("force",70);
        set_skill("sword",70);
        set_skill("stormdance", 50);
        map_skill("dodge","stormdance");
        set("force", 3000);
        set("max_force", 600);

        set("force_factor", 10);
        setup();
        carry_object(__DIR__"obj/clasp")->wear();
        carry_object(__DIR__"obj/deer_boot")->wear();
        carry_object(__DIR__"obj/skirt2")->wear();
        carry_object(__DIR__"obj/bamboo_sword")->wield();

}

void init()
{
       object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }

}
void greeting(object ob)
{
        if( !ob || !present(ob, environment(this_object())) ) return;
        switch( random(2) ) {
                case 0:
                  say( "���ض���΢Ц�����ƵĶ���˵������ʮ���������ĵ�һ�����ˡ�\n");
                        break;
                case 1:
                  say( "���ض���΢Ц������ػζ��Ŵӱ�ɴ��¶���İ������ \n ˵������λ" +
RANK_D->query_respect(ob)
                   + "����ã���ӭ����ۡ԰��\n");
        }
}


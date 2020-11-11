#include <ansi.h>
inherit NPC;
int ask_job();
int ask_pei();

void create()
{
        set_name("��ƽ֮", ({ "lin pingzhi", "lin", "pingzhi" }));
        set("title", HIW "�����ھ��ٵ���" NOR );
              set("gender", "����");
        set("age", 20);
        set("long", "�����ǡ������ھ֡����ٵ��ң�����ƽ֮��\n");

        set("combat_exp", 300000);
        set("shen_type", 1);

        set("max_neili", 500);
        set("neili", 500);
        set("jiali", 10);

        set_skill("force", 40);
        set_skill("sword", 50);
        set_skill("unarmed", 50);
        set_skill("dodge", 50);
        set_skill("parry", 50);

        set("inquiry", ([
                "ʧ��" : (:ask_pei:),
                "����" : (:ask_job:),
                             "����" : (:ask_job:),
         ]) );


        set_temp("apply/attack", 50);
        set_temp("apply/defense", 50);
        set_temp("apply/damage", 15);

        setup();
        carry_object("/obj/weapon/sword")->wield();
        carry_object("/obj/cloth")->wear();
}


int ask_job()
{
        object me = this_player(), ob; 
        
        if (file_name(environment(this_object())) !="/d/city/biaoju") {
                command("shrug");
                command("say �Ҳ����ھ֣���֪����û�й������㰡!");
                return 1;
                }                               

        if (me->query("combat_exp") < 2000000) {
                command("say "+ me->query("name")+"������־���Ҫ��������");
                return 1;
                }
       
        if (me->query("quest/yunbiao")==1) {
                command("say ������ʲô����ȥ������!��Ȼ�����������!!");
                return 1;
                }
                
        me->set("quest/yunbiao",1);
        ob = new("/d/city/quest/biaotou");
        ob->move(environment(me));
        ob->set_temp("owner/id", me->query("id"));
        ob->set("combat_exp", me->query("combat_exp"));

        ob->set("max_qi",me->query("max_qi") * 5);
        ob->set("qi", me->query("qi") * 5); 
        ob->set("eff_qi",me->query("eff_qi") * 5);
        ob->set("max_neili",me->query("max_neili"));
        ob->set("neili",me->query("neili"));
        ob->set_skill("force",me->query_skill("force"));
        ob->set_skill("taiji-shengong",me->query_skill("unarmed"));
        ob->map_skill("force", "taiji-shengong");
        if(random(2)==0){
                command("say " + RANK_D->query_respect(me) +"�������ã�����һ����Ҫ�˵�����������Ǯ�ۿ����С�");
                ob->set_temp("yangzhou",1);
                }
          else  {
                command("say " + RANK_D->query_respect(me) +"�������ã�����һ����Ҫ�˵��������й١��������С�");
                ob->set_temp("taishan",1);
            
                }
         
 
       command("say ��ͺ���λ��ʦһ�������,��סҪ������ͷ��");
       command("chat "+ me->query("name") + "�����Ǹ����ھ����ڣ���·Ӣ�ۺ��ܶ����ա�");
       return 1;
}       

int ask_pei()
{
        object me = this_player();
        int kar, dot, balance;
        kar = me->query("kar");
        dot = (50 - random(kar)) * (50 - random(kar)) * 250;
        balance = me->query("balance");
        
        if (balance < dot ) {
                command("?");
                command("say ����Ҫ��" + chinese_number(dot / 10000) + "���ƽ����⳥���ǵ���ʧ��");
                }
        else {
                me->add("balance",-dot);
                command("nod");
                command("say �õģ����ȥ����Ϣ�ɣ�");
                call_out("cancel",120);
                }
        return 1;
}
                
int cancel()
{
        object me = this_player();
        me->set("quest/yunbiao",0);
        command("tell " + me->query("id") + " ����⳥�����Ѿ������ˡ�");
}

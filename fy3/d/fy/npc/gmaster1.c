// xgchen edit for 2001

inherit NPC;
#include <ansi.h>
int ask_pei();
int test_dart();
void create()
{
	set_name("����", ({ "meng", "cha meng" }) );
	set("title", HIY "��ʨ��" NOR);
	set("gender", "����" );
	set("age", 42);
	set("skill_public",1);
      set("inquiry",  ([
		"mission" : (: test_dart :),
		"����" : (: test_dart :),
                 "ʧ��" : (:ask_pei:),       ]) );       
	set("int", 30);
        create_family("�����׼�", 21, "����");
	set("long",
		"��ʨ�Ʋ����������׼ҵ��ӣ��˲��������ˬ���ҹ㽻���ѣ�
		 ������������̵ģ�ֻҪΪ�ھֳ����������ͿϽ̣�\n"
		);
       set("chat_chance", 50);
       set("chat_msg", ({
                " ����˵����������ھ����ⲻ��\n",
        }) );        
	set("attitude", "peaceful");
	set_skill("unarmed", 60);
	set_skill("changquan", 50);
	set_skill("literate", 60);
	set_skill("force", 70);
	set_skill("dodge",60);
	set_skill("parry",50);
	map_skill("unarmed", "changquan");
	set("combat_exp", 190000);
	setup();
	carry_object(__DIR__"obj/jinzhuang")->wear();
}
void init()
{
        ::init();
        add_action("do_accept", "accept");
}

int recognize_apprentice(object ob)
{
        if(ob->query("quest/ybover")){
                say("����˵�����㣮�������ûΪ�ھֳ�������....\n");
                return 0;
        }

        return 1;
}
int test_dart()
{
	object me;
	
	me=this_player();
        if (this_player()->query("vendetta/authority")>0)
   {            
                command("say ��λ"+RANK_D->query_respect(this_player())+"�������Ʒ�񲻺ã�����ô���ģ�");
                        return 1;    
       }
        if (is_busy())
       {
                command("say ��λ"+RANK_D->query_respect(this_player())+"����������Ҫ����");
                        return 1;    
       }
        if (query("marks/gived") > 1 )
	{
		command("say �����ھ�����û����Ҫ�����ڡ�");
		return 1;
	}
          this_player()->set_temp("quest/answer",1);
        start_busy(random(10));
	command("say �����Ϲ�Ǯׯ��һ�ʽ���Ҫ�˵����������Ը��Э�����ǣ�(accept mission)");
	return 1;
}
int do_accept(string arg)
{    
	object ob,cart,biaotou;
	object me,*team;
	int i;	
	if (arg != "mission") return 0;
	me=this_player();
	team=me->query_team();
	if (sizeof(team)==0) team=({me});
	for (i=0;i<sizeof(team);i++)
	{
		if (team[i]->query("combat_exp")<1500000)
		{
			command("say ����·;Σ�գ��ҿ���λ"+RANK_D->query_respect(team[i])+"�ƺ����ˣ�");
			return 1;
                }
        if (this_player()->query("combat_exp")>10000000)
                {
                        command("say �ҿ���λ"+RANK_D->query_respect(team[i])+"����̫���ˣ������ƺ����ˣ�");
                        return 1;
               }
                if (!intp(team[i]->query("deposit")) || team[i]->query("deposit")<1000000)
		{
			command("say ������Σ�յ��£��ҿ�"+RANK_D->query_respect(team[i])+"û���⳥������");
			return 1;
		}
	}
	
	if (sizeof(team) != 0 && (team[0]!=me)) 
			return notify_fail("say ֻ�ж����������������ڡ�\n");
        if (this_player()->query("quest/yunbiao"))
        return notify_fail("����˵��: ���Ѿ��ӹ����ˣ���ô����ȥ��ɣ�\n");
        if (this_player()->query_temp("quest/answer")<1)
        return notify_fail("����˵��: ��Ҫ�ش�ʲô���飿\n");
        if (this_player()->query("vendetta/authority")>0)
        return notify_fail("����˵��: ���Ѿ��ǹٸ�Ҫ�����ˣ���ô���������ء�\n");
        if (query("marks/gived") > 1 )
        return notify_fail("����˵��: ���Ѿ������˽��ˣ����´ΰɡ�\n");
        if (is_busy())
        return notify_fail("����˵��: �����ں�æ����Ȼᡣ\n");
        add("marks/gived",1);
        this_player()->delete("quest/ybpei");
        this_player()->set_temp("quest/biao_b",1);
	command("say �ðɡ���������ͷ�߰ɡ�");
	command("say ���ڿ���Ҫ��˫�ݵģ�һ·С�ġ�");
	command("rumor ��ʨ�ھֵ��ڶ��Ѿ������ˡ�");
	
	biaotou=new(__DIR__"biaotou");
        me->set("quest/yunbiao",1);
        biaotou->move(environment(me));
        biaotou->set_temp("owner/id", me->query("id"));
        biaotou->set("combat_exp", me->query("combat_exp"));
        biaotou->set("max_sen",me->query("sen") * 5);
        biaotou->set("max_gin",me->query("gin") * 3);
        biaotou->set("max_kee",me->query("kee") * 4);
        biaotou->set("eff_sen", me->query("sen") * 3); 
        biaotou->set("eff_gin",me->query("gin") * 3);
        biaotou->set("eff_kee", me->query("kee") * 4); 
        biaotou->set("sen", me->query("sen") * 3); 
        biaotou->set("gin", me->query("gin") * 3); 
        biaotou->set("kee", me->query("kee") * 4); 
        biaotou->set("eff_force",me->query("force"));
        biaotou->set("max_force",me->query("force"));
        biaotou->set("force",me->query("force"));
        biaotou->set_skill("dodge",me->query_skill("dodge"));
        biaotou->set_skill("iron-cloth",me->query_skill("iron-cloth")/3*2);
        biaotou->set_skill("changquan",me->query_skill("unarmed"));
        biaotou->map_skill("unarmed", "chuanquan");
        biaotou->move(environment());
	
    for(i=0;i<sizeof(team);i++)
       	team[i]->set_temp("protecting",cart);
    	
    me->set_temp("protecting",cart);
    me->set_leader(biaotou);
    me->delete_temp("quest/answer");
        start_busy(random(40));
    return 1;
}
int ask_pei()
{
        object me = this_player();
        int kar, dot, balance;
        kar = me->query("kar");
        dot = (random(50)+50)* 10000;
        balance = me->query("deposit");
        
        if (balance < dot || this_player()->query("quest/ybpei")) {
                command("?");
                command("say ����Ҫ�⳥������Ҫ��" + chinese_number(dot / 10000) + "���ƽ����⳥���ǵ���ʧ��");
                }
        else {
                me->add("deposit",-dot);
                command("nod");
                command("say �õģ��һ��������Ͽ�"+chinese_number(dot / 10000)+"���ƽ����ȥ����Ϣ�ɣ�");
                me->delete("quest/yunbiao");
                me->add("quest/ybpei",1);
                }
        return 1;
}
void reset()
{
delete("marks/gived");
}                  
